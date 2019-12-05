#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "investidor.h"

Investidor *novoInvestidor(int dinheiro){
    Investidor *inv;
    inv = (Investidor*)malloc(sizeof(Investidor));
    if(inv!=NULL){
        printf("Informe o nome do investidor: ");
        fgets(inv->name, sizeof(inv->name), stdin);
        inv->name[strlen(inv->name)-1] = '\0';
        inv->dinheiro = dinheiro;
        inv->totalLucro = 0;
        inv->qtdInvestimentos = 0;
        inv->investimentos = (Investimento*)malloc(sizeof(Investimento)*100);
        if(inv->investimentos!=NULL){
            return inv;
        }
        free(inv);
    }
    return NULL;
}

int destroyInvestidor(Investidor *inv){
    if(inv!=NULL){
        free(inv->investimentos);
        free(inv);
        return 1;
    }
    return 0;
}

void printAcao(Acao *ac, int i){
    if(ac!=NULL){
        printf("%d - Lucro da Acao: %d\n", i, ac->lucro);
        printf("%d - Preco da Acao: %d\n", i, ac->preco);
    }
}


// Uma sugestão de modelo de função de compra
// Recebe o vetor de ações e a struct do investidor
int compra(Acao* acoes, Investidor* inv){
    int choice = 0, i = 0;
    static int cont =0;
    double lucro_da_rodada=0, lucroAtual=0, custo_da_rodada=0, porcentagem =0, dinheiro = inv->dinheiro;

    setbuf(stdin, NULL);
    cont++;
    printf("\nDigite o número da ação ou -1 para sair:\n");
    scanf("%d", &choice);
    if (choice == -1) return -1;
    printf("Digite a porcentagem da ação (1 a 100%):\n");
    scanf(" %lf", &porcentagem);

    //Lucro e custo da compra
    lucro_da_rodada = (double) ((porcentagem/100)* acoes[choice].lucro);
    custo_da_rodada = (double) ((porcentagem/100)* acoes[choice].preco);
    lucroAtual = inv->totalLucro + lucro_da_rodada;
    dinheiro = dinheiro - custo_da_rodada;

    // Atualiza na struct inv
    inv->dinheiro = dinheiro;
    inv->totalLucro = lucroAtual;
    inv->qtdInvestimentos= cont;
    inv->investimentos[cont-1].porcentagem = porcentagem;
    inv->investimentos[cont-1].lucro = lucro_da_rodada;
    inv->investimentos[cont-1].d_investido = custo_da_rodada;
    inv->investimentos[cont-1].acao->lucro = acoes[choice].lucro;
    inv->investimentos[cont-1].acao->preco = acoes[choice].preco;
    printf("\nCompra realizada\n");
    printf("\nDinheiro Atual:%lf\n", inv->dinheiro);
    printf("Lucro Atual:%lf\n", inv->totalLucro);
    printf("Vezes investidas:%d\n", inv->qtdInvestimentos);
    printf("\nCarteira de Ações:\n");

    //Exibe as compras realizadas
    for (i = 0; i < cont; i ++){
        printf("Custo:%lf Lucro %lf\n",inv->investimentos[i].d_investido,inv->investimentos[i].lucro);
    }

return 0;
}


