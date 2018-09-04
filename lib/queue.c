#include <stdio.h>
#include <stdlib.h>
#include "queue.h"


Queue* queue_init()
{
  Queue* queue = malloc(sizeof(Queue));
  queue->cap = 10;
  queue->length = 0;
  queue->first = 0;
  queue->last = 0;
  queue->ring = malloc(sizeof(int) * queue->cap);
  return queue;
}

void queue_resize(Queue* queue)
{
  int* newRing = malloc(sizeof(int) * queue->cap * 2);
  for(int i = queue->first, j = 0; i != queue->last; i = (i + 1) % queue->cap, j++)
  {
    newRing[j] = queue->ring[i];
  }
  free(queue->ring);
  queue->first = 0;
  queue->last = queue->length - 1;
  queue->ring = newRing;
  queue->cap *= 2;
  
}

void queue_enqueue(Queue* queue, int data)
{
  if(queue->length == 0)
  {
  queue->ring[queue->last] = data;
  queue->length++;
  return;
  }
  if(queue->cap == queue->length)
  {
    queue_resize(queue);
  }
  if(queue->last == queue->cap - 1)
  {
    queue->last = 0;
  } else
  {
    queue->last++;
  }

    queue->ring[queue->last] = data;
    queue->length++;
}

int queue_dequeue(Queue* queue)
{
  if(queue->length == 0)
  {
    printf("NOTHING IN QUEUE\n");
  } else {

    int result = queue->ring[queue->first];
    if(queue->first == queue->cap - 1)
    {
      queue->first = 0;
    }
    else
    {
      queue->first++;
    }

    queue->length--;

    return result;
  }
  return 0;
}

int queue_size(Queue* queue)
{
  return queue->length;
}

int queue_peek(Queue* queue, int index)
{
  return queue->ring[index];
}

