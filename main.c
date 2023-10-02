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
    Lista_p* prod;
    char nome[50];
    int senha;
    int ext = 0, esc_t, saida = 0, tam_s, esc_a, esc_in;

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
    }while(!saida);

    while(!ext)
    {
        if(esc_t == 2) menu_f();
        else menu_c();
        scanf("%i", &esc_a);

        if(esc_a < 0) printf("Escolha invalida\n");
        else if((esc_t == 2) && (esc_a > 5)) printf("Escolha invalida\n");
        else if((esc_t == 3) && (esc_a > 4)) printf("Escolha invalida\n");

        switch(esc_a)
        {
        case 1:
            ext = 1;
            break;
        case 2:
            menu_stq(esc_t);
            scanf("%i", &esc_in);

            if(esc_in < 0) printf("Escolha invalida\n");
            else if((esc_t == 2) && (esc_in >3)) printf("Escolha invalida");
            else if((esc_t == 3) && (esc_in >2)) printf("Escolha invalida");

            if(esc_in == 1) break;
            else if(esc_in == 2) Mostrar_p(prod);
           /* else if((esc_in == 3) && (esc_t == 2))
            {

            }*/
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
    printf("Escolha:\n1)Sair\n2)Ver o estoque\n");
    if(tipo == 1) printf("3)Modificar o estoque\n");
}
