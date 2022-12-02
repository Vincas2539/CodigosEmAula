#include <stdio.h>
#include <stdbool.h>
int cont = 1;
int arranjo(int lista[], int t, int saidas[], int m,  int i);
int imprime(int lista[], int t);

int imprime(int lista[], int t){
  printf("%3d: (", cont);
  cont++;
  for(int l=1; l<=t; l++){
    printf(" %d ", lista[l]);
  }
  printf(")\n");
}
// Arranjo para qualquer tamanho
/* 

int arranjo(int lista[], int t, int saidas[], int m, int i){
  if(i>m){
    printf("%3d: (", cont);
    cont++;
    for(int l=1; l<=m; l++){
      printf("%d, ", saidas[l]);
    }
    printf(")\n");
    return 0;
  }
  for(int j=1; j<=t; j++){
    saidas[i] = lista[j];
    arranjo(lista, t, saidas, m, i+1);
  }
}


int main(void) {
  int lista[5] = {0, 1, 2, 3, 4}, saidas[4], i, j;
  arranjo(lista, 4, saidas, 3, 1);
  
  return 0;
}
  */

// Fazer subsequencias
/*
int arranjo(int lista[], int t, int saidas[], int m, int i, int j){
  for(;j<=t; j++){
    saidas[i] = lista[j];
    imprime(saidas, i);
    arranjo(lista, t, saidas, m, i+1, j+1);
  }
}


int main(void) {
  int lista[4] = {0, 1, 2, 3}, saidas[4], i, j;
  arranjo(lista, 3, saidas, 3, 1, 1);
  
  return 0;
}
*/

//backtracking

int arranjo(int lista[], int t, int saidas[], int m, int i){
  if (i>m){
    imprime(saidas, m);
    return 0;
  }
  
  for(int j=1;j<=t; j++){
    bool igual = false;
    saidas[i] = lista[j];
      for(int k=1; k<i; k++){
        if (saidas[i] == saidas[k])
          igual = true;
      }
    if(!igual)
      arranjo(lista, t, saidas, m, i+1);
  }
  return 0;
}


int main(void) {
  int lista[4] = {0, 1, 2, 3}, saidas[4], i, j;
  arranjo(lista, 3, saidas, 3, 1);
  
  return 0;
}
