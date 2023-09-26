#include <stdio.h>
#include <stdlib.h>

// Hàm s?p x?p m?ng s? nguyên b?ng thu?t toán Insertion Sort
void insertionSort(int arr[], int size) {
    int i, key, j;
    for (i = 1; i < size; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Hàm ki?m tra hai t?p h?p A và B có b?ng nhau không
int Check(int A[], int n, int B[], int m) {
    if (n != m) {
        return 0;  // A khác B vì s? ph?n t? khác nhau
    }

    // S?p x?p các t?p h?p A và B
    insertionSort(A, n);
    insertionSort(B, m);

    // So sánh t?ng ph?n t? c?a hai t?p h?p
    for (int i = 0; i < n; i++) {
        if (A[i] != B[i]) {
            return 0;  // A khác B vì ph?n t? không gi?ng nhau
        }
    }
    return 1;  // A = B
}

int main() {
    int n, m;

    printf("Nh?p s? ph?n t? c?a t?p h?p A: ");
    scanf("%d", &n);

    int A[n];

    printf("Nh?p các ph?n t? c?a t?p h?p A:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    printf("Nh?p s? ph?n t? c?a t?p h?p B: ");
    scanf("%d", &m);

    int B[m];

    printf("Nh?p các ph?n t? c?a t?p h?p B:\n");
    for (int i = 0; i < m; i++) {
        scanf("%d", &B[i]);
    }

    if (Check(A, n, B, m)) {
        printf("A = B\n");
    } else {
        printf("A khác B\n");
    }
    return 0;
}

