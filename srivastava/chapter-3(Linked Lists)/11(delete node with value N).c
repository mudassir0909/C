//It took 30 minutes to solve this one !
//Improvement: 6 minutes
#include <stdio.h>
#include <stdlib.h>

struct node{
  int info;
  struct node *link;
};

struct node *populate_list(struct node *start);
void display(struct node *start);
struct node *delete_nodes(struct node *start, int value);

int main(int argc, char *argv[]){
  int choice, value;
  struct node *start = NULL;
  start = populate_list(start);
  while(1){
    printf("Choose your option\n");
    printf("0. Exit\n");
    printf("1. Delete a Node\n");
    printf("2. Display List\n");
    scanf("%d", &choice);
    if(choice == 0){
      exit(0);
    }else if(choice == 1){
      if(start==NULL){
        printf("List empty !\n");
      }else{
        printf("Enter the number to be deleted\n");
        scanf("%d", &value);
        start = delete_nodes(start, value);
        printf("After deletion the list is:\n");
        display(start);
      }
    }else if (choice == 2){
      display(start);
    }else{
      printf("Wrong Choice\n");
    }
  }
  return 0;
}

struct node *delete_nodes(struct node *start, int value){
  struct node *p = start, *tmp, *r;
  r = p;
  while(1){
    if(p == NULL){
      return start;
    }else{
      if(p->info == value){
        if(p == start){
          tmp = start;
          start = start->link;
          p = start;
          free(tmp);
        }else{
          tmp = p;
          p = p->link;
          r->link = p;
          free(tmp);
        }
      }else{
        r = p;
        p = p->link;
      }
    }
  }
}

void display(struct node *start){
  struct node *p = start;
  while(p!=NULL){
    printf("%d ", p->info);
    p = p->link;
  }
  printf("\n");
}

struct node *populate_list(struct node *start){
  int arr[15] = {1,2,23,2,2,1,1,4,5,6,6,7,8,9,99},i;
  struct node *p, *tmp;
  for(i=0; i<15; i++){
    tmp = (struct node *)malloc(sizeof(struct node));
    tmp->info = arr[i];
    tmp->link = NULL;
    if(i==0){
      start = tmp;
    }else{
      p = start;
      while(p->link != NULL)
        p = p->link;
      p->link = tmp;
    }
  }
  return start;
}