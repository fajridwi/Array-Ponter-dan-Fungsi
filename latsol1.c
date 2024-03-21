#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Fungsi untuk menghitung jumlah langkah pertukaran yang diperlukan
int countSwaps(int *cards, int n) {
    int swaps = 0;

    // Menggunakan algoritma Selection Sort untuk mengurutkan kartu
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (cards[j] < cards[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            // Jika kartu dengan nilai terkecil tidak berada di posisi saat ini, lakukan pertukaran
            int temp = cards[i];
            cards[i] = cards[minIndex];
            cards[minIndex] = temp;
            swaps++;
        }
    }

    return swaps;
}

int main() {
    int n;
    // Meminta input jumlah kartu
    printf("Masukkan Jumlah Kartu: ");
    if (scanf("%d", &n) != 1) {
        printf("Invalid input\n");
        return 1;
    }

    int *cards = (int *)malloc(n * sizeof(int));
    if (cards == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Membaca nilai kartu
    printf("Masukkan Nilai Kartu: ");
    for (int i = 0; i < n; i++) {
        char value[10];
        if (scanf("%s", value) != 1) {
            printf("Invalid input\n");
            free(cards);
            return 1;
        }
        if (strcmp(value, "J") == 0) {
            cards[i] = 11;
        } else if (strcmp(value, "Q") == 0) {
            cards[i] = 12;
        } else if (strcmp(value, "K") == 0) {
            cards[i] = 13;
        } else if (strcmp(value, "A") == 0) {
            cards[i] = 1;
        } else {
            cards[i] = atoi(value);
            if (cards[i] < 1 || cards[i] > 10) {
                printf("Invalid input\n");
                free(cards);
                return 1;
            }
        }
    }

    // Menghitung jumlah langkah pertukaran yang diperlukan untuk mengurutkan kartu
    int minSwaps = countSwaps(cards, n);

    // Menampilkan output sesuai yang diharapkan
    printf("Jumlah minimal langkah pertukaran: %d\n", minSwaps);

    free(cards); // Dealokasi memori
    return 0;
}