#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaclientes.h"
#include "listafuncionarios.h"
#include "listaprodutos.h"

void menu_c();
void menu_f();
void menu_stq(int tipo);

int main()
{
    Lista_p* prod = Criar_p();
    Produto insere_p;
    char nome[50];
    int senha;
    int ext = 0, esc_t, saida = 0, tam_s, esc_a, esc_in, verif;

    //entrar como funcionario ou cliente
    do
    {
        printf("Escolha:\n1)Sair\n2)Entrar como funcionario\n3)Entrar como cliente\n");
        scanf("%i", &esc_t);

        if((esc_t < 0) || (esc_t > 3)) printf("Escolha invalida\n");

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

            scanf("%i", &senha);
            if(senha) saida = 1;

            break;

        //acessar como cliente
        case 3:
            //alocar lista de clientes aqui
            printf("A SENHA 0000 VOLTA PARA A TELA ANTERIOR\nInsira seu nome e sua senha nessa ordem:\n");
            setbuf(stdin, NULL);
            fgets(nome, 50, stdin);

            tam_s = strlen(nome);
            nome[tam_s - 1] = '\0';

            scanf("%i", &senha);
            if(senha) saida = 1;

            break;
        }
        system("cls");
    }
    while(!saida);

    while(!ext)
    {
        //imprime as informacoes iniciais
        if(esc_t == 2) menu_f();
        else menu_c();
        scanf("%i", &esc_a);

        if(esc_a < 0) printf("Escolha invalida\n");
        else if((esc_t == 2) && (esc_a > 5)) printf("Escolha invalida\n");
        else if((esc_t == 3) && (esc_a > 4)) printf("Escolha invalida\n");

        system("cls");
        switch(esc_a)
        {
        //sai do sistema
        case 1:
            ext = 1;
            break;
        case 2:
            //acessa o estoque
            do
            {
                system("pause");
                system("cls");
                menu_stq(esc_t);
                scanf("%i", &esc_in);

                if(esc_in < 0) printf("Escolha invalida\n");
                else if((esc_t == 2) && (esc_in >3)) printf("Escolha invalida");
                else if((esc_t == 3) && (esc_in >4)) printf("Escolha invalida");

                system("cls");
                if(esc_in == 2) Mostrar_p(prod);
                else if(esc_t == 2)
                {
                    switch(esc_in)
                    {
                    case 3:
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

                        verif = InsereProduto(prod, insere_p);
                        if(verif == 0) printf("Produto inserido\n");
                        else if(verif == 1) printf("O produto ja existe\n");
                        else printf("Lista nao alocada\n");

                        break;
                    case 4:
                        setbuf(stdin, NULL);
                        printf("Insira o nome do produto: ");
                        fgets(insere_p.nome, 50, stdin);
                        tam_s = strlen(insere_p.nome);
                        insere_p.nome[tam_s - 1] = '\0';

                        verif = RemoveProduto(prod, insere_p);
                        if(verif == 0) printf("Feito\n");
                        else if(verif == 2) printf("Lista nao alocada\n");
                        else if(verif == 1) printf("Lista vazia\n");
                        else printf("Produto nao encontrado\n");
                        break;
                    case 5:
                        setbuf(stdin, NULL);
                        printf("Insira o nome do produto: ");
                        fgets(insere_p.nome, 50, stdin);
                        tam_s = strlen(insere_p.nome);
                        insere_p.nome[tam_s - 1] = '\0';

                        printf("Insira a nova quantidade do produto: ");
                        scanf("%i", &insere_p.quantidade);

                        verif = ModificarQuantidade(prod, insere_p);
                        if(verif == 0) printf("Feito\n");
                        else if(verif == 2) printf("Lista nao alocada\n");
                        else if(verif == 1) printf("Lista vazia\n");
                        else printf("Produto nao encontrado\n");
                        break;
                    case 6:
                        setbuf(stdin, NULL);
                        printf("Insira o nome do produto: ");
                        fgets(insere_p.nome, 50, stdin);
                        tam_s = strlen(insere_p.nome);
                        insere_p.nome[tam_s - 1] = '\0';

                        printf("Insira o novo preco do produto: ");
                        scanf("%f", &insere_p.preco);

                        verif = ModificarPreco(prod, insere_p);
                        if(verif == 0) printf("Feito\n");
                        else if(verif == 2) printf("Lista nao alocada\n");
                        else if(verif == 1) printf("Lista vazia\n");
                        else printf("Produto nao encontrado\n");
                        break;
                    }
                }
            }
            while(esc_in != 1);
            break;
        case 3:
            break;

        }
    }
}

void menu_c()
{
    printf("Escolha:\n1)Sair\n2)Acessar o estoque\n3)Acessar seus gastos mensais\n4)Comprar produtos\n");
}
void menu_f()
{
    printf("Escolha:\n1)Sair\n2)Acessar o estoque\n3)Acessar os gastos mensais do mercado\n4)Registrar compras\n5)Cadastrar pessoas\n");
}

void menu_stq(int tipo)
{
    printf("Escolha:\n1)Voltar para a tela anterior\n2)Ver o estoque\n");
    if(tipo == 2) printf("3)Inserir Produto\n4)Remover Produto\n5)Modificar a quantidade de um produto\n6)Modificar o preco de um produto\n");
}

void menu_gst(int tipo)
{
    printf("Escolha:\n");
    if(tipo == 3) printf("2)Acessar os seus gastos\n");
}
