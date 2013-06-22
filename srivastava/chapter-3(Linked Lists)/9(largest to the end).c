#include <stdio.h>
#include <stdlib.h>

struct node{
  int info;
  struct node *link;
};

struct node *populate_list(struct node *start);
struct node *addatbeg(struct node *start, int data);
struct node *addatend(struct node *start, int data);
struct node *largest_to_end(struct node *start);
void display(struct node *start);
int main(int argc, char *argv[]){
  struct node *start = NULL;
  start = populate_list(start);
  printf("The List: \n");
  display(start);
  start  = largest_to_end(start);
  printf("After pushing the largest value to end\n");
  display(start);
  return 0;
}

void display(struct node *start){
  struct node *p = start;
  while(p != NULL){
    printf("%d ", p->info);
    p = p->link;
  }
  printf("\n");
}

struct node *populate_list(struct node *start){
  int arr[10] = {4,7,23,4,56,3,2,3,5,6}, i;
  start = addatbeg(start, arr[0]);
  for(i = 1; i<=9; i++){
    start = addatend(start, arr[i]);
  }
  return start;
}

struct node *addatbeg(struct node *start, int data){
  struct node *tmp = (struct node *)malloc(sizeof(struct node));
  tmp->info = data;
  tmp->link = NULL;
  start = tmp;
  return start;
}

struct node *addatend(struct node *start, int data){
  struct node *p = start, *tmp = (struct node *)malloc(sizeof(struct node));
  while(p->link != NULL)
    p =  p->link;
  tmp->info = data;
  tmp->link = p->link;
  p->link = tmp;
  return start;
}

struct node *largest_to_end(struct node *start){
  struct node *p,*q,*r;
  for(r=p=start; p->link != NULL; r=p,p=p->link){
    q = p->link;
    if(p->info > q->info){
      p->link = q->link;
      q->link = p;
      if(p==start)
        start = q;
      else
        r->link = q;
      p = q;
    }
  }
  return start;
}