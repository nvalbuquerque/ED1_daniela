#include <stdio.h>
#include <stdlib.h>
#include "agendamento.h"

void menu() {
    printf("\n===== MENU PRINCIPAL =====\n");
    printf("1. Cadastrar agendamento\n");
    printf("2. Listar agendamentos por CPF\n");
    printf("3. Listar agendamentos por sala\n");
    printf("4. Remover agendamento\n");
    printf("5. Exibir historico completo\n");
    printf("0. Sair\n");
    printf("==========================\n");
    printf("Escolha uma opcao: ");
}

int main() {
    ListaCabecalho listaAgendamentos;
    inicializarListaCabecalho(&listaAgendamentos);  // inicializa a lista com cabeçalho
    int opcao;
    char cpf[15];
    char sala[10];
    char data[11];

    do {
        menu();
        scanf("%d", &opcao);
        getchar(); // consumir \n

        switch (opcao) {
            case 1:
                cadastrarAgendamento(&listaAgendamentos);
                break;

            case 2:
                printf("\nCPF para consulta: ");
                fgets(cpf, sizeof(cpf), stdin);
                cpf[strcspn(cpf, "\n")] = 0;
                listarAgendamentosPorCPF(&listaAgendamentos, cpf);
                break;

            case 3:
                printf("\nSala para consulta: ");
                fgets(sala, sizeof(sala), stdin);
                sala[strcspn(sala, "\n")] = 0;
                listarAgendamentosPorSala(&listaAgendamentos, sala);
                break;

            case 4:
                printf("\nCPF: ");
                fgets(cpf, sizeof(cpf), stdin);
                cpf[strcspn(cpf, "\n")] = 0;
                printf("Data para remover: ");
                fgets(data, sizeof(data), stdin);
                data[strcspn(data, "\n")] = 0;
                removerAgendamento(&listaAgendamentos, cpf, data);
                break;

            case 5:
                //exibirHistorico(&listaAgendamentos); TEM QUE IMPLEMENTAR AINDA
                break;

            case 0:
                printf("\nEncerrando programa...\n");
                break;

            default:
                printf("\nOpcao invalida!\n");
        }

    } while (opcao != 0);

    liberarListaCabecalho(&listaAgendamentos); // libera memória
    return 0;
}
