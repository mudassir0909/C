#include <stdio.h>

int main(int argc, char *argv[]){
  int arr[5] = {1,2,3,4,5};
  int i;
  for(i=0; i<5; i++){
    printf("Value of arr[%d] = %d\n",i, *(arr+i));
    printf("Address of arr[%d] = %p\n",i, (arr+i));
  }
  return 0;
}