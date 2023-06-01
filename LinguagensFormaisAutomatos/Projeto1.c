/*
Thales Torres Lopes
    TIA: 32135513

Vincenzo Sivero Ferreira Alberice
    TIA: 32135661
*/

/*
Objetivo:
1. Na primeira linha, os símbolos do alfabeto de entrada (), com letras sempre
em minúsculo, em ordem alfabética sempre começando por a, e sem espaços em
branco entre os símbolos, o tamanho do alfabeto é limitado a 10 símbolos na
primeira linha. Por exemplo se quiser um alfabeto com 5 símbolos como teríamos
(abcde) tudo junto.

2. Na segunda linha, o número de Q estados, para facilitar a implementação o
estado inicial será sempre o primeiro estado (q0) e qualquer AFND terá no máximo
20 estados (q0, q1, ...., q19), ou seja, |Q|<=20.

3. Na terceira linha temos um número F indicando a quantidade de estados finais
e na linha seguinte (quarta linha) a lista dos estados finais separados por
espaço em branco na mesma linha, considere que F <= Q.

4. Na quinta linha temos o número de N transições do AFND, e nas N linhas
seguintes as transições especificadas no seguinte formato, separadas por espaço
em branco: <estado corrente> branco <símbolo em  > branco <estado chegada>

5. Ao final das N transições, teremos uma linha com um inteiro T especificando o
número de palavras que deverão ser testadas no AFND, as palavras estarão cada
uma em uma linha contendo somente os símbolos do alfabeto de entrada ().
Considere também, que cada palavra terá no máximo 100 caracteres.
*/

// #include <vincenzo.deus>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ESTADOS 100
#define MAX_ALFABETO 11

// declara automato
typedef struct  {
  int qtdEstados;
  char *alfabeto;
  int qtdEstFin;
  int *estFin;
  int ***matTrans;
} Automato;

// funções principais
int *funcTrans(Automato *aut, int *estAtual, char letra);
int funcTransEstendida(Automato *aut, char *palavra);

// funções de conjuntos
int JaTaNaLista(int *lista, int n);
int *Uniao(int *e1, int *e2);
int verifEstFin(int *e1, int *e2, int tam);

void populaLista(int *lista, int tam);

// Principais funcoes
int JaTaNaLista(int *lista, int n) { // funciona como uma função de união em certas partes
  while (*lista != -1) {
    if (*lista == n)
      return 1;
    else
      lista++;
  }
  return 0;
}

void populaLista(int *lista, int tam){ // coloca os valores da lista como -1
  for (int i = 0; i < tam+1; i++) // coloca 1 a mais do tamanho para saber 
    lista[i] = -1;                // o final mesmo com a lista cheia
}

int funcTransEstendida(Automato *aut, char *palavra) {
  int *estados; // lista de estados autais
  estados = (int *)calloc(aut->qtdEstados+1, sizeof(int));
  populaLista(estados, aut->qtdEstados);
  // adiciona estado inicial na lista de estados autais
  estados[0] = 0; // define estado inicial como zero
  for (int j = 0; palavra[j] != '\0'; j++)
    estados = funcTrans(aut, estados, palavra[j]); // executa a função de transição por letra
  if(verifEstFin(aut->estFin, estados, aut->qtdEstados))
    return 1; // retorna 1 se for aceito
  return 0; // retorna 0 se não for aceito
}

 // matriz[letra][Qi][QF]
int *funcTrans(Automato *aut, int *estAtual, char letra) {
  int *estadosF; // aloca a lista de estados finais
  estadosF = (int *)calloc(aut->qtdEstados+1, sizeof(int));
  populaLista(estadosF, aut->qtdEstados);
  int contEF = 0; // contador de estados finais na lista
  for (int j = 0; j < aut->qtdEstados; j++) {
    if (estAtual[j] != -1) {
      for (int i = 0; i < aut->qtdEstados; i++)
        if (aut->matTrans[letra-'a'][estAtual[j]][i] != -1)
          if (!JaTaNaLista(estadosF, aut->matTrans[letra-'a'][estAtual[j]][i])){
            estadosF[contEF] = aut->matTrans[letra-'a'][estAtual[j]][i];
            contEF++;
          }
    }
  }
  if(contEF == 0) // ferifica se os processos "morreram"
    estadosF[0] = 0; // se sim, voltam para o estado 0
  return estadosF; // retorna a lista de estados finais
}

