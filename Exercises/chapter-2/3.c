#include <stdio.h>

int main(){
  int i =0, sum=0, arr[6] = {4,2,6,0,5,10};
  while(arr[i]){
    sum += arr[i];
    i++;
  }
  printf("sum is %d\n", sum);
  return 0;
}

/*
  OUTPUT
  sum is 12
*/