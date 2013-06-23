//Took 25 minutes to properly solve !!
/*Condition: We do not know the length & we should not reverse the list*/

#include <stdio.h>
#include <stdlib.h>

struct node{
  int info;
  struct node *link;
};

void print_nth_node(struct node *start, int index);
void display(struct node *start);

int main(int argc, char *argv[]){
  struct node *start, *tmp, *end;
  int arr[10] = {1,2,3,4,5,6,7,8,9,10}, choice, index;
  for(index=0; index<10; index++){
    tmp = (struct node *)malloc(sizeof(struct node));
    tmp->info = arr[index];
    tmp->link = NULL;
    if(index==0){
      start = tmp;
      end = start;
    }else{
      end->link = tmp;
      end = end->link;
    }
  }
  while(1){
    printf("0. Exit\n");
    printf("1. Display List\n");
    printf("2. Print nth node\n");
    scanf("%d", &choice);
    switch(choice){
      case 0:
        exit(0);
      case 1:
        display(start);
        break;
      case 2:
        printf("Enter n value from last\n");
        scanf("%d", &index);
        print_nth_node(start, index);
        break;
      default:
        printf("Wrong choice\n");
    }
  }
}

void print_nth_node(struct node *start, int index){
  struct node *t, *p = start;
  int i;
  while(t != NULL){
    t = p;
    for(i=1; i<=index; i++){
      if(t==NULL){
        printf("Invalid index entered\n");
        return;
      }else{
        t = t->link;
      }
    }
    if(t != NULL)
      p = p->link;
  }
  printf("The node is %d\n", p->info);
}

void display(struct node *start){
  struct node *p = start;
  while(p!=NULL){
    printf("%d ", p->info);
    p = p->link;
  }
  printf("\n");
}