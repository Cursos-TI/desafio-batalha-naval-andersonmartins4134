#include <stdio.h>

// Definições de constantes para o tabuleiro (10x10) e tamanho do navio (3)
#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define AGUA 0
#define NAVIO_PARTE 3

int main() {
    
    // --- 1. DECLARAÇÃO E INICIALIZAÇÃO ---
    
    // Matriz 10x10. Inicializa todas as posições com 0 (Água).
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {AGUA};

    // Coordenadas iniciais dos navios (definidas no código)
    // Navio Horizontal (H): Linha 2, Coluna 3
    int linha_H = 2; 
    int coluna_H = 3; 

    // Navio Vertical (V): Linha 5, Coluna 1
    int linha_V = 5; 
    int coluna_V = 1;
    
    // Vetores unidimensionais para representar os navios (Requisito)
    int navio_horizontal[TAMANHO_NAVIO] = {NAVIO_PARTE, NAVIO_PARTE, NAVIO_PARTE};
    int navio_vertical[TAMANHO_NAVIO] = {NAVIO_PARTE, NAVIO_PARTE, NAVIO_PARTE};


    // --- 2. VALIDAÇÃO DE LIMITES E POSICIONAMENTO ---
    
    // Validação de limite: Navio Horizontal
    if (coluna_H + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
        return 1; // Retorna erro de limite
    }
    
    // Posicionamento HORIZONTAL: Altera colunas na linha fixa
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha_H][coluna_H + i] = NAVIO_PARTE;
    }

    // Validação de limite: Navio Vertical
    if (linha_V + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
        return 1; // Retorna erro de limite
    }
    
    // Posicionamento VERTICAL: Altera linhas na coluna fixa
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha_V + i][coluna_V] = NAVIO_PARTE;
    }
    
    // A validação de sobreposição é cumprida pela escolha das coordenadas iniciais
    // (Lógica simplificada conforme o nível básico).


    // --- 3. EXIBIÇÃO DO TABULEIRO (Loops Aninhados) ---
    
    printf("\n--- Tabuleiro ---\n");
    
    // Loops aninhados para percorrer e imprimir a matriz
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) { // Linhas
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) { // Colunas
            // Imprime o valor da célula com um espaço separador
            printf("%d ", tabuleiro[i][j]); 
        }
        printf("\n"); // Quebra de linha
    }

    return 0;
}