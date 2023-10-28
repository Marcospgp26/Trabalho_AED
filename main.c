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

void menu_escolhas(int tipo, int *retorno);

//A PARTE DO ESTOQUE
void menu_estoque(int tipo, Lista_p **l);
void Inserir_Produtos_main(Lista_p **l);
void Remover_Produto_main(Lista_p **l);
void Modifica_Quantidade_main(Lista_p **l);
void Modifica_Preco_main(Lista_p **l);


int main()
{
    Lista_p* prod = Criar_p();
    char nome[50];
    char senhaaux[25];
    int senha;
    char ch;
    int ext = 0, esc_t, saida = 0, tam_s, esc_a;

    //entrar como funcionario ou cliente
    do
    {
        printf("Escolha:\n1)Sair\n2)Entrar como funcionario\n3)Entrar como cliente\n");
        scanf("%i", &esc_t);

        if((esc_t < 0) || (esc_t > 3))
            printf("Escolha invalida\n");

        system("cls");
        switch(esc_t)
        {
        //saida do programa
        case 1:
            ext = 1;
            saida = 1;
            break;

        //Entrar como funcionario
        case 2:

            //alocar lista de funcionario aqui
            printf("A SENHA 0000 VOLTA PARA A TELA ANTERIOR\nInsira seu nome e sua senha nessa ordem:\n");
            setbuf(stdin, NULL);
            fgets(nome, 50, stdin);

            tam_s = strlen(nome);
            nome[tam_s - 1] = '\0';

            int i = 0;

            while(1)
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

            senha = atoi(senhaaux);  //essa função converte uma string em número inteiro, pois no código a senha é interpretada como int

            if(senha)
                saida = 1;

            break;

        //acessar como cliente
        case 3:
            //alocar lista de clientes aqui
            printf("A SENHA 0000 VOLTA PARA A TELA ANTERIOR\nInsira seu nome e sua senha nessa ordem:\n");
            setbuf(stdin, NULL);
            fgets(nome, 50, stdin);

            tam_s = strlen(nome);
            nome[tam_s - 1] = '\0';

            int j = 0;

            while(1)
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

            senha = atoi(senhaaux);

            if(senha)
                saida = 1;

            break;
        }
        system("cls");
    }
    while(!saida);

    while(!ext)
    {
        //imrpiem o primeiro menu efetivo do programa
        system("cls");
        menu_escolhas(esc_t, &esc_a);
        switch(esc_a)
        {
            system("cls");
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

        }
    }
}

void menu_gst(int tipo)
{
    printf("Escolha:\n");
    if(tipo == 3)
        printf("2)Acessar os seus gastos\n");

}


//==================================================================================================================================================================================================
void menu_escolhas(int tipo, int *retorno)
{
    //imprime as informacoes iniciais
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
            Mostrar_p(*l);
        else if(tipo == 2)
        {
            switch(escolha)
            {
            case 3:
                Inserir_Produtos_main(l);
                break;
            case 4:
                Remover_Produto_main(l);
            case 5:
                Modifica_Quantidade_main(l);
            }
        }
        system("pause");
    }

}

void Inserir_Produtos_main(Lista_p **l)
{
    int verif;
    int tam_s;
    Produto insere_p;

    setbuf(stdin, NULL);
    printf("Insira o nome do produto: ");
    fgets(insere_p.nome, 50, stdin);
    tam_s = strlen(insere_p.nome);
    insere_p.nome[tam_s - 1] = '\0';

    setbuf(stdin, NULL);
    printf("Insira o codigo do produto: ");
    fgets(insere_p.codigo, 10, stdin);
    tam_s = strlen(insere_p.codigo);
    insere_p.codigo[tam_s - 1] = '\0';

    setbuf(stdin, NULL);
    printf("Insira o tipo do produto: ");
    fgets(insere_p.tipo, 50, stdin);
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
    int verif;
    int tam_s;
    Produto insere_p;

    setbuf(stdin, NULL);
    printf("Insira o nome do produto: ");
    fgets(insere_p.nome, 50, stdin);
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

    int verif;
    int tam_s;
    Produto insere_p;

    setbuf(stdin, NULL);
    printf("Insira o nome do produto: ");
    fgets(insere_p.nome, 50, stdin);
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
    int verif;
    int tam_s;
    Produto insere_p;

    setbuf(stdin, NULL);
    printf("Insira o nome do produto: ");
    fgets(insere_p.nome, 50, stdin);
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
void menu_escolhas(int tipo, int *retorno)
{
    //imprime as informacoes iniciais
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
            Mostrar_p(*l);
        else if(tipo == 2)
        {
            switch(escolha)
            {
            case 3:
                Inserir_Produtos_main(l);
                break;
            case 4:
                Remover_Produto_main(l);
            case 5:
                Modifica_Quantidade_main(l);
            }
        }
        system("pause");
    }

}

void Inserir_Produtos_main(Lista_p **l)
{
    int verif;
    int tam_s;
    Produto insere_p;

    setbuf(stdin, NULL);
    printf("Insira o nome do produto: ");
    fgets(insere_p.nome, 50, stdin);
    tam_s = strlen(insere_p.nome);
    insere_p.nome[tam_s - 1] = '\0';

    setbuf(stdin, NULL);
    printf("Insira o codigo do produto: ");
    fgets(insere_p.codigo, 10, stdin);
    tam_s = strlen(insere_p.codigo);
    insere_p.codigo[tam_s - 1] = '\0';

    setbuf(stdin, NULL);
    printf("Insira o tipo do produto: ");
    fgets(insere_p.tipo, 50, stdin);
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
    int verif;
    int tam_s;
    Produto insere_p;

    setbuf(stdin, NULL);
    printf("Insira o nome do produto: ");
    fgets(insere_p.nome, 50, stdin);
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

    int verif;
    int tam_s;
    Produto insere_p;

    setbuf(stdin, NULL);
    printf("Insira o nome do produto: ");
    fgets(insere_p.nome, 50, stdin);
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
    int verif;
    int tam_s;
    Produto insere_p;

    setbuf(stdin, NULL);
    printf("Insira o nome do produto: ");
    fgets(insere_p.nome, 50, stdin);
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