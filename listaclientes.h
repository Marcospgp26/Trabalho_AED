#ifndef LISTACLIENTES_H_INCLUDED
#define LISTACLIENTES_H_INCLUDED

typedef struct cliente
{
    int senha;
    char CPF[11];
    char nome[50];
    float gasto;
}Cliente;

typedef struct lista_c Lista_c;

Lista_c* Criar_c();
void Mostrar_c(Lista_c* l);
int ListaVazia_c(Lista_c *l);
int Tamanho_c(Lista_c *l);

int Inserir_inicio_c(Lista_c *l, Cliente it);
int Inserir_fim_c(Lista_c *l, Cliente it);
int Inserir_posicao_c(Lista_c *l, Cliente it, int pos);

int Remover_inicio_c(Lista_c *l, Cliente it);
int Remover_fim_c(Lista_c *l, Cliente it);
int Remover_posicao_c(Lista_c *l, Cliente it, int pos);

int Buscar_Item_Chave_c(Lista_c *l, Cliente it);
int Buscar_Posicao_c(Lista_c *l, int pos, Cliente *it);

#endif // LISTACLIENTES_H_INCLUDED
