#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
  int *p, i, n;
  printf("Enter the count of integers\n");
  scanf("%d", &n);
  p = (int *)malloc(n*sizeof(int));
  if (p==NULL){
    printf("Memory not sufficient \n");
    exit(1);
  }
  for(i=0; i<n; i++){
    printf("Enter value-%d\n", i+1);
    scanf("%d", (p+i));
  }
  for(i=0;i<n;i++)
    printf("value-%d is %d\n", i+1, *(p+i));
  return 0;
}