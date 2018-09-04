#include <stdio.h>
#include "lib/list.h"
#include "lib/list.c"
#include "lib/queue.h"
#include "lib/queue.c"
#include "lib/stack.h"
#include "lib/stack.c"

void test_list()
{
  List* myList = list_init();
  printf("Size of the list: %d \n", list_size(myList));

  list_push(myList, 5);
  list_push(myList, 10);
  list_push(myList, -2);

  printf("Size of the list: %d \n", list_size(myList));

  for (int i = 0; i < list_size(myList); ++i)
  {
    printf("Value at %d: %d \n", i, list_get(myList, i));
  }

  list_destroy(myList);
};

void test_queue()
{
  Queue* myQueue = queue_init();
  printf("size of queue: %d \n", queue_size(myQueue));
  queue_dequeue(myQueue);
  printf("adding 10 to queue\n");
  queue_enqueue(myQueue, 1);
  queue_enqueue(myQueue, 2);
  queue_enqueue(myQueue, 3);
  queue_enqueue(myQueue, 4);
  queue_enqueue(myQueue, 5);
  queue_enqueue(myQueue, 6);
  queue_enqueue(myQueue, 7);
  queue_enqueue(myQueue, 8);
  queue_enqueue(myQueue, 9);
  queue_enqueue(myQueue, 10);
  printf("size of queue: %d \n", queue_size(myQueue));
  printf("dequeuing %d\n", queue_dequeue(myQueue));
  printf("dequeuing %d\n", queue_dequeue(myQueue));
  printf("dequeuing %d\n", queue_dequeue(myQueue));
  printf("dequeuing %d\n", queue_dequeue(myQueue));
  printf("dequeuing %d\n", queue_dequeue(myQueue));
  printf("size of queue: %d \n", queue_size(myQueue));
  printf("adding 10 to queue\n");
  queue_enqueue(myQueue, 11);
  queue_enqueue(myQueue, 12);
  queue_enqueue(myQueue, 13);
  queue_enqueue(myQueue, 14);
  queue_enqueue(myQueue, 15);
  queue_enqueue(myQueue, 16);
  queue_enqueue(myQueue, 17);
  queue_enqueue(myQueue, 18);
  queue_enqueue(myQueue, 19);
  queue_enqueue(myQueue, 20);
  printf("size of queue: %d \n", queue_size(myQueue));

}

void test_stack()
{
  struct Stack* mystack = stack_init();
  printf("Current size of the stack is: %d\n", stack_size(mystack));
  stack_push(mystack, 1);
  stack_push(mystack, 2);
  stack_push(mystack, 3);
  stack_push(mystack, 4);
  stack_push(mystack, 5);
  stack_push(mystack, 6);
  stack_push(mystack, 7);
  stack_push(mystack, 8);
  printf("Current size of the stack is: %d\n", stack_size(mystack));

  printf("%d popped off of top from stack\n",stack_pop(mystack));
  stack_peek(mystack);
  printf("%d popped off of top from stack\n",stack_pop(mystack));
  stack_peek(mystack);
  printf("%d popped off of top from stack\n",stack_pop(mystack));
  stack_peek(mystack);
  printf("Current size of the stack is: %d\n", stack_size(mystack));

}

int main(int argc, char *argv[])
{
  test_list();
  test_queue();
  test_stack();

  return 0;

}
