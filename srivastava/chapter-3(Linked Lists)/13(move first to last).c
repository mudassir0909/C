//Finished in 9 minutes, Cool :)

#include <stdio.h>
#include <stdlib.h>

struct node{
  int info;
  struct node *link;
};

struct node *populate_list(struct node *start);
void display(struct node *start);
int main(int argc, char *argv[]){
  struct node *start = NULL, *p, *tmp;
  start = populate_list(start);
  printf("The list is :\n");
  display(start);
  p = start;
  while(p->link != NULL)
    p = p->link;
  tmp = start;
  start = start->link;
  p->link = tmp;
  tmp->link = NULL;
  printf("The list after pushing the first node to last is:\n");
  display(start);
  return 0;
}

struct node *populate_list(struct node *start){
  int arr[5] = {1,2,3,4,5}, i ;
  struct node *tmp, *end;
  for(i = 0; i<5; i++){
    tmp = (struct node *)malloc(sizeof(struct node));
    tmp-> info = arr[i];
    tmp-> link = NULL;
    if(i == 0){
      start = tmp;
      end = start;
    }else{
      end->link = tmp;
      end = end->link;
    }
  }
  return start;
}

void display(struct node *start){
  struct node *p = start;
  while(p != NULL){
    printf("%d ", p->info);
    p = p->link;
  }
  printf("\n");
}
