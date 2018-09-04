#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

struct Stack* stack_init()
{
  struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
  stack->cap = 8;
  stack->size = 0;
  stack->top = -1;
  stack->arr = (int*)malloc(sizeof(int) * stack->size);
  return stack;
}

int stack_size(Stack* stack)
{
  return stack->size;
}

void stack_resize(Stack* stack)
{
  int *newArr = malloc(sizeof(int) * stack->size * 2);

  for (int i = 0; i < stack->size; i++)
  {
    newArr[i] = stack->arr[i];
  }

free(stack->arr);
stack->arr = newArr;
stack->size *= 2;
}

int stack_is_full(struct Stack* stack)
{
  if(stack->top == stack->size)
    return 1;
  else
    return 0;
}

int stack_is_empty(struct Stack* stack)
{
  if(stack->top == -1)
    return 1;
  else
    return 0 ;
}

void stack_push(struct Stack* stack, int data)
{
  if(!stack_is_full(stack))
  {
    stack->arr[++stack->top] = data;
    stack->size++;
    printf("Pushed %d to the stack \n", data);
  } else {
    stack_resize(stack);
  }
}

int stack_peek(struct Stack* stack)
{
  printf("element at top of stack is: %d \n", stack->arr[stack->top]);
  return 0;
}


int stack_pop(struct Stack* stack)
{
  if(!stack_is_empty(stack))
  {
    return stack->arr[stack->top--];;
  } else {
    printf("can not pop from empty stack");
  }
  return 0;
}


