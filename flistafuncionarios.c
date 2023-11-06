    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "listafuncionarios.h"

    typedef struct no_f
    {
        Funcionario valor;
        struct no_f *prox;
    }No_f;

    typedef struct lista_f
    {
        No_f *inicio;
    }Lista_f;

    Lista_f* Criar_f()
    {
        Lista_f *l = (Lista_f*) malloc(sizeof(Lista_f));
        if(l != NULL) l->inicio = NULL;
        return l;
    }

    int ListaVazia_f(Lista_f *l)
    {
        if(l == NULL) return 2;
        if(l->inicio == NULL) return 0;
        return 1;
    }


    int Inserir_inicio_f(Lista_f *l, Funcionario *it)
    {
        if(l == NULL) return 2;
        No_f* n = (No_f*) malloc(sizeof(No_f));

        n->valor = *it;
        n->prox = l->inicio;
        l->inicio = n;

        return 0;
    }

    int Remover_inicio_f(Lista_f *l)
    {
        if(l == NULL) return 2;
        if(ListaVazia_f(l) == 0) return 1;

        No_f* n = l->inicio;
        l->inicio = n->prox;
        free(n);
        return 0;
    }

    //===================================================================================================================================================
    void MostrarDadosPagamento(Lista_f *l)
    {
        if(l != NULL)
        {
            printf("| NOME | CPF | PAGAMENTO |\n");
            No_f *n = l->inicio;
            float a = 0;

            while(n != NULL)
            {
                printf("| %s | %s | %f |\n", n->valor.nome, n->valor.CPF, n->valor.pagamento);
                a += n->valor.pagamento;
                n = n->prox;
            }
            printf("Pagamento total ; %f\n", a);
        }
    }

    int MostraOcorrencia_f(Lista_f *l, Funcionario *it)
    {
        if(l == NULL) return 2;
        if(ListaVazia_f(l) == 0) return 1;

        No_f* n = l->inicio;
        int a;

        while(n != NULL)
        {
            a = strcmp(n->valor.CPF, it->CPF);
            if(a == 0)
                return 0;
            n = n->prox;
        }
        return 3;
    }

    int InsereFuncionario(Lista_f *l, Funcionario *it)
    {
        if(l == NULL) return 2;
        if(MostraOcorrencia_f(l, it) == 0) return 1;

        if(ListaVazia_f(l) == 0) return Inserir_inicio_f(l, it); //claro que nesse caso é bem mais simples

        No_f *insere = (No_f*) malloc(sizeof(No_f));
        No_f *percorre = l->inicio, *aux = NULL;
        int verif;

        insere->valor = *it;

        while(percorre != NULL)
        {
            verif = strcmp((insere->valor.nome), (it->nome)); //precisamos organizar a lista em ordem alfabetica

            if(verif < 0) //nesse caso ja o que percorre esta exatamente no da frente de onde desejamos colocar
                break;

            aux = percorre;
            percorre = percorre->prox; //essas duas linhas se explicam, somente o processo de movimentar os ponteiros péla lista;
        }

        if(aux == NULL) return Inserir_inicio_f(l, it); //Pode ser um nome tipo Aaron, nunca se sabe

        insere->prox = percorre;
        aux->prox = insere;//somente inserindo

        return 0;
    }

    int MudaSalarioFuncionario(Lista_f *l, Funcionario *it)
    {
        if(l == NULL) return 2;
        if(ListaVazia_f(l) == 0) return 1;

        No_f* n = l->inicio;
        int a;

        while(n != NULL)
        {
            a = strcmp((n->valor.CPF), it->CPF);
            if(a == 0)
            {
                n->valor.pagamento = it->pagamento;
                return 0;
            }
            n = n->prox;
        }
        return 1;
    }

    int MudaSalarioCargo(Lista_f *l, Funcionario *it)
    {
        if(l == NULL) return 2;
        if(ListaVazia_f(l) == 0) return 1;

        No_f* n = l->inicio;
        int a, verif = 0;

        while(n != NULL)
        {
            a = strcmp((n->valor.funcao), it->funcao);
            if(a == 0)
            {
                n->valor.pagamento = it->pagamento;
                verif = 1;
            }
            n = n->prox;
        }
        if(verif) return 0;

        return 1;
    }

    int MudaCargoFuncionario(Lista_f *l, Funcionario *it)
    {
        if(l == NULL) return 2;
        if(ListaVazia_f(l) == 0) return 1;

        No_f *percorre = l->inicio;

        while(percorre != NULL)
        {
            if((strcmp(percorre->valor.CPF, it->CPF)) == 0) break; //Chegou no funcionario desejado - Marcos

            percorre = percorre->prox;
        }

        if(percorre != NULL)
        {
            strcpy(percorre->valor.funcao, it->funcao); //modifica o cargo
            return 0;
        }
        return 1;
    }

    int RemoveFuncionario(Lista_f *l, Funcionario *it)
    {
        if(l == NULL) return 2;
        if(ListaVazia_f(l) == 0) return 1;

        No_f *n = l->inicio;
        No_f *aux = NULL;

        if(strcmp(it->CPF, n->valor.CPF) == 0) //verifica o primeiro funcionario (poderia ser verificado depois, mas prefiro assim - Marcos
            return Remover_inicio_f(l);

        while(n != NULL)
        {
            if(strcmp(it->CPF, n->valor.CPF) == 0) //Esse aqui somente procura o funcionario
            {
                break;
            }
            aux = n;
            n = n->prox;
        }

        if(n != NULL) //Se ele nao chegou no fim
        {
            aux->prox = n->prox;
            free(n);
            return 0;
        }

        return 1;

    }

    float GastoTotalFuncionarios(Lista_f *l){
        if(l == NULL) return -2;
        if(ListaVazia_f(l) == 0) return 0;

        No_f *no = l->inicio;
        float SalarioTot = 0;

        while(no != NULL){
            SalarioTot += no->valor.pagamento;
            no = no->prox;
        }

        return SalarioTot;
    }

    FILE *FLf_abrir(){
        FILE *p;

        p = fopen("funcionarios.txt", "r+"); //assume que o arquivo já existe

        if(p == NULL) {
            printf("Registro de funcionarios nao foi criado!\nCriando novo arquivo...\n");
            p = fopen("funcionarios.txt", "w");
            fclose(p);
            p = fopen("funcionarios.txt", "r+");
            if(p == NULL) {
                printf("Nao foi possivel acessar o registro de funcionarios.\n");
                return 0;
            } else return p;
        }

        return p;
    }

    int FLf_carregar(Lista_f *l, FILE *pf){
        if(pf == NULL) return 2;

        No_f *noLista = l->inicio;

        //Lista_f *aux = Criar_f();
        //No_f *noListaAux = aux->inicio;

        if((fscanf(pf, "%i %s %s %s %f\n", &noLista->valor.senha, &noLista->valor.CPF, &noLista->valor.nome, &noLista->valor.funcao, &noLista->valor.pagamento)) != 5) {
            printf("Nao foi detectado nenhum campo no arquivo (funcionarios), ou houve erro na hora da leitura, para carregar informacoes, primeiro salve alguma coisa no arquivo!\n");
            return 1;
        }

        while((fscanf(pf, "%i %s %s %s %f\n", &noLista->valor.senha, &noLista->valor.CPF, &noLista->valor.nome, &noLista->valor.funcao, &noLista->valor.pagamento)) == 5) {
            noLista = noLista ->prox;
        }

        return 0;
    }

    int FLf_salvar(Lista_f *l, FILE *pf){
        if(pf == NULL) return 2;
        if(l == NULL) return 1;

        FILE *temp;
        temp = fopen("temp_funcionarios.txt", "w");

        No_f *noLista = l->inicio;

        while(noLista != NULL) {
            fprintf(temp, "%i %s %s %s %f\n", noLista->valor.senha, noLista->valor.CPF, noLista->valor.nome, noLista->valor.funcao, noLista->valor.pagamento);
            noLista = noLista->prox;
        }

        fclose(temp);
        remove("funcionarios.txt");
        rename("temp_funcionarios.txt", "funcionarios.txt");

        return 0;
    }