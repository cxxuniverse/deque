#include "deque.h"

int main() {
  cxc_deque* deque = deque_create(sizeof(int));
  cxc_deque* deque_f = deque_create(sizeof(float));

  int a = 1, b = 2, c = 3;
  float fa = 1.123f, fb = 1.223f, fc = 1.3123f;

  deque_push_back(deque, &a);
  deque_push_back(deque, &b);
  deque_push_back(deque, &c);

  deque_push_back(deque_f, &fa);
  deque_push_back(deque_f, &fb);
  deque_push_back(deque_f, &fc);

  float fd = 3.14f;

  deque_push_front(deque_f, &fd);

  deque_traverse(deque, deque_print_int);
  printf("\n");
  deque_traverse(deque_f, deque_print_float);
  printf("\n");

  //   deque_pop_front(deque);
  //   deque_pop_back(deque);

  deque_clear(deque_f);

  deque_pop_front(deque_f);
  deque_pop_back(deque_f);

  deque_push_front(deque_f, &fd);

  deque_traverse(deque_f, deque_print_float);
  printf("\n");

  return 0;
}