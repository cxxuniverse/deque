#include "deque.h"

bool deque_is_empty(cxc_deque* deque) { return deque->head == NULL; }

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

void node_destroy(node_t* node) {
  if (!node) return;

  free(node->data);
  free(node);
}

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

void deque_traverse(cxc_deque* deque, callback_fn cb) {
  if (deque_is_empty(deque)) return;

  node_t* current = deque->head;

  while (current != NULL) {
    cb(current);
    current = current->next;
  }
}

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
