#include <stdio.h>

//variáveis para o tamanho da matriz do "tabuleiro"
int COLUNAS;
int LINHAS;
 
// Função que inicializa a matriz com linhas e colunas valendo 0
void matrizInicial(int matriz[LINHAS][COLUNAS]) 
{

    for (int lin = 0; lin < LINHAS; lin++) 
    {
        for (int col = 0; col < COLUNAS; col++) 
        {
            matriz[lin][col] = 0;
        }
    }
}


// Função para exibir ao usuário a matriz completa com informação sobre o tamanho das linhas e colunas
void printMatriz(int matriz[LINHAS][COLUNAS]) 
{

    printf("\n\n");
    printf("    ");
    //Laço para mostrar o tamanho das colunas
    for (int col = 0; col < COLUNAS; col++) 
    {
        //arrumando formatação para que fique alinhado 
        if (col < 10) 
        {
            printf("%d  ", col);
        } 
        else 
        {
            printf("%d ", col);
        }
    }
    printf("\n");
    //Laço para mostrar os valores da matriz
    for (int lin = 0; lin < LINHAS; lin++) 
    {
        printf("\n");

        //Mostrando o tamanho das linhas
        if (lin < 10) 
        {
            printf("%d  ", lin);
        } 
        else 
        {
            printf("%d ", lin);
        }
        //Laço para mostrar os valores da matriz
        for (int col = 0; col < COLUNAS; col++) 
        {
            //mostrando os valores da matriz
            printf(" %s", matriz[lin][col]==0?"  ":"\u25A0 ");
        }
    }
}

//Variável de análise dos termos vizinhos para determinar se estão "vivos" 
int analisaVizinhos(int matriz[LINHAS][COLUNAS], int coordLin, int coordCol) 
{

    int in_qtdVizinhos = 0;
    int in_elemento;

    for (int lin = 0; lin < 3; lin++) 
    {
        for (int col = 0; col < 3; col++) 
        {

            //in_linha + (in_cordLinha - 1): vizinhos considerando o termo                   anterior de cada linha
            //in_coluna + (in_cordColuna - 1): vizinhos considerando o termo                 anterior de cada coluna
            //se for uma posição inexiste na matriz ele não considera como                   vizinho, 
            //se for uma posição -1 é uma posição inexistente, 
            //se for uma posição maior que o numero de linhas ou de colunas tbm              é inexistente
            if (!((lin + (coordLin - 1) == -1 || col + (coordCol - 1) == -1) || (lin + (coordLin - 1) > LINHAS) || (col + (coordCol - 1) > COLUNAS))) 
            {

                // Conteudo do vizinho que vai ser analisado
                in_elemento = matriz[lin + (coordLin - 1)][col + (coordCol - 1)];

                // Elimina da análise o ponto central
                if (lin == 1 && col == 1) 
                {
                    continue;
                }
                // Se o vizinho estiver vivo será somado na quantidade de                        vizinhos
                else if (in_elemento == 1) 
                {
                    in_qtdVizinhos++;
                }
            }
        }
    }
    return in_qtdVizinhos;
}


// Função que define se a célula será alterada ou não dependendo de seus vizinhos
void pontoPrincipal(int matriz[LINHAS][COLUNAS], int qtdVizinhos, int coordLin, int coordCol) 
{

    // se a célula estiver viva, e os vizinhos forem < 2 a célula morre
    if (qtdVizinhos < 2 && matriz[coordLin][coordCol] == 1) 
    {
        matriz[coordLin][coordCol] = 0;
    }

    // se a célula estiver viva, e os vizinhos forem > 3 a célula morre
    else if (qtdVizinhos > 3 && matriz[coordLin][coordCol] == 1) 
    {
        matriz[coordLin][coordCol] = 0;
    }

    // se a célula estiver morta, e os vizinhos forem == 3 a célula vive
    else if (qtdVizinhos == 3 && matriz[coordLin][coordCol] == 0) 
    {
        matriz[coordLin][coordCol] = 1;
    }

    // se a célula estiver viva, e os vizinhos forem == 2 ou == 3 a célula continua viva
    else if ((qtdVizinhos == 2 || qtdVizinhos == 3) && matriz[coordLin][coordCol] == 1) {
        matriz[coordLin][coordCol] = 1;
    }
}

