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

//funcoes basicas
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

//Funcao auxiliar

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

//Parte de estoque
int InsereProduto(Lista_p *l, Produto it)
{
    if(l == NULL) return 2;
    if(MostraOcorrencia_p(l, it) == 0) return 1;
    if(ListaVazia_p(l) == 0)
        return Inserir_inicio_p(l, it);

    No_p* aux = (No_p*)malloc(sizeof(No_p));
    No_p* aux2 = NULL;
    No_p* n = (No_p*) malloc(sizeof(No_p));
    int v;

    do
    {
        v = strcmp((aux->valor.nome), (it.nome));
        if(v != 0)
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

//Parte de reseva
int Reduz_X(Lista_p *l, Produto *it)
{
    if(l == NULL) return 2;

    No_p *noLista = l->inicio;

    while(noLista != NULL)
    {
        if(strcmp(noLista->valor.codigo, it->codigo) == 0)
        {
            if((noLista->valor.quantidade) < (it->quantidade)) return 3;
            noLista->valor.quantidade -= it->quantidade;
            strcpy(it->nome, noLista->valor.nome);
            strcpy(it->tipo, noLista->valor.tipo);
            it->preco = noLista->valor.preco;
            return 0;
        }
        noLista = noLista->prox;
    }
    return 1;
}

int Aumenta_X(Lista_p *l, Produto *it)
{
    if(l == NULL) return 2;

    No_p *noLista = l->inicio;

    while(noLista != NULL)
    {
        if(strcmp(noLista->valor.codigo, it->codigo) == 0)
        {
            if((noLista->valor.quantidade) < (it->quantidade)) return 3;
            noLista->valor.quantidade += it->quantidade;
            return 0;
        }
        noLista = noLista->prox;
    }
    if(noLista == NULL) return InsereProduto(l, *it);
}

int ConsultaPrimeiro(Lista_p *l, Produto *it)
{
    if(l == NULL) return 2;
    if(ListaVazia_p(l) == 0) return 1;
    No_p *n = l->inicio;
    n->valor = *it;
    return 0;
}
//Parte de Economia
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

//Parte de FILE
FILE *FLp_criar(){
    FILE *p; 

    
    printf("Registro do estoque nao foi criado!\nCriando novo arquivo...\n");
    system("pause");
    p = fopen("produtos.txt", "w");
    fclose(p);


    return p;
}
int FLp_carregar(Lista_p *l, FILE *pp){
        //assume que o arquivo já existe e tenta ler os dados
        pp = fopen("produtos.txt", "r");

        if(pp == NULL){
            pp = FLp_criar();
            pp = fopen("produtos.txt", "r");
        }
        //caso não exista, um novo arquivo é criado, normalmente ocorre durante a primeira execução

        No_p *noLista = l->inicio;
        Produto it;

        if((fscanf(pp, "%[^,],%[^,],%[^,],%i,%f,%f\n", it.nome, it.codigo, it.tipo, &it.quantidade, &it.preco, &it.custo)) != 6) {
            printf("Nao foi detectado nenhum campo no arquivo (produtos), ou houve erro na hora da leitura, para carregar informacoes, primeiro salve alguma coisa no arquivo!\n");
            return 1;
        }
        //leitura dos dados do arquivo

        InsereProduto(l, it);
        //caso o if falhe, insere o primeiro elemento já lido pelo carrinho de leitura

        while((fscanf(pp, "%[^,],%[^,],%[^,],%i,%f,%f\n", it.nome, it.codigo, it.tipo, &it.quantidade, &it.preco, &it.custo)) == 6) {
            InsereProduto(l, it);
            
        }
        //inserção dos dados do arquivo para a memória do programa

        fclose(pp);

        return 0;
    }

int FLp_salvar(Lista_p *l, FILE *pp){

        if(l == NULL) return 1;

        pp = fopen("produtos.txt", "w"); //abre em modo de escrita e exclui o arquivo antigo

        No_p *noLista = l->inicio;

        while(noLista != NULL) {
            fprintf(pp, "%s,%s,%s,%i,%f,%f\n", noLista->valor.nome, noLista->valor.codigo, noLista->valor.tipo, noLista->valor.quantidade, noLista->valor.preco, noLista->valor.custo);
            noLista = noLista->prox;
        }
        //salva os dados modificados/utilizados durante a execução em um arquivo .txt
        
        fclose(pp);

        return 0;
    }