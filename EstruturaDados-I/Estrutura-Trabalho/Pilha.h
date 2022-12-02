#ifndef _PILHA_H_
#define _PILHA_H_

#include "Vector.h"


class Pilha: public Vector{
  public: 
    int topo;

  public:
    Pilha();

    int size();
    void push(int n);

    void pop();
    int top();
};

Pilha::Pilha() {
  topo = -1;
  qtde = 0;
}

int Pilha::size() {
  return qtde;
}

void Pilha::push(int n){
  topo++;
  qtde++;
  add(topo, n);
}

void Pilha::pop() {
  remove(topo);
  qtde --;
  topo --;
}

int Pilha::top(){
  return A[topo];
}

#endif