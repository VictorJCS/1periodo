#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <locale.h>
#include <windows.h>

#define ROWS 8
#define COLS 8

typedef struct {
    int x;
    int y;
} Position;

void printMatrix(int matrix[ROWS][COLS], int posX, int posY, int initialPosX, int initialPosY) {
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
                printf("|%c|", matrix[i][j] == 0 ? '-' : (matrix[i][j] == 1 ? 'R' : (matrix[i][j] == 2 ? 'S' : (matrix[i][j] == 3 ? ' ' : '-'))));
        }
        printf("\n");
    }
}

void clearMatrix(int matrix[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            matrix[i][j] = 0;
        }
    }
}

void placeDirt(int matrix[ROWS][COLS], int numItems) {
    int posX, posY;
    for (int i = 0; i < numItems; i++) {
        system("cls");
        printf("Posicione as sujeiras:\n");
        printMatrix(matrix, -1, -1, -1, -1);

        printf("\nSujeira %d\nLinha: ", i + 1);
        while (scanf("%d", &posX) != 1 || posX < 0 || posX >= ROWS) {
            printf("\nLinha inv�lida! Digite novamente: ");
            while (getchar() != '\n');
        }

        printf("Coluna: ");
        while (scanf("%d", &posY) != 1 || posY < 0 || posY >= COLS) {
            printf("\nColuna inv�lida! Digite novamente: ");
            while (getchar() != '\n');
        }

        while (matrix[posX][posY] != 0) {
            printf("\nPosi��o ocupada! Digite novamente:\nSujeira %d\nLinha: ", i + 1);
            while (scanf("%d", &posX) != 1 || posX < 0 || posX >= ROWS) {
                printf("\nLinha inv�lida! Digite novamente: ");
                while (getchar() != '\n');
            }
            printf("Coluna: ");
            while (scanf("%d", &posY) != 1 || posY < 0 || posY >= COLS) {
                printf("\nColuna inv�lida! Digite novamente: ");
                while (getchar() != '\n');
            }
        }

        matrix[posX][posY] = 2;
        system("cls");
        printMatrix(matrix, -1, -1, -1, -1);
    }
}

int findNearestDirt(int matrix[ROWS][COLS], int posX, int posY, int *dirtX, int *dirtY) {
    int minDistance = ROWS * COLS;
    int found = 0;

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (matrix[i][j] == 2) {
                int distance = abs(posX - i) + abs(posY - j);
                if (distance < minDistance && (posX == i || posY == j)) {
                    minDistance = distance;
                    *dirtX = i;
                    *dirtY = j;
                    found = 1;
                }
            }
        }
    }
    return found;
}

int isValidMove(int matrix[ROWS][COLS], int posX, int posY) {
    return (posX >= 0 && posX < ROWS && posY >= 0 && posY < COLS && matrix[posX][posY] != 2);
}

void moveRobot(int *posX, int *posY, int targetX, int targetY, int matrix[ROWS][COLS], Position *path, int *pathLength) {
    while (*posX != targetX || *posY != targetY) {
        if (*posX != targetX) {
            if (*posX < targetX && isValidMove(matrix, *posX + 1, *posY))
                (*posX)++;
            else if (*posX > targetX && isValidMove(matrix, *posX - 1, *posY))
                (*posX)--;
        } else {
            if (*posY < targetY && isValidMove(matrix, *posX, *posY + 1))
                (*posY)++;
            else if (*posY > targetY && isValidMove(matrix, *posX, *posY - 1))
                (*posY)--;
        }
        matrix[*posX][*posY] = 3; // Atualiza a posi��o para vazio
        path[*pathLength].x = *posX;
        path[*pathLength].y = *posY;
        (*pathLength)++;
    }
}

void clearPath(int matrix[ROWS][COLS], Position path[], int pathLength) {
    for (int i = 0; i < pathLength; i++) {
        matrix[path[i].x][path[i].y] = 3; // Marca o caminho percorrido como vazio
    }
}

