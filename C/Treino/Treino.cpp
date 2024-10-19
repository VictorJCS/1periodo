

int main() {
    int matriz[5][5], i, j;

    for (i = 0; i < 5; i++) {  
        for (j = 0; j < 5; j++) {
            matriz[i][j] = 1;
            if (i == j) {
                matriz[i][j] = 0;
            }
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    return 0;
}
