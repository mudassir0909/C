#include <stdio.h>

int main(int argc, char *argv[]){
  int c;

  printf("Number of arguments passed are %d\n", argc);

  printf("The arguments entered are as follows:\n");
  for(c = 0; c < argc; c++){
    printf("%d. Command Line Argument passed is %s\n", c+1, argv[c]);
  }
}