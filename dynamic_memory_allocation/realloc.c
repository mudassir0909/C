#include <stdio.h>
#include <stdlib.h>

void suicide(int *ptr);
int main(int argc, char *argv[]){
  int *p, n, i;

  printf("Enter number of integers to be stored\n");
  scanf("%d", &n);
  p = (int *)malloc(n*sizeof(int));
  suicide(p);
  for(i=0; i < n; i++){
    printf("Enter Value-%d\n",i+1);
    scanf("%d",p+i);
  }
  printf("Entered values are\n");
  for(i=0; i<n; i++)
    printf("%d\n", *(p+i));
  p = (int *)realloc(p, (n+5)*sizeof(int));
  suicide(p);
  printf("Add 5 more values now\n");
  for(i=n; i< n+5; i++){
    printf("Enter Value-%d\n",i+1);
    scanf("%d",p+5+i);
  }
  printf("New values are\n");
  for(i=n; i< n+5; i++)
    printf("%d\n", *(p+5+i));
}

void suicide(int *ptr){
  if(ptr == NULL)
    exit(0);
}