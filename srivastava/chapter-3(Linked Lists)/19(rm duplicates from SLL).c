//Took you 22 minutes to solve correctly, takes: 3
//Remarks, design algo properly before diving into code !

#include <stdio.h>
#include <stdlib.h>

struct node{
  int info;
  struct node *link;
};

struct node *populate_list(struct node *start);
void display(struct node *start);
void remove_duplicates(struct node *start);

int main(int argc, char *argv[]){
  struct node *start = NULL;
  int value;
  start = populate_list(start);
  display(start);
  remove_duplicates(start);
  printf("After removal of duplicates\n");
  display(start);
}


void remove_duplicates(struct node *start){
  int prev = start->info;
  struct node *tmp, *p = start, *q;
  q = p->link;
  while(q != NULL){
    if(p->info == q->info){
      tmp = q;
      q = q->link;
      p->link = q;
      free(tmp);
    }else{
      p = p->link;
      q = q->link;
    }
  }
}

struct node *populate_list(struct node *start){
  int arr[20]={1,1,1,2,2,3,3,3,3,3,3,5,4,4,6,6,6,6,6,6}, i;
  struct node *tmp, *end;
  for(i=0;i<20;i++){
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
