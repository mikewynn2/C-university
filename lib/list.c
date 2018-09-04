#include <stdlib.h>
#include "list.h"


List* list_init()
{
  List* list = malloc(sizeof(List));
  list->size = 0;
  list->cap = 10;
  list->last = 0;
  list->arr = malloc(sizeof(int) * list->cap);
  return list;
}

void list_destroy(List* list)
{
  free(list->arr);
  free(list);
}


int list_size(List* list)
{
  return list->size;
}

void list_resize(List* list)
{
  int *newArr = malloc(sizeof(int) * list->cap * 2);

  for (int i = 0; i < list->size; ++i) 
  {
    newArr[i] = list->arr[i];
  }

  free(list->arr);
  list->arr = newArr;
  list->cap *= 2;
}

void list_push(List* list, int value)
{
  if (list->cap == list->size) 
  {
    list_resize(list);
  }

  list->arr[list->last++] = value;
  list->size++;
}

int list_get(List* list, int index)
{
  return list->arr[index];
}


