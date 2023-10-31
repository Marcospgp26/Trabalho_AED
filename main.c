#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "listaclientes.h"
#include "listafuncionarios.h"
#include "listaprodutos.h"

#define ENTER 13
#define TAB 9
#define BKSP 8
#define SPACE 32

//define usado para definir códigos ASCII utilizados ao longo do código

int menu_entrada(Lista_f **func, Lista_c **clien, int *tipo);
int entrada_funcionario(Lista_f **func);
int entrada_cliente(Lista_c **clien);
void menu_escolhas(int tipo, int *retorno);

//A PARTE DO ESTOQUE
void menu_estoque(int tipo, Lista_p **l);
void Inserir_Produtos_main(Lista_p **l);
void Remover_Produto_main(Lista_p **l);
void Modifica_Quantidade_main(Lista_p **l);
void Modifica_Preco_main(Lista_p **l);

//CONTROLE DE GASTOS


//INSERCAO
void Cadastro(Lista_f *func, Lista_c *clien);
void Insere_Funcionario_main(Lista_f *func);
void Muda_Cargo_main(Lista_f *func);
void Modifica_Salario_Func_main(Lista_f *func);

int VerificaCPF(char *str, int tam);


int main()
{
    Lista_p* prod = Criar_p();
    Lista_c* clien = Criar_c();
    Lista_f* func = Criar_f();
    int ext = 0, esc_t, esc_a;

    ext = menu_entrada(&func, &clien, &esc_t);

    while(!ext)
    {
        //imprime o primeiro menu efetivo do programa
        system("cls");
        menu_escolhas(esc_t, &esc_a);
        switch(esc_a)
        {
        //sai do sistema
        case 1:
            ext = 1;
            break;
        case 2:
            //acessa o estoque
            menu_estoque(esc_t, &prod);
            break;
        case 3:
            break;
        case 4:
            break;
        }
        if((esc_t == 2) && (esc_a == 5))
        {
            Cadastro(func, clien);
        }
    }
}


//==================================================================================================================================================================================================
int menu_entrada(Lista_f **func, Lista_c **clien, int *tipo)
{
    int esc_t;
    int saida_completa = 0, saida_menu= 0;
    do
    {
        printf("*****SEJA BEM VINDO AO MERCADO BIG BOM*****\n\n");
        printf("Escolha:\n1)Sair\n2)Entrar como funcionario\n3)Entrar como cliente\n");
        scanf("%i", &esc_t);

        if((esc_t < 0) || (esc_t > 3))
            printf("Escolha invalida\n");
        switch(esc_t)
        {
        case 1:
            saida_completa = 1;
            saida_menu = 1;
            break;
        case 2:
            saida_menu = entrada_funcionario(func);
            break;
        case 3:
            saida_menu = entrada_cliente(clien);
            break;
        }
        system("pause");
    }
    while(!saida_menu);
    *tipo = esc_t;
    return saida_completa;
}

int entrada_funcionario(Lista_f **func)
{

    printf("*****ENTRAR COMO FUNCIONARIO*****\n\n");

    Funcionario *entrada = (Funcionario *) malloc (sizeof(Funcionario));

    char ch, senhaaux[5];

    printf("INSIRA A SENHA 0000 VOLTA PARA VOLTAR A TELA ANTERIOR:\n");
    printf("CPF: ");
    setbuf(stdin, NULL);
    
    int k = 0;

    while(k < 11){
        ch = getch();
        entrada->CPF[k] = ch;
        k++;
        printf("%c",ch);
    } //loop para entrada do CPF do funcionario



    
    printf("\nSenha: ");
    int i = 0;
    while(i < 4) //maximo de 4 numeros por senha
    {
        ch=getch();
        if(ch == ENTER)
        {
            senhaaux[i] = '\0';
            break;
        }
        else if(ch == BKSP)
        {
            if(i > 0)
            {
                i--;
                printf("\b \b");
            }
        }
        else if(ch == TAB || ch == SPACE)
        {
            continue;
        }
        else
        {
            senhaaux[i] = ch;
            i++;
            printf("*");
        }
        //o intuito desse while é, ao inserir a senha, o usuario ver apenas asteriscos por motivos de segurança
    }

    entrada->senha = atoi(senhaaux);  //essa função converte uma string em número inteiro, pois no código a senha é interpretada como int

    if(entrada->senha) return 1;
    return 0;
}

