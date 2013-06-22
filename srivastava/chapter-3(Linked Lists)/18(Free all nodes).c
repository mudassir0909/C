//Took 5 minutes, single take, Nice work !

#include <stdio.h>
#include <stdlib.h>

struct node{
  int info;
  struct node *link;
};

struct node *populate_list(struct node *start);
struct node *free_nodes(struct node *start);
void display(struct node *start);

int main(int argc, char *argv[]){
  struct node *start = NULL;
  start = populate_list(start);
  display(start);
  start = free_nodes(start);
  display(start);
}

struct node *free_nodes(struct node *start){
  struct node *tmp;
  while(start != NULL){
    tmp = start;
    start = start->link;
    free(tmp);
  }
  return start;
}

struct node *populate_list(struct node *start){
  struct node *tmp, *end;
  int i, arr[5] = {1,2,3,4,5};
  for(i=0;i<5;i++){
    tmp = (struct node *)malloc(sizeof(struct node));
    tmp->info = arr[i];
    tmp->link = NULL;
    if(i==0){
      start = tmp;
      end= start;
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