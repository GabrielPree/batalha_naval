#include <stdio.h> 

#define LINHAS 10
#define COLUNAS 10
#define TAMANHO_NAVIO 3

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[LINHAS][COLUNAS]) {
    // Exibe o tabuleiro com os números das linhas e letras das colunas
    printf("   ");// Espaço para o cabeçalho das colunas
    for (char j = 'A'; j < 'A' + COLUNAS; j++) { // letras de A a J pois A + colunas(10) = K
        printf("%c ", j); // Preenche as Colunas com letras de A a J
    }
    printf("\n");
    for (int i = 0; i < LINHAS; i++) {
        printf("%2d ", i + 1); // Preenche a linha com números de 1 a 10
        for (int j = 0; j < COLUNAS; j++) {
            printf("%d ", tabuleiro[i][j]); // Preenche o tabuleiro com 0s e 3s
        }
        printf("\n");
    }
}

// Função para verificar se a posição do navio é válida
int verificarPosicao(int tabuleiro[LINHAS][COLUNAS], int linha, int coluna, char orientacao) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) { // Loop para verificar a posição do navio
        // Inicializa as coordenadas x e y com a linha e coluna fornecidas na função adicionarNavio
        int x = linha; 
        int y = coluna;

        switch (orientacao) { // Verifica a orientação do navio
            case 'H': // Horizontal
                y += i;
                break;
            case 'V': // Vertical
                x += i;
                break;
            case 'D': // Diagonal para a direita 
                x += i;
                y += i;
                break;
            case 'E': // Diagonal para a esquerda
                x += i;
                y -= i;
                break;
            default:
                return 0; 
        }

        // Verifica se a posição está fora dos limites ou sobrepondo outro navio
        if (x >= LINHAS || y >= COLUNAS || y < 0 || tabuleiro[x][y] == 3) { 
            return 0;
        }
    }
    return 1;
}

//função para adicionar navio ao tabuleiro
void adicionarNavio(int tabuleiro[LINHAS][COLUNAS]) {
    /*
    -Solicita ao usuário a linha, coluna e orientação do navio.
    -Verifica se a posição é válida e se não há sobreposição com outro navio.
    -Se a posição for válida, adiciona o navio ao tabuleiro.
    -Se não for válida, solicita novamente a posição.
    -repete o processo até que uma posição válida seja fornecida.
    */
    int linha, coluna;
    char orientacao;

    printf("Digite a linha de início (1 a %d): ", LINHAS);
    scanf("%d", &linha); // Solicita a linha de início
    linha--; // Ajusta para o índice da matriz (0 a 9)
    if (linha < 0 || linha >= LINHAS) { // Verifica se a linha está dentro dos limites
        printf("Linha inválida! Tente novamente.\n");
        adicionarNavio(tabuleiro);
        return;
    }
    printf("Digite a coluna de início (A a J): "); 
    scanf(" %c", &orientacao);  // Solicita a coluna de início
    coluna = orientacao - 'A'; // Converte a letra para índice
    if (coluna < 0 || coluna >= COLUNAS) { // Verifica se a coluna está dentro dos limites
        printf("Coluna inválida! Tente novamente.\n");
        adicionarNavio(tabuleiro);
        return;
    }
    printf("Digite a orientação (H para horizontal, V para vertical, D para diagonal direita, E para diagonal esquerda): "); 
    scanf(" %c", &orientacao); // Solicita a orientação do navio
    // Verificação da posição e orientação
    if (!verificarPosicao(tabuleiro, linha, coluna, orientacao)) {
        printf("Posição inválida ou sobreposição de navio! Tente novamente.\n"); 
        adicionarNavio(tabuleiro); // Se a posição for inválida, chama a função novamente para solicitar uma nova posição
        return;
    }
    // Adiciona o navio na posição especificada
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        // Inicializa as coordenadas x e y com a linha e coluna fornecidas
        int x = linha;
        int y = coluna;

        switch (orientacao) {
            case 'H': // Horizontal
                y += i; // Incrementa a coluna para a posição horizontal
                break;
            case 'V': // Incrementa a linha para a posição vertical
                x += i;
                break;
            case 'D': // Incrementa a linha e coluna para a posição diagonal direita
                x += i;
                y += i;
                break;
            case 'E': // Incrementa a linha e decrementa a coluna para a posição diagonal esquerda
                x += i;
                y -= i;
                break;
        }
        tabuleiro[x][y] = 3; // Marca a posição do navio no tabuleiro com o número 3
    }
    printf("Navio adicionado com sucesso!\n"); // Exibe mensagem de sucesso ao adicionar o navio
}

