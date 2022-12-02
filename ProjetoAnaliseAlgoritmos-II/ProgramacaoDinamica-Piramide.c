#include <stdio.h>
#include <stdlib.h>

void printMatriz(int **mat, int qtdE){
  printf("\n|v/e |[ 1]|[ 2]|[ 3]|[ 4]|[ 5]|\n");
  for (int i = 0; i < qtdE; i++){
    printf("|[%2d]| ", i+1);
    for (int j = 0; j < qtdE; j++)
      printf("%2d | ", mat[i][j]);
    printf("\n\n");
  }
}

int Piramide(int P[][5], int **S, int n) {
  for(int i=n-1; i>=0; i--){
    for(int j=0; j <=i; j++){
      //printMatriz(S, 5);
      if( i == n-1)
        S[i][j] = P[i][j];
      else{
        int esq = S[i+1][j];
        int dir = S[i+1][j+1];
        if(esq > dir)
          S[i][j] = esq + P[i][j];
        else
          S[i][j] = dir + P[i][j];
      }
    }
  }
  return 0;
}

int main() {
  int i, j;
    
  int **s = (int**)calloc(5, sizeof(int*));
  for (int l =0; l < 5; l++){
    s[l] = (int*) calloc(5, sizeof(int));
  }
  
  int matriz[][5] = {{7,0,0,0,0},
                    {3,8,0,0,0},
                    {8,1,0,0,0},
                    {2,7,4,4,0},
                    {4,5,2,6,5}};

  printf("%d", Piramide(matriz, s, 5));

  printMatriz(s, 5);
  
  return 0;
}
