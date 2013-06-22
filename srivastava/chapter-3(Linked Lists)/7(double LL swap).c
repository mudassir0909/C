#include <stdio.h>
#include <stdlib.h>

struct node
{
  /* data */
  int info;
  struct node *next;
  struct node *prev;
};

struct node *populate_linked_list(struct node *start);
struct node *insert_at_beg(struct node *start, int value);
struct node *insert_at_end(struct node *start, int value);
void display(struct node *start);
struct node *swap_beg(struct node *p, struct node *q);
void swap(struct node *p, struct node *q);
void swap_end(struct node *p, struct node *q);

int main(int argc, char *argv[]){
  struct node *start = NULL;
  start = populate_linked_list(start);
  printf("Before Swapping:\n");
  display(start);
  struct node *p, *q, *r;
  for(p=start; p!=NULL; p=p->next){
    q = p->next;
    if(p == start){
      start = swap_beg(p, q);
    }else if(q->next == NULL){
      swap_end(p, q);
    }else{
      swap(p, q);
    }
  }
  printf("After Swapping:\n");
  display(start);

  return 0;
}

struct node *swap_beg(struct node *p, struct node *q){
  struct node *r = q->next;
  p->next = r;
  q->next = p;
  q->prev = p->prev;
  p->prev = q;
  r->prev = p;
  return q;
}

void swap_end(struct node *p, struct node *q){
  struct node *r = p->prev;
  q->prev = r;
  r->next = q;
  q->next = p;
  p->prev = q;
  p->next = NULL;
}

void swap(struct node *p, struct node *q){
  struct node *r, *s;
  r = p->prev;
  s = q->next;
  r->next = q;
  p->next = s;
  q->prev = r;
  q->next = p;
  p->prev = q;
  s->prev = p;
}

struct node *populate_linked_list(struct node *start){
  start = insert_at_beg(start, 1);
  int i;
  for(i = 2; i <= 8; i++){
    start = insert_at_end(start, i);
  }
  return start;
}

struct node *insert_at_beg(struct node *start, int value){
  struct node *tmp;
  tmp = (struct node *)malloc(sizeof(struct node));
  tmp->info = value;
  tmp->next = NULL;
  tmp->prev = NULL;
  start = tmp;
  return start;
}

struct node *insert_at_end(struct node *start, int value){
  struct node *tmp;
  struct node *p = start;
  while(p->next != NULL){
    p = p->next;
  }
  tmp = (struct node *)malloc(sizeof(struct node));
  tmp->info = value;
  tmp->next = NULL;
  tmp->prev = p;
  p->next = tmp;
  return start;
}

void display(struct node *start){
  struct node *p = start;
  if(start == NULL){
    printf("List is empty\n");
    return;
  }
  while(p != NULL){
    printf("%d ", p->info);
    p = p->next;
  }
  printf("\n");
}