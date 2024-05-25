#include "deque.h"

/**
 * @brief Create a new node with given data.
 *
 * @param data Pointer to the data to be stored in the node.
 * @param data_size Size of the data to be stored in the node.
 * @return Pointer to the newly created node.
 */
node_t* node_create(void* data, size_t data_size) {
  node_t* node = (node_t*)malloc(sizeof(node_t));

  if (!node) {
    fprintf(stderr, "[node_create]: error while allocating memory.");
    exit(-1);
  }

  node->data = malloc(data_size);

  if (!node->data) {
    fprintf(stderr, "[node_create]: error while allocating data memory.");
    exit(-1);
  }

  memcpy(node->data, data, data_size);
  node->prev = node->next = NULL;

  return node;
}

/**
 * @brief Destroy a node and free its memory.
 *
 * @param node Pointer to the node to be destroyed.
 */
void node_destroy(node_t* node) {
  if (!node) return;

  free(node->data);
  free(node);
}

/**
 * @brief Create a new deque.
 *
 * @param data_size Size of the data to be stored in the deque nodes.
 * @return Pointer to the newly created deque.
 */
cxc_deque* deque_create(size_t data_size) {
  cxc_deque* deque = (cxc_deque*)malloc(sizeof(cxc_deque));

  if (!deque) {
    fprintf(stderr, "[deque_create]: error while allocating memory for deque.");
    exit(-1);
  }

  deque->data_size = data_size;
  deque->head = deque->tail = NULL;

  return deque;
};

/**
 * @brief Check if the deque is empty.
 *
 * @param deque Pointer to the deque.
 * @return true if the deque is empty, false otherwise.
 */
bool deque_is_empty(cxc_deque* deque) { return deque->head == NULL; }

void deque_push_front(cxc_deque* deque, void* data) {
  node_t* new_node = node_create(data, deque->data_size);

  if (deque_is_empty(deque)) {
    deque->tail = new_node;
  } else {
    new_node->next = deque->head;
    deque->head->prev = new_node;
  }

  deque->head = new_node;
}

/**
 * @brief Push data to the front of the deque.
 *
 * @param deque Pointer to the deque.
 * @param data Pointer to the data to be pushed.
 */
void deque_push_back(cxc_deque* deque, void* data) {
  node_t* new_node = node_create(data, deque->data_size);

  if (deque_is_empty(deque)) {
    deque->head = deque->tail = new_node;
  } else {
    new_node->prev = deque->tail;
    deque->tail->next = new_node;
    deque->tail = new_node;
  }
}

/**
 * @brief Push data to the back of the deque.
 *
 * @param deque Pointer to the deque.
 * @param data Pointer to the data to be pushed.
 */
void deque_destroy(cxc_deque* deque) {
  if (deque_is_empty(deque)) return;

  node_t* current = deque->head;

  while (current != NULL) {
    node_t* next = current->next;
    node_destroy(current);
    current = next;
  }

  free(deque);
}

/**
 * @brief Remove and destroy the front node of the deque.
 *
 * @param deque Pointer to the deque.
 */
void deque_pop_front(cxc_deque* deque) {
  if (deque_is_empty(deque)) return;

  node_t* old_head = deque->head;

  if (old_head->next == NULL) {
    deque->head = NULL;
    deque->tail = NULL;
  } else {
    deque->head = old_head->next;
    deque->head->prev = NULL;
  }

  node_destroy(old_head);
};

/**
 * @brief Remove and destroy the back node of the deque.
 *
 * @param deque Pointer to the deque.
 */
void deque_pop_back(cxc_deque* deque) {
  if (deque_is_empty(deque)) return;

  node_t* old_tail = deque->tail;

  if (old_tail->prev == NULL) {
    deque->head = deque->tail = NULL;
  } else {
    deque->tail = old_tail->prev;
    deque->tail->next = NULL;
  }

  node_destroy(old_tail);
};

/**
 * @brief Traverse the deque and apply a callback function to each node.
 *
 * @param deque Pointer to the deque.
 * @param cb Callback function to apply to each node.
 */
void deque_traverse(cxc_deque* deque, callback_fn cb) {
  if (deque_is_empty(deque)) return;

  node_t* current = deque->head;

  while (current != NULL) {
    cb(current);
    current = current->next;
  }
}

/**
 * @brief Clear the deque, destroying all nodes.
 *
 * @param deque Pointer to the deque.
 */
void deque_clear(cxc_deque* deque) {
  if (deque_is_empty(deque)) return;

  node_t* current = deque->head;

  while (current != NULL) {
    node_t* next = current->next;
    node_destroy(current);
    current = next;
  }

  deque->head = deque->tail = NULL;
}

// numbers
void deque_print_int(node_t* node) { printf("%d\t", *(int*)node->data); }
void deque_print_bool(node_t* node) { printf("%d\t", *(bool*)node->data); }
void deque_print_float(node_t* node) { printf("%f\t", *(float*)node->data); }
void deque_print_double(node_t* node) { printf("%f\t", *(double*)node->data); }

// char, cstr
void deque_print_cstr(node_t* node) { printf("%s\t", (char*)node->data); }
void deque_print_char(node_t* node) { printf("%c\t", *(char*)node->data); }
