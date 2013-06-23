
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
  struct node *ptr1, *ptr2, *dup;
  ptr1 = start;
 
  /* Pick elements one by one */
  while(ptr1 != NULL && ptr1->link != NULL)
  {
     ptr2 = ptr1;
 
     /* Compare the picked element with rest of the elements */
     while(ptr2->link != NULL)
     {
       /* If duplicate then delete it */
       if(ptr1->info == ptr2->link->info)
       {
          /* sequence of steps is important here */
          dup = ptr2->link;
          ptr2->link = ptr2->link->link;
          free(dup);
       }
       else /* This is tricky */
       {
          ptr2 = ptr2->link;
       }
     }
     ptr1 = ptr1->link;
  }
  // struct node *p, *q, *tmp, *prev;
  // for(p=start; p->link != NULL; p=p->link){
  //   for(prev=q=p; q->link!=NULL; prev=q,q=q->link){
  //     if(p->info == q->link->info){
  //       tmp = q->link;
  //       q->link = tmp->link;
  //       free(tmp);
  //       q = prev;
  //     }
  //   }
  // }
}

struct node *populate_list(struct node *start){
  int arr[20]={1,1,1,2,2,3,5,3,3,3,3,5,6,4,1,2,6,6,6,1}, i;
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
