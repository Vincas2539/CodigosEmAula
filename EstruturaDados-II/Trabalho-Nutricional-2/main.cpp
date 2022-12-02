/*
Lucas Gasparetto Narcizo de Morais | TIA: 41715233
Luiz Gabriel Profirio Mendes | TIA: 42082293
Victor Silva Fernandes | TIA: 32163967
Vincenzo Sivero Ferreira Alberice | TIA: 32135661
*/

#include "AVL.h"
#include "Alimento.h"
#include <iostream>
#include <cmath>
#include <fstream>  // Biblioteca utilizada para funções de arquivo
#include <iostream> // referência: https://cplusplus.com/reference/fstream/
#include <list>     // referência: https://cplusplus.com/reference/list/list/
#include <string>   // referência: https://cplusplus.com/reference/string/
#include <vector>

using namespace std;

void imprimeSomatoria(AVL *arv, list<string> sn, list<float> sq);
void imprimeCout(string a, int esp);
void printMenu(AVL *arv);
void ProcessArquivo(AVL* arv, string nomeArquivo);

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

void Search(AVL *avl) {
  string nome;
  std::cout << "Search number: ";
  std::cin >> nome;
  NodeAVL *node = avl->Search(nome);
  if (node)
    std::cout << "Node found:\n" << node->ToString();
  else
    std::cout << "*** ERROR! Couldn't find node!\n";
}

void Predecessor(AVL *avl) {
  string nome;
  std::cout << "Find predecessor of: ";
  std::cin >> nome;
  NodeAVL *node = avl->Predecessor(nome);
  if (node)
    std::cout << "Predecessor of " << nome << ":\n" << node->ToString();
  else
    std::cout << "*** ERROR! There is no predecessor of " << nome << "!\n";
}

void Successor(AVL *avl) {
  string nome;
  std::cout << "Find successor of: ";
  std::cin >> nome;
  NodeAVL *node = avl->Successor(nome);
  if (node)
    std::cout << "Successor of " << nome << ":\n" << node->ToString();
  else
    std::cout << "*** ERROR! There is no successor of " << nome << "!\n";
}

void FindMin(AVL *avl) {
  NodeAVL *node = avl->FindMin();
  if (node)
    std::cout << "Minimum:\n" << node->ToString();
  else
    std::cout
        << "*** ERROR! Couldn't find minimum (tree is probably empty...)\n";
}

void FindMax(AVL *avl) {
  NodeAVL *node = avl->FindMax();
  if (node)
    std::cout << "Maximum:\n" << node->ToString();
  else
    std::cout
        << "*** ERROR! Couldn't find maximum (tree is probably empty...)\n";
}

void TraverseInOrder(AVL *avl) { std::cout << avl->TraverseInOrder() << '\n'; }

void TraversePreOrder(AVL *avl) { std::cout << avl->TraversePreOrder() << '\n'; }

void TraversePostOrder(AVL *avl) { std::cout << avl->TraversePostOrder() << '\n'; }

void Clear(AVL *avl) { avl->Clear(); }


// -------------------------------- NOVO --------------------------------

void salvarArquivo(AVL *arv, string nome){
  ofstream arquivo;
  arquivo.open(nome, ios::app);
  arquivo << "Alimentos,porcao,Calorias,Gorduras,Gorduras Totais,Sodio,Potassio,Carboidrato total,Fibra alimentar,Acucares,Proteína,Vitamina A,Vitamina C,Calcio,Ferro,Gordura saturada,Colesterol,Tipo de comida" << endl;
  arv->Save(arquivo);
  arquivo.close();
}

void ProcessArquivo(AVL* arv, string nomeArquivo){
  Alimento *alimento;
  int count = 1;
  ifstream arquivo;
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
      alimento = new Alimento(atributos);
      arv->Insert(atributos[0], alimento);
      count++;
    }
    arquivo.close();
  }
}

