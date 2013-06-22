//It took 27 minutes to solve this one !
//Improvement: 3 minutes

#include <stdio.h>
#include <stdlib.h>

struct node{
  int info;
  struct node *link;
};

struct node *populate_list(struct node *start, int arr[], int n);
struct node *addatbeg(struct node *start, int data);
struct node *addatend(struct node *start, int data);
void display(struct node *start);
void display_as_per_list_values(struct node *start1, struct node *start2);
struct node *print_value_at(struct node *index, int value);

int main(int argc, char *argv[]){
  struct node *start1=NULL, *start2 = NULL;
  int arr1[5] = {1,2,5,7,8}, arr2[10] = {11,22,33,44,55,66,77,88,99,111};
  start1 = populate_list(start1, arr1, 5);
  start2 = populate_list(start2, arr2, 10);
  printf("The Lists are: \n");
  display(start1);
  display(start2);
  printf("Displaying values in 2nd list as per values in 1st list\n");
  display_as_per_list_values(start1, start2);
  return 0;
}

void display_as_per_list_values(struct node *start1, struct node *start2){
  struct node *p = start1, *index = start2;
  int prev=1, current;
  while(p != NULL){
    current = p->info;
    index = print_value_at(index, current-prev);
    prev = current;
    p = p->link;
  }
}

struct node *print_value_at(struct node *index, int value){
  int count;
  for(count = 0; count < value; count++){
    index = index->link;
  }
  printf("%d\n", index->info);
  return index;
}

void display(struct node *start){
  struct node *p = start;
  while(p != NULL){
    printf("%d ", p->info);
    p = p->link;
  }
  printf("\n");
}

struct node *populate_list(struct node *start, int arr[], int n){
  int i;
  for(i=0; i<n; i++){
    if(i==0){
      start = addatbeg(start, arr[i]);
    }else{
      start = addatend(start, arr[i]);
    }
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
  struct node *tmp = (struct node *)malloc(sizeof(struct node)), *p;
  tmp->info = data;
  tmp->link = NULL;
  p = start;
  while(p->link != NULL)
    p = p->link;
  p->link = tmp;
  return start;
}