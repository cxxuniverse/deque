#ifndef CXC_DEQUE_H
#define CXC_DEQUE_H

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  struct Node* next;
  struct Node* prev;
  void* data;
} Node;

typedef struct {
  Node* rear;
  Node* front;

  size_t element_size;
} Deque;

Deque* deque_create(void);

void deque_destroy(Deque* deque);
void deque_push_front(Deque* deque, void* data);
void deque_push_back(Deque* deque, void* data);
void deque_pop_front(Deque* deque);
void deque_pop_back(Deque* deque);
void deque_clear(Deque* deque);

void deque_traverse(Deque* deque);
#endif