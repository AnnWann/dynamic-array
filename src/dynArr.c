#include <stdlib.h>
#include <stdio.h>


typedef struct dynArr{
  void* arr;
  int topIndex;
  int size;
  int (*add)(struct dynArr*, int);
  int (*get)(struct dynArr*, int);
} dynArr;

int get(dynArr* self, int index);
int add(dynArr*  self, int val);



dynArr* dynamicArray(int size){
  dynArr* arr = malloc(sizeof(dynArr));

  arr->size = size;
  arr->arr = malloc(sizeof(int) * size);
  arr->add = &add;
  arr->get = &get;
  arr->topIndex = 0;
  return arr;
}

int get(dynArr* self, int index){
  int* i = self->arr;
  return i[index];
}
int add(dynArr* self, int val){
  int* i = self->arr;
  i[self->topIndex++] = val;
  return 1;
}

int main(){
  dynArr* arr = dynamicArray(3);
  arr->add(arr, 1);
  arr->add(arr, 2);
  arr->add(arr, 3);

  for(int i = 0; i < arr->size; i++){
    printf("%d", arr->get(arr, i));
  }
}

