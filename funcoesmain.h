#ifndef FUNCOESMAIN_H_INCLUDED
#define FUNCOESMAIN_H_INCLUDED

int menu_entrada(Lista_f **func, Lista_c **clien, int *tipo,  Cliente *pessoa);
int entrada_funcionario(Lista_f **func);
int entrada_cliente(Lista_c **clien,  Cliente *pessoa);
int logar_cliente(Lista_c **clien, Cliente *pessoa);
int cadastrar_cliente(Lista_c **clien, Cliente *pessoa);
void menu_escolhas(int tipo, int *retorno);


//A PARTE DO ESTOQUE
void menu_estoque(int tipo, Lista_p **l);
void Inserir_Produtos_main(Lista_p **l);
void Remover_Produto_main(Lista_p **l);
void Modifica_Quantidade_main(Lista_p **l);
void Modifica_Preco_main(Lista_p **l);

//CONTROLE DE GASTOS
void FluxoDeCaixa(Lista_c *clien, Lista_p *prod, Lista_f *func);
void AcessaGastos(int tipo, Lista_c *clien, Lista_p *prod, Lista_f *func, Cliente *pessoa);

//RESERVA DE ALIMENTOS
void Menu_Reserva(Lista_c *clien, Lista_p *prod, Cliente *pessoa);
void Reservar_Alimentos(Lista_c *clien, Lista_p *prod, Cliente *pessoa);
void Insere_carro(Lista_c *clien, Lista_p *prod, Cliente *pessoa);
void Retira_carro(Lista_c *clien, Lista_p *prod, Cliente *pessoa);


//INSERCAO
void Cadastro(Lista_f *func, Lista_c *clien);
void Insere_Funcionario_main(Lista_f *func);
void Muda_Cargo_main(Lista_f *func);
void Modifica_Salario_Func_main(Lista_f *func);
void Modifica_Salario_Cargo_main(Lista_f *func);
void Remove_Funcionario_main(Lista_f *func);

int VerificaCPF(char *str, int tam);

//FILE
int fecharF(FILE *p);
#endif // FUNCOESMAIN_H_INCLUDED