// Função que realiza a troca na matriz que contém a proxima geração para a matriz que terá a geração atual
void geracaoAtual(int matriz[LINHAS][COLUNAS], int proximaGeracao[LINHAS][COLUNAS]) 
{

    for (int lin = 0; lin < LINHAS; lin++) 
    {
        for (int col = 0; col < COLUNAS; col++) 
        {
            matriz[lin][col] = proximaGeracao[lin][col];
        }
    }
}


// Função que insere uma "célula viva" para uma determinada coordenada indicada pelo usuário
void inputCelulaViva(int proximaGeracao[LINHAS][COLUNAS], int coordLin, int coordCol) 
{

    proximaGeracao[coordLin][coordCol] = 1;
}

// Função que processa todas as outras funções 
void processamento(int matriz[LINHAS][COLUNAS], int proximaGeracao[LINHAS][COLUNAS]) 
{

    for (int lin = 0; lin < LINHAS; lin++) 
    {
        for (int col = 0; col < COLUNAS; col++) 
        {
            pontoPrincipal(proximaGeracao, analisaVizinhos(matriz, lin, col), lin, col);
        }
    }
    geracaoAtual(matriz, proximaGeracao);
    printMatriz(matriz);
    printf("\n");
}

int main(void) 
{

    printf("JOGO DA VIDA DE CONWAY \n\n");

    // while que valida os valores das entradas de linhas e colunas
    while (1) 
    {
        // Informa ao usuário a faixa permitida na entrada
        printf("\nDigite o tamanho da matriz:\n\n");

        // Pede um valor de entrada para o usuário para quantidade de linhas que         tera a matriz
        printf("Digite o número de linhas: ");
        scanf("%d", & LINHAS);

        // Pede um valor de entrada para o usuário para quantidade de coluna que         tera a matriz
        printf("Digite o número de colunas: ");
        scanf("%d", & COLUNAS);

        // Se a faixa digitada pelo usuário estiver dentro do esperado finaliza          o while, senão roda o while ate que a faixa digitada esteja correta
        if (!(COLUNAS < 5 || LINHAS < 5 || LINHAS > 30 || COLUNAS > 30)) 
        {
            break;
        } 
        else 
        {
            printf("\nDigite novamente um valor (entre 5 e 30):\n\n");
        }
    }

    // Cria as matrizes, principal e a auxiliar que terá a proxima geração
    int matriz[LINHAS][COLUNAS];
    int proximaGeracao[LINHAS][COLUNAS];

    // Inicia a matriz principal e a matriz auxiliar com todas as posições           zeradas
    matrizInicial(matriz);
    matrizInicial(proximaGeracao);

    // Exibe para o usuário a primeira geração
    printMatriz(matriz);

    // Loop que define as ações tomadas, até que o usuário encerre o programa
    while (1) 
    {
        int in_opc;

        // Exibe para o usuário um menu com um menu com as opções possiveis
        printf("\nMenu do jogo da vida:\n\nEscolha uma opção:\n1.Visualizar a proxima geracao;\n2.Inserir novo ponto\n3.Finalizar o jogo da vida\n");
        scanf("%d", & in_opc);

        // Se o usuário escolher a opção 1 irá ver a proxima geração de celulas
        if (in_opc == 1) 
        {
            processamento(matriz, proximaGeracao);
        }

        // Se o usuário escolher a opção 2 irá definir um novo ponto na matriz
        else if (in_opc == 2) 
        {

            int coordLin;
            int coordCol;

            // Pede ao usuário o valor da coordenada da linha
            printf("\nDigite o número da linha:");
            scanf("%d", & coordLin);

            // Pede ao usuário o valor da coordenada da coluna
            printf("\nDigite o número da coluna:");
            scanf("%d", & coordCol);

            // O valor será inserido na matriz auxiliar que contem a proxima                 geração, 
            //será feito o espelhamento para a matriz principal
            //exibido para o usuário a matriz modificada
            inputCelulaViva(proximaGeracao, coordLin, coordCol);
            geracaoAtual(matriz, proximaGeracao);
            printMatriz(matriz);
        }
          
        // Se o usuário escolher a opção 0 o programa será encerrado
        else if (in_opc == 3) 
        {
            break;
        }
    }
}