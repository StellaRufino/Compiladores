#include <stdio.h>
#include <stdlib.h>

//memória disponivel para o interpretadorador
#define MEMORY_SIZE 30000

//função recebe o codigo à ser interpretado
void interpretador(char* codigo) {
    char memoria[MEMORY_SIZE] = {0};
    char* ponteiro = memoria; // ponteiro que inicia no primeiro elemento do array

    //enquanto for diferente de 0
    while (*codigo) {
        switch (*codigo) {
            case '>':
                ++ponteiro; // incrementa e aponta pra proxima celula de memoria
                break;
            case '<':
                --ponteiro;// decrementa e aponta pra proxima celula de memoria
                break;
            case '+':
                ++(*ponteiro); // incrementa
                break;
            case '-':
                --(*ponteiro); // decrementa
                break; 
            case '.':
                putchar(*ponteiro); // imprime
                break;
            case ',':
                *ponteiro = getchar(); // le e armazena na celula indicada pelo ponteiro 
                break;
            // se o cara caractere for 0, pula para fora do loop 
            case '[': 
                if (!(*ponteiro)) {
                    int contador = 1;
                    while (contador > 0) {
                        ++codigo;
                        if (*codigo == '[')
                            ++contador;
                        else if (*codigo == ']')
                            --contador;
                    }
                }
                break;
            case ']':
                if (*ponteiro) {
                    int contador = 1;
                    while (contador > 0) {
                        --codigo;
                        if (*codigo == ']')
                            ++contador;
                        else if (*codigo == '[')
                            --contador;
                    }
                }// se for diferente de 0 reinicia o loop
                break;
        }
        ++codigo; //incrementa e vai pro proximo caractere
    }
}

int main() {
    //input
    FILE * arq = fopen("input.txt", "r");
    //verifica o input para encontrar erros
    if (arq == NULL) {
        printf("Falha ao abrir o arquivo.\n");
        return 1;
    }
    //para obter o tamanho do arquivo
    fseek(arq, 0, SEEK_END);//seek_end vai ate o fim do arquivo
    long tam_arq = ftell(arq); //ftell retorna a posição atual do ponteiro indicando o tamanho do arquivo
    fseek(arq, 0, SEEK_SET); //volta pro inicio do arquivo
    //aloca a memoria
    char* codigo = malloc(tam_arq + 1);
    if (codigo == NULL) {
        printf("Falha ao alocar memória.\n");
        return 1;
    }

    //le o arquivo da variavel codigo le o byte de dados e add \0 no final do arquivo  
    fread(codigo, 1, tam_arq, arq);
    codigo[tam_arq] = '\0';

    fclose(arq);

    interpretador(codigo);

    free(codigo);//libera memoria

    return 0;
}
