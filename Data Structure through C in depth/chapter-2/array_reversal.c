#include <stdio.h>

void print_array(int arr[], int n);

int main(int argc, char *argv[]){
  int array[] = {1,2,3,4,5,6,7,8,9,10,11};
  int i, temp;

  printf("Original Array is\n");
  print_array(array, 11);

  for(i = 0; i < 6; i++){
    temp = array[i];
    array[i] = array[10-i];
    array[10-i] = temp;
  }
  printf("Reversed Array\n");
  print_array(array, 11);

  return 0;
}

void print_array(int arr[], int n){
  int i;
  for(i = 0; i < n; i++){
    printf("%d\n", arr[i]);
  }  
}