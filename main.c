#include <stdio.h>
#include <stdlib.h>
#include <string.h>//vamos precisar da string.h para realizar comparacoes com os elementos no file.

typedef struct dados
{
    char CPF[12], Senha[7];//os dois esta com uma casa a mais por causa do fgets
}Dados;

int main()
{
    int esc1, ext = 0, endcod = 0;
    Dados* info = (Dados *) malloc(sizeof(Dados));

    //insercao de dados para entrar no sistema
    do
    {
        /*esse verifica qual opcao o funcionario deseja para o login
        (vai ser importante durante todo o codigo) entao nao reutilizar a variavel esc1*/
        do
        {
            printf("Escolha uma opcao para entrar no programa\n(1) - Cliente\n(2) - Funcionario\n(3) - Sair\n");
            scanf("%i", &esc1);

            if(esc1 < 1 || esc1 > 3)
            {
                printf("Escolha invalida.Por favor reensira-a\n");
            }
        }while(esc1 < 1 || esc1 > 3) ;

        switch(esc1)
        {
        case 1:
            do
            {
                //aqui é onde aloca a lista com os clientes.
                printf("INSIRA A SENHA 000000 PARA RETORNAR A TELA ANTERIOR\n");
                printf("Insira seu CPF: ");
                fflush(stdin);
                fgets(info->CPF, 12, stdin);
                printf("Insira sua senha: ");
                fflush(stdin);
                fgets(info->Senha, 7, stdin);

                if((strcmp((info ->Senha), "000000")) == 0)
                {
                    break;
                }
                else
                {
                    //passar verificando cada elemento da lista, para verificar se de fato esse usuario existe e fazer ext = 1 se sim;
                    //para facilitar fazer a funcao de busca retornar os mesmos valores e fazer duas funcoes de busca uma de CPF e uma de Senha
                    
                    ext = 1;
                }
            }while(!ext);
            break;
        case 2:
            do
            {
                //aqui é onde aloca a lista com os clientes.
                printf("INSIRA A SENHA 000000 PARA RETORNAR A TELA ANTERIOR\n");
                printf("Insira seu CPF: ");
                fflush(stdin);
                fgets(info->CPF, 12, stdin);
                printf("Insira sua senha: ");
                fflush(stdin);
                fgets(info->Senha, 7, stdin);

                if((strcmp((info ->Senha), "000000")) == 0)
                {
                    break;
                }
                else
                {
                    //passar verificando cada elemento da lista, para verificar se de fato esse usuario existe e fazer ext = 1 se sim;
                    ext = 1;
                }
            }while(!ext);
            break;
        case 3:
            endcod = 1;
            ext = 1;
        }
    }while(!ext);

}