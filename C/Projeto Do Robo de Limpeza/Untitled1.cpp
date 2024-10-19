#include <stdio.h>//Cora��o
#include <stdlib.h>//Extens�o do dio
#include <ctype.h>//Reseta a tela
#include <locale.h>//Escolher idioma
#include <windows.h>//Para usar os camandos do cmd
//(#Define) uma vari�vel (global)=pode ser usada em todo c�digo
#define ROWS 8 //Difine linhas 
#define COLS 8//Define Colunas
// Fun��o para imprimir a matriz representando o ambiente
void printMatrix(int matrix[ROWS][COLS], int itemCount, int posX, int posY, int initialPosX, int initialPosY) {
    // Imprime os n�meros das colunas
    printf("   ");//Imprimir vazio
    for (int i = 0; i < COLS; i++)//N�meros da coluna + contador
        printf("%2d ", i);//Imprime o n�mero da coluna
    printf("\n");//Quebra de linha

    // Imprime a matriz
    for (int i = 0; i < ROWS; i++) {//N�meros da linha + contador
        printf("%2d ", i); // Imprime o n�mero da linha
        for (int j = 0; j < COLS; j++) {
            // Verifica se a posi��o � a do rob�, a posi��o inicial vazia ou outra c�lula
            if (i == posX && j == posY)
                printf("|R|"); // Rob�
            else if (i == initialPosX && j == initialPosY && matrix[i][j] != 1)
                printf("|E|"); // Posi��o inicial vazia
            else//PrintMatrix ChamandoMatrix   Se=0 sen�o=0 ChamaMatriz   Se=1  sen�o=1				se=2	sen�o=2
                printf("|%c|", matrix[i][j] == 0 ? '-' : (matrix[i][j] == 1 ? 'R' : (matrix[i][j] == 2 ? 'S' : '-'))); // Outras c�lulas
        }								    //Imprime(-) ContinuaBloco      Printa(R) 				 Printa(S)
        printf("\n");
    }
}

// Verifica se h� sujeira nas c�lulas vizinhas � posi��o atual do rob�
int hasDirtNearby(int matrix[ROWS][COLS], int posX, int posY) {
    // Percorre as c�lulas vizinhas nas dire��es horizontal e vertical
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            // Exclui a verifica��o para c�lulas diagonais
            if ((i == 0 || j == 0) && (i != 0 || j != 0)) {
                int nextX = posX + i;
                int nextY = posY + j;
                // Verifica se a c�lula vizinha est� dentro dos limites da matriz e se cont�m sujeira
                if (nextX >= 0 && nextX < ROWS && nextY >= 0 && nextY < COLS && matrix[nextX][nextY] == 2)
                    return 1; // Retorna verdadeiro se houver sujeira pr�xima
            }
        }
    }
    return 0; // Retorna falso se n�o houver sujeira pr�xima
}

// Coloca as sujeiras aleatoriamente na matriz
void placeDirt(int matrix[ROWS][COLS], int *itemCount, int numItems) {// Puxa a Matriz o ContadorDeItens e o TotalDeItens
    int posX, posY;////Posi��o X e Y da sujeira
    for (int i = 0; i < numItems; i++) {//Puxa X itens e repete X vezes
        system("cls"); // Limpa a tela
        printf("Posicione as sujeiras:\n");//Impress�o convencional
        printMatrix(matrix, *itemCount, -1, -1, -1, -1); // Imprime a matriz atual

        // Solicita a posi��o da sujeira ao usu�rio e (N_itens + 1) imprime de forma mais did�tica ao usu�rio
        printf("\nSujeira %d\nLinha: ", i + 1);
        while (scanf("%d", &posX) != 1 || posX < 0 || posX >= ROWS) {//Excess�o para ver se o valor informado est� dentro ou fora da matriz
            printf("\nLinha inv�lida! Digite novamente: ");
            while (getchar() != '\n'); // Limpa o buffer de entrada
        }

        posY = 0;//Reseta Y

        do {//Fa�a bloco
            printf("Coluna: ");//Imprime Coluna
            while (scanf("%d", &posY) != 1 || posY < 0 || posY >= COLS) {//Excess�o para ver se o valor informado est� dentro do limite de colunas
                printf("\nColuna inv�lida! Digite novamente: ");
                while (getchar() != '\n'); // Limpa o buffer de entrada
            }
            break;//Para quebar o la�o do loop
        } while (1);

        // Verifica se a posi��o est� ocupada
        while (matrix[posX][posY] != 0) {//Enquanto (True/Verdade) repita
            printf("\nPosi��o ocupada! Digite novamente:\nSujeira %d\nColuna: ", i + 1);//Excess�o/Printa se ocupada
            while (scanf("%d", &posY) != 1 || posY < 0 || posY >= COLS) {//Verificando se posi��o inv�lida
                printf("\nColuna inv�lida! Digite novamente: ");//Printa se inv�lida
                while (getchar() != '\n'); // Limpa o buffer de entrada
            }
        }

        matrix[posX][posY] = 2; // Marca a posi��o da sujeira na matriz como 2
        system("cls"); // Limpa a tela
        printMatrix(matrix, *itemCount, -1, -1, -1, -1); // Imprime a matriz atual
    }
}