void imprimeSomatoria(AVL *arv, list<string> sn, list<float> sq) {
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
  NodeAVL *no;
  list<string> erro;

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
      imprimeCout(T[b], 21);
    }
  }
  cout << " | " << endl;
  while (sn.size() > 0) {
    no = arv->Search(sn.front());

    if (no == nullptr){
      erro.push_back(sn.front());
      sn.pop_front();
      sq.pop_front();
      continue;
    }

    imprimeCout(sn.front(), 21);

    imprimeCout(to_string(sq.front()), 10);
    mult = sq.front();
    somaQtd = somaQtd + sq.front();

    

    calorias += no->GetData()->getCalorias() * mult;
    imprimeCout(to_string(no->GetData()->getCalorias()), 8);

    calGordura += no->GetData()->getCalGordura() * mult;
    imprimeCout(to_string(no->GetData()->getCalGordura()), 8);

    gordurasTot += no->GetData()->getGordurasTot() * mult;
    imprimeCout(to_string(no->GetData()->getGordurasTot()), 17);

    sodio += no->GetData()->getSodio() * mult;
    imprimeCout(to_string(no->GetData()->getSodio()), 12);

    potassio += no->GetData()->getPotassio() * mult;
    imprimeCout(to_string(no->GetData()->getPotassio()), 8);

    carbTot += no->GetData()->getCarbTot() * mult;
    imprimeCout(to_string(no->GetData()->getCarbTot()), 18);

    fibras += no->GetData()->getFibras() * mult;
    imprimeCout(to_string(no->GetData()->getFibras()), 6);

    acucares += no->GetData()->getAcucar() * mult;
    imprimeCout(to_string(no->GetData()->getAcucar()), 8);

    proteina += no->GetData()->getProteina() * mult;
    imprimeCout(to_string(no->GetData()->getProteina()), 8);

    vitaminaA += no->GetData()->getVitA() * mult;
    imprimeCout(to_string(no->GetData()->getVitA()), 10);

    vitaminaC += no->GetData()->getVitC() * mult;
    imprimeCout(to_string(no->GetData()->getVitC()), 10);

    calcio += no->GetData()->getCalcio() * mult;
    imprimeCout(to_string(no->GetData()->getCalcio()), 6);

    ferro += no->GetData()->getFerro() * mult;
    imprimeCout(to_string(no->GetData()->getFerro()), 5);

    gorduraSat += no->GetData()->getGordSat() * mult;
    imprimeCout(to_string(no->GetData()->getGordSat()), 16);

    colesterol += no->GetData()->getColesterol() * mult;
    imprimeCout(to_string(no->GetData()->getColesterol()), 10);

    sn.pop_front();
    sq.pop_front();
    cout << " | ";
    cout << endl;
  }

  imprimeCout("SOMA TOTAL", 21);
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
  
  cout << "Alimentos não encontrados: ";
  while(erro.size() > 0){
    cout << erro.front();
    erro.pop_front();
    if(erro.size() == 0)
      cout << ".";
    else
      cout << ", ";
  }
  cout << endl << endl;
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

void printMenu(AVL *arv) {
  int tipo = 15, fruta, vegetal, mar, qtdF, qtdV, qtdS;
  string nomeArquivo;
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
    cout << "[5] Remover alimento" << endl;
    cout << "[6] Mostrar todos os alimentos" << endl;
    cout << "[7] Salvar nova arvore em um arquivo csv" << endl;
    cout << "[8] Recarregar arquivo csv" << endl;
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
      arv->imprimeEscolha(arv->GetRoot(), 'F', &opcoes);
      for (int i = 0; i < opcoes.size(); i++) {
        cout << "[" << i + 1 << "] " << opcoes.at(i) << " - "
             << arv->imprimePorcao(arv->GetRoot(), opcoes[i]) << endl;
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
      arv->imprimeEscolha(arv->GetRoot(), 'V', &opcoes);
      for (int i = 0; i < opcoes.size(); i++) {
        cout << "[" << i + 1 << "] " << opcoes.at(i) << " - "
             << arv->imprimePorcao(arv->GetRoot(), opcoes[i]) << endl;
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
      arv->imprimeEscolha(arv->GetRoot(), 'S', &opcoes);
      for (int i = 0; i < opcoes.size(); i++) {
        cout << "[" << i + 1 << "] " << opcoes.at(i) << " - "
             << arv->imprimePorcao(arv->GetRoot(), opcoes[i]) << endl;
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

    case 5:
      opcoes.clear();
      cout << "Remover: " << endl << endl;
      arv->imprimeTudo(arv->GetRoot(), &opcoes);
      for (int i = 0; i < opcoes.size(); i++)
        cout << "[" << i + 1 << "] " << opcoes.at(i) << endl;
      cout << endl << "[0] Sair" << endl;
      cout << "------------------------------------------" << endl;
      cout << "Escolha um alimento para remover: ";
      cin >> fruta;
      cout << endl;
      if (fruta < 0 || fruta > opcoes.size()) {
        cout << "Opção incorreta!" << endl;
        break;
      } else if (fruta == 0)
        break;

      arv->Remove(opcoes.at(fruta - 1));
      break;

    case 6:
      TraverseInOrder(arv);
      break;

    case 7:
      cout << "Digite o nome que deseja salvar o arquivo (Digite 0 para cancelar): ";
      cin >> nomeArquivo;
      cout << endl;
      if(nomeArquivo != "0")
        salvarArquivo(arv, nomeArquivo+".csv");
      else
        cout << "Cancelado! Retornando para o menu." << endl;
      break;

    case 8:
      arv->Clear();
      cout << "Digite o nome do arquivo que deseja abrir (Digite 0 para cancelar): ";
      cin >> nomeArquivo;
      cout << endl;
      if(nomeArquivo != "0")
        ProcessArquivo(arv, nomeArquivo);
      else
        cout << "Cancelado! Retornando para o menu." << endl;
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

int main() {
  AVL *arv = new AVL();
  string nomeArquivo;
  
  cout << "Digite o nome do arquivo com informações nutritivas: ";
  cin >> nomeArquivo;
  cout << endl;
  
  ProcessArquivo(arv, nomeArquivo);
  printMenu(arv);
}

