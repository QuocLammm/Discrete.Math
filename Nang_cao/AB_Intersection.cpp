#include <stdio.h>
#include <stdlib.h>

// H�m s?p x?p m?ng s? nguy�n b?ng thu?t to�n Insertion Sort
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

// H�m ki?m tra hai t?p h?p A v� B c� b?ng nhau kh�ng
int Check(int A[], int n, int B[], int m) {
    if (n != m) {
        return 0;  // A kh�c B v� s? ph?n t? kh�c nhau
    }

    // S?p x?p c�c t?p h?p A v� B
    insertionSort(A, n);
    insertionSort(B, m);

    // So s�nh t?ng ph?n t? c?a hai t?p h?p
    for (int i = 0; i < n; i++) {
        if (A[i] != B[i]) {
            return 0;  // A kh�c B v� ph?n t? kh�ng gi?ng nhau
        }
    }
    return 1;  // A = B
}

int main() {
    int n, m;

    printf("Nh?p s? ph?n t? c?a t?p h?p A: ");
    scanf("%d", &n);

    int A[n];

    printf("Nh?p c�c ph?n t? c?a t?p h?p A:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    printf("Nh?p s? ph?n t? c?a t?p h?p B: ");
    scanf("%d", &m);

    int B[m];

    printf("Nh?p c�c ph?n t? c?a t?p h?p B:\n");
    for (int i = 0; i < m; i++) {
        scanf("%d", &B[i]);
    }

    if (Check(A, n, B, m)) {
        printf("A = B\n");
    } else {
        printf("A kh�c B\n");
    }
    return 0;
}