void printMatrixWithStation(int matrix[ROWS][COLS], int initialPosX, int initialPosY) {
    printf("   ");
    for (int i = 0; i < COLS; i++)
        printf("%2d ", i);
    printf("\n");

    for (int i = 0; i < ROWS; i++) {
        printf("%2d ", i);
        for (int j = 0; j < COLS; j++) {
            if (i == initialPosX && j == initialPosY)
                printf("|E|");
            else
                printf("|%c|", matrix[i][j] == 0 ? '-' : ' '); // Imprime '-' apenas para c�lulas vazias
        }
        printf("\n");
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

        printf("Escolha a posi��o inicial do rob�\nDe 0 a 7\nLinha: ");
        while (scanf("%d", &initialPosX) != 1 || initialPosX < 0 || initialPosX >= ROWS) {
            printf("\nLinha inv�lida! Digite novamente: ");
            while (getchar() != '\n');
        }

        printf("Coluna: ");
        while (scanf("%d", &initialPosY) != 1 || initialPosY < 0 || initialPosY >= COLS) {
            printf("\nColuna inv�lida! Digite novamente: ");
            while (getchar() != '\n');
        }

        posX = initialPosX;
        posY = initialPosY;
        matrix[posX][posY] = 1;

        printf("\nEstado inicial do ambiente:\n");
        printMatrix(matrix, posX, posY, initialPosX, initialPosY);

        printf("\nQuantas sujeiras voc� deseja colocar? ");
        while (scanf("%d", &numItems) != 1 || numItems <= 0) {
            printf("\nN�mero inv�lido de sujeiras! Digite novamente: ");
            while (getchar() != '\n');
        }
        placeDirt(matrix, numItems);

        printf("\nMovendo o rob� automaticamente para a sujeira...\n");

        Position path[ROWS * COLS];
        int pathLength = 0;

        while (itemCount < numItems) {
            int dirtX, dirtY;

            if (findNearestDirt(matrix, posX, posY, &dirtX, &dirtY)) {
                matrix[posX][posY] = 3;  // Deixa a casa vazia
                moveRobot(&posX, &posY, dirtX, dirtY, matrix, path, &pathLength);
                if (posX == dirtX && posY == dirtY) {
                    itemCount++;
                    printf("Sujeira removida!\n");
                }
                matrix[posX][posY] = 1;
                system("cls");
                printMatrix(matrix, posX, posY, initialPosX, initialPosY);
                Sleep(1000);
            } else {
                break;
            }
        }

        if (itemCount == numItems) {
            printf("\nTodas as sujeiras foram removidas! Parab�ns!\n");

            // Retornar � posi��o inicial pelo mesmo caminho
            printf("\nRetornando � posi��o inicial...\n");
            int prevPosX = initialPosX;
            int prevPosY = initialPosY;

            for (int i = pathLength - 1; i >= 0; i--) {
                int tempPosX = posX;  // Salvamos a posi��o atual antes do movimento
                int tempPosY = posY;

                matrix[posX][posY] = 3;  // Deixa a casa vazia
                posX = path[i].x;
                posY = path[i].y;
                matrix[posX][posY] = 1;
                system("cls");
                printMatrix(matrix, posX, posY, initialPosX, initialPosY);
                Sleep(1000);

                prevPosX = tempPosX;  // Atualizamos a posi��o anterior
                prevPosY = tempPosY;
            }
            printf("\nRetornou ao ponto inicial!\n");
            clearPath(matrix, path, pathLength); // Limpa o caminho percorrido pelo rob�
            matrix[initialPosX][initialPosY] = 0; // Marca a posi��o inicial como vazia
            matrix[posX][posY] = 1; // Marca a posi��o final como a esta��o
            system("cls");
            printMatrixWithStation(matrix, initialPosX, initialPosY); // Imprime a matriz com a esta��o na posi��o final
        } else {
            printf("\nErro de locomo��o! O sistema ser� encerrado.\n");
        }

        printf("\nDeseja reiniciar o sistema? (S/N): ");
        scanf(" %c", &playAgain);
        system("cls");

    } while (tolower(playAgain) == 's');

    printf("\nDesligando...\n");
    return 0;
}
