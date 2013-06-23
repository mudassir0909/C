//Took 16 minutes and no errors :)
#include <stdio.h>
#include <stdlib.h>

struct node{
  int info;
  struct node *link;
};

struct node *populate_list(struct node *start, int arr[] ,int n);
void display(struct node *start);
struct node *ll_union(struct node *start1, struct node *start2);
int number_exists(struct node *start, int value);
struct node *insert_number(struct node *start, int value);

int main(int argc, char *argv[]){
  int arr1[5] = {1,2,3,3,4}, arr2[7] = {12,3,3,4,5,6,7};
  struct node *start1, *start2, *start3;
  start1 = populate_list(start1, arr1, 5);
  start2 = populate_list(start2, arr2, 7);
  start3 = ll_union(start1, start2);
  printf("Union of \n");
  display(start1);
  printf("and\n");
  display(start2);
  printf("is\n");
  display(start3);
  return 0;
}

struct node *insert_number(struct node *start, int value){
  struct node *tmp = (struct node *)malloc(sizeof(struct node)), *p=start;
  tmp->info = value;
  tmp->link = NULL;
  if(start  == NULL){
    start = tmp;
  }else{
    while(p->link != NULL)
      p = p->link;
    p->link = tmp;
  }
  return start;
}

struct node *ll_union(struct node *start1, struct node *start2){
  struct node *start3 = NULL, *p1 = start1, *p2 = start2;
  while(p1 != NULL){
    if(!number_exists(start3, p1->info)){
      start3 = insert_number(start3, p1->info);
    }else{
      p1 = p1->link;
    }
  }
  while(p2 != NULL){
    if(!number_exists(start3, p2->info)){
      start3 = insert_number(start3, p2->info);
    }else{
      p2 = p2->link;
    }
  }
  return start3;
}

struct node *populate_list(struct node *start, int arr[], int n){
  struct node *tmp, *end;
  int i;
  for(i=0;i<n;i++){
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

int number_exists(struct node *start, int value){
  if(start == NULL)
    return 0;
  struct node *p = start;
  while(p!=NULL){
    if(p->info == value)
      return 1;
    p = p->link;
  }
  return 0;
}