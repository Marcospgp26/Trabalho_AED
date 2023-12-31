#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "listaclientes.h"
#include "listafuncionarios.h"
#include "listaprodutos.h"
#include "funcoesmain.h"

#define ENTER 13
#define TAB 9
#define BKSP 8
#define SPACE 32    //codigos ASCII que serao uteis ao decorrer do código

int menu_entrada(Lista_f **func, Lista_c **clien, int *tipo,  Cliente *pessoa) //Consiste na parte em que se escolhe o tipo de entrada
{
    int esc_t;
    int saida_completa = 0, saida_menu= 0;

    do
    {
        system("cls");
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
            saida_menu = entrada_cliente(clien, pessoa);
            break;
        }
        system("pause");
    }
    while(!saida_menu);
    *tipo = esc_t;
    return saida_completa;
}

int entrada_funcionario(Lista_f **func) //A parte de entrada de funcionario
{

    printf("*****ENTRAR COMO FUNCIONARIO*****\n\n");

    Funcionario *entrada = (Funcionario *) malloc (sizeof(Funcionario));

    char ch, senhaaux[5];

    while(1){
        printf("INSIRA A SENHA 0000 VOLTA PARA VOLTAR A TELA ANTERIOR:\n");
        printf("CPF: ");
        setbuf(stdin, NULL);

        int k = 0;

        while(k < 11)
        {
            ch = getch();
            if(ch == ENTER)
            {
                entrada->CPF[k] = '\0';
                break;
            }
            else if(ch == BKSP)
            {
                if(k > 0)
                {
                    k--;
                    printf("\b \b");
                }
            }
            else if(ch == TAB || ch == SPACE)
            {
                continue;
            }
            else{
                entrada->CPF[k] = ch;
                k++;
                printf("%c",ch);
            }
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
        printf("\n");

        entrada->senha = atoi(senhaaux);  //essa função converte uma string em número inteiro, pois no código a senha é interpretada como int
        entrada->CPF[11] = '\0';
        int saida = Buscar_Item_Chave_f(*func,*entrada); //procura o funcionario na lista de funcionarios

        if(saida == 0) return 1;

        else{
            if(entrada->senha == 0) return 0;
            printf("Dados incorretos/Nao foram encontrados\n");
        }
    }    
}

int entrada_cliente(Lista_c **clien, Cliente *pessoa)  //A opcao de escolhas de entrada para clientes
{
    int esc, verif, saida, ext = 0;
    do
    {
        system("cls");
        printf("Escolha:\n1)Voltar\n2)Logar\n3)Cadastrar\n");
        scanf("%i", &esc);

        if((esc < 0) || (esc > 3)) printf("Escolha invalida, por favor, reensira-a\n");
        switch(esc)
        {
            case 1:
            verif = 0;
            ext = 1;
            break;
            return 0;
            case 2:
            verif = logar_cliente(clien, pessoa);
            break;
            case 3:
            verif = cadastrar_cliente(clien, pessoa);
            break;

        }
        if(ext) break;
    }while(!verif);
    
    return verif;
}

int logar_cliente(Lista_c **clien, Cliente *pessoa) //Acredita que o cliente ja exista, por isso loga com o cliente
{
    printf("*****LOGAR COMO CLIENTE*****\n\n");

    Cliente *entrada = (Cliente *) malloc (sizeof(Cliente));

    char ch, senhaaux[5];

    while(1){
        printf("INSIRA A SENHA 0000 VOLTA PARA VOLTAR A TELA ANTERIOR:\n");
        printf("CPF: ");
        setbuf(stdin, NULL);

        int k = 0;

        while(k < 11)
        {
            ch = getch();
            if(ch == ENTER)
            {
                entrada->CPF[k] = '\0';
                break;
            }
            else if(ch == BKSP)
            {
                if(k > 0)
                {
                    k--;
                    printf("\b \b");
                }
            }
            else if(ch == TAB || ch == SPACE)
            {
                continue;
            }
            else{
                entrada->CPF[k] = ch;
                k++;
                printf("%c",ch);
            }
        } //loop para entrada do CPF do cliente




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
        printf("\n");

        entrada->senha = atoi(senhaaux);  //essa função converte uma string em número inteiro, pois no código a senha é interpretada como int
        entrada->CPF[11] = '\0';
        int saida = Buscar_Item_Chave_c(*clien,*entrada);
        
        pessoa->carrinho = entrada->carrinho;
        strcpy(pessoa->CPF,entrada->CPF);
        pessoa->gasto = entrada->gasto;
        pessoa->historico = entrada->historico;
        pessoa->senha = entrada->senha;
        
        if(saida == 0) return 1;
        else{
            if(entrada->senha == 0) return 0;
            printf("Dados incorretos/Nao foram encontrados\n");
        }
    }
}

int cadastrar_cliente(Lista_c **clien, Cliente *pessoa) //Cadastro de novos clientes
{
    Cliente *it = (Cliente *) malloc(sizeof(Cliente));
    int tam_s, aprova, i =0;
    char ch, senhaaux[5];

    printf("*****CADASTRO DE CLIENTE*****\n\n");
    //Processo basico de insercao de dados

    do
    {

        aprova = 0;
        setbuf(stdin, NULL);
        printf("CPF: ");
        int k = 0;

        while(k < 11)
        {
            ch = getch();
            if(ch == ENTER)
            {
                it->CPF[k] = '\0';
                break;
            }
            else if(ch == BKSP)
            {
                if(k > 0)
                {
                    k--;
                    printf("\b \b");
                }
            }
            else if(ch == TAB || ch == SPACE)
            {
                continue;
            }
            else
            {
                it->CPF[k] = ch;
                k++;
                printf("%c",ch);
            }
        }
        printf("\n");

        it->CPF[11] = '\0';
        tam_s = strlen(it->CPF);
        if(tam_s != 11) aprova = 1;
        else if(VerificaCPF(it->CPF, tam_s)) aprova = 1; //O CPF eh algo que por si so eh mto complexo, entao vamos usar uma funcao para verifica-lo (se voce esta testando essa parte isso pode ser um pouco chato, uma dica, use seu proprio CPF ou de alguem que voce conheca)

        if(aprova) printf("\nCPF Invalido, por favor reensira- o\n\n");

    }
    while(aprova);

    //aqui da para colocar os asteriscos dnv se quiser, podemos colocar toda a p-arte dos asteriscos numa funcao separada e reutilizar ela
    printf("Senha: ");
    do
    {
        while(i < 4) //maximo de 4 numeros por senha
        {
            setbuf(stdin, NULL);
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
        printf("\n");

        it->senha = atoi(senhaaux);

        if(it->senha == 0) printf("Senha invalida\n");
    }
    while(it->senha == 0);

    pessoa->historico = NULL;
    pessoa->gasto = 0;
    pessoa->carrinho = NULL;

    pessoa->senha = it->senha;
    strcpy(pessoa->CPF,it->CPF);

    aprova = InsereCliente(*clien, *it); //Basciamente essa funcao verifica se o funcionario ja existe pelo CPF e coloca ele em ordem alfabetica - Marcos
    
    if(aprova == 2) printf("Lista nao alocada\n");
    else if(aprova == 1)
    {
        printf("O cliente ja existe\n");
        return 0;
    }
    else
    {
        printf("Cliente adicionado\n");
        return 1;
    }
}

void menu_escolhas(int tipo, int *retorno) //Menu principal do programa
{
    // imprime as informações iniciais
    printf("*****MENU DO MERCADO BIG BOM*****\n\n");
    if (tipo == 2)
        printf("Escolha:\n1)Sair\n2)Acessar o estoque\n3)Acessar o fluxo de caixa do mercado\n4)Modificar dados de funcionarios\n");
    else
        printf("Escolha:\n1)Sair\n2)Acessar o estoque\n3)Acessar seus gastos mensais\n4)Comprar produtos\n");

    scanf(" %i", retorno);

    if (*retorno < 0)
        printf("Escolha inválida\n");
    else if ((tipo == 2) && (*retorno > 5))
        printf("Escolha inválida\n");
    else if ((tipo == 3) && (*retorno > 4))
        printf("Escolha inválida\n");
}



//PARTE DE ESTOQUE
void menu_estoque(int tipo, Lista_p **l) //Esse menu serve para o acesso das funcoes de estoque
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

void Inserir_Produtos_main(Lista_p **l) //Essa funcao insere um novo produto na lista de estoque
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

void Remover_Produto_main(Lista_p **l) //Essa funcao identifica um produto e remove ele da lista de estoque
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

void Modifica_Quantidade_main(Lista_p **l) //Essa funcao modifica a quantidade existente de um produto no estoque
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

void Modifica_Preco_main(Lista_p **l) //Essa funcao modifica o preco da venda de um estoque
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

//PARTE DE ECONOMIA
void FluxoDeCaixa(Lista_c *clien, Lista_p *prod, Lista_f *func) //"Fluxo de Caixa" refere-se a quantidade de lucro de um mercado, essa funcao calcula isso
{
    float gastoFunc = GastoTotalFuncionarios(func), gastoClien = GastoTotalClientes(clien), gastoProd = GastoTotalProdutos(prod);
    float saldo = gastoClien - gastoFunc - gastoProd;

    system("cls");
    printf("*****FLUXO DE CAIXA*****\n");
    printf("+ RS%.2f - Receita\n",gastoClien);
    printf("- RS%.2f - Salarios dos funcionarios\n",gastoFunc);
    printf("- RS%.2f - Custo do estoque\n",gastoProd);
    printf("Saldo: RS%.2f\n",saldo);

    system("pause");
}

void AcessaGastos(int tipo, Lista_c *clien, Lista_p *prod, Lista_f *func, Cliente *pessoa) //Funcao para guiar os diferentes tipos de entrada até uma aba de economia
{
    switch(tipo){
        case 3:
            MostraHistorico(clien, pessoa);
            break;
        case 2:
            FluxoDeCaixa(clien,prod,func);
            break;
    }
}


//PARTE DE RESERVA
void Menu_Reserva(Lista_c *clien, Lista_p *prod, Cliente *pessoa)
{
    int esc;
    system("cls");
    while(esc != 1)
    {
        system("cls");
        printf("*****RESERVAR PRODUTOS *****\n\n");

        printf("Escolha uma opcao\n1)Sair\n");
        printf("2)Reservar produtos\n");

        scanf("%i", &esc);
        if(esc == 2) Reserva_Menu(clien, prod, pessoa);
    }

}

void Reserva_Menu(Lista_c *clien, Lista_p *prod, Cliente *pessoa)
{
    int esc;

    do
    {
        system("cls");
        printf("*****MENU RESERVAR*****\n");
        printf("Escolha:\n1)Sair\n2)Ver o estoque\n3)Ver o carrinho\n4)Inserir Produto\n5)Retirar Produto\n");
        scanf("%i", &esc);

        system("cls");
        switch(esc)
        {
            case 2:
            Mostrar_p(prod);
            system("pause");
            break;
            case 3:
            mostracarrinho(clien, pessoa);
            break;
            case 4:
            Reservar(clien, prod, pessoa);
            break;
            case 5:
            Retirar(clien, prod, pessoa);
        }
    }while(esc != 1);

    apagacarrinho(clien, pessoa);
    printf("OBRIGADO POR COMPRAR NO MERCADO BIG BOM!\n");
    system("pause");
}

void Reservar(Lista_c *clien, Lista_p *prod, Cliente *pessoa)
{
    int tam_s, verif, verif2, code;
    Produto insere;

    printf("*****INSERIR NO CARRINHO*****\n");
    setbuf(stdin, NULL);
    printf("Insira o codigo do produto: ");
    scanf("%d",&code);
    itoa(code,insere.codigo,10);
    tam_s = strlen(insere.codigo);
    

    printf("Insira quantas quantidades voce deseja comprar: ");
    scanf("%i", &insere.quantidade);

    verif = Reduz_X(prod, &insere);
    if(verif == 3) printf("Valor excedeu o estoque\n");
    else if(verif == 2) printf("Sem estoque\n");
    else if(verif == 1) printf("Produto nao encontrado\n");
    else
    {
        verif2 = inserecarrinho(clien, pessoa, &insere);
        if(verif2 == 0) printf("Produto inserido\n");
        if(verif2 == 1) printf("Produto nao encontrado\n");
        if(verif2 == 2) printf("Lista inexistente\n");
    }
}

void Retirar(Lista_c *clien, Lista_p *prod, Cliente *pessoa)
{
    int tam_s, verif, verif2;
    Produto insere;

    printf("*****RETIRAR DO CARRINHO*****\n");

    setbuf(stdin, NULL);
    printf("Insira o codigo do produto: ");
    fgets(insere.codigo, 10, stdin);
    tam_s = strlen(insere.codigo);
    insere.codigo[tam_s - 1] = '\0';

    printf("Insira quantas quantidades unidades voce deseja retirar: ");
    scanf("%i", &insere.quantidade);

    verif = removecarrinho(clien, pessoa, &insere);
    if(verif == 4) printf("Nao existe carrinho\n");
    else if(verif == 3) printf("Retirou uma quantidade excessiva\n");
    else if(verif == 2) printf("Nao existe lista de clientes\n");
    else if(verif == 1) printf("Produto nao encontrado\n");
    else
    {
        Aumenta_X(prod, &insere);
    }
}

//PARTE DE CADASTRO
void Cadastro(Lista_f *func, Lista_c *clien) //Esse aqui na verdade é um menu, mostrando as diversas posibilidades de entradas de modificacao/insercao de funcionarios
{ 
    system("cls");
    printf("*****CADASTRAR FUNCIONARIOS E/OU CLIENTES NO SISTEMA*****\n\n");
    int esc = 0;
    do
    {
        printf("Escolha:\n1)Sair\n2)Inserir funcionario\n3)Modificar cargo de funcionario\n4)Modificar salario de funcionario\n5)Modificar salario de um cargo\n6)Remover funcionario\n");
        scanf("%i", &esc);

        if((esc < 1) || (esc > 6)) printf("Escolha invalida\n");

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
            break;
        case 5:
            Modifica_Salario_Cargo_main(func);
            break;
        case 6:
            Remove_Funcionario_main(func);
            break;

        }
    }
    while(esc != 1);
}

void Insere_Funcionario_main(Lista_f *func)  //Nesse caso considere que o gerente esta cadastrando um funcionario
{
    Funcionario it;
    int tam_s, aprova, i =0;
    char ch, senhaaux[5];

    printf("*****CADASTRAR FUNCIONARIOS NO SISTEMA*****\n\n");
    //Processo basico de insercao de dados
    setbuf(stdin, NULL);
    printf("Nome: ");
    fgets(it.nome, 51, stdin);
    it.nome[strlen(it.nome) - 1] = it.nome[strlen(it.nome)];

    do
    {

        aprova = 0;
        setbuf(stdin, NULL);
        printf("CPF: ");
        int k = 0;

        while(k < 11)
        {
            ch = getch();
            if(ch == ENTER)
            {
                it.CPF[k] = '\0';
                break;
            }
            else if(ch == BKSP)
            {
                if(k > 0)
                {
                    k--;
                    printf("\b \b");
                }
            }
            else if(ch == TAB || ch == SPACE)
            {
                continue;
            }
            else
            {
                it.CPF[k] = ch;
                k++;
                printf("%c",ch);
            }
        }
        printf("\n");

        it.CPF[11] = '\0';
        tam_s = strlen(it.CPF);
        if(tam_s != 11) aprova = 1;
        else if(VerificaCPF(it.CPF, tam_s)) aprova = 1; //O CPF eh algo que por si so eh mto complexo, entao vamos usar uma funcao para verifica-lo (se voce esta testando essa parte isso pode ser um pouco chato, uma dica, use seu proprio CPF ou de alguem que voce conheca)

        if(aprova) printf("\nCPF Invalido, por favor reensira- o\n\n");

    }
    while(aprova);

    setbuf(stdin, NULL);
    printf("Cargo: ");
    fgets(it.funcao, 50, stdin);
    it.funcao[strlen(it.funcao) - 1] = it.funcao[strlen(it.funcao)];

    //aqui da para colocar os asteriscos dnv se quiser, podemos colocar toda a p-arte dos asteriscos numa funcao separada e reutilizar ela
    printf("Senha: ");
    do
    {
        while(i < 4) //maximo de 4 numeros por senha
        {
            setbuf(stdin, NULL);
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
        printf("\n");

        it.senha = atoi(senhaaux);

        if(it.senha == 0) printf("Senha invalida\n");
    }
    while(it.senha == 0);

    printf("Pagamento: ");
    scanf("%f", &it.pagamento);

    aprova = InsereFuncionario(func, &it); //Basciamente essa funcao verifica se o funcionario ja existe pelo CPF e coloca ele em ordem alfabetica - Marcos
    if(aprova == 2) printf("Lista nao alocada\n");
    else if(aprova == 1) printf("O funcionario ja existe\n");
    else printf("Funcionario adicionado\n");

}

void Muda_Cargo_main(Lista_f *func) //Essa funcao pega o cargo e muda ela
{
    Funcionario it;
    int verif;
    char ch;
    int k = 0;

    printf("*****MUDAR CARGO DE UM FUNCIONARIO*****\n\n");
    do
    {
        setbuf(stdin, NULL);
        printf("Insira o CPF do funcionario: ");
        //Aqui voce insere o CPF para encontrar o funcionario
        while(k < 11)
        {
            ch = getch();
            if(ch == ENTER)
            {
                it.CPF[k] = '\0';
                break;
            }
            else if(ch == BKSP)
            {
                if(k > 0)
                {
                    k--;
                    printf("\b \b");
                }
            }
            else if(ch == TAB || ch == SPACE)
            {
                continue;
            }
            else
            {
                it.CPF[k] = ch;
                k++;
                printf("%c",ch);
            }
        }
        if(strlen(it.CPF) != 11) printf("\nCPF invalido\n");

    }
    while(strlen(it.CPF) != 11);  //Verifica se o CPF foi devidamente digitado

    setbuf(stdin, NULL);
    printf("Insira o novo cargo do funcionario: ");
    fgets(it.funcao, 50, stdin); //Insere o novo cargo
    it.funcao[strlen(it.funcao) - 1] =  it.funcao[strlen(it.funcao)];

    verif = MudaCargoFuncionario(func, &it); //Tenta mudar a situacao do funcionario

    if(verif == 2) printf("Lista nao alocada\n");
    else if(verif == 1) printf("Funcionario nao encontrado, impossivel realizar o procedimento\n");
    else printf("Cargo modificado!\n");
}

void Modifica_Salario_Func_main(Lista_f *func) //Essa funcao modifica o salario de somente um funcionario
{
    Funcionario it;
    int verif, aprova, tam_s;

    printf("*****MUDAR SALARIO DE UM FUNCIONARIO*****\n\n");

    do
    {

        aprova = 0;
        setbuf(stdin, NULL);
        printf("Insira o CPF: ");
        int k = 0;
        char ch;

        while(k < 11)
        {
            ch = getch();
            if(ch == ENTER)
            {
                it.CPF[k] = '\0';
                break;
            }
            else if(ch == BKSP)
            {
                if(k > 0)
                {
                    k--;
                    printf("\b \b");
                }
            }
            else if(ch == TAB || ch == SPACE)
            {
                continue;
            }
            else
            {
                it.CPF[k] = ch;
                k++;
                printf("%c",ch);
            }
        }
        printf("\n");

        it.CPF[11] = '\0';
        tam_s = strlen(it.CPF);
        if(tam_s != 11) aprova = 1;
        else if(VerificaCPF(it.CPF, tam_s)) aprova = 1; //O CPF eh algo que por si so eh mto complexo, entao vamos usar uma funcao para verifica-lo (se voce esta testando essa parte isso pode ser um pouco chato, uma dica, use seu proprio CPF ou de alguem que voce conheca)

        if(aprova) printf("\nCPF Invalido, por favor reensira- o\n\n");

    }
    while(aprova);

    printf("Insira o novo salario do funcionario: ");
    scanf("%f", &it.pagamento);

    verif = MudaSalarioFuncionario(func, &it);

    if(verif == 2) printf("Lista nao alocada\n");
    else if(verif == 1) printf("Funcionario nao encontrado\n");
    else printf("Salario modificado\n");

}

void Modifica_Salario_Cargo_main(Lista_f *func) //Essa funcao modifica um salario de um cargo em especifico
{
    Funcionario it;
    int verif;

    printf("*****MUDAR SALARIO DE UM CARGO*****\n\n");

    printf("Insira o cargo: ");
    setbuf(stdin, NULL);
    fgets(it.funcao, 50, stdin);
    it.funcao[strlen(it.funcao) - 1] = it.funcao[strlen(it.funcao)];

    printf("Insira o novo salario: ");
    scanf("%f", &it.pagamento);

    verif = MudaSalarioCargo(func, &it);

    if(verif == 0) printf("Salario modificado\n");
    else if(verif == 2) printf("Sem lista\n");
    else printf("Cargo nao encontrado\n");
}

void Remove_Funcionario_main(Lista_f *func) //Essa funcao remove um funcionario da lista de funcionarios
{
    Funcionario it;
    int verif, aprova, tam_s;

    printf("*****REMOVER UM FUNCIONARIO*****\n\n");

    do
    {

        aprova = 0;
        setbuf(stdin, NULL);
        printf("Insira o CPF: ");
        int k = 0;
        char ch;

        while(k < 11)
        {
            ch = getch();
            if(ch == ENTER)
            {
                it.CPF[k] = '\0';
                break;
            }
            else if(ch == BKSP)
            {
                if(k > 0)
                {
                    k--;
                    printf("\b \b");
                }
            }
            else if(ch == TAB || ch == SPACE)
            {
                continue;
            }
            else
            {
                it.CPF[k] = ch;
                k++;
                printf("%c",ch);
            }
        }
        printf("\n");

        it.CPF[11] = '\0';
        tam_s = strlen(it.CPF);
        if(tam_s != 11) aprova = 1;
        else if(VerificaCPF(it.CPF, tam_s)) aprova = 1; //O CPF eh algo que por si so eh mto complexo, entao vamos usar uma funcao para verifica-lo (se voce esta testando essa parte isso pode ser um pouco chato, uma dica, use seu proprio CPF ou de alguem que voce conheca)
        //Tecnicamente essa funcao de verificar o CPF nao he necessaria aqui, mas como aviso eh algo muito bom;
        if(aprova) printf("\nCPF Invalido, por favor reensira- o\n\n");

    }
    while(aprova);

    verif = RemoveFuncionario(func, &it); //Procura o funcionario e depois remover ele

    if(verif == 2) printf("Sem Lista\n");
    else if(verif == 1) printf("Funcionario nao encontrado\n");
    else printf("Funcionario Removido\n");


}


//FUNCAO DE VERIFICAR CPF
int VerificaCPF(char *str, int tam) //Esa funcao verifica o CPF para validar na entrada
{
    int i, numeros[11], DV1 = 0, DV2 = 0;
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


//FUNCAO DE FILE
int fecharF(FILE *p){
        if(p == NULL) return 1;
    
        fclose(p);
        free(p);
        p = NULL;

        return 0;
    }