// função para adicionar o poder cone ao tabuleiro
void poderCone(int tabuleiro[LINHAS][COLUNAS]) {
    int x = 0, y = 3; // Coordenadas iniciais do poder cone
    for (int i = 0; i < 3; i++) {
        for (int j = -i; j <= i; j++) {  // O loop interno vai de -i até +i para formar o cone
            int nx = x + i;    // Coordenada da linha
            int ny = y + j;    // Coordenada da coluna
            // Verifica se as coordenadas estão dentro dos limites do tabuleiro
            if (nx >= 0 && nx < LINHAS && ny >= 0 && ny < COLUNAS) {
                tabuleiro[nx][ny] = 5;  // Marca a posição do poder cone no tabuleiro com o número 5
            }
        }
    }
}

// função para adicionar o poder cruz ao tabuleiro
void poderCruz(int tabuleiro[LINHAS][COLUNAS]) {
    int x = 4, y = 6; // Coordenadas iniciais do poder cruz
    // Horizontal - 5 casas no total (2 para cada lado e a central)
    for (int j = -2; j <= 2; j++) { // j -2 a 2 para cobrir 5 casas pois 2 para cada lado e a central
        int ny = y + j; // Coordenada da coluna
        if (ny >= 0 && ny < COLUNAS) { // Verifica se está dentro dos limites
            tabuleiro[x][ny] = 5; // Marca a posição na linha central
        }
    }
    // Vertical - 3 casas no total (1 para cima e 1 para baixo)
    for (int i = -1; i <= 1; i++) { // i -1 a 1 para cobrir 3 casas pois 1 para cima e 1 para baixo
        int nx = x + i; // Coordenada da linha
        if (nx >= 0 && nx < LINHAS) { // Verifica se está dentro dos limites
            tabuleiro[nx][y] = 5; // Marca a posição na coluna central
        }
    }
}

// função para adicionar o poder octaedro ao tabuleiro
void poderOctaedro(int tabuleiro[LINHAS][COLUNAS]) {
    int x = 7, y = 2; // Coordenadas iniciais do poder cruz
    // Horizontal - 3 casas no total (1 para cada lado e a central)
    for (int j = -1; j <= 1; j++) { // j -1 a 1 para cobrir 3 casas pois 1 para cada lado e a central
        int ny = y + j; // Coordenada da coluna
        if (ny >= 0 && ny < COLUNAS) { // Verifica se está dentro dos limites
            tabuleiro[x][ny] = 5; // Marca a posição na linha central
        }
    }
    // Vertical - 3 casas no total (1 para cima e 1 para baixo)
    for (int i = -1; i <= 1; i++) { // i -1 a 1 para cobrir 3 casas pois 1 para cima e 1 para baixo
        int nx = x + i; // Coordenada da linha
        if (nx >= 0 && nx < LINHAS) { // Verifica se está dentro dos limites
            tabuleiro[nx][y] = 5; // Marca a posição na coluna central
        }
    }
}

// Função principal
int main() {

    // Inicializa o tabuleiro com água (0)
    int tabuleiro[LINHAS][COLUNAS] = {0};
    int quantidade;

    printf("Bem-vindo ao jogo Batalha Naval!\n");
    printf("Tabuleiro inicial:\n");
    exibirTabuleiro(tabuleiro); // Exibe o tabuleiro inicial
    printf("Quantos navios deseja adicionar? "); // Pergunta ao usuário quantos navios deseja adicionar
    scanf("%d", &quantidade);
    for (int i = 0; i < quantidade; i++) { // Loop para adicionar os navios
        printf("\nAdicionando navio %d/%d:\n", i + 1, quantidade);// Exibe o número do navio
        adicionarNavio(tabuleiro);// Chama a função para adicionar o navio
        exibirTabuleiro(tabuleiro);// Exibe o tabuleiro após adicionar o navio+
    }
    printf("\nTabuleiro após adicionar os Poderes:\n");
    poderCone(tabuleiro); // Chama a função para adicionar o poder cone
    poderCruz(tabuleiro); // Chama a função para adicionar o poder cruz
    poderOctaedro(tabuleiro); // Chama a função para adicionar o poder octaedro
    exibirTabuleiro(tabuleiro); // Exibe o tabuleiro após adicionar os 


    return 0;
}