#include <stdio.h>

int main(void) {
  int lista[4] = {0, 1, 2, 3}, saidas[4];

  for (int i=1; i<=3; i++){
    saidas[1] = lista[i];
    for(int j=1; j<=3; j++){
      saidas[2] = lista[j];
      for(int k=1; k<=3; k++){
        saidas[3]= lista[k];
        printf("(");
        for(int l=1; l<=3; l++){
          printf("%d,", saidas[l]);
        }
        printf(")");
      }
    }
  }
  return 0;
}