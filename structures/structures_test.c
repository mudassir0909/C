#include <stdio.h>

struct employee{
  char name[20];
  int employee_id;
  float salary;
};

int main(int argc, char *argv[]){
  struct employee e1;
  printf("Enter the name, employee_id, salary of employee\n");
  scanf("%s%d%f", e1.name, &e1.employee_id, &e1.salary);
  printf("employee %s has employee_id %d and he earns %10.2f rupees\n", e1.name, e1.employee_id, e1.salary);
  return 0;
}