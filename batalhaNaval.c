#include <stdio.h>

int main() {
    
    // --- NÍVEL AVENTUREIRO: TABULEIRO 10x10 E NAVIOS DIAGONAIS ---

    // Definição da matriz 10x10 para o tabuleiro
    // O valor 0 representa água e o valor 3 representa navio
    int tabuleiro[10][10];
    
    // Inicialização do tabuleiro: preenchendo tudo com 0 (água)
    // Usamos loops aninhados: um para percorrer as linhas (i) e outro as colunas (j)
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Definição das coordenadas iniciais dos 4 navios
    // O tamanho do navio é fixo em 3 posições
    
    // Navio 1: Horizontal (Linha fixa, Coluna aumenta)
    int navio1_linha = 1;
    int navio1_coluna = 1;

    // Navio 2: Vertical (Linha aumenta, Coluna fixa)
    int navio2_linha = 5;
    int navio2_coluna = 8;

    // Navio 3: Diagonal Principal (Linha aumenta E Coluna aumenta)
    int navio3_linha = 0;
    int navio3_coluna = 6;

    // Navio 4: Diagonal Secundária (Linha aumenta E Coluna diminui)
    int navio4_linha = 6;
    int navio4_coluna = 4;


    // --- POSICIONAMENTO DOS NAVIOS ---

    // Navio 1 (Horizontal)
    // Validação simples: verifica se a posição final cabe no tabuleiro (limite 10)
    if (navio1_coluna + 3 <= 10) {
        for (int i = 0; i < 3; i++) {
            // Somei 'i' apenas na coluna para andar para a direita
            tabuleiro[navio1_linha][navio1_coluna + i] = 3;
        }
    }

    // Navio 2 (Vertical)
    // Validação simples: verifica se a posição final da linha cabe no tabuleiro
    if (navio2_linha + 3 <= 10) {
        for (int i = 0; i < 3; i++) {
            // Somamos 'i' apenas na linha para andar para baixo
            tabuleiro[navio2_linha + i][navio2_coluna] = 3;
        }
    }

    // Navio 3 (Diagonal)
    // Lógica: Para ser diagonal, precisamos mover a linha e a coluna juntas.
    // Validei se cabe tanto na linha quanto na coluna.
    if (navio3_linha + 3 <= 10 && navio3_coluna + 3 <= 10) {
        for (int i = 0; i < 3; i++) {
            // Somei 'i' na linha E na coluna. Assim ele desce e vai para direita.
            tabuleiro[navio3_linha + i][navio3_coluna + i] = 3;
        }
    }

    // Navio 4 (Diagonal Inversa)
    // Lógica: A linha aumenta (desce), mas a coluna diminui (vai para esquerda).
    // Validei se a coluna não fica negativa (menor que 0).
    if (navio4_linha + 3 <= 10 && navio4_coluna - 3 >= -1) {
        for (int i = 0; i < 3; i++) {
            // Somei 'i' na linha e subtraímos 'i' da coluna
            tabuleiro[navio4_linha + i][navio4_coluna - i] = 3;
        }
    }

    // --- EXIBIÇÃO DO TABULEIRO ---
    
    printf("\n--- Batalha Naval: Nível Aventureiro ---\n");
    printf("Legenda: 0 = Água, 3 = Navio\n\n");

    // Loops aninhados para imprimir a matriz no formato de tabela
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n"); // Pula uma linha no final de cada linha da matriz
    }

    return 0;
}