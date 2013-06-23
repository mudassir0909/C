//Took 21 minutes
#include <stdio.h>
#include <stdlib.h>

struct node{
  int info;
  struct node *link;
};

void display(struct node *start);
struct node *populate_list(struct node *start, int arr[], int n);
struct node *intersection(struct node *start1, struct node *start2);
void remove_duplicates(struct node *start);

int main(int argc, char *argv[]){
  int arr1[10] = {10,2,3,4,5,6,7,8,9,10}, arr2[5] = {5,4,1,2,10};
  struct node *start1 = populate_list(start1, arr1, 10);
  struct node *start2 = populate_list(start2, arr2, 5);
  printf("Inter section of \n");
  display(start1);
  printf("&\n");
  display(start2);
  printf("is:\n");
  struct node *start3 = intersection(start1, start2);
  display(start3);
  return 0;
}

struct node *intersection(struct node *start1, struct node *start2){
  struct node *p, *q, *start3 = NULL, *tmp, *end;
  for(p = start1; p != NULL; p=p->link){
    for(q = start2; q != NULL; q = q->link){
      if(p->info == q->info){
        tmp = (struct node *)malloc(sizeof(struct node));
        tmp->info = p->info;
        tmp->link = NULL;
        if(start3==NULL){
          start3 = tmp;
          end = start3;
        }else{
          end->link = tmp;
          end = end->link;
        }
      }
    }
  }
  remove_duplicates(start3);
  return start3;
}

void remove_duplicates(struct node *start){
  struct node *p, *q, *tmp, *prev;
  for(p=start; p->link != NULL; p=p->link){
    for(prev=q=p; q->link!=NULL; prev=q,q=q->link){
      if(p->info == q->link->info){
        tmp = q->link;
        q->link = tmp->link;
        free(tmp);
        q = prev;
      }
    }
  }
}

struct node *populate_list(struct node *start, int arr[], int n){
  struct node *tmp, *end;
  int i;
  for(i=0; i<n; i++){
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