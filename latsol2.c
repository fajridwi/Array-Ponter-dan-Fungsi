#include <stdio.h>

int isValidPosition(int x, int y, int size) {
    return (x >= 0 && x < size && y >= 0 && y < size);
}

void koboImaginaryChess(int i, int j, int size, int *chessBoard) {
    int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
    int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

    for (int k = 0; k < 8; k++) {
        int ni = i + dx[k];
        int nj = j + dy[k];
        
        if (isValidPosition(ni, nj, size)) {
            chessBoard[ni * size + nj] = 1;
        }
    }
}

int main() {
    int i, j;
    printf("Masukkan posisi i dan j: ");
    scanf("%d %d", &i, &j);

    int size = 8;
    int chessBoard[size][size];
    for (int x = 0; x < size; x++) {
        for (int y = 0; y < size; y++) {
            chessBoard[x][y] = 0;
        }
    }

    koboImaginaryChess(i, j, size, (int *)chessBoard);

    for (int x = 0; x < size; x++) {
        for (int y = 0; y < size; y++) {
            printf("%d", chessBoard[x][y]);
        }
        printf("\n");
    }

    return 0;
} 