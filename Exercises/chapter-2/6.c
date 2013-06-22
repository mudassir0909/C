#include <stdio.h>

int main(int argc, char *argv[]){
  int i, arr[5] = {25, 30, 35, 40, 45}, *p;
  p = arr;
  for(i=0; i<5 ; i++)
    printf("%d\t%d\t\n", *(p+i), p[i]);
  return 0;
}

/*
OUTPUT
  25  25
  30  30
  35  35
  40  40
  45  45
*/