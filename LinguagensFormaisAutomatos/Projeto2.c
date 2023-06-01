/*
Thales Torres Lopes
    TIA: 32135513

Vincenzo Sivero Ferreira Alberice
    TIA: 32135661

Agradecimento especial
    Prof Fabio Lubacheski
*/

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

// declarando funcoes ->
void programa();
void declaracoes();
void comandos();
void atribuicao();
void expr();
void termo();
void fator();
void variavel();
void numero();
void letra();
void digito();
void comentario();
void proxTerminal();
void erro(int i);

// declarando variaveis globais ->
char *entrada;
int linha = 1;

// comecando programa ->
void programa() {
  declaracoes();
  comandos();
  proxTerminal();
}

void declaracoes() {
  if (entrada[0] == 'i' && entrada[1] == 'n' && entrada[2] == 't' &&
      (entrada[3] == ' ' || entrada[3] == '\n' || entrada[3] == '\t')) {
    entrada++;
    entrada++;
    entrada++;
    entrada++;
  } else
    erro(1);
  proxTerminal();
  variavel();
  proxTerminal();
  if (*entrada == ';')
    entrada++;

  proxTerminal();

  while (entrada[0] == 'i' && entrada[1] == 'n' && entrada[2] == 't' &&
         (entrada[3] == ' ' || entrada[3] == '\n' || entrada[3] == '\t')) {
    entrada++;
    entrada++;
    entrada++;
    entrada++;
    proxTerminal();
    variavel();
    if (*entrada == ';')
      entrada++;
    else
      erro(4);
    proxTerminal();
  }
}

void comandos() {
  atribuicao();
  while (*entrada == ';') {
    entrada++;
    proxTerminal();
    atribuicao();
  }
  proxTerminal();
  if (*entrada != '\x0')
    erro(11);
}

void atribuicao() {
  variavel();
  if (*entrada == '=')
    entrada++;
  else
    erro(1);
  proxTerminal();
  expr();
}

void expr() {
  if (*entrada == '+' || *entrada == '-') {
    entrada++;
    proxTerminal();
  }
  termo();
  while (*entrada == '+' || *entrada == '-') {
    entrada++;
    proxTerminal();
    termo();
  }
}

void termo() {
  fator();
  while (*entrada == '*' || *entrada == '/') {
    entrada++;
    proxTerminal();
    fator();
  }
}

void fator() {
  if (*entrada == '(') {
    entrada++;
    proxTerminal();
    expr();
    if (*entrada == ')') {
      entrada++;
      proxTerminal();
    } else
      erro(3);
  } else
    numero();
}

void variavel() {
  letra();
  while (isalpha(*entrada))
    entrada++;
  proxTerminal();
}

void numero() {
  digito();
  while (isdigit(*entrada))
    entrada++;
  proxTerminal();
}

void letra() {
  if (isalpha(*entrada)) {
    entrada++;
  } else
    erro(2);
}

void digito() {
  if (isdigit(*entrada)) // strchar("abc012",*entrada);
    entrada++;
  else
    erro(1);
}

void comentario() {
  while (*entrada != '\n')
    entrada++;
  entrada++;
  linha++;
}

void proxTerminal() {
  while (*entrada == ' ')
    entrada++;
  if (*entrada == '\n') {
    entrada++;
    linha++;
    proxTerminal();
  }
  if (entrada[0] == '/' && entrada[1] == '/') {
    entrada++;
    entrada++;
    comentario();
    proxTerminal();
  }
}

void erro(int e) {
  proxTerminal();
  printf("Erro na linha %d\n", linha);
  switch (e) {
  case 1: // erro de numero
    printf("Esperado: [numero]. \t Encontrado: '%c'\n", *entrada);
    break;
  case 2: // erro de letra
    if (*entrada == '\x0') {
      printf("Esperado: [letra]. \t Encontrado: [fim do arquivo]\nUltima "
             "atribuicao nao deve ter ';'\n");
      break;
    }
    printf("Esperado uma letra. \t Encontrado '%c'\n", *entrada);
    break;
  case 3: // erro de expressao
    printf("Esperado: ')'. \t Encontrado: '%c'\n", *entrada);
    break;
  case 4:
    printf("Esperado: ';'. \t Encontrado: '%c'\n", *entrada);
  case 11: // erro de atribuicao
    printf("Antes de nova atribuicao eh preciso utilizar ';' \t Encontrado: "
           "'%c'\n",
           *entrada);
    break;
  case 12: // erro de leitura
    printf("Esperado fim do programa. \t Encontrado '%c'\n", *entrada);
    break;
  }
  exit(1);
}

int main(void) {
  FILE *arq;
  char nomeArquivo[100];
  int linhaAtual = 0;
  int tam;

  printf("Digite o nome do arquivo:");
  scanf("%s", nomeArquivo);

  arq = fopen(nomeArquivo, "r");

  fseek(arq, 0, SEEK_END);
  tam = ftell(arq); // pega o tamanho do arquivo
  rewind(arq);      // volta o ponteiro do arquivo para o inicio

  entrada = (char *)calloc(
      tam, sizeof(char)); // aloca entrada com o tamanho do arquivo

  fread(entrada, sizeof(char), tam, arq); // le o arquivo e armazena em entrada

  fclose(arq);

  printf("Iniciando execucao!\n");

  proxTerminal();
  if (*entrada == '\x0') {
    printf("\nPrograma vazio.\n");
    exit(0);
  }
  programa();

  if (*entrada == '\x0') { // se cheguei ao final da entrada
    printf("\nPrograma reconhecido sem erros.\n%d linhas analisadas", linha);
  } else
    erro(12);

  return 0;
}