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
  double *ptr, *end;
  int tamVet;
  cout << "Digite o tamanho do vetor: ";
  cin >> tamVet;
  ptr = new double[tamVet];
  for (int i = 0; i < tamVet; i++){
    cout << "Digite um valor: " ;
    cin >> ptr[i];
    cout << endl;
  }

  cout << "Valores do vetor:" << endl;
  for(int i = 0; i < tamVet; i++){
    cout << ptr[i] << endl;
  }
  end = func(ptr, tamVet);
  // std::cout
  cout << "Endereço do menor valor: " << end << endl;
  cout << "Valor do menor valor: " << *end << endl;
  
}

