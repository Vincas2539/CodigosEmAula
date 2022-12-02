#include <string>
#include <iostream>
#include "LinkedList.h"

LinkedList::LinkedList(){
	head = nullptr;
  tail = nullptr;
  qtd = 0;
};
LinkedList::~LinkedList(){
	clear();
};

// Libera mem�ria 
void LinkedList::clear(){
	NodeLL *pAnt, *pAnda = head;
	
	while(pAnda != nullptr){
		pAnt = pAnda;  // Libera o n�
		pAnda = pAnda->getProx();
		pAnt->setProx(nullptr);
		delete pAnt;
		pAnt = nullptr;
	}
	head = nullptr;
  tail = nullptr;
  qtd = 0;
}

bool LinkedList::isEmpty(){
	if (getHead() == nullptr) return true;
	else return false;
};

bool LinkedList::isFull(){
	NodeLL *aux = new NodeLL();
	
	if (aux == nullptr) {
    std::cout << "ta cheio" << std::endl;
    return true;
  }

	aux = nullptr;
  
	return false;
};
		
bool LinkedList::insertHead(std::string linha){
	NodeLL *aux;
    if (!isFull()){
      aux = new NodeLL(linha, nullptr);
      if (isEmpty()){ // Lista est� vazia
        head = aux;
      }else { // Insere no come�o e atualiza o ponteiro
      	aux->setProx(head);
      	head = aux;
      }
      qtd++;
      return true;
    }
    else return false; // std::cout << "Overflow � Sem mem�ria";
};

bool LinkedList::insertTail(std::string linha){
	NodeLL *aux;
    if (!isFull()){
      aux = new NodeLL(linha, nullptr);
      if (isEmpty()){ // Lista est� vazia
        head = aux;
        tail = aux;
      }else { // Insere no final e atualiza o ponteiro
        this->getTail()->setProx(aux);
        setTail(aux);
      }
      qtd++;
	    return true;
    }
    else return false; // std::cout << "Overflow � Sem mem�ria";
};

		
NodeLL* LinkedList::search(std::string linha){
	NodeLL *pAnda;
	
    if (isEmpty()) {
		return nullptr; // Lista vazia
    }else{
      pAnda = head;
      // procura a posi�o do elemento na lista
      while ((pAnda != nullptr) && (pAnda->getLinha() != linha))
        pAnda = pAnda->getProx();
      return pAnda; // Retorna a refer�ncia para o elemento	encontrado
    }
}

bool LinkedList::remove(std::string linha){
	NodeLL *pAnt = nullptr, *pAnda;
    if (isEmpty()) return false; // Lista vazia
    else{
      pAnda = head;
      // procura a posi�o do elemento na lista
      while ((pAnda != nullptr) && (pAnda->getLinha() != linha)){
        pAnt = pAnda;
        pAnda = pAnda->getProx();
      }
      if (pAnda == nullptr) return false; // Se n�o encontrou o elemento
      // Se elemento encontrado remove da lista
      else {
      	// se o elemento encontrado est� na cabe�a da lista
      	if (head == pAnda) {
  		  head = pAnda->getProx();
  	    } else{ // remove elemento do meio/fim
  	    	pAnt->setProx(pAnda->getProx());
  		  }
        qtd--;
		    delete pAnda;
      	pAnda = nullptr;
      	return true;   
      }
    }
}

void LinkedList::print(){
	NodeLL *pAnda; 
  pAnda = head;

  int count = 0;
  while (pAnda != nullptr) {
    count++;
    std::cout << count << "ª linha: " << pAnda->getLinha() << std::endl;
    pAnda = pAnda->getProx();
  }
}