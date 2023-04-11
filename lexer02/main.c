#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum Token {
    Mais,
    Menos,
    Multiplicacao,
    Potencia,
    Divisao,
    Indeterminado,
};

struct TokenList {
    enum Token token;
    struct TokenList *next;
};

void usar_token(char *sinalizador, struct TokenList **tokens) {
    *tokens = NULL;
    struct TokenList *add_final = NULL;
    while (*sinalizador != '\0') {
        if (*sinalizador == '+') {
            struct TokenList *node = malloc(sizeof(struct TokenList));
            node->token = Mais;
            node->next = NULL;
            if (add_final == NULL) {
                *tokens = node;
            } else {
                add_final->next = node;
            }
            add_final = node;
        } else if (*sinalizador == '-') {
            struct TokenList *node = malloc(sizeof(struct TokenList));
            node->token = Menos;
            node->next = NULL;
            if (add_final == NULL) {
                *tokens = node;
            } else {
                add_final->next = node;
            }
            add_final = node;
            
        }  else if (*sinalizador == '*') {
            
         if (*(sinalizador + 1 ) == '*') {
            struct TokenList *node = malloc(sizeof(struct TokenList));
            node->token = Potencia;
            node->next = NULL;
                if (add_final == NULL) {
                    *tokens = node;
                } else {
                    add_final->next = node;
                }
                add_final = node;   
             sinalizador++;
             
        } 
         else {
           struct TokenList *node = malloc(sizeof(struct TokenList));
            node->token = Multiplicacao;
            node->next = NULL;
                if (add_final == NULL) {
                    *tokens = node;
                } else {
                    add_final->next = node;
                }
                 add_final = node;

         }
           
        }
        
         else if (*sinalizador == '/') {
            struct TokenList *node = malloc(sizeof(struct TokenList));
            node->token = Divisao;
            node->next = NULL;
            if (add_final == NULL) {
                *tokens = node;
            } else {
                add_final->next = node;
            }
            add_final = node;    
        } else if (*sinalizador != ' ') {
            struct TokenList *node = malloc(sizeof(struct TokenList));
            node->token = Indeterminado;
            node->next = NULL;
            if (add_final == NULL) {
                *tokens = node;
            } else {
                add_final->next = node;
            }
            add_final = node;
        }
        sinalizador++;
    }
}

void imprimir_tokens(struct TokenList *tokens) {
    printf("Tokens: ");
    while (tokens != NULL) {
        switch (tokens->token) {
        case Mais:
            printf("Mais, ");
            break;
        case Menos:
            printf("Menos, ");
            break;
        case Multiplicacao:
            printf("Multiplicar, ");
            break;
        case Potencia:
            printf("Potencia, ");
            break;
        case Divisao:
            printf("Dividir, ");
            break;
        case Indeterminado:
            printf("Indeterminado, ");
            break;
        }
        tokens = tokens->next;
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
     FILE *fp = fopen("input.txt", "r");
    if (fp == NULL) {
        printf("Erro ao abrir arquivo: %s\n", argv[1]);
        return 1;
    }

    char buffer[1024];
    struct TokenList *tokens = NULL;
    while (fgets(buffer, 1024, fp) != NULL) {
        buffer[strcspn(buffer, "\n")] = '\0';  // remove o caractere de nova linha
        usar_token(buffer, &tokens);
        imprimir_tokens(tokens);
    }

    fclose(fp);
    return 0;
}