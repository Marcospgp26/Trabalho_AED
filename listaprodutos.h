#ifndef LISTAPRODUTO_H_INCLUDED
#define LISTAPRODUTO_H_INCLUDED

typedef struct produto
{
    char nome[51];
    char codigo[11];
    char tipo[51];
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
int ReduzX(Lista_p *l, Produto *it);
int AumentaX(Lista_p *l, Produto it);
float GastoTotalProdutos(Lista_p *l);
//===================================================================================================================================================
FILE *FLp_criar();
int FLp_carregar(Lista_p *l, FILE *pp);
int FLp_salvar(Lista_p *l, FILE *pp);

#endif // LISTAPRODUTO_H_INCLUDED
