#ifndef ____LDL____
#define ____LDL____

#include "No.h"
// Classe de Lista Duplamente Encadeada
class LDL{
	private:
		No *cabeca;
		int qtde;
	public:
		LDL();
		~LDL() {};// Exercício
		void setCabeca(No *cabeca){ this->cabeca = cabeca;	};
		No *getCabeca(){ return cabeca; };
		int getQtde(){ return qtde;	};
		void setQtde(int qtde) { this->qtde =  qtde; };
		bool isEmpty();	
		bool isFull();	
		bool insereOrdemCrescente(int chave, Elemento dado);
		void mostraOrdemCrescente();
		void mostraOrdemDecrescente();
		No *busca(int chave); // Exercício
		No *remove(int chave); // Exercício
    bool atualiza(int chave, int newDado);
    bool inserir(int chave, int newDado);
};

#endif