int entrada_cliente(Lista_c **clien)
{

    printf("*****ENTRAR COMO CLIENTE*****\n\n");

    Cliente *entrada = (Cliente *) malloc (sizeof(Cliente));
    char ch, senhaaux[5];

    printf("INSIRA A SENHA 0000 VOLTA PARA VOLTAR A TELA ANTERIOR\n");
    setbuf(stdin, NULL);
    
    int k = 0;

    printf("CPF: ");
    while(k < 11){
        ch = getch();
        entrada->CPF[k] = ch;
        k++;
        printf("%c",ch);
    } //loop para entrada do CPF do cliente

    printf("\nSenha: ");
    int j = 0;
    while(j < 4) //Maximo de 4 numeros por senha
    {
        ch = getch();
        if(ch == ENTER)
        {
            senhaaux[j] = '\0';
            break;
        }
        else if(ch == BKSP)
        {
            if(j > 0)
            {
                j--;
                printf("\b \b");
            }
        }
        else if(ch == TAB || ch == SPACE)
        {
            continue;
        }
        else
        {
            senhaaux[j] = ch;
            j++;
            printf("*");
        }
    }

    entrada->senha = atoi(senhaaux);

    if(entrada->senha) return 1;
    return 0;
}

void menu_escolhas(int tipo, int *retorno)
{
    //imprime as informacoes iniciais
    printf("*****MENU DO MERCADO BIG BOM*****\n\n");
    if(tipo == 2)
        printf("Escolha:\n1)Sair\n2)Acessar o estoque\n3)Acessar os gastos mensais do mercado\n4)Registrar compras\n5)Cadastrar pessoas\n");
    else
        printf("Escolha:\n1)Sair\n2)Acessar o estoque\n3)Acessar seus gastos mensais\n4)Comprar produtos\n");
    scanf("%i", retorno);

    if(*retorno < 0)
        printf("Escolha invalida\n");
    else if((tipo == 2) && (*retorno> 5))
        printf("Escolha invalida\n");
    else if((tipo == 3) && (*retorno > 4))
        printf("Escolha invalida\n");
}

//==================================================================================================================================================================================================
void menu_estoque(int tipo, Lista_p **l)
{
    int escolha = 0;
    while(escolha != 1)
    {
        system("cls");
        printf("*****ESTOQUE*****\n\n");

        printf("Escolha:\n1)Voltar para a tela anterior\n2)Ver o estoque\n");
        if(tipo == 2)
            printf("3)Inserir Produto\n4)Remover Produto\n5)Modificar a quantidade de um produto\n6)Modificar o preco de um produto\n");
        scanf("%i", &escolha);

        if(escolha < 0)
            printf("Escolha invalida\n");
        else if((tipo == 2) && (escolha >3))
            printf("Escolha invalida");
        else if((tipo == 3) && (escolha >4))
            printf("Escolha invalida");

        system("cls");

        if(escolha == 2)
        {
            printf("*****ESTOQUE ATUAL*****\n\n");
            Mostrar_p(*l);
        }
        else if(tipo == 2)
        {
            switch(escolha)
            {
            case 3:
                Inserir_Produtos_main(l);
                break;
            case 4:
                Remover_Produto_main(l);
                break;
            case 5:
                Modifica_Quantidade_main(l);
                break;
            case 6:
                Modifica_Preco_main(l);
                break;
            }
        }
        system("pause");
    }

}

void Inserir_Produtos_main(Lista_p **l)
{
    printf("*****INSERCAO DE NOVOS PRODUTOS*****\n\n");
    int verif;
    int tam_s;
    Produto insere_p;

    setbuf(stdin, NULL);
    printf("Insira o nome do produto: ");
    fgets(insere_p.nome, 51, stdin);
    tam_s = strlen(insere_p.nome);
    insere_p.nome[tam_s - 1] = '\0';

    setbuf(stdin, NULL);
    printf("Insira o codigo do produto: ");
    fgets(insere_p.codigo, 10, stdin);
    tam_s = strlen(insere_p.codigo);
    insere_p.codigo[tam_s - 1] = '\0';

    setbuf(stdin, NULL);
    printf("Insira o tipo do produto: ");
    fgets(insere_p.tipo, 51, stdin);
    tam_s = strlen(insere_p.tipo);
    insere_p.tipo[tam_s - 1] = '\0';

    printf("Insira a quantidade de produtos que vai existir no estoque: ");
    scanf("%i", &insere_p.quantidade);

    printf("Insira o preco do produto: ");
    scanf("%f", &insere_p.preco);

    printf("Insira o custo do mercado para comprar o produto: ");
    scanf("%f", &insere_p.custo);

    verif = InsereProduto(*l, insere_p);
    if(verif == 0)
        printf("Produto inserido\n");
    else if(verif == 1)
        printf("O produto ja existe\n");
    else
        printf("Lista nao alocada\n");

}

