#ifndef PILHACARRINHO_H_INCLUDED
#define PILHACARRINHO_H_INCLUDED

typedef struct produto Produto;
typedef struct pilha Pilha;

Pilha *CriarPilha();
void LimparPilha(Pilha *p);
int TamanhoPilha(Pilha *p);
int Pop(Pilha *p, Produto *it);
int Push(Pilha *p, Produto it);
int Consultar(Pilha *p, Produto *it);
int PilhaVazia(Pilha *p);
void MostrarPilha(Pilha *p);


#endif // PILHACARRINHO_H_INCLUDED
