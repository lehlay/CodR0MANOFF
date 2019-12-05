#ifndef INVESTIDOR_H_INCLUDED
#define INVESTIDOR_H_INCLUDED


typedef struct acao
{
    int lucro;
    int preco;
} Acao;


typedef struct _investimento_
{
    Acao *acao;
    double porcentagem;
    double lucro;
    double d_investido;

}Investimento;


typedef struct _investidor_
{
    char name[300];
    double dinheiro;
    double totalLucro;
    int qtdInvestimentos;
    Investimento *investimentos;

}Investidor;

Investidor *novoInvestidor(int dinheiro);
int destroyInvestidor(Investidor *inv);

void printAcao(Acao *ac, int i);

#endif // INVESTIDOR_H_INCLUDED
