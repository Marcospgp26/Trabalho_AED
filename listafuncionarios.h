#ifndef LISTAFUNCIONARIOS_H_INCLUDED
#define LISTAFUNCIONARIOS_H_INCLUDED

typedef struct funcionario
{
    int senha;
    char CPF[11];
    char nome[50];
    char funcao[50];
    float pagamento;
}Funcionario;

typedef struct lista_f Lista_f;

Lista_f* Criar_f();
int ListaVazia_f(Lista_f *l);
int Inserir_inicio_f(Lista_f *l, Funcionario *it);
int Remover_inicio_f(Lista_f *l);


int Buscar_Item_Chave_f(Lista_f *l, Funcionario it);
int Buscar_Posicao_f(Lista_f *l, int pos);

//===================================================================================================================================================
void MostrarDadosPagamento(Lista_f *l);
int MostraOcorrencia_f(Lista_f *l, Funcionario *it);
int InsereFuncionario(Lista_f *l, Funcionario *it);
int VerificarSenha(Lista_f *l, Funcionario *it);
int MudaSalarioFuncionario(Lista_f *l, Funcionario *it);
int MudaSalarioCargo(Lista_f *l, Funcionario *it);
int MudaCargoFuncionario(Lista_f *l, Funcionario *it);

#endif // LISTAFUNCIONARIOS_H_INCLUDED
