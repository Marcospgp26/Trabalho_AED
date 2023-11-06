#include <stdio.h>
#include <stdlib.h>
#include "listaclientes.h"
#include "listafuncionarios.h"
#include "listaprodutos.h"
#include "funcoesmain.h"


int main()
{
    FILE *arqCL = FLc_abrir();
    FILE *arqFNC = FLf_abrir();
    FILE *arqESTQ = FLp_abrir();
    Lista_p* prod = Criar_p();
    Lista_c* clien = Criar_c();
    Lista_f* func = Criar_f();
    Cliente* pessoa = NULL;
    int ext = 0, esc_t, esc_a;

    ext = menu_entrada(&func, &clien, &esc_t, pessoa);

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
            AcessaGastos(esc_t,clien,prod,func);
            break;
        }
        if((esc_t == 2) && (esc_a == 4))
        {
            Cadastro(func, clien);
        }
        if((esc_t == 3) && (esc_a == 4))
        {
            Menu_Caixa(clien, prod, pessoa);
        }
    }
    FLp_salvar(prod, arqESTQ);
    FLc_salvar(clien, arqCL);
    FLf_salvar(func, arqFNC);
    fecharF(arqESTQ);
    fecharF(arqCL);
    fecharF(arqFNC);
    
    printf("\n");
    system("pause");
    return 0;
}
