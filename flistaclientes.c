#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaclientes.h"

typedef struct no_c{
    Cliente valor;
    struct no_c *prox;
}No_c;

typedef struct lista_c{
    No_c *inicio;
} Lista_c;

Lista_c* Criar_c(){
    Lista_c *l = (Lista_c*)malloc(sizeof(Lista_c));
    l->inicio = NULL;
    return l;
}

void Mostrar_c(Lista_c* l){
    if(l != NULL)
    {
        No_c* n = l->inicio;
        printf("SENHA | CPF | NOME | GASTO |");
        printf("[");
        while(n != NULL)
        {
            printf("| %d | %s | %s | RS%.2f |\n",n->valor.senha,n->valor.CPF,n->valor.nome,n->valor.gasto);
            n = n->prox;
        }
        printf("]");
    }
}
int ListaVazia_c(Lista_c *l){
    if(l == NULL) return 2;
    if(l->inicio == NULL) return 0;
    return 1;
}

int Tamanho_c(Lista_c *l){
    int num = 0;

    No_c *NoLista = l->inicio;

    while(NoLista != NULL){
        num++;
        NoLista = NoLista->prox;
    }

    return num;
}

int Inserir_inicio_c(Lista_c *l, Cliente it){
    if(l == NULL) return 2;

    if(Buscar_Item_Chave_c(l, it) == 0){
        return 3;
    }

    No_c* n = (No_c*) malloc(sizeof(No_c));
    n->valor = it;

    n->prox = l->inicio;
    l->inicio = n;

    return 0;
}

int Inserir_fim_c(Lista_c *l, Cliente it){
    if (l == NULL)
    return 2;
    if (listaVazia(l) == 0){
        return inserirInicio(l,it);
    }
    if(Buscar_Item_Chave_c(l, it) == 0){
        return 3;
    }

    No_c *noLista = l->inicio;
    while (noLista->prox != NULL)
        noLista = noLista->prox;
    No_c *no = (No_c*)malloc(sizeof(No_c));
    no->valor = it;
    no->prox = noLista->prox;
    noLista->prox = no;
    return 0;
}

int Inserir_posicao_c(Lista_c *l, Cliente it, int pos){
    if (l == NULL) return 2;
    if (pos < 0) return 3;
    if ((listaVazia(l) == 0)||(pos == 0)){
        return inserirInicio(l,it);
    }
    if(Buscar_Item_Chave_c(l, it) == 0){
        return 4;
    }
    No_c *noLista = l->inicio;
    int p = 1;
    while ((noLista->prox != NULL)&&(p != pos)) {
        p++;
        noLista = noLista->prox;
    }
    No_c *no = (No_c*)malloc(sizeof(No_c));
    no->valor = it;
    no->prox = noLista->prox;
    noLista->prox = no;
    return 0;
}

int Remover_inicio_c(Lista_c *l, Cliente it){
    if(l == NULL) return 2;
    if(ListaVazia_p(l) == 0) return 1;

    No_c* n = l->inicio;
    l->inicio = n->prox;
    free(n);
    return 0;
}

int Remover_fim_c(Lista_c *l, Cliente it){
    if (l == NULL)
        return 2;
    if (listaVazia(l) == 0)
        return 1;
    No_c *noAuxiliar = NULL;
    No_c *noLista = l->inicio;
    while (noLista->prox != NULL) {
        noAuxiliar = noLista;
        noLista = noLista->prox;
    }
    if (noAuxiliar == NULL) l->inicio = NULL;
    else noAuxiliar->prox = NULL;
    free(noLista);
    return 0;
}

int Remover_posicao_c(Lista_c *l, Cliente it, int pos){
    if (l == NULL) {
        return 2;
    }

    if (listaVazia(l) == 0) {
        return 1;
    }

    if (pos == 0) {
        
        return removerInicio(l);
    }

    No_c *noAux = NULL;
    No_c *noLista = l->inicio;
    int p = 0;

   
    while (p < pos - 1 && noLista->prox != NULL) {
        noAux = noLista;
        p++;
        noLista = noLista->prox;
    }

    
    if (noLista->prox == NULL) {
        return 1; 
    }

   
    noAux = noLista;
    noLista = noLista->prox;
    noAux->prox = noLista->prox;

    free(noLista);

    return 0;
}

int Buscar_Item_Chave_c(Lista_c *l, Cliente it){
    if (l == NULL)
        return 2;
    No_c *noLista = l->inicio;
    while ((noLista != NULL)) {
        if ((noLista->valor).CPF == it.CPF) {
            return 0;
        }
        noLista = noLista->prox;
    }
    return 1;
}

int Buscar_Posicao_c(Lista_c *l, int pos, Cliente *it){
    if(l == NULL) return 2;

    if(listaVazia(l) == 0){
        return 1;
    }

    No_c *noLista = l->inicio;
    int p = 0;

    while((noLista->prox != NULL) && (p != pos)){
        p++;
        noLista = noLista->prox;
    }

    strcpy(it->CPF,noLista->valor.CPF);
    it->senha = noLista->valor.senha;
    it->gasto = noLista->valor.gasto;
    strcpy(it->nome,noLista->valor.nome);

    return 0;
}

float verificaGastos(Lista_c *l, int it){
    No_c *noLista = l->inicio;
    
    while(noLista != NULL){
        if(noLista->valor.CPF == it){
            break;
        }
        noLista = noLista->prox;
    }
    
    return noLista->valor.gasto;
}
