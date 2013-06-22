// Finished in 5 minutes Awesome :D

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
  printf("The list is\n");
  display(start);
  p = start;
  while(p->link->link != NULL)
    p = p->link;
  tmp = p->link;
  tmp->link = start;
  p->link = NULL;
  start = tmp;
  printf("After Changes: \n");
  display(start); 
  return 0;
}

void display(struct node *start){
  struct node *p = start;
  while(p!=NULL){
    printf("%d ", p->info);
    p = p->link;
  }
  printf("\n");
}

struct node *populate_list(struct node *start){
  struct node *end, *p;
  int arr[5] = {1,2,3,4,5}, i;
  for(i =0; i<5; i++){
    p = (struct node *)malloc(sizeof(struct node));
    p->info = arr[i];
    p->link =NULL;
    if(i==0){
      start = p;
      end = start;
    }else{
      end->link = p;
      end = end->link;
    }
  }
  return start;
}