#include <iostream>
#include "BST.h"
using namespace std;

ArvoreBST::ArvoreBST(){raiz = NULL;}


void ArvoreBST::inserir(int chave){
  if(raiz == NULL)
    raiz = new No(chave); 
  else
    inserirAux(raiz, chave);
}


void ArvoreBST::inserirAux(No *no, int chave){
  if(chave < no->getChave()){
    if(no->getEsq() == NULL){
      No *novo_no = new No(chave);
      no->setEsq(novo_no);
    }
    else{
      inserirAux(no->getEsq(), chave);
    }
  }
  else if(chave > no->getChave()){
    if(no->getDir() == NULL){
      No *novo_no = new No(chave);
      no->setDir(novo_no);
    }
    else{
      inserirAux(no->getDir(), chave);
    }
  }
}


void ArvoreBST::emOrdem(No* no){
  if(no != NULL){
    emOrdem(no->getEsq());
    cout << no->getChave() << " ";
    emOrdem(no->getDir());
  }
}


void ArvoreBST::preOrdem(No* no){
  if(no != NULL){
    cout << no->getChave() << " ";
    preOrdem(no->getEsq());
    preOrdem(no->getDir());
  }
}


void ArvoreBST::posOrdem(No* no){
  if(no != NULL){
    posOrdem(no->getEsq());
    posOrdem(no->getDir());
    cout << no->getChave() << " ";

  }
}


bool ArvoreBST::pesquisarRec(int chave){
  if(raiz == NULL){
    return false;
  }
  return pesquisarRecAux(raiz, chave);
}


bool ArvoreBST::pesquisarRecAux(No *no, int chave){
  if(no->getChave() == chave){
    return true;
  }else if(chave < no->getChave()){
    if(no->getEsq() == NULL)
      return false;
    else
      return pesquisarRecAux(no->getEsq(), chave);
  }else if(chave > no->getChave()){
    if(no->getDir() == NULL){
      return false;
    }else{
      return pesquisarRecAux(no->getDir(), chave);
    }
  }
  return false;
}


bool ArvoreBST::pesquisarIter(int chave){
  No *no = raiz;
  while(true){
    if (no->getChave() == chave)
      return true;
    else if (chave < no->getChave()){
      if (no->getEsq() == NULL)
        return false;
      no = no->getEsq();
    }else if (chave > no->getChave()){
      if (no->getDir() == NULL)
        return false;
      no = no->getDir();
    }else
      return false;
  }
}


int ArvoreBST::qdeNos(No* no, int &count){
  if(no != NULL){
    count = count +1;
    qdeNos(no->getEsq(), count);
    qdeNos(no->getDir(), count);
  }
  return count;
}


int ArvoreBST::min(){
  if (raiz == NULL){
    cout << "Arvore vazia!" << endl;
    return 1;
  }
  No *no;
  no = raiz;
  while(true){
    if (no->getEsq() != NULL)
      no = no->getEsq();
    else{
      cout << "Menor chave: " << no->getChave();
      return 0;
    }
  }
}


int ArvoreBST::max(){
  if (raiz == NULL){
    cout << "Arvore vazia!" << endl;
    return 1;
  }
  No *no;
  no = raiz;
  while(true){
    if (no->getDir() != NULL)
      no = no->getDir();
    else{
      cout << "Maior chave: " << no->getChave() << endl;
      return 0;
    }
  }
}


void ArvoreBST::folhas(No *no){
  if (no->getEsq() != NULL){
    folhas(no->getEsq());
  }
  if (no->getDir() != NULL){
    folhas(no->getDir());
  }
  if(no->getEsq() == NULL && no->getDir() == NULL){
    cout << no->getChave() << " ";
  }
}


void ArvoreBST::removerFolha(int chave){
  No *no = raiz;
  No *aux = raiz;
  while(true){
    if (no == NULL){
      cout << "\nEste nó não existe!" << endl;
      cout << "Exemplos de nós possíveis: ";
      folhas(raiz);
      break;
    }
    if (no->getEsq() == NULL && no->getDir() == NULL && chave == no->getChave()){
      if (no == raiz){
        raiz = NULL;
        delete no;
        no = NULL;
        break;
      }else if (aux->getEsq() == no){
        aux->setEsq(NULL);
        delete no;
        no = NULL;
        break;
      } else if (aux->getDir() == no){
        aux->setDir(NULL);
        delete no;
        no = NULL;
        break;
      }
      
    } else if (no == raiz){
      if(chave < no->getChave()){
        no = no->getEsq();
      } else if (chave > no->getChave()){
        no = no->getDir();
      } else{
        cout << "Não é possível remover este nó! Ele não é uma folha." << endl;
        if (raiz != NULL){
          cout << "Exemplos de nós possíveis: ";
          folhas(raiz);
        }
        break;
      }
      
    } else{
      if(chave < no->getChave()){
        aux = no;
        no = no->getEsq();
      } else if (chave > no->getChave()){
        aux = no;
        no = no->getDir();
      } else if (chave == no->getChave()){
        cout << "\nNão é possível remover este nó! Ele não é uma folha." << endl;
        cout << "Exemplos de nós possíveis: ";
        folhas(raiz);
        break;
      }
    }
  }
}

int maior;
int ArvoreBST::alturaBST(){
  int count = 0;
  maior = 0;
  return alturaBSTAux(raiz, count);
}

int ArvoreBST::alturaBSTAux(No *no, int count){
  if(no != NULL){
    alturaBSTAux(no->getEsq(), count+1);
    alturaBSTAux(no->getDir(), count+1);
  }else if (maior < count){
    maior = count;
  }
  return maior;
}

