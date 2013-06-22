#include <stdio.h>

int main(int argc, char *argv[]){
  int i, first = 0, second = 1, next, n;

  printf("Enter the length of the sequence\n");
  scanf("%d", &n);

  for(i = 0; i < n; i++){
    if(i <= 1){
      next = i;
    }else{
      next = first + second;
      first = second;
      second = next;
    }

    printf("%d ", next);
  }

  printf("\n");
  return 0;
}