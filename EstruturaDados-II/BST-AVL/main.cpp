#include <iostream>
#include "BST.h"

int count;

int main(int argc, char *argv[]){ 
	ArvoreBST arv;
  int opcao, x;

  int a = 0;
  int j = 5;
  int k = 10;
  int l = 15;
  while(a<5){
    arv.inserir(k);
    k++;
    arv.inserir(l);
    l++;
    arv.inserir(j);
    j++;
    arv.inserir(a);
    a++;
  }
  

  
  cout << ("\nTestando o TAD BST (Elementos do tipo int)\n");

	while(true){
  	cout << "\n\n";
    cout << "\n***********************************";
    cout << "\n\tMenu - Arvore BST\n";
    cout << "\nEntre com a opcao:";
		cout << "\n -----1: Inserir";
		cout << "\n -----2: Pesquisar Recursivamente";
    cout << "\n -----3: Pesquisar Iterativamente";
		cout << "\n -----4: Imprimir em ordem";
    cout << "\n -----5: Imprimir quantidade";
    cout << "\n -----6: Imprimir menor chave na BST";
    cout << "\n -----7: Imprimir maior chave na BST";
    cout << "\n -----8: Imprimir folhas em ordem";
    cout << "\n -----9: Remove folhas";
    cout << "\n ----10: Altura da árvore";
		cout << "\n ----11: Sair do programa\n";
		cout << "\n***********************************";
		cout << "\n-> ";
		cin >> opcao;
    
		switch(opcao) {
	 		case 1: {
      cout << "\n Informe o valor (int) -> ";
      cin >> x;
      arv.inserir(x);
      break;
			}
			case 2: {
        int busca;
        cout << "\n Digite o número que quer buscar: ";
        cin >> busca;
        if (arv.pesquisarRec(busca) == true)
          cout << "\n Encontrou!";
        else
          cout << "\n Não encontrou!";
        break;
			}
      case 3: {
        int busca;
        cout << "\n Digite o número que quer buscar: ";
        cin >> busca;
        if (arv.pesquisarIter(busca) == true)
          cout << "\n Encontrou!";
        else
          cout << "\n Não encontrou!";
        break;
			}
			case 4: {
        cout << "Percorrendo em ordem...\n";
        arv.emOrdem(arv.getRaiz());
        break;
			}
      case 5:{
        count = 0;
        cout << "Quantidade de nós: ";
        cout << arv.qdeNos(arv.getRaiz(), count);
        break;
      }
      case 6:{
        arv.min();
        break;
      }
      case 7:{
        arv.max();
        break;
      }
      case 8:{
        if (arv.getRaiz() != NULL){
          arv.folhas(arv.getRaiz());
        }else
          cout << "Árvore vazia!" << endl;
        break;
      }
      case 9:{
        int rmv;
        cout << "\n Digite o número que deseja remover: ";
        cin >> rmv;
        if (arv.getRaiz() != NULL)
          arv.removerFolha(rmv);
        else
          cout << "Árvore vazia!" << endl;
        break;
      }
      case 10:{
        cout << "Altura da BST: ";
        if (arv.getRaiz() == NULL){
          cout << "-1" << endl;
        } else {
          cout << arv.alturaBST() -1 << endl;
        }
        break;
      }
			case 11:{
        cout << "Finalizando aplicação!" << endl;
        break;
			}
			default:
				cout << "\n Opcao invalida! \n\n\n";
        } // fim switch
    }


	return 0;
}