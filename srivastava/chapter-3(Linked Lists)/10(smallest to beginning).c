// Took 36 minutes to solve :-/ 22-Jun-2013

#include <stdio.h>
#include <stdlib.h>

struct node{
  int info;
  struct node *link;
};

struct node *populate_list(struct node *start);
struct node *addatbeg(struct node *start, int data);
struct node *addatend(struct node *start, int data);
void display(struct node *start);
struct node *smallest_to_beg(struct node *start);
int main(int argc, char *argv[]){
  struct node *start = NULL;
  start = populate_list(start);
  printf("Actual List\n");
  display(start);
  start = smallest_to_beg(start);
  printf("After moving smalled to beginning\n");
  display(start);
  return 0;
}

struct node *smallest_to_beg(struct node *start){
  struct node *p, *r, *tmp;
  for(r=p=start->link; p != NULL; r=p,p=p->link){
    if(start->info > p->info){
      if(p == start->link){
        start->link = p->link;
        p->link = start;
      }else{
        tmp = p->link;
        p->link = start->link;
        start->link = tmp;
        r->link = start;
      }
      tmp = start;
      start = p;
      p = tmp;
    }
  }
  return start;
}

struct node *populate_list(struct node *start){
  int arr[10] = {10,9,8,7,6,5,4,3,2,1},i;
  start = addatbeg(start, arr[0]);
  for(i = 1; i<=9; i++){
    start = addatend(start, arr[i]);
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

struct node *addatbeg(struct node *start, int data){
  struct node *tmp = (struct node *)malloc(sizeof(struct node));
  tmp->info = data;
  tmp->link = NULL;
  start = tmp;
  return start;
}

struct node *addatend(struct node *start, int data){
  struct node *tmp = (struct node *)malloc(sizeof(struct node)), *p = start;
  while(p->link != NULL)
    p = p->link;
  tmp->info = data;
  tmp->link = NULL;
  p->link = tmp;
  return start;
}