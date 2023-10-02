#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void menu_c();
void menu_f();

int main()
{
    char nome[50];
    int senha;
    int ext = 0, esc_t, saida = 0, tam_s, esc_a;

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
        else if((esc_t == 1) && (esc_a > 4)) printf("Escolha invalida\n");

        switch(esc_a)
        {
        case 1:
            ext = 1;
            break;

        }
    }
    return 0;
}

void menu_c()
{
    printf("Escolha:\n1)Sair\n2)Acessar o estoque\n3)Acessar seus gastos mensais\n4)Comprar produtos\n");
}
void menu_f()
{
    printf("Escolha:\n1)Sair\n2)Acessar o estoque\n3)Acessar os gastos mensais do mercado\n4)Registrar compras\n5)Cadastrar pessoas\n");
}