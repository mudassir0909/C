#include <stdio.h>

void func(int arr[]);
int main(){
  int arr[5] = {5,10,15,20,25};
  func(arr);
  return 0;
}

void func(int arr[]){
  int i=5, sum =0;
  while(i>2)
    sum += arr[--i];
  printf("sum is %d\n", sum);
}

/*
Output is
  sum is 60
*/