#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <locale.h>
#include <windows.h>

#define ROWS 8
#define COLS 8

void printMatrix(int matrix[ROWS][COLS], int itemCount, int posX, int posY, int initialPosX, int initialPosY) {
    printf("   ");
    for (int i = 0; i < COLS; i++)
        printf("%2d ", i);
    printf("\n");

    for (int i = 0; i < ROWS; i++) {
        printf("%2d ", i);
        for (int j = 0; j < COLS; j++) {
            if (i == posX && j == posY)
                printf("|R|");
            else if (i == initialPosX && j == initialPosY && matrix[i][j] != 1)
                printf("|E|");
            else
                printf("|%c|", matrix[i][j] == 0 ? '-' : (matrix[i][j] == 1 ? 'R' : (matrix[i][j] == 2 ? 'S' : '-')));
        }
        printf("\n");
    }
}

int hasDirtNearby(int matrix[ROWS][COLS], int posX, int posY) {
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if ((i == 0 || j == 0) && (i != 0 || j != 0)) {
                int nextX = posX + i;
                int nextY = posY + j;
                if (nextX >= 0 && nextX < ROWS && nextY >= 0 && nextY < COLS && matrix[nextX][nextY] == 2)
                    return 1;
            }
        }
    }
    return 0;
}

void placeDirt(int matrix[ROWS][COLS], int *itemCount, int numItems) {
    int posX, posY;
    for (int i = 0; i < numItems; i++) {
        system("cls");
        printf("Posicione as sujeiras:\n");
        printMatrix(matrix, *itemCount, -1, -1, -1, -1);

        printf("\nSujeira %d\nLinha: ", i + 1);
        while (scanf("%d", &posX) != 1 || posX < 0 || posX >= ROWS) {
            printf("\nLinha inválida! Digite novamente: ");
            while (getchar() != '\n');
        }

        posY = 0;

        do {
            printf("Coluna: ");
            while (scanf("%d", &posY) != 1 || posY < 0 || posY >= COLS) {
                printf("\nColuna inválida! Digite novamente: ");
                while (getchar() != '\n');
            }
            break;
        } while (1);

        while (matrix[posX][posY] != 0) {
            printf("\nPosição ocupada! Digite novamente:\nSujeira %d\nColuna: ", i + 1);
            while (scanf("%d", &posY) != 1 || posY < 0 || posY >= COLS) {
                printf("\nColuna inválida! Digite novamente: ");
                while (getchar() != '\n');
            }
        }

        matrix[posX][posY] = 2;
        system("cls");
        printMatrix(matrix, *itemCount, -1, -1, -1, -1);
    }
}

void clearMatrix(int matrix[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            matrix[i][j] = 0;
        }
    }
}

// Função para movimentar o robô automaticamente
void moveRobot(int *posX, int *posY) {
    int moveOptions[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}}; // Opções de movimento: cima, esquerda, baixo, direita
    int randomMove = rand() % 4; // Gera um número aleatório de 0 a 3
    *posX += moveOptions[randomMove][0]; // Atualiza a posição X de acordo com o movimento escolhido
    *posY += moveOptions[randomMove][1]; // Atualiza a posição Y de acordo com o movimento escolhido
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    int matrix[ROWS][COLS], numItems, itemCount;
    char playAgain;

    do {
        itemCount = 0;
        clearMatrix(matrix);

        int initialPosX, initialPosY;
        int posX, posY;

        do {
            printf("Escolha a posição inicial do robô\nDe 0 a 7\nLinha: ");
            while (scanf("%d", &initialPosX) != 1 || initialPosX < 0 || initialPosX >= ROWS) {
                printf("\nLinha inválida! Digite novamente: ");
                while (getchar() != '\n');
            }

            do {
                printf("Coluna: ");
                while (scanf("%d", &initialPosY) != 1 || initialPosY < 0 || initialPosY >= COLS) {
                    printf("\nColuna inválida! Digite novamente: ");
                    while (getchar() != '\n');
                }
                break;
            } while (1);

            break;
        } while (1);

        posX = initialPosX;
        posY = initialPosY;
        matrix[posX][posY] = 1;

        printf("\nEstado inicial do ambiente:\n");
        printMatrix(matrix, itemCount, posX, posY, initialPosX, initialPosY);

        printf("\nQuantas sujeiras você deseja colocar? ");
        while (scanf("%d", &numItems) != 1 || numItems <= 0) {
            printf("\nNúmero inválido de sujeiras! Digite novamente: ");
            while (getchar() != '\n');
        }
        placeDirt(matrix, &itemCount, numItems);

        // Loop para movimentar o robô enquanto houver sujeira próxima e ainda houver sujeiras não removidas
        while (itemCount < numItems && hasDirtNearby(matrix, posX, posY)) {
            moveRobot(&posX, &posY);
            system("cls");
            printMatrix(matrix, itemCount, posX, posY, initialPosX, initialPosY);
            Sleep(900); // Tempo de espera antes do próximo movimento
        }

        if (itemCount == numItems && !hasDirtNearby(matrix, posX, posY)) {
            printf("\nRetornou ao ponto inicial!\n");
        }

        if (!hasDirtNearby(matrix, posX, posY) && itemCount < numItems) {
            printf("\nErro de locomoção! O sistema será encerrado.\n");
            printf("\nDeseja reiniciar o sistema? (S/N): ");
            scanf(" %c", &playAgain);
            system("cls");
            continue;
        }

        printf("\nDeseja reiniciar o sistema? (S/N): ");
        scanf(" %c", &playAgain);
        system("cls");

    } while (tolower(playAgain) == 's');

    printf("\nDesligando...\n");
    return 0;
}
