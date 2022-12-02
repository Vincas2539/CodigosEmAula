#ifndef _VECTOR_H_
#define _VECTOR_H_

#include <iostream>

using namespace std;

class Vector{
  public:
	int A[10];

    int maximo; // N° maximo de elementos.
    int qtde; // Elementos do Vetor.

	
    bool isEmpty;

  public:
	Vector();
    
    int size(); // Retorna tamanho do vetor
    int get(int i); // Pega da posicao

    void set(int i, int n);  // Mudar valor na posicao desejada
    void add(int i, int n); // Adicionar à posicao desejada
    void addfinal(int n); // Adicionar ao final

    void remove(int i); // Remove na posicao 

    void printar(){
      for (int i=0; i < qtde; i++){
        cout << A[i] << "\t";
      }
    }

    // int search(int n);
};


Vector::Vector() {
  qtde = 0;
  int A[10];
  isEmpty = true;
}

int Vector::size() {
  return qtde;
}

int Vector::get(int n){
  return A[n];
}

void Vector::set(int i, int n) {
  A[i] = n;
}

void Vector::add(int i, int n){
  A[i] = n;
}

void Vector::remove(int i){
  bool apos = false;
  for(int j = 0; j < qtde - 1; j++){
    if (i == j){
      apos = true;
    }

    if (apos){
      A[j] = A[j + 1];
    }

  }
}


#endif