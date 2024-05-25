#ifndef CXC_DEQUE_H
#define CXC_DEQUE_H

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node node_t;
typedef struct Deque cxc_deque;

typedef void (*callback_fn)(node_t* node);

struct Node {
  void* data;
  node_t* prev;
  node_t* next;
};

struct Deque {
  node_t* head;
  node_t* tail;
  size_t data_size;
};

bool deque_is_empty(cxc_deque* deque);

node_t* node_create(void* data, size_t data_size);

void node_destroy(node_t* node);

cxc_deque* deque_create(size_t data_size);

void deque_push_front(cxc_deque* deque, void* data);

void deque_push_back(cxc_deque* deque, void* data);

void deque_destroy(cxc_deque* deque);

void deque_pop_front(cxc_deque* deque);

void deque_pop_back(cxc_deque* deque);

void deque_traverse(cxc_deque* deque, callback_fn cb);

void deque_clear(cxc_deque* deque);

// numbers
void deque_print_int(node_t* node);
void deque_print_bool(node_t* node);
void deque_print_float(node_t* node);
void deque_print_double(node_t* node);

// char, cstr
void deque_print_cstr(node_t* node);
void deque_print_char(node_t* node);

#endif