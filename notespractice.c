#include <stdio.h>

int main(void){
  int a[] = {10, 20, 30, 40};
  int *p;
  p = a;
  printf("%d\n", ++*p);
  printf("%p\n", *p++);
  printf("%d\n", ++(*p));
  printf("%d\n", (*p)++);
}

