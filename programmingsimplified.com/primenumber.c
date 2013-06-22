#include <stdio.h>

int main(){
  int number;

  printf("Please enter a number\n");
  scanf("%d", &number);
  
  if(number == 2){
    printf("It's a prime number\n");
  }else{
    int i;
    for(i = 2; i <= number-1; i++){
      if(number%i == 0)
        break;
    }
    
    if (number == i){
      printf("%d is a prime number\n", number);
    }else{
      printf("%d is not a prime number\n", number);
    }
  }
  return 0;
}
