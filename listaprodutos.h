#ifndef LISTAPRODUTO_H_INCLUDED
#define LISTAPRODUTO_H_INCLUDED

typedef struct produto
{
    char codigo[10];
    char tipo[50];
    int quantidade;
    float preco;
}Produto;

typedef struct lista_p Lista_p;

Lista_p* Criar_p();
void Mostrar_p(Lista_p* l);
int ListaVazia_p(Lista_p *l);
int Tamanho_p(Lista_p *l);

int Inserir_inicio_p(Lista_p *l, Produto it);
int Inserir_fim_p(Lista_p *l, Produto it);
int Inserir_posicao_p(Lista_p *l, Produto it);

int Remover_inicio_p(Lista_p *l, Produto it);
int Remover_fim_p(Lista_p *l, Produto it);
int Remover_posicao_p(Lista_p *l, Produto it);

int Buscar_Item_Chave_p(Lista_p *l, Produto it);
int Buscar_Posicao_p(Lista_p *l, int pos);

#endif // LISTAPRODUTO_H_INCLUDED
