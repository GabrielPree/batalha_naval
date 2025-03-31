#include <stdio.h>
 
int main() {

    int tabuleiro[10][10] = {0}; //Inicializa o tabuleiro com 0 sinalizando água


    // Adiciona o navio de tamanho 3 na posição desejada na horizontal (linha 2, coluna E)
    int linha = 1;   // Linha 2 (índice 1)
    int colunaInicial = 4;  // Coluna E (índice 4)
    for (int i = 0; i < 3; i++) {
         tabuleiro[linha][colunaInicial + i] = 3;
    }
    // Adiciona o navio de tamanho 3 na posição desejada na vertical (linha 7, coluna B)
    int linha2 = 6;   // Linha 7 (índice 6)
    int coluna = 1;  // Coluna B (índice 1)
    for (int i = 0; i < 3; i++) {
         tabuleiro[linha2 + i][coluna] = 3;
    }
    // Adiciona o navio de tamanho 3 na posição desejada na diagonal para direita (linha 7, coluna E)
    int linha3 = 6;   // Linha 7 (índice 6)
    int coluna3 = 4;  // Coluna E (índice 4)
    for (int i = 0; i < 3; i++) {
            tabuleiro[linha3 + i][coluna3 + i] = 3;
    }
    // Adiciona o navio de tamanho 3 na posição desejada na diagonal para esquerda (linha 3, coluna I)
    int linha4 = 2;   // Linha 3 (índice 2)
    int coluna4 = 8;  // Coluna I (índice 8)
    for (int i = 0; i < 3; i++) {
            tabuleiro[linha4 + i][coluna4 - i] = 3;
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