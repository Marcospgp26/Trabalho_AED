#ifndef LISTACLIENTES_H_INCLUDED
#define LISTACLIENTES_H_INCLUDED


typedef struct lista_p Lista_p;
typedef struct produto Produto;
typedef struct pilha Pilha;

typedef struct cliente
{
    int senha;
    char CPF[12];
    float gasto;
    Pilha *historico;
    Lista_p *carrinho;
}Cliente;

typedef struct lista_c Lista_c;

//Funcoes basicas
Lista_c* Criar_c();
void Mostrar_c(Lista_c* l);
int ListaVazia_c(Lista_c *l);
int Tamanho_c(Lista_c *l);
int Inserir_inicio_c(Lista_c *l, Cliente it);
int Inserir_fim_c(Lista_c *l, Cliente it);
int Inserir_posicao_c(Lista_c *l, Cliente it, int pos);
int Remover_inicio_c(Lista_c *l);
int Remover_fim_c(Lista_c *l);
int Remover_posicao_c(Lista_c *l, Cliente it, int pos);
int Buscar_Item_Chave_c(Lista_c *l, Cliente it);
int Buscar_Posicao_c(Lista_c *l, int pos, Cliente *it);


//Parte economia
int aumentaGasto(Lista_c *l, Cliente *pessoa, float compra);
float GastoTotalClientes(Lista_c *l);
void MostraHistorico(Lista_c *l, Cliente *pessoa);

//Parte de insercao
int InsereCliente(Lista_c *l, Cliente it);

//Parte de Reserva
void mostracarrinho(Lista_c *l, Cliente *pessoa);
int inserecarrinho(Lista_c *l, Cliente *pessoa, Produto *it);
int removecarrinho(Lista_c *l, Cliente *pessoa, Produto *it);
int apagacarrinho(Lista_c *l, Cliente *pessoa);

//Parte de FILE
FILE *FLc_criar();
int FLc_carregar(Lista_c *l, FILE *pc);
int FLc_salvar(Lista_c *l, FILE *pc);

#endif // LISTACLIENTES_H_INCLUDED
