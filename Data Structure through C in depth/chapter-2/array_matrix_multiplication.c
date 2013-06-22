#include <stdio.h>

int main(){
  int mat1[][3] = {{1,2,3}, {4,5,6}};
  int mat2[][2] = {{1,2}, {4,5}, {7,8}};
  int i,j,k, mat3[2][2], col=0;

  for(i=0;i<2;i++){
    for(j=0;j<2;j++){
      mat3[i][j] = 0;
      for(k=0; k<3; k++){ 
        mat3[i][j] += mat1[i][k] * mat2[k][j];
      }
    }
  }

  for(i=0;i<2;i++){
    for(j=0;j<2;j++){
      printf("%d ",mat3[i][j] );
    }
    printf("\n");
  }
}