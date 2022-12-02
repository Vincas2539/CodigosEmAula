#ifndef BST
#define BST

#include <iostream>
using namespace std;


class No{
private:
	No *esq, *dir;
	int chave, FB;
public:
	No(int dado){
		chave = dado;
    FB = -1;
		esq = NULL;
		dir = NULL;
	}

	// fun�es getters e setters
	int getChave(){return chave;}
	No* getEsq(){return esq;}
	No* getDir(){return dir;}
	void setEsq(No *no){esq = no;}
	void setDir(No *no){dir = no;}
};


class ArvoreBST{
private:
	No *raiz;
public:
	ArvoreBST();
  ~ArvoreBST(){};
  No* getRaiz(){return raiz;}
	void inserir(int chave);
	void inserirAux(No *no, int chave);
	void emOrdem(No* no);
	void preOrdem(No* no);
	void posOrdem(No* no);

  bool pesquisarRec(int chave);
  bool pesquisarRecAux(No *no, int chave);
  bool pesquisarIter(int chave);
  int qdeNos(No* no, int &count);
  int min();
  int max();
  void folhas(No *no);
  void removerFolha(int chave);
  int alturaBST();
  int alturaBSTAux(No *no, int count);
};

#endif
