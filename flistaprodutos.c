#include <stdio.h>
#include <stdlib.h>
#include "listaprodutos.h"

typedef struct no_p
{
    Produto valor;
    struct no_p* prox;
}No_p;

typedef struct lista_p
{
    No_p* fim;
}Lista_p;

Lista_p* Criar_p()
{
    Lista_p* l = (Lista_p*) malloc(sizeof(Lista_p));
    if(l != NULL) l->fim = NULL;
    return l;
}

void Mostrar_p(Lista_p* l)
{
    if(l != NULL)
    {
       printf("[");
       No_p* n= l->fim;
       do
       {
           printf("| %s | %s | %s | %d | %f |\n",n->valor.nome, n->valor.codigo, n->valor.tipo, n->valor.quantidade, n->valor.preco);

       }while(n != l->fim);
    }
}

int ListaVazia_p(Lista_p *l)
{
    if(l == NULL) return 2;
    if(l->fim == NULL) return 0;
    return 1;
}

int Tamanho_p(Lista_p *l)
{
    if(l == NULL) return (-1);
    No_p* n = l->fim;
    if(n == NULL) return 0;
    int cnt = 0;

    do
    {
        cnt++;
        n = n->prox;
    }while(n != l->fim);
    return cnt;
}

int Inserir_inicio_p(Lista_p *l, Produto it)
{
    if(l == NULL) return 2;
    No_p* n = (No_p*) malloc(sizeof(No_p));
    No_p* aux = l->fim;

    n->valor = it;
    if(aux == NULL)
    {
        n->prox = n;
        l->fim = n;
    }
    else
    {
        n->prox = aux->prox;
        n->prox = aux;
    }
    return 0;
}

int Inserir_fim_p(Lista_p *l, Produto it)
{
    if(l == NULL) return 2;
    if(ListaVazia_p(l) == 0)
        return Inserir_inicio_p(l, it);
    No_p* n = (No_p*) malloc(sizeof(No_p));
    No_p* aux = l->fim;


}