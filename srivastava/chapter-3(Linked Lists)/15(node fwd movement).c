//It took 35 minutes, hmm...

#include <stdio.h>
#include <stdlib.h>

struct node{
  int info;
  struct node *link;
};

void display(struct node *start);
int isValid(struct node *start,int value);
struct node *populate_list(struct node *start);
struct node *move_node(struct node *start, int value, int pos_count);

int main(int argc, char * argv[]){
  struct node *start = NULL;
  int value, count;
  start = populate_list(start);
  printf("The List before: \n");
  display(start);
  printf("Enter the node to be moved forward\n");
  scanf("%d", &value);
  if(isValid(start, value)){
    printf("Enter the number of positions to be moved forward\n");
    scanf("%d", &count);
    start = move_node(start, value, count);
    printf("List after movement\n");
    display(start);
  }else{
    printf("The entered value doesn't exist in the list\n");
  }
}

struct node *move_node(struct node *start, int value, int pos_count){
  struct node *p = start, *q, *tmp;
  int i;
  if(start->info == value){
    q = start;   
  }else{
    while(p->link->info !=  value)
      p = p->link;
    q = p->link;    
  }
  for(i=1; i<= pos_count; i++){
    if(q->link == NULL){
      printf("Invalid count entered !\n");
      return start;
    }
    q = q->link;
  }
  if(start->info == value){
    tmp = start->link;
    start->link = q->link;
    q->link = start;
    start = tmp;
  }else{
    tmp = p->link;
    p->link = tmp->link;
    tmp->link = q->link;
    q->link = tmp;
  }
  return start;
}

struct node *populate_list(struct node *start){
  int arr[10] = {1,2,3,4,5,6,7,8,9,10}, i;
  struct node *tmp, *end;
  for(i=0; i<10; i++){
    tmp = (struct node *)malloc(sizeof(struct node));
    tmp->info = arr[i];
    tmp->link = NULL;
    if(i==0){
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
  struct node *p;
  p = start;
  while(p!=NULL){
    printf("%d ", p->info);
    p = p->link;
  }
  printf("\n");
}

int isValid(struct node *start, int value){
  struct node *p = start;
  while(p != NULL){
    if(p->info == value)
      return 1;
    p = p->link;
  }
  return 0;
}