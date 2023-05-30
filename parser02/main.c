#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tinyexpr.h"

#define MAX_EXPRESSION_LENGTH 256

int main() {
  
    // Abre o arquivo para leitura
    FILE *arq = fopen("input.txt", "r");
    if (!arq) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    // Lê cada linha do arquivo e avalia a expressão
    char expressao[MAX_EXPRESSION_LENGTH];
    while (fgets(expressao, MAX_EXPRESSION_LENGTH, arq)) {
        // Remove o caractere de nova linha
        expressao[strcspn(expressao, "\n")] = '\0';

        int error;
        double resultado = te_interp(expressao, &error);

        if (error != 0) {
            printf("erro na expressao: %s\n", expressao);
        } else {
            printf("Expressão: '%s'\nResultado: %f\n\n", expressao, resultado);
        }
    }

    // Fecha o arquivo
    fclose(arq);

    return 0;
}

