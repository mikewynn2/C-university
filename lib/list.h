#ifndef list_h
#define list_h


typedef struct {
  int size;
  int cap;
  int* arr;
  int last;
} List;

List* list_init();

void list_destroy();

int list_size(List* list);

void list_push(List* list, int value);

int list_get(List* list, int index);

#endif
