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
            printf("\nLinha inv�lida! Digite novamente: ");
            while (getchar() != '\n');
        }

        posY = 0;

        do {
            printf("Coluna: ");
            while (scanf("%d", &posY) != 1 || posY < 0 || posY >= COLS) {
                printf("\nColuna inv�lida! Digite novamente: ");
                while (getchar() != '\n');
            }
            break;
        } while (1);

        while (matrix[posX][posY] != 0) {
            printf("\nPosi��o ocupada! Digite novamente:\nSujeira %d\nColuna: ", i + 1);
            while (scanf("%d", &posY) != 1 || posY < 0 || posY >= COLS) {
                printf("\nColuna inv�lida! Digite novamente: ");
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
            printf("Escolha a posi��o inicial do rob�\nDe 0 a 7\nLinha: ");
            while (scanf("%d", &initialPosX) != 1 || initialPosX < 0 || initialPosX >= ROWS) {
                printf("\nLinha inv�lida! Digite novamente: ");
                while (getchar() != '\n');
            }

            do {
                printf("Coluna: ");
                while (scanf("%d", &initialPosY) != 1 || initialPosY < 0 || initialPosY >= COLS) {
                    printf("\nColuna inv�lida! Digite novamente: ");
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

        printf("\nQuantas sujeiras voc� deseja colocar? ");
        while (scanf("%d", &numItems) != 1 || numItems <= 0) {
            printf("\nN�mero inv�lido de sujeiras! Digite novamente: ");
            while (getchar() != '\n');
        }
        placeDirt(matrix, &itemCount, numItems);

        printf("\nDigite 'W' para cima, 'A' para esquerda, 'S' para baixo, 'D' para direita\n");
        printf("Digite 'Q' para Desligar.\n");

        char move;
        while (itemCount < numItems && hasDirtNearby(matrix, posX, posY)) {
            scanf(" %c", &move);
            system("cls");

            int nextX = posX, nextY = posY;

            switch (tolower(move)) {
                case 'w': nextX = posX - 1; break;
                case 'a': nextY = posY - 1; break;
                case 's': nextX = posX + 1; break;
                case 'd': nextY = posY + 1; break;
                case 'q': printf("Desligando...\n"); return 0;
                default: printf("\nComando inv�lido! Tente novamente.\n");
            }

            if (nextX >= 0 && nextX < ROWS && nextY >= 0 && nextY < COLS && matrix[nextX][nextY] == 2) {
                matrix[posX][posY] = 0;
                posX = nextX;
                posY = nextY;
                itemCount++;
                printf("Sujeira removida!\n");
                printf("\nN�mero de sujeiras removidas: %d\n", itemCount);
            } else {
                printf("Movimento inv�lido ou n�o h� sujeira para remover!\n");
           
