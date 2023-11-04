#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaprodutos.h"

typedef struct no_p
{
    Produto valor;
    struct no_p *prox;
}No_p;

typedef struct lista_p
{
    No_p *inicio;
}Lista_p;

Lista_p* Criar_p()
{
    Lista_p *l = (Lista_p*) malloc(sizeof(Lista_p));
    l->inicio = NULL;
    return l;
}

void Mostrar_p(Lista_p* l)
{
    if(l != NULL)
    {
        No_p* n = l->inicio;
        printf("NOME | CODIGO | TIPO | QUANTIDADE | PRECO |\n");
        while(n != NULL)
        {
            printf("| %s | %s | %s | %d | %f |\n", n->valor.nome, n->valor.codigo, n->valor.tipo, n->valor.quantidade, n->valor.preco);
            n = n->prox;
        }
    }
}

int ListaVazia_p(Lista_p *l)
{
    if(l == NULL) return 2;
    if(l->inicio == NULL) return 0;
    return 1;
}

int Inserir_inicio_p(Lista_p *l, Produto it)
{
    if(l == NULL) return 2;

    No_p* n = (No_p*) malloc(sizeof(No_p));
    n->valor = it;

    n->prox = l->inicio;
    l->inicio = n;

    return 0;
}

int Remover_inicio_p(Lista_p *l)
{
    if(l == NULL) return 2;
    if(ListaVazia_p(l) == 0) return 1;

    No_p* n = l->inicio;
    l->inicio = n->prox;
    free(n);
    return 0;
}

//===================================================================================================================================================

int MostraOcorrencia_p(Lista_p *l, Produto it)
{
    if(l == NULL) return 2;
    if(ListaVazia_p(l) == 0) return 1;

    No_p* n = l->inicio;
    int a, b;

    while(n != NULL)
    {
        a = strcmp((n->valor.nome), (it.nome));
        b = strcmp((n->valor.codigo), (it.codigo));
        if((a == 0) && (b == 0))
        {
            return 0;
        }
        n = n->prox;
    }
    return 3;
}

int InsereProduto(Lista_p *l, Produto it)
{
    if(l == NULL) return 2;
    if(MostraOcorrencia_p(l, it) == 0) return 1;
    if(ListaVazia_p(l) == 0)
        return Inserir_inicio_p(l, it);

    No_p* aux = l->inicio;
    No_p* aux2 = NULL;
    No_p* n = (No_p*) malloc(sizeof(No_p));
    int v;

    do
    {
        v = strcmp((aux->valor.nome), (it.nome));
        if(v > 0)
            break;
        aux2 = aux;
        aux = aux->prox;
    }while(aux != NULL);

    if(aux2 == NULL)
    {
        return Inserir_inicio_p(l, it);
    }

    n->prox = aux2->prox;
    aux2->prox = n;
    n->valor = it;
    return 0;
}

int RemoveProduto(Lista_p *l, Produto it)
{
    if(l == NULL) return 2;
    if(ListaVazia_p(l) == 0) return 1;

    No_p* n = l->inicio;
    No_p* aux = NULL;

    if(strcmp((n->valor.nome), (it.nome)) == 0)
        return Remover_inicio_p(l);

    int v;
    do
    {
        v = strcmp((n->valor.nome), (it.nome));
        if(v == 0)
            break;
        aux = n;
        n = n->prox;
    }while(n != NULL);

    if(v == 0)
    {
        aux->prox = n->prox;
        free(n);
        return 0;
    }
    return 3;
}

int ModificarQuantidade(Lista_p *l, Produto it)
{
    if(l == NULL) return 2;
    if(ListaVazia_p(l) == 0) return 1;

    No_p* n= l->inicio;
    int v;
    while(n != NULL)
    {
        v = strcmp((n->valor.nome), it.nome);
        if(v == 0)
            break;
        n = n->prox;
    }

    if(v == 0)
    {
        n->valor.quantidade = it.quantidade;
        return 0;
    }
    return 3;
}

int ModificarPreco(Lista_p *l, Produto it)
{
    if(l == NULL) return 2;
    if(ListaVazia_p(l) == 0) return 1;

    No_p* n= l->inicio;
    int v;
    while(n != NULL)
    {
        v = strcmp((n->valor.nome), it.nome);
        if(v == 0)
            break;
        n = n->prox;
    }

    if(v == 0)
    {
        n->valor.preco = it.preco;
        return 0;
    }
    return 3;
}

int ReduzX(Lista_p *l, Produto *it)
{
    if(l == NULL) return 2;
    if(ListaVazia_p(l) == 0) return 1;

    No_p* n= l->inicio;
    int v;
    while(n != NULL)
    {
        v = strcmp((n->valor.codigo), it->codigo);
        if(v == 0)
            break;
        n = n->prox;
    }

    if(n == NULL) return 1;

    if(n->valor.quantidade < it->quantidade) return 3;

    strcpy(it->nome, n->valor.nome);
    strcpy(it->tipo, n->valor.tipo);
    it->preco = n->valor.preco;
    it->custo = 0;

    n->valor.quantidade -= it->quantidade;
    if(n->valor.quantidade == 0)
        RemoveProduto(l, n->valor);

    return 0;
}

int AumentaX(Lista_p *l, Produto it)
{
    if(l == NULL) return 2;

    No_p* n= l->inicio;
    int v;

    while(n != NULL)
    {
        v = strcmp((n->valor.codigo), it.codigo);
        if(v == 0)
            break;
        n = n->prox;
    }

    if(n == NULL) return InsereProduto(l, it);
    n->valor.quantidade += it.quantidade;
    return 0;

}

float GastoTotalProdutos(Lista_p *l){
    if(l == NULL) return -2;
    if(ListaVazia_p(l) == 0) return 0;

    No_p *no = l->inicio;
    float CustoTot = 0;

    while(no != NULL){
        CustoTot += (no->valor.custo * no->valor.quantidade);
        no = no->prox;
    }

    return CustoTot;
}

FILE *FLp_abrir(){
    FILE *p;

    p = fopen("produtos.txt", "r+"); //assume que o arquivo já existe

    if(p == NULL) {
        printf("Registro do estoque nao foi criado!\nCriando novo arquivo...\n");
        p = fopen("produtos.txt", "w");
        fclose(p);
        p = fopen("produtos", "r+");
        if(p == NULL) {
            printf("Nao foi possivel acessar o registro de produtos.\n");
            return 0;
        } else return p;
    }

    return p;
}

int FLp_fechar(FILE *pp){
    if(pp == NULL) return 1;
    
    fclose(pp);
    free(pp);
    pp = NULL;

    return 0;
}