// Fun��o para limpar a matriz
void clearMatrix(int matrix[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            matrix[i][j] = 0; // Marca todas as c�lulas como vazias
        }
    }
}

// Fun��o principal
int main() {
    setlocale(LC_ALL, "Portuguese");//Permite acentua��o usando o idioma selecionado
    int matrix[ROWS][COLS], numItems, itemCount;//Matrix(Linhas&Colunas),N�meroTotalDeItens,ContadorDeItens de (0 � X)
    char playAgain;//Jogar novamente
	// Loop principal do programa/Bloco do game
    do {//Start do game
        itemCount = 0;//Reset de itens
        // Inicializa a matriz com zeros
        clearMatrix(matrix);

        int initialPosX, initialPosY;//Vari�vel para salvar a posi��o inicial do robo (X & Y)
        int posX, posY;//Vari�vel da posi��o do robo
        
        // Solicita a posi��o inicial do rob� ao usu�rio
        do {
            printf("Escolha a posi��o inicial do rob�\nDe 0 a 7\nLinha: ");//Printa a escolha de (linha)
            while (scanf("%d", &initialPosX) != 1 || initialPosX < 0 || initialPosX >= ROWS) {//Verifica se o valor est� dentro da matiz (linhas)(0 a 7)
                printf("\nLinha inv�lida! Digite novamente: ");//Imprime erro
                while (getchar() != '\n'); // Limpa o buffer de entrada
            }

            do {//Bloco da posi��o do robo(Coluna)
                printf("Coluna: ");//Imprime a escolha de (coluna)
                while (scanf("%d", &initialPosY) != 1 || initialPosY < 0 || initialPosY >= COLS) {//Verifica se o valor esta dentro da matriz(colunas)(0 a 7).
                    printf("\nColuna inv�lida! Digite novamente: ");
                    while (getchar() != '\n'); // Limpa o buffer de entrada
                }
                break;
            } while (1);

            break;
        } while (1);
		//Salva posi��o inicial
        posX = initialPosX;//De X
        posY = initialPosY;//De Y
        matrix[posX][posY] = 1; // Marca a posi��o inicial do rob� na matriz como 1

        printf("\nEstado inicial do ambiente:\n");
        printMatrix(matrix, itemCount, posX, posY, initialPosX, initialPosY); // Imprime a matriz atual

        // Solicita ao usu�rio a quantidade de sujeiras a serem colocadas
        printf("\nQuantas sujeiras voc� deseja colocar? ");
        while (scanf("%d", &numItems) != 1 || numItems <= 0) {
            printf("\nN�mero inv�lido de sujeiras! Digite novamente: ");
            while (getchar() != '\n'); // Limpa o buffer de entrada
        }
        placeDirt(matrix, &itemCount, numItems); // Coloca as sujeiras na matriz

        // Solicita ao usu�rio os comandos para movimentar o rob�
        printf("\nDigite 'W' para cima, 'A' para esquerda, 'S' para baixo, 'D' para direita\n");
        printf("Digite 'Q' para Desligar.\n");

        char move;
        // Loop para movimentar o rob� enquanto houver sujeira pr�xima e ainda houver sujeiras n�o removidas
        while (itemCount < numItems && hasDirtNearby(matrix, posX, posY)) {
            scanf(" %c", &move); // Obt�m o comando do usu�rio
            system("cls"); // Limpa a tela

            int nextX = posX, nextY = posY;

            // Calcula a pr�xima posi��o do rob� de acordo com o comando recebido
            switch (tolower(move)) {
                case 'w': nextX = posX - 1; break;
                case 'a': nextY = posY - 1; break;
                case 's': nextX = posX + 1; break;
                case 'd': nextY = posY + 1; break;
                case 'q': printf("Desligando...\n"); return 0; // Encerra o programa se o usu�rio digitar 'Q'
                default: printf("\nComando inv�lido! Tente novamente.\n");
            }

            // Verifica se a pr�xima posi��o � v�lida e cont�m sujeira
            if (nextX >= 0 && nextX < ROWS && nextY >= 0 && nextY < COLS && matrix[nextX][nextY] == 2) {
                matrix[posX][posY] = 0; // Remove o rob� da posi��o atual na matriz
                posX = nextX;
                posY = nextY;
                itemCount++; // Incrementa o contador de sujeiras removidas
                printf("Sujeira removida!\n");
                printf("\nN�mero de sujeiras removidas: %d\n", itemCount);
            } else {
                printf("Movimento inv�lido ou n�o h� sujeira para remover!\n");
            }

            matrix[posX][posY] = 1; // Marca a nova posi��o do rob� na matriz como 1
            printMatrix(matrix, itemCount, posX, posY, initialPosX, initialPosY); // Imprime a matriz atual

            // Verifica se todas as sujeiras foram removidas
            if (itemCount == numItems) printf("\nTodas as sujeiras foram removidas! Parab�ns!\n");
        }

        // Verifica se todas as sujeiras foram removidas e o rob� retornou � posi��o inicial
        if (itemCount == numItems && !hasDirtNearby(matrix, posX, posY)) {
            while (posX != initialPosX || posY != initialPosY) {
                // Prioriza verifica��o da posi��o Y quando o rob� se moveu para esquerda ou direita
                if (posY > initialPosY && posX == initialPosX) {
 					matrix[posX][posY] = 0;                  
				    posY--;
                    printf("\nMovendo para a esquerda\n");
                } else if (posY < initialPosY && posX == initialPosX) {
                    matrix[posX][posY] = 0;
					posY++;
                    printf("\nMovendo para a direita\n");
                }
                
                // Prioriza verifica��o da posi��o X quando o rob� se moveu para cima ou para baixo
                if (posX > initialPosX) {
                    matrix[posX][posY] = 0;
					posX--;
                    printf("\nMovendo para cima\n");
                } else if (posX < initialPosX) {
                    matrix[posX][posY] = 0;
					posX++;
                    printf("\nMovendo para baixo\n");
                }
                matrix[posX][posY] = 1; // Marca a nova posi��o do rob� na matriz como 1
                system("cls"); // Limpa a tela
				printMatrix(matrix, itemCount, posX, posY, initialPosX, initialPosY); // Imprime a matriz atual
                Sleep(900); // Espera um tempo para visualiza��o
            }
            printf("\nRetornou ao ponto inicial!\n");
        }

        // Verifica se n�o h� sujeira pr�xima e ainda h� sujeiras n�o removidas
        if (!hasDirtNearby(matrix, posX, posY) && itemCount < numItems) {
            printf("\nErro de locomo��o! O sistema ser� encerrado.\n");
            printf("\nDeseja reiniciar o sistema? (S/N): ");
            scanf(" %c", &playAgain);
            system("cls");
            continue;
        }

        // Pergunta ao usu�rio se deseja reiniciar o sistema
        printf("\nDeseja reiniciar o sistema? (S/N): ");
        scanf(" %c", &playAgain);
        system("cls");

    } while (tolower(playAgain) == 's'); // Repete o loop enquanto o usu�rio desejar

    printf("\nDesligando...\n"); // Mensagem de encerramento
    return 0;
}
