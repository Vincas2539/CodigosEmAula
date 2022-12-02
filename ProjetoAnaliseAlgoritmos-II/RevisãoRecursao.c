#include <stdio.h>
/*
int main(void) {
  int a=5, b=12, c;
  int *p;
  int *q;
  p = &a;
  q = &b;
  c = *p + *q;
  printf("c = %d", c);
  return 0;
}
*/

float soma(int v[], int i, int n){
  float s = 0;
  if(i==n){
    return 0;
  }
  else{
    s = soma(v, i+1, n);
    s = s + v[i];
    return s;
  }
}

int main(void){
  int v[] = {10, 20, 30, 40};
  printf("soma = %f", soma(v, 0, 4));
}
