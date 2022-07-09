#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>
#include <time.h>
            //definicoes dos vetores da struct
#define T_BUFFER 512
#define T_NOME 80
#define T_CPF 16
#define T_VACINA 100
#define T_DATA 15

#define Q_MAXIMO_VACINADOS 200

struct registro_vacinado {
    char nome[T_NOME];
    char cpf[T_CPF];
    char vacina[T_VACINA];
    char data[T_DATA];
    int lote;
    int cod;
};

void
msg_pausa(char *msg) // um void de pause
{
    char buffer[T_BUFFER];
    if (msg != NULL) {
        printf("%s\n", msg);
    }
    printf("Pressione enter para continuar!\n");
    fgets(buffer, T_BUFFER, stdin);
}

void
barra_simples(int tamanho, char chr) //aqui um void de barra para o menu, nada demais
{
    int contador;
    for (contador = 0; contador < tamanho; contador++)
        putchar(chr);
    putchar('\n');
}

int
menu_principal(void)
{
    char buffer[T_BUFFER] = {'\0'};
    int opcao;
    do {
        system("cls");
        barra_simples(20, '-');
        printf("\t\n1-Registrar Vacinado.\n");
        printf("\t\n2-Listar Aplicacoes.\n");
        printf("\t\n3-Buscar CPF.\n");
        printf("\t\n4-Sair.\n");
        barra_simples(20, '-');
        fgets(buffer, T_BUFFER, stdin);
        sscanf(buffer, "%i", &opcao);
        if (opcao < 1 || opcao > 4) {
            printf("Opcao invalida!\n");
        }
    } while (opcao < 1 || opcao > 4); // um loop para nao encerrar na opcao invalida
    return(opcao);
}

int main(void)

{
    int x;
    system("color 1F");
    struct registro_vacinado vacinados[Q_MAXIMO_VACINADOS]; //chama a struct de vacina e o define. Vacinados vai ser usado de memoria
    int
        q_registros = 0, //o armazenamento temporario
        opcao = 0,
        contador,               //algumas variaveis
        n_busca = 0;
    char buffer[T_BUFFER];
    setlocale(LC_ALL, "Portuguese");

    do {
        opcao = menu_principal();

        switch (opcao) {
            case 1:
                do {
                    struct registro_vacinado tmp;
                    do {
                        system("cls");

                        srand((unsigned)time(NULL));
                        x=rand()%1001;
                        printf("Seu Codigo é: %d\n", x);
                        printf("Digite o codigo acima, para confirmar: \n"); // foi gerado e nao digitado pelo usario!!! só pedi confirmacao
                        fgets(buffer, T_BUFFER, stdin);
                        sscanf(buffer, "%i", &tmp.cod);
                        system("cls");
                        printf("Insira seu nome:");
                        fgets(buffer, T_BUFFER, stdin);
                        buffer[strlen(buffer)-1] = '\0';
                        strcpy(tmp.nome, buffer);
                        system("cls");
                        printf("Insira seu CPF:");
                        fgets(buffer, T_BUFFER, stdin);
                        buffer[strlen(buffer)-1] = '\0';
                        strcpy(tmp.cpf, buffer);
                        system("cls");
                        printf("Insira nome da Vacina:");
                        fgets(buffer, T_BUFFER, stdin);
                        buffer[strlen(buffer)-1] = '\0';
                        strcpy(tmp.vacina, buffer);
                        system("cls");
                        printf("Insira a Data:");
                        fgets(buffer, T_BUFFER, stdin);
                        buffer[strlen(buffer)-1] = '\0';
                        strcpy(tmp.data, buffer);
                        system("cls");
                        printf("Insira numero do lote:");
                        fgets(buffer, T_BUFFER, stdin);
                        sscanf(buffer, "%i", &tmp.lote);
                        system("cls");
                        barra_simples(40, '-');
                        printf("Codigo: %d\n", tmp.cod);
                        printf("Nome:%s\n", tmp.nome);
                        printf("CPF:%s\n", tmp.cpf);
                        printf("Nome da vacina:%s\n", tmp.vacina);
                        printf("Data da vacinacao:%s\n", tmp.data);
                        printf("Numero do lote:%i\n", tmp.lote);
                        barra_simples(40, '-');
                        printf("As informações estão corretas?\n1-Sim ou 2-Não\n");
                        fgets(buffer, T_BUFFER, stdin);
                        sscanf(buffer, "%i", &opcao);

                        if (opcao == 2) {
                            system("cls");
                            printf("Insira as informações novamente!\n");
                        }
                    } while (opcao == 2);
                    system("cls");
                    printf("Salvar o cadastro?\n1-Sim 2-Não\n");
                    fgets(buffer, T_BUFFER, stdin);
                    sscanf(buffer, "%i", &opcao);

                    if (opcao == 1) {

                        vacinados[q_registros] = tmp; //tudo dentro de tmp joga pra q_registros para contar e atribui junto com q_registros
                        q_registros++;
                    }
system("cls");
                    printf("Fazer outro cadastro?\n1-Sim 2-Não\n");
                    fgets(buffer, T_BUFFER, stdin);
                    sscanf(buffer, "%i", &opcao);

                } while (opcao == 1);
                opcao = 0;
                break;

            case 2:
                for (contador = 0; contador < q_registros; contador++) {
                    system("cls");
                    printf("Exibindo cadastros\n");
                    printf("Codigo: %d\n", vacinados[contador].cod);
                    printf("Nome:%s\n", vacinados[contador].nome);
                    printf("CPF:%s\n", vacinados[contador].cpf);
                    printf("Nome da Vacina:%s\n", vacinados[contador].vacina);
                    printf("Data:%s\n", vacinados[contador].data);
                    printf("Numero do lote:%i\n", vacinados[contador].lote);
                    msg_pausa(NULL);

                }
                break;

            case 3:
                printf("Digite o cpf para ser encontrado:");
                fgets(buffer, T_BUFFER, stdin);
                buffer[strlen(buffer)-1] = '\0';
                for (contador = 0; contador < q_registros; contador++) {
                    if (strcmp(vacinados[contador].cpf, buffer) == 0) { //busca o cpf
                        n_busca = contador;
                        break;
                    }
                }

                if (contador < q_registros) {
                    system("cls");
                    printf("Registro de vacina encontrado!\n");
                    printf("Codigo: %d\n",vacinados[contador].cod);
                    printf("Nome:%s\n", vacinados[contador].nome);
                    printf("CPF:%s\n", vacinados[contador].cpf);
                    printf("Nome da Vacina:%s\n", vacinados[contador].vacina);
                    printf("Data:%s\n", vacinados[contador].data);
                    printf("Numero do lote:%i\n", vacinados[contador].lote);
                } else {
                    printf("Registro não encontrado!\n");
                }
                msg_pausa(NULL);
                break;

            case 4:
                msg_pausa("O programa sera finalizado!");
        }
    } while (opcao != 4);
    return(0);
}
