/*
  Lucas Gasparetto Narcizo de Morais | TIA:
  Luiz Gabriel Profirio Mendes | TIA: 42082293
  Victor Silva Fernandes | TIA: 32163967
  Vincenzo Sivero Ferreira Alberice | TIA: 32135661
*/

#ifndef BST
#define BST

#include "Alimento.h"
#include <iostream>
#include <list>
#include <string>
#include <vector>

using namespace std;

class ArvoreBST {
private:
  Alimento *raiz;

public:
  ArvoreBST();
  ~ArvoreBST(){};
  Alimento *getRaiz() { return raiz; }
  void inserir(string atr[]);
  void inserirAux(Alimento *no, string atr[]);
  void emOrdem(Alimento *no);
  void preOrdem(Alimento *no);
  void posOrdem(Alimento *no);

  string imprimePorcao(Alimento *no, string nome);
  void imprimeEscolha(Alimento *no, char tipo, vector<string> *lista);
  Alimento *pesquisarIter(string nome);
  int min();
  int max();
};

#endif