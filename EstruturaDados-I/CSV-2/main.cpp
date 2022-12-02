#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "LinkedList.h"
#include "filaSequencialClasse.h"

using namespace std;

/*
1 - Sexo
2 - tipo
3 - intubado
4 - pneumonia
5 - idade
6 - gravidez
7 - diabetes
8 - pulmonar
9 - asma
10 - imunossupressão
11 - hipertensão
12 - outras doenças
13 - cardiovascular
14 - obesidade
15 - insuficiencia renal
16 - fumante
17 - outro caso
18 - teste covid
19 - terapia intensiva
20 - obito
*/

string readFileIntoString(const string& path) { // Função Para leitura do arquivo csv
    auto ss = ostringstream{};
    ifstream input_file(path);
    if (!input_file.is_open()) {
        cerr << "Não foi possível abrir o arquivo - '" << path << "'" << endl;
        exit(EXIT_FAILURE);
    }
    ss << input_file.rdbuf();
    return ss.str();
} 

LinkedList *InicLista(){ // Função para criar lista encadeada
  string filename("df_covid.csv");
  string file_contents;
  LinkedList *lista = new LinkedList();

  char delimiter = ',';

  file_contents = readFileIntoString(filename);

  istringstream sstream(file_contents);

  string record;

  int counter = 0;
  while (std::getline(sstream, record)) {
    lista->insertTail(record);

    counter += 1;
  }
  return lista;
} 

LinkedList *getNovaLista(LinkedList *lista, int atr, int valAtr){
  LinkedList *listaAux = new LinkedList;
  NodeLL *pAnda;
  string carac;
  int valorCarac;
  string linha;
  
  pAnda = lista->getHead();
  listaAux->insertTail(pAnda->getLinha());
  pAnda = pAnda->getProx();

  while(pAnda != nullptr){
    int contador = 0;
    
    for(int i = 0; i < pAnda->getLinha().length(); i++){
      linha = pAnda->getLinha();
      carac = linha.at(i);
      
      if(linha.at(i) != ','){
        if(linha.at(i+1) != ','){
          i++;
          carac = carac + linha.at(i);
        }
        contador++;
        if(contador == atr){
          valorCarac = stoi(carac);
          if(valorCarac == valAtr){
            listaAux->insertTail(pAnda->getLinha());
          }
        }
      }
    }
    pAnda = pAnda->getProx();
  }
  
  return listaAux;
}

int contadorMortoVivo(LinkedList *listaAux, int val){
  NodeLL *pAnda;
  string carac;
  int valorCarac;
  string linha;

  int contadorMorte = 0;
  
  pAnda = listaAux->getHead();
  pAnda = pAnda->getProx();

  while(pAnda != nullptr){
    int contador = 0;
    
    for(int i = 0; i < pAnda->getLinha().length(); i++){
      linha = pAnda->getLinha();
      carac = linha.at(i);
      
      if(linha.at(i) != ','){
        if(linha.at(i+1) != ','){
          i++;
          carac = carac + linha.at(i);
        }
        contador++;
        
        if(contador == 20){
          valorCarac = stoi(carac);
          if(valorCarac == val){
            contadorMorte++;
          }
        }
      }
    }
    pAnda = pAnda->getProx();
    //cout << contador << ",";
  }
  return contadorMorte;
}


