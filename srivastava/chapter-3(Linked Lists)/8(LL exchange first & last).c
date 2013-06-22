#include <stdio.h>
#include <stdlib.h>

struct node{
  int info;
  struct node *link;
};

struct node *populate_list(struct node *start);
struct node *add_at_beg(struct node *start, int data);
struct node *add_at_end(struct node *start, int data);
void exchange_by_data(struct node *start);
struct node *clear_list(struct node *start);
struct node *exchange_by_links(struct node *start);
void display(struct node *start);

int main(int argc, char *argv[]){
  struct node *start = NULL;
  start = populate_list(start);
  printf("Created List\n");
  display(start);
  exchange_by_data(start);
  printf("After Exchange first & last node data\n");
  display(start);
  start = clear_list(start);
  start = populate_list(start);
  printf("After repopulating the list\n");
  display(start);
  start = exchange_by_links(start);
  printf("Exchange by rearranging the links\n");
  display(start);
  return 0;
}

struct node *populate_list(struct node *start){
  start = add_at_beg(start, 1);
  int i;
  for(i = 2; i<=10; i++)
    start = add_at_end(start, i);
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

struct node *exchange_by_links(struct node *start){
  struct node *p = start, *tmp;
  while(p->link->link != NULL)
    p = p->link;
  tmp = p->link;
  tmp->link = start->link;
  start->link = NULL;
  p->link = start;
  return tmp;
}

void exchange_by_data(struct node *start){
  struct node *p = start;
  while(p->link != NULL)
    p = p->link;
  int tmp = start->info;
  start->info = p->info;
  p->info = tmp;
}

struct node *clear_list(struct node *start){
  struct node *tmp;
  while(start != NULL){
    tmp = start;
    start = start->link;
    free(tmp);
  }
  return NULL;
}

struct node *add_at_beg(struct node *start, int data){
  struct node *tmp = (struct node *)malloc(sizeof(struct node));
  tmp->info = data;
  tmp->link = NULL;
  start = tmp;
  return start;
}

struct node *add_at_end(struct node *start, int data){
  struct node *tmp = (struct node *)malloc(sizeof(struct node)), *p;
  while(p->link != NULL)
    p = p->link;
  tmp->info = data;
  tmp->link = NULL;
  p->link = tmp;
  return start;
}