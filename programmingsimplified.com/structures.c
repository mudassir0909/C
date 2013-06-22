#include <stdio.h>

struct sample_structure
{
  int number;
  char *pointer;
};

int main(int argc, char *argv[]){
  struct sample_structure number_plate;

  char car_name[] = "Volkswagon Beetle";
  number_plate.number = 4951;
  number_plate.pointer = car_name;
  
  printf("struct number_plate details\n");
  printf("Number plate of car %s is %d\n", number_plate.pointer, number_plate.number);
  return 0;
}