/*
  Lucas Gasparetto Narcizo de Morais | TIA: 41715233
  Luiz Gabriel Profirio Mendes | TIA: 42082293
  Victor Silva Fernandes | TIA: 32163967
  Vincenzo Sivero Ferreira Alberice | TIA: 32135661
*/

#include "Alimento.h"
#include "BST.h"
#include <cmath>
#include <fstream>  // Biblioteca utilizada para funções de arquivo
#include <iostream> // referência: https://cplusplus.com/reference/fstream/
#include <list>     // referência: https://cplusplus.com/reference/list/list/
#include <string>   // referência: https://cplusplus.com/reference/string/
#include <vector>

using namespace std;

string T[17] = {"Nome",
                "Quantidade",
                "Calorias",
                "Gorduras",
                "Gorduras Totais",
                "Sodio",
                "Potassio",
                "Carbodratos Totais",
                "Fibras",
                "Acucares",
                "Proteina",
                "Vitamina A",
                "Vitamina C",
                "Calcio",
                "Ferro",
                "Gordura Saturada",
                "Colesterol"};

void imprimeSomatoria(ArvoreBST *arv, list<string> sn, list<float> sq);
void imprimeCout(string a, int esp);

void printMenu(ArvoreBST *arv) {
  int tipo = 15, fruta, vegetal, mar, qtdF, qtdV, qtdS;
  vector<string> opcoes;
  list<string> selecaoNome;
  list<float> selecaoQtd;
  opcoes.begin();

  cout << " -------- Calculadora Nutricional --------" << endl << endl;
  while (tipo != 0) {
    cout << "------------------ MENU ------------------" << endl;
    cout << "[1] Frutas" << endl;
    cout << "[2] Vegetais" << endl;
    cout << "[3] Frutos do Mar" << endl;
    cout << endl;
    cout << "[4] Exibir total de dados nutricionais" << endl;
    cout << endl;
    cout << "[0] Sair" << endl;
    cout << "------------------------------------------" << endl;
    cout << "Selecione uma opção: ";
    cin >> tipo;
    cout << endl;

    switch (tipo) {
      // -------------------- Fruta --------------------
    case 1:
      opcoes.clear();
      cout << "Escolha uma fruta: " << endl << endl;
      arv->imprimeEscolha(arv->getRaiz(), 'F', &opcoes);
      for (int i = 0; i < opcoes.size(); i++) {
        cout << "[" << i + 1 << "] " << opcoes.at(i) << " - "
             << arv->imprimePorcao(arv->getRaiz(), opcoes[i]) << endl;
      }
      cout << endl << "[0] Sair" << endl;
      cout << "------------------------------------------" << endl;
      cout << "Escolha a fruta que consumiu: ";
      cin >> fruta;
      cout << endl;
      if (fruta < 0 || fruta > opcoes.size()) {
        cout << "Opção incorreta!" << endl;
        break;
      } else if (fruta == 0)
        break;
      selecaoNome.push_back(opcoes.at(fruta - 1));

      cout << "Digite a porção consumida: ";
      cin >> qtdF;
      cout << endl;
      selecaoQtd.push_back(qtdF);
      break;

      // -------------------- Vegetal --------------------
    case 2:
      opcoes.clear();
      cout << "Escolha um vegetal: " << endl << endl;
      arv->imprimeEscolha(arv->getRaiz(), 'V', &opcoes);
      for (int i = 0; i < opcoes.size(); i++) {
        cout << "[" << i + 1 << "] " << opcoes.at(i) << " - "
             << arv->imprimePorcao(arv->getRaiz(), opcoes[i]) << endl;
      }
      cout << endl << "[0] Sair" << endl;
      cout << "------------------------------------------" << endl;
      cout << "Escolha o vegetal que consumiu: ";
      cin >> vegetal;
      cout << endl;
      if (vegetal < 0 || vegetal > opcoes.size()) {
        cout << "Opção incorreta!" << endl;
        break;
      } else if (vegetal == 0)
        break;
      selecaoNome.push_back(opcoes.at(vegetal - 1));

      cout << "Digite a porção consumida: ";
      cin >> qtdV;
      cout << endl;
      selecaoQtd.push_back(qtdV);
      break;

      // -------------------- Frutos do mar --------------------
    case 3:
      opcoes.clear();
      cout << "Escolha um fruto do mar: " << endl;
      arv->imprimeEscolha(arv->getRaiz(), 'S', &opcoes);
      for (int i = 0; i < opcoes.size(); i++) {
        cout << "[" << i + 1 << "] " << opcoes.at(i) << " - "
             << arv->imprimePorcao(arv->getRaiz(), opcoes[i]) << endl;
      }
      cout << endl << "[0] Sair" << endl;
      cout << "------------------------------------------" << endl;
      cout << "Escolha o fruto do mar que consumiu: ";
      cin >> mar;
      cout << endl;
      if (mar < 0 || mar > opcoes.size()) {
        cout << "Opção incorreta!" << endl;
        break;
      } else if (mar == 0)
        break;
      selecaoNome.push_back(opcoes.at(mar - 1));

      cout << "Digite a porção consumida: ";
      cin >> qtdS;
      cout << endl;
      selecaoQtd.push_back(qtdS);
      break;

    case 4:
      imprimeSomatoria(arv, selecaoNome, selecaoQtd);
      break;

    case 0:
      cout << "Aplicação finalizada.";
      break;

    default:
      cout << "Opção inválida. Tente novamente." << endl;
      break;
    }
  }
}

