#include <stdio.h>

void my_function();

int main(int argc, char *argv[]){
  my_function();
  return 0;
}

void my_function(){
  printf("I am from the function !\n");
}