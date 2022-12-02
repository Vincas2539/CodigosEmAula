#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

#include "NodeLLC.h"
#include "ListaEncadeadaC.h"

using namespace std;

int printMenu(){
  int opcao;
  cout << "--------------------Menu de Opções--------------------" << endl;
  cout << "1. Inserir uma pessoa para jogar;" << endl;
  cout << "2. Remover uma pessoa do jogo;" << endl;
  cout << "3. Imprimir participantes;" << endl;
  cout << "4. Sortear uma pessoa para sair;" << endl;
  cout << "5. Finalizar." << endl;
  cout << "--------------------------//--------------------------" << endl;
  cout << "Digite a opção escolhida: ";
  cin >> opcao;
  return opcao;
}



int main() {
  int a = 0;
  std::string nome;
  LinkedListC *lista = new LinkedListC();
  
  
  while(a != 5){
    a = printMenu();
    if(a < 1 || a > 5){
      cout << "Opção Inválida!" << endl << endl;
    } else if(a == 1){
      cout << "Digite o nome a ser inserido: ";
      cin >> nome;
      if(lista->insert(nome) == true){
        cout << "Voce inseriu '" << nome << "' na lista!" << endl;
      }
      
    } else if(a == 2){
      cout << "Digite o nome de quem deseja remover: ";
      cin >> nome;
      if(lista->remove(nome) == true){
        cout << "Voce removeu o " << nome << " da lista!" << endl;
      } else {
        cout << nome << " não está na lista!" << endl;
      }
    } else if(a == 3){
      lista->print();
    } else if(a == 4){
      if(!lista->isEmpty()){
        std::string removido;
        unsigned seed = time(0);
        srand(seed);
        removido = lista->rmvSorteado((rand()%lista->getQtd())+1);
        if(removido == "n"){
          cout << "Não há pessoas para remover." << endl;
        }
        cout << removido << " foi escolhido para perder!" << endl;
      }else{
        cout << "Não há pessoas para remover." << endl;
    } 
  }else if(a == 5){
      cout << "Finalizando aplicação!" << endl;
      break;
  }
    cout << "Quantidade de pessoas na lista: " << lista->getQtd() << endl << endl;
  }
}
