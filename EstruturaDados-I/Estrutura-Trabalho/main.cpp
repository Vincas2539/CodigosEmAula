/*
Nome: xxx TIA: xxx
Nome: xxx TIA: xxx
Nome: xxx TIA: xxx
Nome: Vincenzo TIA: 32135661
*/

#include "Pilha.h"
#include "Vector.h"
#include <sstream>
#include <iostream>
#include <string>

using namespace std;

// cout << "========================================" << endl;
int printMenu(){
  int opcao;
  
  cout << "==================MENU==================" << endl;
  cout << "1. Entrada da expressao aritmetica na notacao infixa." << endl;
  cout << "2. Entrada dos valores numericos associados as variaveis." << endl;
  cout << "3. Conversao da expressao, da notacao infixa para a notacao posfixa,\ne exibicao da expressao convertida para posfixa." << endl;
  cout << "4. Avaliacao da expressao (apresentacao do resultado do calculo, mostrando a expressao e os valores das variaveis)." << endl;
  cout << "5. Encerramento do programa." << endl;

  cout << endl << "Digite a opção desejada: ";
  cin >> opcao;

  if(opcao > 5 || opcao < 1){
    cout << "Opção inválida!" << endl;
    
  }

  return opcao;
}

bool checkNum(string str) {
  for (int i = 0; i < str.length(); i++){
    if (isdigit(str[i]) == false){
      return false;
    }
  }
  return true;
}

int main(){
  Pilha p1;
  int resultado = 0;
  int opcao;
  string entrada;
  string delimiter = " ";

  opcao = printMenu();
  
  
  
  cout << "Insira a operação: " << endl;
  getline(std::cin, entrada);
  entrada = entrada + " ";

  size_t pos = 0;
  string valor;

  string operacoes[10];
  int op = 0;


  while ((pos = entrada.find(delimiter)) != string::npos) {
      valor = entrada.substr(0, pos);

      if (checkNum(valor) && valor != ""){
        p1.push(stoi(valor));
      }

      if (valor == "-" || valor == "+" || valor == "*" || valor == "/"){
        operacoes[op] = valor;
        op ++;
      }

      entrada.erase(0, pos + delimiter.length());
  }

  int indice = 0;

  resultado = p1.get(p1.size() - 1);
  for (int i = 0; i < op; i++){
    indice = p1.size() - i - 1;

    if (operacoes[i] == "*"){
      resultado = resultado * p1.get(indice - 1);
    }
    if (operacoes[i] == "+"){
      resultado = resultado + p1.get(indice - 1);
    }
    if (operacoes[i] == "-"){
      resultado = resultado - p1.get(indice - 1);
    }
    if (operacoes[i] == "/"){
      resultado = resultado / p1.get(indice - 1);
    }
    if (operacoes[i] == "^"){
      resultado = resultado % p1.get(indice - 1);
    }

    if (indice == 1){
      break;
    }
  }

  cout << "O resultado é: " << resultado << endl;
}