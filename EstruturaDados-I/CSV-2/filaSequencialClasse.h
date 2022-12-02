/*
   Fila est�tica e sequencial
   Desenvolvimento com Classe
   cria��o: 28/02/2022.
   prof. Dr. Ivan Carlos Alc�ntara de Oliveira
*/

#include <iostream>

using namespace std;

// defini��o de um novo tipo de dado
typedef int Elem;

// constante que indica o 
// Tamanho alocado para a Fila
const int TAM_FILA = 10;

// Classe que representa a fila 
// est�tica e sequencial
class Fila {
	private:
		int inicio, fim;
		Elem e[TAM_FILA];
	public:
		Fila();
		~Fila(){};
		bool qIsEmpty();
		bool qIsFull();
		void enqueue(Elem e);
		Elem dequeue();
		Elem front();
		Elem rear();
		int size();	
};

// Construtor que Inicia a fila vazia
Fila::Fila(){
  inicio = fim = 0;
}

// verifica se a fila est� vazia
bool Fila::qIsEmpty(){
  if (inicio == fim)
   return true;
  else
   return false;
}

// Verifica se a fila est� cheia
bool Fila::qIsFull(){
  if (fim == TAM_FILA)
   return true;
  else
   return false;
}

// insere um elemento no final da fila
void Fila::enqueue ( Elem e ){
  if (! qIsFull(  ))
    this->e[this->fim++] = e;
  else 
    cout << "oveflow - Estouro de Fila";
}

// remove um elemento do final da fila
Elem Fila::dequeue( ){
  if (! qIsEmpty( ))
   return e[inicio++];
  else{
    cout << "underflow - Esvaziamento de Fila";
    return -1;
  }
}

// retorna quem est� no in�cio da fila
// caso a fila n�o esteja vazia
Elem Fila::front(){
  if (! qIsEmpty())
   return e[inicio];
  else{
    cout << "underflow - Esvaziamento de Fila";
    return -1;
  }	
}

// retorna quem est� no final da fila
// caso a fila n�o esteja vazia
Elem Fila::rear(){
  if (! qIsEmpty()){
   int final = this->fim - 1;
   return this->e[final];
  }else{
    cout << "underflow - Esvaziamento de Fila";
    return -1;
  }	
}

// Retorna o total de elementos da fila
int Fila::size(){
	if (!qIsEmpty()) return fim - inicio;
	else return 0;
}

