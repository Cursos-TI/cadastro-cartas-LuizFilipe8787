#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 10        // tamanho do tabuleiro (10x10)
#define MAT 5       // tamanho das matrizes de habilidade (5x5)

// Função que inicializa o tabuleiro com zeros
void init_board(int board[N][N]) {
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            board[i][j] = 0;
}

// Gera a matriz "cone" (apex no topo, expandindo para baixo).
// Usamos MAT x MAT; o 'topo' do cone está na linha 0, coluna central.
void build_cone(int cone[MAT][MAT]) {
    int center = MAT / 2;
    for (int i = 0; i < MAT; ++i) {
        for (int j = 0; j < MAT; ++j) {
            // posição afetada se estiver entre center - i .. center + i (forma de cone apontando pra baixo)
            if (j >= center - i && j <= center + i)
                cone[i][j] = 1;
            else
                cone[i][j] = 0;
        }
    }
}

// Gera a matriz "cruz" (ponto de origem no centro).
void build_cross(int cross[MAT][MAT]) {
    int center = MAT / 2;
    for (int i = 0; i < MAT; ++i) {
        for (int j = 0; j < MAT; ++j) {
            // linha central ou coluna central -> cruz
            if (i == center || j == center)
                cross[i][j] = 1;
            else
                cross[i][j] = 0;
        }
    }
}

// Gera a matriz "octaedro" vista frontal -> losango (diamond).
// Usamos distância de Manhattan ao centro <= center para formar o losango.
void build_octa(int octa[MAT][MAT]) {
    int center = MAT / 2;
    for (int i = 0; i < MAT; ++i) {
        for (int j = 0; j < MAT; ++j) {
            int manhattan = abs(i - center) + abs(j - center);
            if (manhattan <= center)
                octa[i][j] = 1;
            else
                octa[i][j] = 0;
        }
    }
}


void overlay(int board[N][N], int mat[MAT][MAT], int size,
             int origin_r, int origin_c, const char *anchor) {

    int anchor_row = 0;
    int anchor_col = size / 2; // por padrão centro horizontal

    if (strcmp(anchor, "center") == 0) {
        anchor_row = size / 2;
        anchor_col = size / 2;
    } else if (strcmp(anchor, "top") == 0) {
        anchor_row = 0;
        anchor_col = size / 2;
    } else {
        // fallback para center
        anchor_row = size / 2;
        anchor_col = size / 2;
    }

    // Calcula a posição da célula mat[0..size-1][0..size-1] no tabuleiro
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (mat[i][j] != 1) continue; // só interessa células afetadas

            int board_r = origin_r + (i - anchor_row);
            int board_c = origin_c + (j - anchor_col);

            // garante dentro dos limites do tabuleiro
            if (board_r >= 0 && board_r < N && board_c >= 0 && board_c < N) {
                // marca 5 apenas se não for navio (3). Mantemos navio visível.
                if (board[board_r][board_c] == 0) {
                    board[board_r][board_c] = 5;
                }
                // se for 3 (navio), deixamos 3 para não sobrescrever visualmente
            }
        }
    }
}

// Função para imprimir o tabuleiro no console
// 0 = água, 3 = navio, 5 = área afetada
void print_board(int board[N][N]) {
    printf("\nTabuleiro (0=agua, 3=navio, 5=area afetada):\n\n");
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main(void) {
    int board[N][N];
    init_board(board);

    // --- Coloca alguns navios (valor 3) para demonstrar sobreposição ---
    // Exemplo simples: três partes de navio espalhadas
    board[2][2] = 3;
    board[2][3] = 3;
    board[2][4] = 3;

    board[5][6] = 3;
    board[6][6] = 3;

    board[8][1] = 3;

    // --- Constrói as matrizes de habilidade dinamicamente ---
    int cone[MAT][MAT];
    int cross[MAT][MAT];
    int octa[MAT][MAT];

    build_cone(cone);    // cone com apex no topo
    build_cross(cross);  // cruz com origem no centro
    build_octa(octa);    // losango (octaedro frontal) com origem no centro

    // --- Definir pontos de origem no tabuleiro (0-based) ---
    // Observação: posição definida diretamente no código conforme enunciado
    int origin_cone_r = 0;  // ex.: topo row 0 (o cone aponta para baixo a partir daqui)
    int origin_cone_c = 2;

    int origin_cross_r = 6;
    int origin_cross_c = 6;

    int origin_octa_r = 4;
    int origin_octa_c = 8;

    // --- Sobrepõe as habilidades no tabuleiro ---
    overlay(board, cone, MAT, origin_cone_r, origin_cone_c, "top");     // cone: apex no topo
    overlay(board, cross, MAT, origin_cross_r, origin_cross_c, "center"); // cruz: centro
    overlay(board, octa, MAT, origin_octa_r, origin_octa_c, "center");   // octaedro: centro

    // --- Exibe resultado ---
    print_board(board);


    return 0;
}
