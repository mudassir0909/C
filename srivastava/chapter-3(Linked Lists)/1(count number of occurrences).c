#include <stdio.h>
#include <stdlib.h>
struct node{
  int info;
  struct node *link;
};
struct node *create_list(struct node *start);
void display_occurences(struct node *start);
struct node *clear_list(struct node *start);
struct node *addatbeg(struct node *start, int value);
struct node *addatend(struct node *start, int value);
void display_list(struct node *start);
int main(int argc, char *argv[]){
  int choice, has_list;
  struct node *start;
  start = NULL;
  while(1){
    printf("Please enter appropriate number for your choice\n");
    printf("1. Create a Linked List\n");
    printf("2. Find the number of occurences for a given number\n");
    printf("3. Clear Existing List\n");
    printf("Enter 0 to exit\n");
    scanf("%d", &choice);
    switch(choice){
      case 0:
        exit(0);
      case 1:
        start = create_list(start);
        break;
      case 2:
        display_occurences(start);
        break;
      case 3:
        clear_list(start);
        break;
      default:
        printf("Wrong Choice !\n");
    }
  }
}

struct node *create_list(struct node *start){
  int val, count,i;
  printf("Enter number of elements\n");
  scanf("%d", &count);
  for(i=1; i<=count; i++)
  {
    printf("Enter the value--%d\n", i);
    scanf("%d", &val);
    if(i==1){
      printf("Add at beg\n");
      start = addatbeg(start, val);
    }else{
      printf("Add at end\n");
      start = addatend(start, val);
    }
  }
  printf("List successfully created & values are\n");
  display_list(start);
  return start;
}

void display_list(struct node *start){
  if(start==NULL){
    printf("List is empty\n");
  }
  struct node *tmp;
  tmp = start;
  while(tmp != NULL){
    printf("%d ", tmp->info);
    tmp = tmp->link;
  }
  printf("\n");
}

void display_occurences(struct node *start){
  int number,count=0;
  char try_again;
  struct node *tmp;  
  printf("Enter the number you wish to find occurences\n");
  scanf("%d", &number);
  tmp = start;
  while(tmp != NULL){
    if(tmp->info == number){
      count++;
    }
    tmp = tmp->link;
  }
  if(count){  
    printf("Number %d is found %d times\n", number, count);
  }else{
    printf("No occurences found\n");
  }
}

struct node *clear_list(struct node *start){
  struct node *tmp;
  while(start != NULL){
    tmp = start;
    start = start->link;
    free(tmp);
  }
  printf("List emptied\n");
  display_list(start);
  return start;
}

struct node *addatbeg(struct node *start, int value){
  start = (struct node *)malloc(sizeof(struct node));
  if(start == NULL){
    printf("Memory Not Available\n");
  }else{
    start->info = value;
    start->link = NULL;
  }
  return start;
}

struct node *addatend(struct node *start, int value){
  struct node *tmp,*new_node;
  tmp = start;
  while(tmp->link != NULL){
    tmp = tmp->link;
  }
  new_node = (struct node *)malloc(sizeof(struct node));
  new_node->info = value;
  new_node->link = NULL;
  tmp->link = new_node;
  return start;
}