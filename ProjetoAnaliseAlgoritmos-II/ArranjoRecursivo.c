#include <stdio.h>

int arranjo(int lista[], int saidas[], int t, int i);

int arranjo(int lista[], int saidas[], int t, int i){
  if(i>t){
    printf("(");
    for(int l=1; l<=t; l++){
      printf("%d, ", saidas[l]);
    }
    printf(")");
    return 0;
  }
  for(int j=1; j<=t; j++){
    saidas[i] = lista[j];
    arranjo(lista, saidas, t, i+1);
  }
}


int main(void) {
  int lista[4] = {0, 1, 2, 3}, saidas[4], i, j;
  arranjo(lista, saidas, 3, 1);
  
  return 0;
}
