#ifndef LISTAPRODUTO_H_INCLUDED
#define LISTAPRODUTO_H_INCLUDED

typedef struct produto
{
    char nome[50];
    char codigo[10];
    char tipo[50];
    int quantidade;
    float preco;
    float custo;
}Produto;

typedef struct lista_p Lista_p;

Lista_p* Criar_p();
void Mostrar_p(Lista_p* l);
int ListaVazia_p(Lista_p *l);
int Inserir_inicio_p(Lista_p *l, Produto it);
int Remover_inicio_p(Lista_p *l);

//===================================================================================================================================================
int MostraOcorrencia_p(Lista_p *l, Produto it);
int InsereProduto(Lista_p *l, Produto it);
int RemoveProduto(Lista_p *l, Produto it);
int ModificarQuantidade(Lista_p *l, Produto it);
int ModificarPreco(Lista_p *l, Produto it);

//===================================================================================================================================================
FILE *FLp_abrir();
int FLp_carregar(Lista_p *l, FILE *pp);
int FLp_salvar(Lista_p *l, FILE *pp);

#endif // LISTAPRODUTO_H_INCLUDED
