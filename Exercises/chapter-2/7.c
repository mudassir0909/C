#include <stdio.h>

int main(int argc, char *argv[]){
  int i, arr[5] = {25,30,35,40,55};
  for(i=0; i<5; i++){
    printf("%d \n", *arr);
    arr++;
  }
  return 0;
}

/*
OUTPUT
  Error, since arr is a constant pointer and it cannot be changed
*/