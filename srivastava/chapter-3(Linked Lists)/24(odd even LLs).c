//It took 10 minutes to solve this one
/*CONDITION: should not change the original list*/

#include <stdio.h>
#include <stdlib.h>

struct node{
  int info;
  struct node *link;
};

void display(struct node *start);
struct node *populate_list(struct node *start);
struct node *insert_node(struct node *start, int value);

int main(int argc, char *argv[]){
  struct node *start=NULL, *even=NULL, *odd=NULL, *p;
  start = populate_list(start);
  p = start;
  printf("Original List:\n");
  display(start);
  int num;
  while(p != NULL){
    num = p->info;
    if(num%2 == 0){
      even = insert_node(even, num);
    }else{
      odd = insert_node(odd, num);
    }
    p = p->link;
  }
  display(even);
  display(odd);
  return 0;
}

struct node *populate_list(struct node *start){
  int arr[10] = {1,2,3,4,5,6,7,8,9,10}, i;
  for(i=0; i<10; i++)
    start = insert_node(start, arr[i]);
  return start;
}

struct node *insert_node(struct node *start, int value){
  struct node *p = start, *tmp;
  tmp = (struct node *)malloc(sizeof(struct node));
  tmp->info = value;
  tmp->link = NULL;
  /*List is empty*/
  if(start == NULL){
    start = tmp;
  }else{
    while(p->link != NULL)
      p = p->link;
    p->link = tmp;
  }
  return start;
}

void display(struct node *start){
  struct node *p = start;
  while(p!=NULL){
    printf("%d ", p->info);
    p = p->link;
  }
  printf("\n");
}