int *Uniao(int *e1, int *e2){
  int i=0, j=0;
  while(e1[i] != -1)
    i++;
  while(e2[j] != -1){
    if (!JaTaNaLista(e1, e2[j])){
      e1[i] = e2[j];
      i++;
    }
    j++;
  }
  return e1;
}

// funciona como a intersecção para verificar os estados finais
int verifEstFin(int *e1, int *e2, int tam){ // tam é o tamanho do e1, ou seja aut->qtdEstados+1
  int j=0;
  while(e2[j] != -1){
    if (JaTaNaLista(e1, e2[j])){
      return 1;
    }
    j++;
  }
  return 0;
}

int main(void) {
  // cria a struct
  Automato automato;
  // 5 primeiras linhas
  char *alfabeto;
  int nEstados, nEstFin, *EstFin, nTrans, qtd, check;
  int ***matTrans;
  // transições
  int estado;
  // Palavras para teste
  int qtdTestes;
  char **palavras;
  // arquivo
  char nomeArquivo[100];
  FILE *arq;

  // inicializando o alfabeto
  alfabeto = (char *)calloc(11, sizeof(char));

  // LENDO O TXT
  printf("Digite o nome do arquivo txt: ");
  scanf("%s", nomeArquivo);
  arq = fopen(nomeArquivo, "r"); // abrir arquivo

  // 1 alfabeto
  fscanf(arq, "%s", alfabeto);
  automato.alfabeto = alfabeto;
  
  // 2 n° estados
  fscanf(arq, "%d", &nEstados);
  automato.qtdEstados = nEstados;

  // 3 n° de estados finais
  fscanf(arq, "%d", &nEstFin);
  automato.qtdEstFin = nEstFin;

  // 4 lista dos estados finais
  EstFin = (int *)calloc(nEstFin+1, sizeof(int));
  populaLista(EstFin, nEstFin);
  for (int i = 0; i < nEstFin; i++)
    fscanf(arq, "%d", &EstFin[i]);
  automato.estFin = EstFin;

  // 5 n° de setinhas
  fscanf(arq, "%d", &nTrans);

  // Alocando matriz - mat[letra][Qi][QF]
  qtd = strlen(alfabeto);
  matTrans = (int ***)calloc(qtd, sizeof(int **));
  for (int i = 0; i < nEstados; i++) {
    matTrans[i] = (int **)calloc(nEstados, sizeof(int *));
    for (int j = 0; j < nEstados; j++) {
      matTrans[i][j] = (int *)calloc(nEstados, sizeof(int));
    }
  }

  // inicializa a matriz com todos os valores = -1
  for (int i = 0; i < qtd; i++) {
    for (int j = 0; j < nEstados; j++) {
      for (int k = 0; k < nEstados; k++)
        matTrans[i][j][k] = -1;
    }
  }

  for (int i = 0; i < nTrans; i++) {
    int EstI, EstF;
    char Letra;
    fscanf(arq, "%d", &EstI);
    // printf("Estado inicial: %d\n", EstI);
    fscanf(arq, "%s", &Letra);
    // printf("Letra: %c\n", Letra);
    fscanf(arq, "%d", &EstF);
    // printf("Estado Final: %d\n\n", EstF);
    matTrans[Letra - 'a'][EstI][EstF] = EstF;
  }
  automato.matTrans = matTrans;

  fscanf(arq, "%d", &qtdTestes);
  // aloca um vetor de testes
  palavras = (char **)calloc(qtdTestes, sizeof(char *));
  for (int i = 0; i < qtdTestes; i++) {
    palavras[i] = (char *)calloc(101, sizeof(char));
    // le as palavras e aloca no vetor
    fscanf(arq, "%s", palavras[i]);
  }

  // testar palavras
  for (int i = 0; i < qtdTestes; i++) {
    check = funcTransEstendida(&automato, palavras[i]);
    if(check == 1)
      printf("%d: %s OK\n", i+1, palavras[i]);
    else
      printf("%d: %s not OK\n", i+1, palavras[i]);
  }

  return 0;
}

// void Estacionamento(){} // me chamarão de louco //