void Remover_Produto_main(Lista_p **l)
{
    printf("*****REMOCAO DE PRODUTOS*****\n\n");
    int verif;
    int tam_s;
    Produto insere_p;

    setbuf(stdin, NULL);
    printf("Insira o nome do produto: ");
    fgets(insere_p.nome, 51, stdin);
    tam_s = strlen(insere_p.nome);
    insere_p.nome[tam_s - 1] = '\0';

    verif = RemoveProduto(*l, insere_p);
    if(verif == 0)
        printf("Feito\n");
    else if(verif == 2)
        printf("Lista nao alocada\n");
    else if(verif == 1)
        printf("Lista vazia\n");
    else
        printf("Produto nao encontrado\n");
}

void Modifica_Quantidade_main(Lista_p **l)
{
    printf("*****MODIFICAR A QUANTIDADE DOS PRODUTOS*****\n\n");
    int verif;
    int tam_s;
    Produto insere_p;

    setbuf(stdin, NULL);
    printf("Insira o nome do produto: ");
    fgets(insere_p.nome, 51, stdin);
    tam_s = strlen(insere_p.nome);
    insere_p.nome[tam_s - 1] = '\0';

    printf("Insira a nova quantidade do produto: ");
    scanf("%i", &insere_p.quantidade);

    verif = ModificarQuantidade(*l, insere_p);
    if(verif == 0)
        printf("Feito\n");
    else if(verif == 2)
        printf("Lista nao alocada\n");
    else if(verif == 1)
        printf("Lista vazia\n");
    else
        printf("Produto nao encontrado\n");
}

void Modifica_Preco_main(Lista_p **l)
{
    printf("*****MODIFICAR O PRECO DOS PRODUTOS*****\n\n");
    int verif;
    int tam_s;
    Produto insere_p;

    setbuf(stdin, NULL);
    printf("Insira o nome do produto: ");
    fgets(insere_p.nome, 51, stdin);
    tam_s = strlen(insere_p.nome);
    insere_p.nome[tam_s - 1] = '\0';

    printf("Insira o novo preco do produto: ");
    scanf("%f", &insere_p.preco);

    verif = ModificarPreco(*l, insere_p);
    if(verif == 0)
        printf("Feito\n");
    else if(verif == 2)
        printf("Lista nao alocada\n");
    else if(verif == 1)
        printf("Lista vazia\n");
    else
        printf("Produto nao encontrado\n");
}
//==================================================================================================================================================================================================
//==================================================================================================================================================================================================
//==================================================================================================================================================================================================
void Cadastro(Lista_f *func, Lista_c *clien)
{
    system("cls");
    printf("*****CADASTRAR FUNCIONARIOS E/OU CLIENTES NO SISTEMA*****\n\n");
    int esc = 0;
    do
    {
        printf("Escolha:\n1)Sair\n2)Inserir funcionario\n3)Modificar cargo de funcionario\n4)Modificar salario de funcionario\n5)Modificar salario de um cargo\n6)Remover funcionario\n7)Inserir cliente\n");
        scanf("%i", &esc);

        system("cls");
        switch(esc)
        {
        case 2:
            Insere_Funcionario_main(func);
            break;
        case 3:
            Muda_Cargo_main(func);
            break;
        case 4:
            Modifica_Salario_Func_main(func);

        }
    }
    while(esc != 1);
}

