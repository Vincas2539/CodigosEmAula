/*
Integrantes:
  Luiz Gabriel Mendes | TIA: 42082293
  Thales Torres | TIA: 32135513
  Vincenzo Alberice | TIA: 32135661
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

void printMatriz(int **mat, int qtdE){
  printf("\n|v/e|[1]|[2]|[3]|[4]|[5]|[6]|\n");
  for (int i = 0; i < qtdE; i++){
    printf("|[%d]| ", i+1);
    for (int j = 0; j < qtdE; j++)
      printf("%d | ", mat[i][j]);
    printf("\n\n");
  }
}

int main(void) {
  int objetivo, qtdE, e1, e2, t, maiorTE = 0, tempoF = 0;
  int **mat, *E, *R, *T;
  FILE *arquivo;
  char nomeArquivo[100];

  printf("Digite o nome do arquivo txt: ");
  scanf("%s", nomeArquivo);

  arquivo = fopen(nomeArquivo, "r"); // abrir arquivo

  fscanf(arquivo, "%d", &objetivo); // scanf esquina do incendio

  fscanf(arquivo, "%d", &qtdE); // scanf qtd de esquinas no arquivo

  // Alocando dinamicamente os vetores e a matriz
  R = (int*)calloc(qtdE, sizeof(int)); // vetor de rotas
  T = (int*)calloc(qtdE, sizeof(int)); // vetor de tempos
  E = (int*)calloc(qtdE, sizeof(int)); // vetor de esquinas
  mat = (int**)calloc(qtdE, sizeof(int*)); // minha cabeça quase explodiu fazendo ponteiro para ponteiro
  for (int i = 0; i < qtdE; i++)
    mat[i] = (int*)calloc(qtdE, sizeof(int));

  // Lendo esquinas e armazenando na matriz
  while (1){
    fscanf(arquivo, "%d", &e1); // scanf esquina saida
    if (e1 == 0) break; // chegou no final do arquivo
    fscanf(arquivo, "%d", &e2); // scanf esquina chegada
    fscanf(arquivo, "%d", &t); // scanf tempo entre elas
    mat[e1-1][e2-1] = t; // insere o tempo na matriz
    if(t > maiorTE) maiorTE = t; // armazena o maior tempo dentre todos os caminhos
  }

  // Print matriz - utilizado nos testes de desenvolvimento
  // printMatriz(mat, qtdE);

  // programa dado no pdf
  T[0] = 0; // não tem como sair do 1 e ir para o 1 - tempo = 0
  E[0] = -1;
  for (int i = 1; i < qtdE; i++){ // inicializando E e T
    E[i] = i+1;
    T[i] = maiorTE*100;
  }

  int v = 0; // esquina atual
  int e = 0; //  possíveis proximas esquinas
  int end = 0; // variavel de saida do while, quando não há mais esquinas em E[]
  t = maiorTE;
  int somaT; // soma do tempo
  while (!end){
    end = 1; // inicia como se não houvesse mais esquinas em E[]
    t = maiorTE; // sempre coloca o maior tempo em t
    
    // verifica menor
    for (int i = qtdE-1; i >= 1; i--){
      if(E[i] != -1){
        if(T[i] < t){
          t = T[i];
          v = i;
        }
        end = 0; // ainda há esquinas em E[], logo continua o while
      }
    }

    E[v] = -1;
    // "v" acessa "e"
    // ou seja, temos varias esquinas "e" para cada esquina "v"
    for(int i = 1; i < qtdE; i++)
      if(mat[v][i] != 0){ // se tiver como ir para a esquina i, a partir da esquina v
        e = i;
        somaT = T[v] + mat[v][i]; // tempo para chegar onde estou + tempo da proxima esquina
        if(T[e] > somaT){ 
          T[e] = somaT;
          R[e] = v+1; // armazena na proxima esquina, a esquina que estava
        }
      }
  }

  // saida final - printa rota
  printf("\n\nRota ate a esquina #%d: ", objetivo);
  end = 0;
  int posAnt = 0;
  while(!end)
    for (int j = 0; j<qtdE; j++)
      if(R[j] == posAnt){
        posAnt = j+1;
        printf("%d ", j+1);
        if(j+1 == objetivo || posAnt > qtdE)
          end = 1;
      }

  tempoF = T[objetivo-1]; // armazena o tempo para chegar no objetivo
  printf("\nTempo calculado para a rota = %d minutos\n", tempoF);
  
  return 0;
}