void imprimeSomatoria(ArvoreBST *arv, list<string> sn, list<float> sq) {
  int calorias = 0;
  int calGordura = 0;
  float gordurasTot = 0;
  float sodio = 0;
  int potassio = 0;
  int carbTot = 0;
  int fibras = 0;
  int acucares = 0;
  int proteina = 0;
  int vitaminaA = 0;
  int vitaminaC = 0;
  int calcio = 0;
  int ferro = 0;
  int gorduraSat = 0;
  int colesterol = 0;

  int mult = 0;
  float somaQtd = 0;
  Alimento *no;

  cout << "Informações nutricionais consumidas:" << endl;
  cout << endl;
  for (int b = 0; b < 17; b++) {
    if (b == 5)
      imprimeCout(T[b], 12);
    else if (b == 4)
      imprimeCout(T[b], 17);
    else if (b > 0)
      imprimeCout(T[b], T[b].size());
    else {
      imprimeCout(T[b], 20);
    }
  }
  cout << " | " << endl;
  while (sn.size() > 0) {

    imprimeCout(sn.front(), 20);

    imprimeCout(to_string(sq.front()), 10);
    mult = sq.front();
    somaQtd = somaQtd + sq.front();

    no = arv->pesquisarIter(sn.front());

    calorias += no->getCalorias() * mult;
    imprimeCout(to_string(no->getCalorias()), 8);

    calGordura += no->getCalGordura() * mult;
    imprimeCout(to_string(no->getCalGordura()), 8);

    gordurasTot += no->getGordurasTot() * mult;
    imprimeCout(to_string(no->getGordurasTot()), 17);

    sodio += no->getSodio() * mult;
    imprimeCout(to_string(no->getSodio()), 12);

    potassio += no->getPotassio() * mult;
    imprimeCout(to_string(no->getPotassio()), 8);

    carbTot += no->getCarbTot() * mult;
    imprimeCout(to_string(no->getCarbTot()), 18);

    fibras += no->getFibras() * mult;
    imprimeCout(to_string(no->getFibras()), 6);

    acucares += no->getAcucar() * mult;
    imprimeCout(to_string(no->getAcucar()), 8);

    proteina += no->getProteina() * mult;
    imprimeCout(to_string(no->getProteina()), 8);

    vitaminaA += no->getVitA() * mult;
    imprimeCout(to_string(no->getVitA()), 10);

    vitaminaC += no->getVitC() * mult;
    imprimeCout(to_string(no->getVitC()), 10);

    calcio += no->getCalcio() * mult;
    imprimeCout(to_string(no->getCalcio()), 6);

    ferro += no->getFerro() * mult;
    imprimeCout(to_string(no->getFerro()), 5);

    gorduraSat += no->getGordSat() * mult;
    imprimeCout(to_string(no->getGordSat()), 16);

    colesterol += no->getColesterol() * mult;
    imprimeCout(to_string(no->getColesterol()), 10);

    sn.pop_front();
    sq.pop_front();
    cout << " | ";
    cout << endl;
  }

  imprimeCout("SOMA TOTAL", 20);
  imprimeCout(to_string(somaQtd), 10);
  imprimeCout(to_string(calorias), 8);
  imprimeCout(to_string(calGordura), 8);
  imprimeCout(to_string(gordurasTot), 17);
  imprimeCout(to_string(sodio), 12);
  imprimeCout(to_string(potassio), 8);
  imprimeCout(to_string(carbTot), 18);
  imprimeCout(to_string(fibras), 6);
  imprimeCout(to_string(acucares), 8);
  imprimeCout(to_string(proteina), 8);
  imprimeCout(to_string(vitaminaA), 10);
  imprimeCout(to_string(vitaminaC), 10);
  imprimeCout(to_string(calcio), 6);
  imprimeCout(to_string(ferro), 5);
  imprimeCout(to_string(gorduraSat), 16);
  imprimeCout(to_string(colesterol), 10);
  cout << " | " << endl << endl;
}

void imprimeCout(string a, int esp) {
  cout << " | ";
  float c = esp - a.size();
  float m = c / 2;
  int p = c;
  if (a.size() < esp) {
    if (p % 2 == 1) {
      for (int i = 0; i < floor(m); i++)
        cout << " ";
      cout << a;
      for (int i = 0; i < floor(m) + 1; i++)
        cout << " ";
    } else {
      for (int i = 0; i < floor(m); i++)
        cout << " ";
      cout << a;
      for (int i = 0; i < floor(m); i++)
        cout << " ";
    }
  } else if (a.size() >= esp) {
    cout << a;
  }
}

int main() {
  ArvoreBST *arv = new ArvoreBST;

  int count = 1;
  ifstream arquivo;
  string nomeArquivo;
  cout << "Digite o nome do arquivo com informações nutritivas: ";
  cin >> nomeArquivo;
  cout << endl;

  arquivo.open(nomeArquivo, ifstream::in);

  if (!arquivo.is_open())
    cout << "O arquivo nao foi encontrado.";
  else {
    string atributos[18];

    string atb;
    getline(arquivo, atb);
    while (!arquivo.eof()) {

      for (int i = 0; i < 18; i++) {
        if (i != 17) {
          getline(arquivo, atributos[i], ',');
        } else {
          getline(arquivo, atributos[i], '\n');
        }
      }
      arv->inserir(atributos);
      count++;
    }
    printMenu(arv);
  }

  arquivo.close();
}