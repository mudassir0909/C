#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct student{
  char name[20];
  int rollno;
  int marks;
};

struct student *populate_structure();
void display_structure(struct student *s);
int main(int argc, char *argv[]){
  struct student *ptr;
  ptr = populate_structure();
  display_structure(ptr);
  return 0;
}

struct student *populate_structure(){
  struct student *ptr = (struct student *)malloc(sizeof(struct student));
  if(ptr == NULL)
    exit(0);
  strcpy(ptr->name, "Ayaaz");
  ptr -> rollno = 100;
  ptr -> marks = 9;
  return ptr;
}

void display_structure(struct student *s){
  printf("Name of student is %s\n", s->name);
  printf("rollno is %d\n", s->rollno);
  printf("marks are %d\n", s->marks);
}