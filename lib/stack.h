#ifndef stack_h
#define stack_h

typedef struct Stack {
  int top;
  int size;
  int cap;
  int* arr;
}Stack;

Stack* stack_init();

int stack_size(Stack* stack);

int stack_is_full(Stack* stack);

int stack_is_empty(Stack* stack);

void stack_push(Stack* stack, int data);

int stack_peek(Stack* stack);

int stack_pop(Stack* stack);

#endif
