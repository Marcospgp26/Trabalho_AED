#ifndef LISTAFUNCIONARIOS_H_INCLUDED
#define LISTAFUNCIONARIOS_H_INCLUDED

typedef struct funcionario
{
    int senha;
    char CPF[11];
    char nome[50];
    long float pagamento;
}Funcionario;

typedef struct lista_f Lista_f;

Lista_f* Criar_f();
void Mostrar_f(Lista_f *l);
int ListaVazia_f(Lista_f *l);
int Tamanho_f(Lista_f *l);

int Inserir_inicio_f(Lista_f *l, Funcionario it);
int Inserir_fim_f(Lista_f *l, Funcionario it);
int Inserir_posicao_f(Lista_f *l, Funcionario it);

int Remover_inicio_f(Lista_f *l, Funcionario it);
int Remover_fim_f(Lista_f *l, Funcionario it);
int Remover_posicao_f(Lista_f *l, Funcionario it);

int Buscar_Item_Chave_f(Lista_f *l, Funcionario it);
int Buscar_Posicao_f(Lista_f *l, int pos);

#endif // LISTAFUNCIONARIOS_H_INCLUDED
