#include <stdio.h>
#define MAX_SIZE 100

void phephieu(int A[], int n, int B[], int m, int resultSet[], int *s) {
    int i, j;
    *s = 0;

    // Kiem tra tung phan tu cua tap hop A
    for (i = 0; i < n; i++) {
        int flag = 0;

        // Kiem tra xem phan tu có thuoc tap hop B hay không
        for (j = 0; j < m; j++) {
            if (A[i] == B[j]) {
                flag = 1;
                break;
            }
        }

        // Neu phan tu không thuoc tap hop B, thêm nó vào tap KQ
        if (!flag) {
            resultSet[*s] = A[i];
            (*s)++;
        }
    }
}

int main() {
    int A[MAX_SIZE], B[MAX_SIZE], resultSet[MAX_SIZE];
    int n, m, s, i;

    // Nhap so luong phan tu cua tap hop A
    printf("Nhap so luong phan tu cua tap hop A: ");
    scanf("%d", &n);

    // Nhap cac phan tu cua tap hop A
    printf("Nhap cac phan tu cua tap hop A:\n");
    for (i = 0; i < n; i++) {
        printf("Phan tu thu %d: ", i + 1);
        scanf("%d", &A[i]);
    }

    // Nhap so luong phan tu cua tap hop B
    printf("\nNhap so luong phan tu cua tap hop B: ");
    scanf("%d", &m);

    //Nhap cac phan tu cua tap hop B
    printf("Nhap cac phan tu cua tap hop B:\n");
    for (i = 0; i < m; i++) {
        printf("Phan tu thu %d: ", i + 1);
        scanf("%d", &B[i]);
    }

    phephieu(A, n, B, m, resultSet, &s);

    // In ra ket qua
    printf("\nKet qua cua phep hieu (A/B):\n");
    for (i = 0; i < s; i++) {
        printf("%d ", resultSet[i]);
    }
    return 0;
}

