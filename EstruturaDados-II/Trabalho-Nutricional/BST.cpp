/*
  Lucas Gasparetto Narcizo de Morais | TIA:
  Luiz Gabriel Profirio Mendes | TIA: 42082293
  Victor Silva Fernandes | TIA: 32163967
  Vincenzo Sivero Ferreira Alberice | TIA: 32135661
*/

#include "BST.h"
#include "Alimento.h"
#include <iostream>

using namespace std;

ArvoreBST::ArvoreBST() { raiz = NULL; }

void ArvoreBST::inserir(string atr[]) {
  if (raiz == NULL)
    raiz = new Alimento(atr);
  else
    inserirAux(raiz, atr);
}

void ArvoreBST::inserirAux(Alimento *no, string atr[]) {
  if (atr[0] < no->getNome()) {
    if (no->getEsq() == NULL) {
      Alimento *novo_no = new Alimento(atr);
      no->setEsq(novo_no);
    } else {
      inserirAux(no->getEsq(), atr);
    }
  } else if (atr[0] > no->getNome()) {
    if (no->getDir() == NULL) {
      Alimento *novo_no = new Alimento(atr);
      no->setDir(novo_no);
    } else {
      inserirAux(no->getDir(), atr);
    }
  }
}


string ArvoreBST::imprimePorcao(Alimento *no, string nome){
  while (true) {
    if (no->getNome() == nome)
      return no->getPorcao();
    else if (nome < no->getNome()) {
      if (no->getEsq() == NULL)
        return "";
      no = no->getEsq();
    } else if (nome > no->getNome()) {
      if (no->getDir() == NULL)
        return "";
      no = no->getDir();
    } else
      return "";
  }
}


void ArvoreBST::imprimeEscolha(Alimento *no, char tipo, vector<string> *lista) {
  if (no != NULL) {
    imprimeEscolha(no->getEsq(), tipo, lista);
    if (tipo == no->getTipo()){
      lista->push_back(no->getNome());
    }
    imprimeEscolha(no->getDir(), tipo, lista);
  }
}

void ArvoreBST::emOrdem(Alimento *no) {
  if (no != NULL) {
    emOrdem(no->getEsq());
    cout << no->getNome() << endl;
    emOrdem(no->getDir());
  }
}

void ArvoreBST::preOrdem(Alimento *no) {
  if (no != NULL) {
    cout << no->getNome() << endl;
    preOrdem(no->getEsq());
    preOrdem(no->getDir());
  }
}

void ArvoreBST::posOrdem(Alimento *no) {
  if (no != NULL) {
    posOrdem(no->getEsq());
    posOrdem(no->getDir());
    cout << no->getNome() << " ";
  }
}

Alimento *ArvoreBST::pesquisarIter(string nome) {
  Alimento *no = raiz;
  while (true) {
    if (no->getNome() == nome)
      return no;
    else if (nome < no->getNome()) {
      if (no->getEsq() == NULL)
        return nullptr;
      no = no->getEsq();
    } else if (nome > no->getNome()) {
      if (no->getDir() == NULL)
        return nullptr;
      no = no->getDir();
    } else
      return nullptr;
  }
}

int ArvoreBST::min() {
  if (raiz == NULL) {
    cout << "Arvore vazia!" << endl;
    return 1;
  }
  Alimento *no;
  no = raiz;
  while (true) {
    if (no->getEsq() != NULL)
      no = no->getEsq();
    else {
      cout << "Menor chave: " << no->getNome();
      return 0;
    }
  }
}

int ArvoreBST::max() {
  if (raiz == NULL) {
    cout << "Arvore vazia!" << endl;
    return 1;
  }
  Alimento *no;
  no = raiz;
  while (true) {
    if (no->getDir() != NULL)
      no = no->getDir();
    else {
      cout << "Maior chave: " << no->getNome() << endl;
      return 0;
    }
  }
}
