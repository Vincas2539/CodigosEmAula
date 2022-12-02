#include <iostream>

using namespace std;

double *func(double *vet, int tamVet){
  double *menor = &vet[0];
  for(int i = 0; i < tamVet; i++){
    // verifica menor valor
    
    if(vet[i] < *menor){
      menor = &vet[i];
    }
  }

  return menor;
}

int main() {
  double *end, A[5] = {231.312, 895.12, 987.56, 115.3, 659.32};
  end = func(A, 5);
  // std::cout
  cout << "Endereço do menor valor: " << end << endl;
  cout << "Valor do menor valor: " << *end << endl;

  return 0;
}