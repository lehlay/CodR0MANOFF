#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "investidor.h"

///MAIN
int main(){
    Investidor *inv;
    Acao *acoes;
    Acao *ac;
    // Declarei o contador "i" porque no meu pc não roda declarando dentro do for
    // Declarei uma variável chamada level para seleção do cenário
    int qtdAcoes, i, level;
    FILE  *arquivo;
    double dinheiro;
    char test[100];
    int aux;

    // Criei um comando de seleção do nível
    printf("Informe o nível\n");
    scanf("%d", &level);
    switch (level){
        case 1: arquivo = fopen("investimento1.txt", "r"); break;
        case 2: arquivo = fopen("investimento2.txt", "r"); break;
        case 3: arquivo = fopen("investimento3.txt", "r"); break;
        case 4: arquivo = fopen("investimento4.txt", "r"); break;
        case 5: arquivo = fopen("investimento5.txt", "r"); break;
    }
    // Eu limpo o ENTER que fica depois que a pessoa digita o nvel
    setbuf(stdin, NULL);

    fscanf(arquivo, "%d", &qtdAcoes);
    fscanf(arquivo, "%d", &aux);
    dinheiro = aux/1.0;
    acoes = (Acao*)malloc(sizeof(Acao)*qtdAcoes);


    // Tirei o ponteiro "ac" porque não precisa dele
    for(i=0; i<qtdAcoes; i++){
        fscanf(arquivo, "%d", &acoes[i].lucro);
    }
    for(i=0; i<qtdAcoes; i++){
        fscanf(arquivo, "%d", &(acoes[i].preco));
    }
    for( i=0; i<qtdAcoes; i++){
        printAcao((acoes+i), i);
        printf("\n");
    }
    /*
        criar a afuncao investir
        fazer menu
    */

    system("pause");

}
