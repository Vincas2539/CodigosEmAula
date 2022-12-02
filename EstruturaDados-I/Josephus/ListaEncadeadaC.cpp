#include <iostream>
#include <string>

#include "ListaEncadeadaC.h"
#include "NodeLLC.h"

LinkedListC::LinkedListC(){
	head = nullptr;
  qtd = 0;
};
LinkedListC::~LinkedListC(){
	clear();
};

bool LinkedListC::isEmpty(){
	if (head == nullptr) return true;
	else return false;
};

// Libera memória 
void LinkedListC::clear(){
	NodeLLC *pAnt, *pAnda = head;
  if (!isEmpty()){
  	while(pAnda != head && getQtd() > 1){
  		pAnt = pAnda;  // Libera o nó
  		pAnda = pAnda->getProx();
  		pAnt->setProx(nullptr);
  		delete pAnt;
  		pAnt = nullptr;
  	}
  	head = nullptr;	
    clearQtd();
  }
}

bool LinkedListC::isFull(){
	NodeLLC *aux = new NodeLLC();
	
	if (aux == nullptr) return true;

	aux = nullptr;
  delete aux;
	return false;
};

bool LinkedListC::insert(std::string nome){
	NodeLLC *newNo, *pAnda;
    if (!isFull()){
      newNo = new NodeLLC(nome, nullptr);
      if (isEmpty()){ // Lista está vazia
        setHead(newNo);
        newNo->setProx(newNo);
      }else { // Insere no final e atualiza o ponteiro
        pAnda = head;  // Ponteiro que anda até o final da lista 
        while (pAnda->getProx() != head)
          pAnda = pAnda->getProx();
        pAnda->setProx(newNo);
        newNo->setProx(head);
      }
    addQtd();
	  return true;
    } else return false; // std::cout << "Overflow – Sem memória";
};

bool LinkedListC::remove(std::string nome){
	NodeLLC *pAnt = nullptr, *pAnda;
    if (isEmpty() == true) return false; // Lista vazia
    else{
      pAnda = head;
      // procura a posição do elemento na lista
      while ((pAnda->getProx() != head) && (pAnda->getNome() != nome)){
        pAnt = pAnda;
        pAnda = pAnda->getProx();
      }
      if (pAnda->getProx() == head && pAnda->getNome() != nome) return false; // Se não encontrou o elemento
      // Se elemento encontrado remove da lista
      else {
      	// se o elemento encontrado está na cabeça da lista
      	if (head == pAnda && pAnda->getNome() == nome) {
          if(pAnda->getProx() == head){
            head = nullptr;
            rmvQtd();
            return true; 
          }else{
            pAnt = head;
            head = pAnda->getProx();
            while(pAnt->getProx() != head){
              pAnt = pAnt->getProx();
            }
            pAnt->setProx(head);
          }
	      } else{ // remove elemento do meio/fim
	    	  pAnt->setProx(pAnda->getProx());
		    }
        rmvQtd();
        pAnda = nullptr;
		    delete pAnda;
      	return true;  
      }
    }
}

void LinkedListC::print(){
	NodeLLC *pAnda; 
  std::cout << "L: [ " ;
  pAnda = head;
  if(!isEmpty()){
    if(getQtd() == 1){
      std::cout << pAnda->getNome() << " ";
    } else{
      while (pAnda->getProx() != head) {
        std::cout << pAnda->getNome() << " | ";
        pAnda = pAnda->getProx();
      }
      std::cout << pAnda->getNome() << " ";
    }
    std::cout <<  "]\n";
  } else{
    std::cout << "]\n";
  }
}
		

std::string LinkedListC::rmvSorteado(int n){
  NodeLLC *pAnda;
  std::string removido;
  if(!isEmpty()){
    pAnda = head;
    while(n > 1){
      n = n-1;
      pAnda = pAnda->getProx();
    }
    
    removido = pAnda->getNome();
    if(remove(removido)){
      return removido;
    }
  }
  return "n";
}

