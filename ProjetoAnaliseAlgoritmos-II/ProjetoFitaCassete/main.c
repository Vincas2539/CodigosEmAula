/*
  Thales Torres Lopes - TIA: 32135513
  Vincenzo Sivero Ferreira Alberice - TIA: 32135661
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int seq = 1;

int *geraSequencias(int a[], int s[], int n, int i, int tTF, bool *g);
bool valida(int s[],int i);
void imprima(int v[], int i, int n);
void coiso(int v[], int n);
int musicas_ok(int s[],int iteracoes,int tTF);
bool validaTFM(int f[], int qtdM, int tTF);

// imprime as saidas dos testes 
void imprima(int v[], int i, int n){
  if(i == -1){                       // erro de não ter conseguido colocar as musicas na fita
    printf("Impossivel gravar todas as musicas nessa fita\n");
  } else{
    int min, sec;
    double aux;
    printf("Lado A\n");
    for (int l = 0; l < n; l++){
      if (l == i)
        printf("\nLado B\n");
      min = v[l] / 60;               // Transforma o tempo em segundos para minutos e segundos
      sec = v[l] - (60*min);
      printf("%dm %ds\n", min, sec); // Imprime o tempo
    }
  }
}

// funcao criada pelo professor, porem alterada por nos, para gerar sequencias
int *geraSequencias(int a[], int s[], int n, int i, int tTF, bool *g){
  if (*g == true){                   // variavel para parar as recursões
    return s;
  }
  if ( i > n-1 ){                    // caso base
    int c = musicas_ok(s, n, tTF);   // verifica se o array esta de acordo com as regras da fita
    if (c != -1){                    // se estive de acordo:
      imprima(s, c, n);              // imprime os lados
      *g = true;                     // indica que ja foi gerado uma sequencia correta e que deve parar as recursoes
    }
  }
  else{
    for(int j=0; j < n && *g != true; j++){      
      s[i] = a[j];
      if(valida(s,i))
        geraSequencias(a,s,n,i+1,tTF,g);
    }
  }
  return s;
}

// funcao criada pelo professor para validar as sequencias geradas pela funcao geraSequencias
bool valida(int s[],int i){
  for( int j=0; j < i; j++)
    if(s[i]==s[j])
      return false;
  return true;
}

// funcao que valida se eh possivel alocar as musicas nos lados da fita
int musicas_ok(int s[],int qtdM,int tTF){
  int m, soma = 0;
  m = tTF/2;                        // m eh metade do tamanho da fita
  for (int i = 0; i < qtdM; i++){
    soma = soma + s[i];             // adiciona o tamanho da musica a variavel soma
    if (soma > m){                  // se a soma for maior que a metade do disco
      soma = 0;                     // zera a variavel soma 
      for (int j = i; j < qtdM; j++){
        soma = soma + s[j];         // adiciona o tamanho da musica a variavel soma
        if (soma > m){              // se a soma for maior que a metade do disco
          return -1;                // returna -1 que significa erro
        }
      } 
      return i;                     // retorna i que significa o inicio do lado B
    }
  }
  return 0;
}

// funcao que valida se o total de minutos eh maior que o tamanho total da fita
bool validaTFM(int f[], int qtdM, int tTF){
  int soma = 0;
  for (int i = 0; i < qtdM; i++){
    soma = soma + f[i];             // soma o tempo da fita
  }
  if(soma > tTF)
    return false;
  return true;
}


int main(void){
  int iteracoes, tTF, tMS, tMM, qtdM;
  FILE *arquivo;
  char nomeArquivo[100];
  
  printf("Digite o nome do arquivo txt: ");
  scanf("%s", nomeArquivo);

  arquivo = fopen(nomeArquivo, "r");
  
  fscanf(arquivo, "%d", &iteracoes); // scanf qtd de fitas no arquivo
  printf("\nQuantidade de fitas: %d\n", iteracoes);
  
  for (int i = 0; i < iteracoes; i++){
    fscanf(arquivo, "%d", &tTF);     // scanf tamanho da fita
    printf("\nTempo total da fita: %d minutos\n", tTF);
    tTF = tTF * 60;                  // transforma o tempo da fita em segundos
    fscanf(arquivo, "%d", &qtdM);    // scanf qtd de musicas
    int *fita, *fitaS;
    fita = (int*)malloc(qtdM * sizeof(int));
    fitaS = (int*)malloc(qtdM * sizeof(int));
    
    for (int j = 0; j < qtdM; j++){
      fscanf(arquivo, "%d", &tMM);   // scanf tamanho da musica (minutos)
      fscanf(arquivo, "%d", &tMS);   // scanf tamanho da musica (segundos)
      tMS = tMS + 60*tMM;            // transforma minutos em segundos
      fita[j] = tMS;
    }
    if (!validaTFM(fita, qtdM, tTF))
      imprima(fita, -1, qtdM);       // Imprime que nao foi possivel gravar na fita
    else{
      bool gerou = false;
      geraSequencias(fita, fitaS, qtdM, 0, tTF, &gerou);
      if (gerou == false){
        imprima(fitaS, -1, 0);      // Imprime que nao foi possivel gravar na fita
      }
      free (fita);                  // libera o espaco do array fita
      free (fitaS);                 // libera o espaco do array fitaS
    }  
  }
  
  fclose(arquivo);                  // fecha o arquivo
  return 0;                         // como requisitado, retorna 0 para indicar que o programa rodou com exito
}
