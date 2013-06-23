/*Condition: No new nodes should be allocated*/
//Took 5 minutes

#include <stdio.h>
#include <stdlib.h>

struct node{
  int info;
  struct node *link;
};

void display(struct node *start);
struct node *populate_list(struct node *start);
struct node *add_node(struct node *start, struct node *p);

int main(int argc, char *argv[]){
  struct node *start=NULL, *positives = NULL, *negatives = NULL, *p, *tmp;
  start = populate_list(start);
  p = start;
  printf("The List before splitting:\n");
  display(start);
  while(p!=NULL){
    tmp = p->link;
    if(p->info >= 0){
      positives = add_node(positives, p);
    }else{
      negatives = add_node(negatives, p);
    }
    p = tmp;
  }
  printf("Positive Numbers\n");
  display(positives);
  printf("Negative Numbers\n");
  display(negatives);
  return 0;
}

struct node *add_node(struct node *start, struct node *p){
  struct node *ptr = start;
  p->link = NULL;
  /*List is empty*/
  if(start == NULL){
    start = p;
  }else{
    while(ptr->link != NULL)
      ptr = ptr->link;
    ptr->link = p;
  }
  return start;
}

struct node *populate_list(struct node *start){
  int arr[10] = {1,-2,-3,45,-5,6,7,-8,-9,10}, i;
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
  struct node *p = start;
  while(p!=NULL){
    printf("%d ", p->info);
    p = p->link;
  }
  printf("\n");
}