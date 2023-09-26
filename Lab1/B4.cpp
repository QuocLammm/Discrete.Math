#include <stdio.h>
#define MAX_SIZE 100

void tichdescartes(int A[], int n, int B[], int m) {
    int i, j;
    printf("Tích Descartes cua hai tap hop A và B:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("(%d, %d) ", A[i], B[j]);
        }
        printf("\n");
    }
}

int main() {
    int A[MAX_SIZE], B[MAX_SIZE];
    int n, m;

    // Nhap so luong phan tu cua tap hop A
    printf("Nhap so luong phan tu cua tap hop A: ");
    scanf("%d", &n);

    // Nhap cac phan tu cua tap hop A
    printf("Nhap cac phan tu cua tap hop A:\n");
    for (int i = 0; i < n; i++) {
        printf("Phan tu thu %d: ", i + 1);
        scanf("%d", &A[i]);
    }

    // Nhap so luong phan tu cua tap hop B
    printf("\nNhap so luong phan tu cua tap hop B: ");
    scanf("%d", &m);

    //Nhap cac phan tu cua tap hop B
    printf("Nhap cac phan tu cua tap hop B:\n");
    for (int i = 0; i < m; i++) {
        printf("Phan tu thu %d: ", i + 1);
        scanf("%d", &B[i]);
    }
    // goi ham
    tichdescartes(A, n, B, m);
    return 0;
}

