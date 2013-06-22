#include <stdio.h>

int main(int argc, char *argv[]){
  int array[10];
  int smallest, largest, i;

  printf("Enter 10 elements in the array\n");
  for(i = 0; i < 10; i++){
    printf("Enter item-%d\n", i+1);
    scanf("%d", &array[i]);
    if(i==0){
      smallest = largest = array[i];
    }else{
      if (array[i] < smallest){
        smallest = array[i];
      }else if(array[i] > largest){
        largest = array[i];
      }
    }
  }

  printf("The smallest value entered is %d\n", smallest);
  printf("The largest value entered is %d\n", largest);

  return 0;
}