/* Fila Menu(){ // Menu
  int opcao = 3;
  int qtdAtributos = 5;
  int cont = 0;
  Fila  F;
  
  while(opcao > 2 || opcao < -1 || opcao == 0){
    cout << "------Menu 1 (Seleção do genero)------" << endl;
    cout << "1. Mulher;" << endl;
    cout << "2. Homem;" << endl;
    cout << "-1. Finalizar Aplicação." << endl;
    
    cout << "Insira a opção desejada: ";
    cin >> opcao;
    cout << endl;
  }
  while(qtdAtributos > 3 && qtdAtributos < -1){
    cout << "------Menu 2 (Quantidade de atributos)------" << endl;
    cout << "1. Um atributo;" << endl;
    cout << "2. Dois atributos;" << endl;
    cout << "3. Tres atributos;" << endl;
    cout << "-1. Finalizar Aplicação." << endl;

    cout << "Insira a opção desejada: ";
    cin >> qtdAtributos;
    cout << endl;
    if(qtdAtributos > 3 && qtdAtributos < -1)
      cout << "Opção inválida!" << endl;
  }
  while(cont < qtdAtributos){
    cout << "------Menu 3 (Seleção de atributos)------" << endl;
    cout << "1. Sexo;";
    cout << "2. Tipo;";
    cout << "3. Intubado;";
    cout << "4. Pneumonia;";
    cout << "5. Idade;"; // verificar
    cout << "6. Gravidez;";
    cout << "7. Diabetes;";
    cout << "8. Pulmonar;";
    cout << "9. Asma;";
    cout << "10. Imunossupressão;";
    cout << "11. Hipertensão;";
    cout << "12. Outras doenças;";
    cout << "13. Cardiovascular;";
    cout << "14. Obesidade;";
    cout << "15. Insuficiencia renal;";
    cout << "16. Fumante;";
    cout << "17. Outro caso;";
    cout << "18. Teste covid;";
    cout << "19. Terapia intensiva;";
    cout << "20. Obito;";
    cout << "-1. Finalizar Aplicação.";
  
    cont++;
  }
  
  return F;
} */

int main(){
  LinkedList *lista;
  Fila  F;
  int opcao = 3;
  int qtdAtributos = 5;
  int atributo;
  int cont = 0;
  
  LinkedList *lista1;
  LinkedList *lista2;
  LinkedList *lista3;
  
  lista = InicLista(); // Abre arquivo csv e cria a lista encadeada
  
  while(opcao > 2 || opcao < -1 || opcao == 0){
    cout << "------Menu 1 (Seleção do genero)------" << endl;
    cout << "1. Mulher;" << endl;
    cout << "2. Homem;" << endl;
    cout << "-1. Finalizar Aplicação." << endl;
    
    cout << "Insira a opção desejada: ";
    cin >> opcao;
    cout << endl;

    if(opcao > 2 || opcao < -1)
      cout << "Opção inválida!" << endl;
  
  }
  if(opcao == -1){
    cout << "Finalizando Aplicação";
    return 0;
  }

  while(qtdAtributos > 3 || qtdAtributos < -1){
    cout << "------Menu 2 (Quantidade de atributos)------" << endl;
    cout << "1. Um atributo;" << endl;
    cout << "2. Dois atributos;" << endl;
    cout << "3. Tres atributos;" << endl;
    cout << "-1. Finalizar Aplicação." << endl;

    cout << "Insira a opção desejada: ";
    cin >> qtdAtributos;
    cout << endl;
    
    if(qtdAtributos > 3 || qtdAtributos < -1)
      cout << "Opção inválida!" << endl;
    }
  if(qtdAtributos == -1){
    cout << "Finalizando Aplicação";
    return 0;
  }

  while(cont < qtdAtributos){
    cout << "------Menu 3 (Seleção de atributos)------" << endl;
    cout << "2. Tipo;" << endl;
    cout << "3. Intubado;" << endl;
    cout << "4. Pneumonia;" << endl;
    cout << "6. Gravidez;" << endl;
    cout << "7. Diabetes;" << endl;
    cout << "8. Pulmonar;" << endl;
    cout << "9. Asma;" << endl;
    cout << "10. Imunossupressão;" << endl;
    cout << "11. Hipertensão;" << endl;
    cout << "12. Outras doenças;" << endl;
    cout << "13. Cardiovascular;" << endl;
    cout << "14. Obesidade;" << endl;
    cout << "15. Insuficiencia renal;" << endl;
    cout << "16. Fumante;" << endl;
    cout << "17. Outro caso;" << endl;
    cout << "18. Teste covid;" << endl;
    cout << "19. Terapia intensiva;" << endl;
    cout << "20. Obito;" << endl;

    cout << "Insira a opção desejada: ";
    cin >> atributo;
    cout << endl;

    if(atributo > 20 || atributo < 2 || atributo == 5){
      cout << "Opção inválida!" << endl;
    }else{
      cont++;
    }
  }
  
  cout << "Finalizando Aplicação";
  
  return 0;
}