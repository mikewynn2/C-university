#ifndef queue_h
#define queue_h


typedef struct {
  int cap;
  int length;
  int first;
  int last;
  int* ring;
} Queue;

Queue* queue_init();

void queue_enqueue(Queue* queue, int data);

int queue_dequeue(Queue* queue);

int queue_size(Queue* queue);

int queue_peek(Queue* queue, int index);

#endif
