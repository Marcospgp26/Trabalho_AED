#include <stdio.h>
#include <stdlib.h>
#include "pilhacarrinho.h"
#include "listaprodutos.h"

typedef struct noPilha
{
    Produto valor;
    struct noPilha *prox;
}NoPilha;

typedef struct pilha
{
    NoPilha *topo;
}Pilha;

Pilha *CriarPilha()
{
    Pilha *p = (Pilha *) malloc(sizeof(Pilha));
    if(p != NULL) p->topo = NULL;
    return p;
}

void LimparPilha(Pilha *p)
{
    if(p != NULL)
    {
        while(PilhaVazia(p) != 0)
        {
            Produto it;
            Pop(p, &it);
        }
        free(p);
        p = NULL;
    }
}

int TamanhoPilha(Pilha *p)
{
    if(p == NULL) return (-1);
    NoPilha *n = p->topo;
    int i = 0;
    while(n != NULL)
    {
        i++;
        n = n->prox;
    }
    return i;
}

int Pop(Pilha *p, Produto *it)
{
    if(p == NULL) return 2;
    if(PilhaVazia(p) == 0) return 1;

    NoPilha *n = p->topo;

    *it = n->valor;
    p->topo = n->prox;
    free(n);
    return 0;
}

int Push(Pilha *p, Produto it)
{
    if(p == NULL) return 2;
    if(PilhaVazia(p) == 0) return 1;

    NoPilha *inser = (NoPilha *) malloc(sizeof(NoPilha *));
    NoPilha *n = p->topo;

    inser->valor = it;
    inser->prox = n->prox;
    p->topo = inser;
    return 0;
}
int Consultar(Pilha *p, Produto *it)
{
    if(p == NULL) return 2;
    if(PilhaVazia(p) == 0) return 1;
    NoPilha *n = p->topo;
    *it = n->valor;
    return 0;
}

int PilhaVazia(Pilha *p)
{
    if(p == NULL) return 2;
    if(p->topo == NULL) return 0;
    return 1;
}

void MostrarPilha(Pilha *p)
{
    if(p != NULL)
    {
        NoPilha *n = p->topo;
        while(n != NULL)
        {
            printf("NOME | CODIGO | TIPO | QUANTIDADE | PRECO |\n");
            printf("%s | %s | %s",n->valor.nome,n->valor.codigo, n->valor.tipo);
            printf(" | %i | %f |", n->valor.quantidade, n->valor.preco);
            printf("\n");
            n = n->prox;
        }
    }
}
