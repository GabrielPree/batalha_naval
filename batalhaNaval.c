#include <stdio.h>
 
int main() {

    int tabuleiro[10][10] = {0}; //Inicializa o tabuleiro com 0 sinalizando água


    // Adiciona o navio de tamanho 3 na posição desejada (linha 2, coluna E)
    int linha = 1;   // Linha 2 (índice 1)
    int colunaInicial = 4;  // Coluna E (índice 4)
    for (int i = 0; i < 3; i++) {
         tabuleiro[linha][colunaInicial + i] = 3;
    }

    printf("Bem-vindo ao jogo Batalha Naval!\n");
    printf("\n   ");
    for (char j = 'A'; j <= 'J'; j++) {
        printf("%c ", j); // Preenche as Colunas com letras de A a J
    }
    printf("\n");
    for (int i = 0; i < 10; i++) {
        printf("%2d ", i + 1); // Preenche a linha com números de 1 a 10
        for (int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}