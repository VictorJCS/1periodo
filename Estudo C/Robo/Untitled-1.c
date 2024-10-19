#include <stdio.h>
#include <string.h>

// Arrays com as palavras correspondentes
char *units[] = {"", "um", "dois", "três", "quatro", "cinco", "seis", "sete", "oito", "nove"};
char *teens[] = {"dez", "onze", "doze", "treze", "catorze", "quinze", "dezesseis", "dezessete", "dezoito", "dezenove"};
char *tens[] = {"", "", "vinte", "trinta", "quarenta", "cinquenta", "sessenta", "setenta", "oitenta", "noventa"};
char *hundreds[] = {"", "cento", "duzentos", "trezentos", "quatrocentos", "quinhentos", "seiscentos", "setecentos", "oitocentos", "novecentos"};

void convert_to_words(int num, char *result) {
    if (num == 0) {
        strcpy(result, "zero");
        return;
    }

    if (num == 100) {
        strcpy(result, "cem");
        return;
    }

    result[0] = '\0'; // inicializa a string resultante

    int milhar = num / 1000;
    int centena = (num % 1000) / 100;
    int dezena = (num % 100) / 10;
    int unidade = num % 10;

    if (milhar > 0) {
        if (milhar == 1) {
            strcat(result, "mil");
        } else {
            strcat(result, units[milhar]);
            strcat(result, " mil");
        }
    }

    if (centena > 0) {
        if (milhar > 0 && centena > 0) {
            strcat(result, " ");
        }
        strcat(result, hundreds[centena]);
    }

    if (dezena > 1) {
        if ((milhar > 0 || centena > 0) && (dezena > 0 || unidade > 0)) {
            strcat(result, " e ");
        }
        strcat(result, tens[dezena]);
        if (unidade > 0) {
            strcat(result, " e ");
            strcat(result, units[unidade]);
        }
    } else if (dezena == 1) {
        if (milhar > 0 || centena > 0) {
            strcat(result, " e ");
        }
        strcat(result, teens[unidade]);
    } else if (unidade > 0) {
        if (milhar > 0 || centena > 0) {
            strcat(result, " e ");
        }
        strcat(result, units[unidade]);
    }
}

int main() {
    int num;
    char result[100];

    printf("Digite um número entre 0 e 9999: ");
    scanf("%d", &num);

    if (num < 0 || num > 9999) {
        printf("Número fora do intervalo suportado.\n");
        return 1;
    }

    convert_to_words(num, result);
    printf("Número por extenso: %s\n", result);

    return 0;
}
