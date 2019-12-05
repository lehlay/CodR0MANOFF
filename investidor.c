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
