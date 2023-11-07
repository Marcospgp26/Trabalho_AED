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
        printf("SENHA | CPF | GASTO |");
        printf("[");
        while(n != NULL)
        {
            printf("| %d | %s | %s | RS%.2f |\n",n->valor.senha,n->valor.CPF,n->valor.gasto);
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
        if (strcmp(noLista->valor.CPF, it.CPF) == 0 && noLista->valor.senha == it.senha) {
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

    No_c *noLista = l->inicio; //procura até a posicao
    int p = 0;

    while((noLista->prox != NULL) && (p != pos)){
        p++;
        noLista = noLista->prox; //percorre até a posição
    }

    strcpy(it->CPF,noLista->valor.CPF); 
    it->senha = noLista->valor.senha;
    it->gasto = noLista->valor.gasto;
    it->historico = noLista->valor.historico; 
    //retorna o elemento com todas as informações

    return 0;
}


//Insercao
int InsereCliente(Lista_c *l, Cliente it)
{
    if(l == NULL) return 2;
    if(Buscar_Item_Chave_c(l, it) == 0) return 1;
    if(ListaVazia_c(l) == 0)
        return Inserir_inicio_c(l, it); //se vazia insere no inicio
    No_c* n = (No_c*) malloc(sizeof(No_c));
    No_c* aux = l->inicio, *aux2 = NULL;

    int v;
    do
    {
        v = strcmp((aux->valor.CPF), (it.CPF)); //compara o CPF do ponteiro ao do cliente
        if(v < 0)
            break; //sai do loop
        aux2 = aux;
        aux = aux->prox;
    }while(aux != NULL); //percorre ate o fim da lista
    if(aux2 == NULL)
        return Inserir_inicio_c(l, it); //nao movimentou
    n->prox = aux2->prox;
    aux2->prox = n;
    it.carrinho = Criar_p();
    it.historico = CriarPilha();
    n->valor = it; //insere o cliente
    return 0;
}


//PARTE ECONOMICA
float GastoTotalClientes(Lista_c *l){
    if(l == NULL) return -2;
    if(ListaVazia_c(l) == 0) return 0;

    No_c *no = l->inicio;
    float GastoTot = 0; //cria um float

    while(no != NULL){ //vai ate o fim da lisa de clientes
        GastoTot += no->valor.gasto; //adiciona o gasto de cada cliente
        no = no->prox;
    }

    return GastoTot; //retorna todos os gastos somados
}

void MostraHistorico(Lista_c *l, Cliente *pessoa)
{
    if(l != NULL)
    {
        No_c *n = l->inicio;
        while(n != NULL)
        {
            if(strcmp(n->valor.CPF, pessoa->CPF) == 0)
            {
                printf("HISTORICO:\n");
                MostrarPilha(n->valor.historico);
                printf("\nGastos totais: ");
                printf("%i", &n->valor.gasto);
                system("pause");
            }
            n = n->prox;
        }
    }
}

//PARTE DE COMPRAS
void mostracarrinho(Lista_c *l, Cliente *pessoa)
{
    if(l != NULL)
    {
        No_c *n = l->inicio;
        while(n != NULL)
        {
            if(strcmp(n->valor.CPF, pessoa->CPF) == 0)
            {
                Mostrar_p(n->valor.carrinho);
                break;
            }
            n = n->prox;
        }
    }
}

int inserecarrinho(Lista_c *l, Cliente *pessoa, Produto *it)
{
    if(l == NULL) return 2;
    if(ListaVazia_c(l) == 0) return 1;

    No_c *noLista = l->inicio;
    while(noLista != NULL)
    {
        if(strcmp(noLista->valor.CPF,pessoa->CPF) == 0)
        {
            if(noLista->valor.carrinho == NULL) noLista->valor.carrinho = Criar_p();
            else if(MostraOcorrencia_p(noLista->valor.carrinho, *it) == 0) return Aumenta_X(noLista->valor.carrinho, it);
            return InsereProduto(noLista->valor.carrinho, *it);
        }
        noLista = noLista->prox;
    }
    return 1;
}

int removecarrinho(Lista_c *l, Cliente *pessoa, Produto *it)
{
    if(l == NULL) return 2;
    if(ListaVazia_c(l) == 0) return 1;

    No_c *noLista = l->inicio;
    while(noLista != NULL)
    {
        if(strcmp(noLista->valor.CPF, pessoa->CPF))
        {
            if(noLista->valor.carrinho == NULL) return 4;
            else if(MostraOcorrencia_p(noLista->valor.carrinho, *it) == 0) return Reduz_X(noLista->valor.carrinho, it);
        }
        noLista = noLista->prox;
    }
    return 1;
}

int apagacarrinho(Lista_c *l, Cliente *pessoa)
{
    if(l == NULL) return 2;
    if(ListaVazia_c(l) == 0) return 1;
    No_c *n = l->inicio;
    Produto it;

    while(n != NULL)
    {
        if(strcmp(n->valor.CPF, pessoa->CPF) == 0)
        {
            if(n->valor.historico == NULL) n->valor.historico = CriarPilha();
            while(ListaVazia_p(n->valor.carrinho) != 0)
            {
                ConsultaPrimeiro(n->valor.carrinho, &it);
                Push(n->valor.historico, it);
                Reduz_X(n->valor.carrinho, &it);
            }
            free(n->valor.carrinho);
            n->valor.carrinho = NULL;
            return 0;
        }
    }
    return 1;
}

//PARTE DE FILE
FILE *FLc_criar(){
    FILE *p;

    printf("Nao foi criado o registro de clientes!\nCriando novo arquivo...");
    system("pause");
    p = fopen("clientes.txt", "w");
    fclose(p);

    return p;
}

int FLc_carregar(Lista_c *l, FILE *pc){
    pc = fopen("clientes.txt", "r");
    if(pc == NULL){
        pc = FLc_criar();
        pc = fopen("clientes.txt", "r");
    }

    Pilha *aux = CriarPilha();
    No_c *noLista = l->inicio;
    Produto it;
    Cliente itc;

    if((fscanf(pc, "%i,%[^,],%f\n", &itc.senha, itc.CPF, &itc.gasto)) != 3){
        printf("Nao foi detectado nenhum campo no arquivo (clientes), ou houve erro na hora da leitura, para carregar informacoes, primeiro salve alguma coisa no arquivo!\n");
        return 1;
    }
    Inserir_fim_c(l, itc);

    while((fscanf(pc, "%i,%[^,],%f\n", &itc.senha, itc.CPF, &itc.gasto)) == 3){
        while((fscanf(pc, "%[^,],%[^,],%[^,],%i,%f,%f   ", it.nome, it.codigo, it.tipo, &it.quantidade, &it.preco, &it.custo)) == 6){
            Push(aux, it);
            while(PilhaVazia(aux) != 0){
                Pop(aux, &it);
                Push(noLista->valor.historico, it);
            }
        }
        Inserir_fim_c(l, itc);     
    }
    
    return 0;
}

int FLc_salvar(Lista_c *l, FILE *pc){
   
    if(l == NULL) return 1;

    pc = fopen("clientes.txt", "w");   
       
    No_c *noLista = l->inicio;

    Produto it;
    
    while(noLista != NULL){
        fprintf(pc, "%i,%s,%f\n", noLista->valor.senha, noLista->valor.CPF, noLista->valor.gasto);
        
        while(noLista->valor.historico != NULL){
            Pop(noLista->valor.historico, &it);
            fprintf(pc, "%s,%s,%s,%i,%f,%f   ", it.nome, it.codigo, it.tipo, it.quantidade, it.preco, it.custo);
        }

        noLista = noLista->prox;
    }
    fclose(pc);
     
    return 0;
}