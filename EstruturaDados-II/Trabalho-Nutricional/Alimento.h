/*
  Lucas Gasparetto Narcizo de Morais | TIA:
  Luiz Gabriel Profirio Mendes | TIA: 42082293
  Victor Silva Fernandes | TIA: 32163967
  Vincenzo Sivero Ferreira Alberice | TIA: 32135661
*/

#ifndef __Alimento__
#define __Alimento__

#include <iostream>
#include <string>

using namespace std;

class Alimento {
private:
  string nome;
  string porcao;
  int calorias;
  int calGordura;
  float gordurasTot;
  float sodio;
  int potassio;
  int carbTot;
  int fibras;
  int acucares;
  int proteina;
  int vitaminaA;
  int vitaminaC;
  int calcio;
  int ferro;
  int gorduraSat;
  int colesterol;
  char tipo;

  // Elementos dos nós das arvores
  Alimento *esq, *dir;
  int chave;

public:
  // Construtor padrao
  Alimento(){};
  // Construtor que sera utilizado na instanciacao dos objetos
  Alimento(string atributos[]) {
    this->nome = atributos[0];
    this->porcao = atributos[1];
    this->calorias = stoi(atributos[2]); // stoi = string to integer - // https://cplusplus.com/reference/string/stoi/
    this->calGordura = stoi(atributos[3]);
    this->gordurasTot = stod(atributos[4]); // stod = string to float - // https://cplusplus.com/reference/string/stod/
    this->sodio = stod(atributos[5]);
    this->potassio = stoi(atributos[6]);
    this->carbTot = stoi(atributos[7]);
    this->fibras = stoi(atributos[8]);
    this->acucares = stoi(atributos[9]);
    this->proteina = stoi(atributos[10]);
    this->vitaminaA = stoi(atributos[11]);
    this->vitaminaC = stoi(atributos[12]);
    this->calcio = stoi(atributos[13]);
    this->ferro = stoi(atributos[14]);
    this->gorduraSat = stoi(atributos[15]);
    this->colesterol = stoi(atributos[16]);
    this->tipo = atributos[17][0];

    esq = NULL;
    dir = NULL;
  }
  ~Alimento() {}

  // getters e setters alimento
  int getChave() { return chave; }
  Alimento *getEsq() { return esq; }
  Alimento *getDir() { return dir; }
  void setEsq(Alimento *no) { esq = no; }
  void setDir(Alimento *no) { dir = no; }

  // setters - não é necessário pois já foram inseridos na criação do objeto

  // getters
  string getNome() { return nome; }
  string getPorcao() { return porcao; }
  int getCalorias() { return calorias; }
  int getCalGordura() { return calGordura; }
  float getGordurasTot() { return gordurasTot; }
  float getSodio() { return sodio; }
  int getPotassio() { return potassio; }
  int getCarbTot() { return carbTot; }
  int getFibras() { return fibras; }
  int getAcucar() { return acucares; }
  int getProteina() { return proteina; }
  int getVitA() { return vitaminaA; }
  int getVitC() { return vitaminaC; }
  int getCalcio() { return calcio; }
  int getFerro() { return ferro; }
  int getGordSat() { return gorduraSat; }
  int getColesterol() { return colesterol; }
  char getTipo() { return tipo; }

  // util
  void imprimir() {
    cout << this->nome << " " << this->chave << " " << this->porcao << " "
         << this->calorias << " " << this->calGordura << " "
         << this->gordurasTot << " " << this->sodio << " " << this->potassio
         << " " << this->carbTot << " " << this->fibras << " " << this->acucares
         << " " << this->proteina << " " << this->vitaminaA << " "
         << this->vitaminaC << " " << this->calcio << " " << this->ferro << " "
         << this->gorduraSat << " " << this->colesterol << " " << this->tipo
         << endl;
  }
};

#endif