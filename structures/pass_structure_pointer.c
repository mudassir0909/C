#include <stdio.h>

struct student{
  char name[20];
  int age;
  int marks;
};

void print_structure(struct student *p);

int main(int argc, char *argv[]){
  struct student ayaaz = {"Ayaaz", 20, 75}, *ptr = &ayaaz;
  print_structure(ptr);

  return 0;
}

void print_structure(struct student *ptr){
  printf("Name is %s\n", ptr->name);
  printf("Age is %d\n", ptr->age);
  printf("Marks are %d\n", ptr->marks);
}