void Insere_Funcionario_main(Lista_f *func)  //Nesse caso considere que o gerente esta cadastrando um funcionario
{
    Funcionario it;
    int tam_s, aprova;

    printf("*****CADASTRAR FUNCIONARIOS NO SISTEMA*****\n\n");
    //Processo basico de insercao de dados
    setbuf(stdin, NULL);
    printf("Insira o nome: ");
    fgets(it.nome, 51, stdin);
    it.nome[strlen(it.nome) - 1] = it.nome[strlen(it.nome)];

    do
    {

        aprova = 0;
        setbuf(stdin, NULL);
        printf("Insira o CPF: "); //O CPF eh algo que por si so eh mto complexo, entao vamos usar uma funcao para verifica-lo (se voce esta testando essa parte isso pode ser um pouco chato, uma dica, use seu proprio CPF ou de alguem que voce conheca)
        fgets(it.CPF, 12, stdin); //Isso nao permite que \n seja colocado, ate por que eh essencial que as 11 casas estejam ocupadas

        tam_s = strlen(it.CPF);
        if(tam_s != 11) aprova = 1;
        else if(VerificaCPF(it.CPF, tam_s)) aprova = 1;

        if(aprova) printf("\nCPF Invalido, por favor reensira- o\n\n");

    }
    while(aprova);

    setbuf(stdin, NULL);
    printf("Insira o cargo: ");
    fgets(it.funcao, 50, stdin);

    //aqui da para colocar os asteriscos dnv se quiser, podemos colocar toda a p-arte dos asteriscos numa funcao separada e reutilizar ela
    printf("Insira a senha: ");
    scanf("%i", &it.senha);

    printf("Insira o pagamento: ");
    scanf("%f", &it.pagamento);

    aprova = InsereFuncionario(func, &it); //Basciamente essa funcao verifica se o funcionario ja existe pelo CPF e coloca ele em ordem alfabetica - Marcos
    if(aprova == 2) printf("Lista nao alocada\n");
    else if(aprova == 1) printf("O funcionario ja existe\n");
    else printf("Funcionario adicionado\n");

}

void Muda_Cargo_main(Lista_f *func)
{
    Funcionario it;
    int verif;

    printf("*****MUDAR CARGO DE UM FUNCIONARIO*****\n\n");
    do
    {
        setbuf(stdin, NULL);
        printf("Insira o CPF do funcionario: ");
        fgets(it.CPF, 12, stdin);
        if(strlen(it.CPF) != 11) printf("\nCPF invalido\n");

    }
    while(strlen(it.CPF) != 11);  //Verifica se o CPF foi devidamente digitado

    setbuf(stdin, NULL);
    printf("Insira o novo cargo do funcionario: ");
    fgets(it.funcao, 50, stdin);

    verif = MudaCargoFuncionario(func, &it); //Tenta mudar a situacao do funcionario

    if(verif == 2) printf("Lista nao alocada\n");
    else if(verif == 1) printf("Funcionario nao encontrado, impossivel realizar o procedimento\n");
    else printf("Cargo modificado!\n");
}

void Modifica_Salario_Func_main(Lista_f *func)
{
    Funcionario it;
    int verif;

    printf("*****MUDAR SALARIO DE UM FUNCIONARIO*****\n\n");

    do
    {
        setbuf(stdin, NULL);
        printf("Insira o CPF do funcionario: ");
        fgets(it.CPF, 12, stdin);
        if(strlen(it.CPF) != 11) printf("\nCPF invalido\n");

    }
    while(strlen(it.CPF) != 11);

    printf("Insira o novo salario do funcionario: ");
    scanf("%f", &it.pagamento);

    verif = MudaSalarioFuncionario(func, &it);

    if(verif == 2) printf("Lista nao alocada\n");
    else if(verif == 1) printf("Funcionario nao encontrado\n");
    else printf("Salario modificado\n");

}



//ESSA FUNCAO VERIFICA O CPF - NAO CONFIRMEI SE ELA FUNCIONA PQ SE EU FECHAR ESSE PROJETO ELE NAO ABRE MAIS (CODEBLOCKS), ALGUEM POR FAVOR VERIFICA - Marcos
int VerificaCPF(char *str, int tam)
{
    int i, numeros[11], DV1 = 0, DV2;
    for(i = 0; i < 11; i++)
    {
        numeros[i] = (((int) str[i]) - 48);
    }

    for(i = 0; i < 9; i++)
    {
        DV1 += (numeros[i] * (10 - i));
    }

    DV1 %= 11;
    DV1 = 11 - DV1;
    if(DV1 != numeros[9]) return 1; //Essa parte eh o Digito de Validacao 1;

    for(i = 0; i < 10; i++)
    {
        DV2 += (numeros[i] * (11 - i));
    }

    DV2 %= 11;
    DV2 = 11 - DV2;

    if(DV2 != numeros[10]) return 1; //Essa parte é do digito de validacao 2;

    return 0;
}
