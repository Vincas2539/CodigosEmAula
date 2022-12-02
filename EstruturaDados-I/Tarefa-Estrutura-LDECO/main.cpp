#include <iostream>
#include "LDL.h"

using namespace std;

void printLista(LDL *l){
  cout << "Crescente" << endl;
	l->mostraOrdemCrescente();
	
	cout << "\n\nDecrescente" << endl;
	l->mostraOrdemDecrescente();
  cout << endl;
  cout << endl;
}

LDL *intercala(LDL *l1, LDL *l2){
  LDL *lf = new LDL();
  No *p1, *p2;
  int qtd;
  
  p1 = l1->getCabeca();
  p2 = l2->getCabeca();
  if(l1->getQtde() > l2->getQtde())
    qtd = l1->getQtde();
  else
    qtd = l2->getQtde();
  while(qtd > 0){
    if(p1->getProx() != l1->getCabeca()){
      lf->insereOrdemCrescente(p1->getChave(), p1->getDado());
      p1 = p1->getProx();
    }
    if(p2->getProx() != l2->getCabeca()){
      lf->insereOrdemCrescente(p2->getChave(), p2->getDado());
      p2 = p2->getProx();
    }
    qtd--;
  }
  while(p1->getProx() != l1->getCabeca()){
    lf->insereOrdemCrescente(p1->getChave(), p1->getDado());
    p1 = p1->getProx();
  }
  return lf;
}




int main() {
	LDL *lista = new LDL();
	lista->insereOrdemCrescente(2, 2); // insere (chave, dado)
	lista->insereOrdemCrescente(10, 10);
	lista->insereOrdemCrescente(25, 25);
	lista->insereOrdemCrescente(12, 12);
	lista->insereOrdemCrescente(23, 23);
	lista->insereOrdemCrescente(55, 55);
	lista->insereOrdemCrescente(22, 22);
	lista->insereOrdemCrescente(43, 43);
	lista->insereOrdemCrescente(1, 1);


	printLista(lista);

	// Faz uma pausa antes de finalizar o programa
  int opcao = 0;
  while(opcao != 5){
    cout << "--Menu--" << endl;
    cout << "1. Printar lista" << endl;
    cout << "2. Buscar;" << endl;
    cout << "3. Remover;" << endl;
    cout << "4. Intercalar listas;" << endl;
    cout << "5. Finalizar." << endl << endl;
    cout << "Digite a opção desejada: ";
    cin >> opcao;
    cout << endl;
    if(opcao == 1){
      printLista(lista);
    } else if(opcao == 2){
      int chave;
      cout << "Digite o valor a ser buscado: ";
      cin >> chave;
      if (lista->busca(chave) != nullptr){
        cout << "Encontrado!" << endl;
      } else{
        cout << "Não encontrado!" << endl;
      }
      cout << endl;
    } else if(opcao == 3){
      int chave;
      cout << "Digite o valor a ser removido: ";
      cin >> chave;
      lista->remove(chave);
    } else if(opcao == 4){
      LDL *lista2 = new LDL();
	    
      lista2->insereOrdemCrescente(5, 5); // insere (chave, dado)
	    lista2->insereOrdemCrescente(8, 8);
    	lista2->insereOrdemCrescente(12, 12);
    	lista2->insereOrdemCrescente(20, 20);
    	lista2->insereOrdemCrescente(30, 30);
    	lista2->insereOrdemCrescente(32, 32);
    	lista2->insereOrdemCrescente(40, 40);
    	lista2->insereOrdemCrescente(43, 43);
    	lista2->insereOrdemCrescente(90, 90);
      
      printLista(intercala(lista, lista2));
    }
  }
  cout << "Finalizando aplicação";
	return 0;
}