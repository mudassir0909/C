#include <stdio.h>
void do_stuff(float a[], int *b, char c[5]);
int main(int argc, char *argv[]){
  float a[] = {1.2,3.3,5.0,4.3,6.7};
  int b[] = {1,2,3,4,5};
  char c[] = {'a','b','c','d','e'};
  printf("Inside main()\n");
  printf("size of a is %lu\n", sizeof(a));
  printf("size of b is %lu\n", sizeof(b));
  printf("size of c is %lu\n", sizeof(c));
  do_stuff(a, b, c);
  return 0;
}

void do_stuff(float a[], int *b, char c[5]){
  printf("Inside do_stuff()\n");
  printf("size of a is %lu\n", sizeof(a));
  printf("size of b is %lu\n", sizeof(b));
  printf("size of c is %lu\n", sizeof(c));
}