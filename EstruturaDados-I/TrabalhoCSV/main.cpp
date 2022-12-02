/* 
Link apresentação: https://docs.google.com/presentation/d/11Nn2X8tG7KJXYVEU6o8WPmzMYgXjaCsa2mc-tWAZTaM/edit?usp=sharing

Vincenzo Sivero Ferreira Alberice
32135661

Ana Clara Melo Senne
32145101

Paulo Henrique Sousa Camargo 
32138121

Thales Torres Lopes 
32135513

Victor Silva Fernandes
32163967
*/

#include <bits/stdc++.h> // Biblioteca para contar o tempo
#include <iostream> // bibilioteca de entrada e saida do C++
#include <fstream> // Biblioteca para abrir o arquivo csv
#include <sstream> // Biblioteca para auxiliar o fstream transformando tudo em String
#include <string> // Biblioteca para poder utilizar Strings
#include "LinkedList.h" // Incluindo o codigo de lista simplesmente encadeada do professor

using namespace std;

/* opções
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
        cerr << "Não foi possível abrir o arquivo - '"
             << path << "'" << endl;
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

LinkedList *getNovaLista(LinkedList *lista, int atr, int valAtr){ // gera uma nova lista com os atributos 
  LinkedList *listaAux = new LinkedList;
  NodeLL *pAnda;
  string carac;
  int valorCarac;
  string linha;
  
  pAnda = lista->getHead(); // pula o cabeçalho
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
  
  pAnda = listaAux->getHead(); // pula o cabeçalho
  pAnda = pAnda->getProx();

  while(pAnda != nullptr){
    int contador = 0;
    
    for(int i = 0; i < pAnda->getLinha().length(); i++){ // percorre a linha pelo índice
      linha = pAnda->getLinha();
      carac = linha.at(i);
      
      if(linha.at(i) != ','){ // separa por virgula
        if(linha.at(i+1) != ','){
          i++;
          carac = carac + linha.at(i); // concatena caso tenha dois caracteres
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

void printTempo(int opcao, clock_t start, clock_t end){
  double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
  cout << "Tempo de execução da opção " << opcao << ": " << fixed << time_taken << setprecision(5);
  cout << " segundos." << endl << endl;
}

int Menu(){ // Menu
  int opcao = 0;
  
  cout << "------Menu------" << endl;
  cout << "1. Qtd de homens que tinham alguma doença cardiovascular e morreram de covid;" << endl;
  cout << "2. Qtd de mulheres que tinham diabetes e morreram de covid;" << endl;
  cout << "3. Qtd de mulheres que tem diabetes e não morreram de covid;" << endl;
  cout << "4. Qtd de homens que fumavam, tinham asma e morreram de covid;" << endl;
  cout << "5. Qtd de pessoas que fizeram o teste de covid deu negativo e morreram de covid;" << endl;
  cout << "6. Finalizar Aplicação" << endl;
  cout << "Insira a opção desejada: ";

  cin >> opcao;
  cout << endl << endl;
  return opcao;
}

int main(){
  LinkedList *lista;
  int opcao;

  clock_t start, end;

  
  LinkedList *lista1;
  LinkedList *lista2;
  LinkedList *lista3;

  start = clock(); // Inicia a contar o tempo pra ler do csv
  lista = InicLista(); // Abre arquivo csv e cria a lista encadeada
  end = clock();// termina de contar o tempo pra ler do csv

  double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
  cout << "Tempo de leitura do csv : " << fixed << time_taken << setprecision(5);
  cout << " segundos." << endl << endl;
  
  opcao = Menu();

  while(opcao != 6){ // seleção da opção
    
    if(opcao == 1){
      start = clock();
      lista1 = getNovaLista(lista, 1, 2); // 1 = mulher, 2 = homem
      lista2 = getNovaLista(lista1, 13, 1);
      end = clock();
      cout << "Opção 1: " << contadorMortoVivo(lista2, 1) << " homens." << endl << endl; // 1 = morto, 0 = vivo
      lista1->clear();
      lista2->clear();
      printTempo(1, start, end);
      
    } else if(opcao == 2){
      start = clock();
      lista1 = getNovaLista(lista, 1, 1);
      lista2 = getNovaLista(lista1, 7, 1);
      cout << "Opção 2: " << contadorMortoVivo(lista2, 1) << " mulheres." << endl << endl;
      end = clock();
      lista1->clear();
      lista2->clear();
      printTempo(2, start, end);
      
    } else if(opcao == 3){
      start = clock();
      lista1 = getNovaLista(lista, 1, 1);
      lista2 = getNovaLista(lista1, 7, 1);
      end = clock();
      cout << "Opção 3: " << contadorMortoVivo(lista2, 0) << " mulheres." << endl << endl;
      lista1->clear();
      lista2->clear();
      printTempo(3, start, end);
      
    } else if(opcao == 4){
      start = clock();
      lista1 = getNovaLista(lista, 1, 2);
      lista2 = getNovaLista(lista1, 16, 1);
      lista3 = getNovaLista(lista2, 9, 1);
      end = clock();
      cout << "Opção 4: " << contadorMortoVivo(lista3, 1) << " homens." << endl << endl;
      lista1->clear();
      lista2->clear();
      lista3->clear();
      printTempo(4, start, end);
      
    } else if(opcao == 5){
      start = clock();
      lista1 = getNovaLista(lista, 18, 2);
      end = clock();
      cout << "Opção 5: " << contadorMortoVivo(lista1, 1) << " pessoas." << endl << endl;
      lista1->clear();
      printTempo(5, start, end);
      
    } else if(opcao > 6){
      cout << "Valor inválido!" << endl;
    }
    opcao = Menu();
  }
  cout << "Finalizando Aplicação";
  lista->clear();
  
  return 0;
}


/*
Fonte utilizadas para fazer o projeto:
https://java2blog.com/read-csv-file-in-cpp/
https://waterprogramming.wordpress.com/2017/08/20/reading-csv-files-in-c/
https://www.geeksforgeeks.org/csv-file-management-using-c/
https://www.geeksforgeeks.org/measure-execution-time-with-high-precision-in-c-c/
*/