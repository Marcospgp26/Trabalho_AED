#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaclientes.h"
#include "listaprodutos.h"
#include "pilhacarrinho.h"

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
    if (ListaVazia_c(l) == 0){
        return Inserir_inicio_c(l,it);
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
    if ((ListaVazia_c(l) == 0)||(pos == 0)){
        return Inserir_inicio_c(l,it);
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

int Remover_inicio_c(Lista_c *l){
    if(l == NULL) return 2;
    if(ListaVazia_c(l) == 0) return 1;

    No_c* n = l->inicio;
    l->inicio = n->prox;
    free(n);
    return 0;
}

int Remover_fim_c(Lista_c *l){
    if (l == NULL)
        return 2;
    if (ListaVazia_c(l) == 0)
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

    if (ListaVazia_c(l) == 0) {
        return 1;
    }

    if (pos == 0) {

        return Remover_inicio_c(l);
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

    if(ListaVazia_c(l) == 0){
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
    int CPF;

    while(noLista != NULL){
        CPF = atoi(noLista->valor.CPF);
        if(CPF == it){
            break;
        }
        noLista = noLista->prox;
    }

    return noLista->valor.gasto;
}

int aumentaGasto(Lista_c *l, int it, float compra){
    if(l == NULL){
        return 1;
    }

    if(ListaVazia_c(l) == 0){
        return 2;
    }

    No_c *noLista = l->inicio;
    int CPF;

    while(noLista != NULL){
        CPF = atoi(noLista->valor.CPF);
        if(CPF == it){
            break;
        }
        noLista = noLista->prox;
    }

    noLista->valor.gasto += compra;

    return 0;
}

int InsereCliente(Lista_c *l, Cliente it){
    if(l == NULL) return 2;
    if(Buscar_Item_Chave_c(l, it) == 0) return 1;
    if(ListaVazia_c(l) == 0)
        return Inserir_inicio_c(l, it);
    No_c* n = (No_c*) malloc(sizeof(No_c));
    No_c* aux = l->inicio, *aux2 = NULL;

    int v;
    do
    {
        v = strcmp((aux->valor.nome), (it.nome));
        if(v < 0)
            break;
        aux2 = aux;
        aux = aux->prox;
    }while(aux != NULL);
    if(aux2 == NULL)
        return Inserir_inicio_c(l, it);
    n->prox = aux2->prox;
    aux2->prox = n;
    n->valor = it;
    return 0;
}

float GastoTotalClientes(Lista_c *l){
    if(l == NULL) return -2;
    if(ListaVazia_c(l) == 0) return 0;

    No_c *no = l->inicio;
    float GastoTot = 0;

    while(no != NULL){
        GastoTot += no->valor.gasto;
        no = no->prox;
    }

    return GastoTot;
}

int modificaHistorico(Lista_c *l, Cliente *pessoa, Produto it){
    if(l == NULL) return 2;
    if(ListaVazia_c(l) == 0) return 1;

    No_c *n = l->inicio;

    while(n != NULL)
    {
        if(strcmp(n->valor.CPF, pessoa->CPF) == 0)
        {
            if(n->valor.historico == NULL) n->valor.historico = CriarPilha();
            Push(n->valor.historico, it);
            break;
        }
        n = n->prox;
    }
    if(n == NULL) return 1;
    return 0;
}

int insereCarrinho(Lista_c *l, Cliente *pessoa, Produto it){
    if(l == NULL) return 2;
    if(ListaVazia_c(l) == 0) return 1;

    No_c *n = l->inicio;

    while(n != NULL)
    {
        if(strcmp(n->valor.CPF, pessoa->CPF) == 0)
        {
            if(n->valor.carrinho == NULL) n->valor.carrinho = Criar_p();
            InsereProduto(n->valor.carrinho, it);
            break;
        }
        n = n->prox;
    }
    if(n != NULL) return 0;
    return 1;

}

int removeCarrinho(Lista_c *l, Cliente *pessoa, Produto *it){
    if(l == NULL) return 2;
    if(ListaVazia_c(l) == 0) return 4;

    No_c *n = l->inicio;
    while(n != NULL)
    {
        if(strcmp(n->valor.CPF, pessoa->CPF) == 0)
        {
            return ReduzX(n->valor.carrinho, it);
            break;
        }
        n = n->prox;
    }
    return 4;
}

FILE *FLc_abrir(){
    FILE *p;

    p = fopen("clientes.txt", "r+"); //assume que o arquivo já existe

    if(p == NULL) {
        printf("Registro de clientes não foi criado!\nCriando novo arquivo...\n");
        p = fopen("clientes.txt", "w");
        fclose(p);
        p = fopen("clientes.txt", "r+");
        if(p == NULL) {
            printf("Nao foi possivel acessar o registro de clientes.\n");
            return 0;
        } else return p;
    }

    return p;
}

int FLc_fechar(FILE *pc){
    if(pc == NULL) return 1;
    
    fclose(pc);
    free(pc);
    pc = NULL;

    return 0;
}