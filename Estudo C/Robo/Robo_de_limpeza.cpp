#include <stdio.h>
#include <stdlib.h>
#include <locale.h> // Incluindo o cabe�alho para suporte � acentua��o

#define LINHAS 8
#define COLUNAS 8

// Fun��o para limpar a tela
void limparTela() {
    system("cls"); // No Linux ou Mac use "clear"
}

// Fun��o para mostrar o menu
void mostrarMenu() {
    limparTela();
    printf(
        "########################################\n"
        "#                 MENU                 #\n"
        "########################################\n"
        "#                                      #\n"
        "#             1. Iniciar               #\n"
        "#             2. Sair                  #\n"
        "#                                      #\n"
        "########################################\n"
        "#          Criado por: Victor           #\n"
        "########################################\n"
    );
}

// Fun��o para imprimir a matriz
void imprimirMatriz(char matriz[LINHAS][COLUNAS]) {
    printf("\n\n");
    printf("   ");
    for (int i = 0; i < COLUNAS; i++)
        printf("%2d ", i);
    printf("\n");

    for (int i = 0; i < LINHAS; i++) {
        printf("%2d ", i);
        for (int j = 0; j < COLUNAS; j++) {
            printf("|%c|", matriz[i][j] == 0 ? '-' : matriz[i][j]);
        }
        printf("\n");
    }
}

// Fun��o para adicionar a esta��o do rob�
void adicionarEstacaoRobo(char matriz[LINHAS][COLUNAS], int *estacaoRobo) {
    printf("\nDigite a linha para adicionar a esta��o do rob�: ");
    int linha;
    scanf("%d", &linha);

    printf("Digite a coluna para adicionar a esta��o do rob�: ");
    int coluna;
    scanf("%d", &coluna);

    if (linha >= 0 && linha < LINHAS && coluna >= 0 && coluna < COLUNAS) {
        matriz[linha][coluna] = 'E'; // Altera��o para 'E'
        estacaoRobo[0] = linha;
        estacaoRobo[1] = coluna;
        printf("Esta��o do rob� adicionada com sucesso na posi��o (%d, %d).\n", linha, coluna);
    } else {
        printf("Coordenadas inv�lidas.\n");
    }
}

// Fun��o para adicionar sujeira
void adicionarSujeira(char matriz[LINHAS][COLUNAS], int numeroSujeiras) {
    for (int i = 0; i < numeroSujeiras; i++) {
        printf("\nDigite a linha para adicionar a sujeira %d: ", i + 1);
        int linha;
        scanf("%d", &linha);

        printf("Digite a coluna para adicionar a sujeira %d: ", i + 1);
        int coluna;
        scanf("%d", &coluna);

        if (linha >= 0 && linha < LINHAS && coluna >= 0 && coluna < COLUNAS) {
            matriz[linha][coluna] = 'S'; // Adicionando sujeira
            printf("Sujeira %d adicionada com sucesso na posi��o (%d, %d).\n", i + 1, linha, coluna);
        } else {
            printf("Coordenadas inv�lidas.\n");
            i--; // Para repetir a inser��o da sujeira inv�lida
        }
    }
}

int main() {
    setlocale(LC_ALL, "Portuguese"); // Configurando a localidade para a l�ngua portuguesa
    int escolha;
    char matriz[LINHAS][COLUNAS] = {0}; // Inicializa a matriz com zeros
    int estacaoRobo[2] = {-1, -1}; // Armazena as coordenadas da esta��o do rob�, inicializado com valores inv�lidos

    while (1) {
        mostrarMenu();

        // Solicitar a escolha do usu�rio
        printf("\nEscolha uma op��o: ");
        scanf("%d", &escolha);

        // Processar a escolha
        switch (escolha) {
            case 1: {
                limparTela(); // Limpa a tela ap�s selecionar a op��o 1
                printf("\nOp��o 'Iniciar' selecionada.\n");
                adicionarEstacaoRobo(matriz, estacaoRobo);
                imprimirMatriz(matriz);

                int numeroSujeiras;
                printf("\nDigite o n�mero de sujeiras que deseja adicionar: ");
                scanf("%d", &numeroSujeiras);

                adicionarSujeira(matriz, numeroSujeiras); // Adicionando sujeiras
                imprimirMatriz(matriz); // Imprimir a matriz atualizada ap�s adicionar todas as sujeiras
                break;
            }
            case 2:
                printf("\nSaindo do programa...\n");
                exit(0); // Terminar o programa
            default:
                printf("\nOp��o inv�lida. Tente novamente.\n");
        }

        // Pausar para que o usu�rio veja a mensagem antes de voltar ao menu
        printf("\nPressione Enter para continuar...");
        while (getchar() != '\n'); // Limpar o buffer de entrada
        getchar(); // Capturar o Enter
    }

    return 0;
}
