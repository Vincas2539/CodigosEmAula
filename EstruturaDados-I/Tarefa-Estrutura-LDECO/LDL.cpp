#include <iostream>
#include "No.h"
#include "LDL.h"

// Construtor vazio
// inicia o cabeça da lista como null
LDL::LDL(){
	this->cabeca = nullptr;
	this->qtde = 0;
}

bool LDL::isEmpty() { // Verifica se lDL está vazia
	if (this->cabeca == nullptr) {
		return true; 
	} else {
	    return false;	
	};  
}


bool LDL::isFull(){ // verifica se alista está cheia
	No *aux = new No();
	
	if (aux == nullptr) return true;

	aux = nullptr;
	return false;
};

// Percorre a lDL em ordem crescente 
// e mostra os seus valores
void LDL::mostraOrdemCrescente(){
	// Percorre a lista e imprime os valores
	// em ordem Crescente
	if (cabeca == nullptr) cout << "Lista vazia!" << endl;
	else{
		cout << "Lista: [ ";
		No *pAnda = this->cabeca;
		while (pAnda->getProx() != this->cabeca){
			cout << pAnda->getChave() << " ";
			pAnda= pAnda->getProx();
		}
		cout << pAnda->getChave() << "]";
	}
}


// Percorre a lDL em ordem decrescente e mostra os seus valores
void LDL::mostraOrdemDecrescente(){
	// Percorre a lista e imprime os valores
	// em ordem decrescente
	if (cabeca == nullptr) cout << "Lista vazia!" << endl;
	else{
		cout << "Lista: [ ";
		No *pAnda = this->cabeca;
		while (pAnda->getAnt() != this->cabeca){
			pAnda= pAnda->getAnt();
			cout << pAnda->getChave() << " ";
		}
		cout << pAnda->getAnt()->getChave() << "]";
	}
}

// Insere um novo elemento na LDL na ordem
// crescente
bool LDL::insereOrdemCrescente(int chave, Elemento dado){
	// Cria um novo no
	No *novoNo = new No(chave, dado, nullptr, nullptr);
	
	if (isFull()) return false;

	// se lista vazia, insere o nó no ponteiro cabeça
	// e faz o nó apontar para ele mesmo
	if (cabeca == nullptr) {
		this->cabeca = novoNo;
		novoNo->setProx(novoNo);
		novoNo->setAnt(novoNo);
	} else { 
	    // Caso contrário, procura posição de inserção
	    // na ordem crescente de valores
		No *pAnda = this->cabeca, *pAnt = nullptr;
		while (pAnda->getProx() != cabeca && pAnda->getChave() < chave){
				pAnt = pAnda;
				pAnda = pAnda->getProx();
		}	
		// Se não andou na lista e a chave que pAnda aponta
	    // é maior que a chave a ser inserida, significa que a chave
		// a ser inserida é antes do cabeça
		// e cabeça precisa ser redefinido
		if (pAnt == nullptr && pAnda->getChave() > chave){
			novoNo->setAnt(this->cabeca->getAnt());
			this->cabeca->getAnt()->setProx(novoNo);
			this->cabeca->setAnt(novoNo);
			novoNo->setProx(this->cabeca);
			this->cabeca = novoNo;
		} else {
			// Caso pAnda tenha caminhado na lista e
			// a chave que o pAnda aponta é maior do que a chave a ser inserido
			// insere o nó depois do ponteiro anterior pAnt
		 	if (pAnda->getChave() > chave && pAnt != nullptr) {	 
				pAnt->getProx()->setAnt(novoNo);
				novoNo->setProx(pAnda);
				pAnt->setProx(novoNo);
				novoNo->setAnt(pAnt);
			} else {// Senão, insere a chave depois do pAnda
		    	pAnda->getProx()->setAnt(novoNo);
				novoNo->setProx(pAnda->getProx());
				pAnda->setProx(novoNo);
				novoNo->setAnt(pAnda);
			}
		}
	}
	this->qtde++;
	return true;
}


No *LDL::busca(int chave){
  if(!isEmpty()){
    No* pAnda = this->cabeca; // Init pAnda
    while (pAnda->getProx() != cabeca){
        if (pAnda->getChave() == chave)
            return pAnda;
        pAnda = pAnda->getProx();
    }
  } else cout << "Lista vazia!" << endl;
  return nullptr;
}

No *LDL::remove(int chave){
  No* apaga;
  apaga = busca(chave);
  if(apaga != nullptr){
    if(apaga->getProx() != apaga){
      apaga->getAnt()->setProx(apaga->getProx());
      apaga->getProx()->setAnt(apaga->getAnt());
    }
    apaga->setProx(nullptr);
    apaga->setAnt(nullptr);
    apaga = nullptr;
    delete apaga;
    cout << chave << " apagado com sucesso!" << endl;
    return cabeca;
  }
  cout << "Valor não está na lista!" << endl;
  return nullptr;
}

bool LDL::atualiza(int chave, int newDado){
  No *att;
  att = busca(chave);
  if(att == nullptr){
    return false;
  }
  att->setDado(newDado);
  return true;
}