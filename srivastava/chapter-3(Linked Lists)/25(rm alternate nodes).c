// Took 12 minutes ! 3 retakes :-/
/*Condition: Remove even positioned nodes*/

#include <stdio.h>
#include <stdlib.h>

struct node{
  int info;
  struct node *link;
};

void display(struct node *start);
void remove_even_nodes(struct node *start);
struct node *insert_node(struct node *start, int value);

int main(int argc, char *argv[]){
  struct node *start = NULL;
  int arr[10] = {1,2,3,4,5,6,7,8,9,10}, i;
  for(i=0; i<10; i++)
    start = insert_node(start, arr[i]);
  printf("Original list:\n");
  display(start);
  remove_even_nodes(start);
  printf("After removing even nodes\n");
  display(start);
}

void display(struct node *start){
  struct node *p = start;
  while(p!= NULL){
    printf("%d ", p->info);
    p = p->link;
  }
  printf("\n");
}

struct node *insert_node(struct node *start, int value){
  struct node *p=start;
  struct node *tmp = (struct node *)malloc(sizeof(struct node));
  tmp->info = value;
  tmp->link = NULL;
  if(start == NULL){
    start = tmp;
  }else{
    while(p->link != NULL)
      p = p->link;
    p->link = tmp;
  }
  return start;
}

void remove_even_nodes(struct node *start){
  struct node *tmp, *p = start;
  while(p!=NULL && p->link != NULL ){
    tmp = p->link;
    p->link = tmp->link;
    free(tmp);
    p = p->link;
  }
}