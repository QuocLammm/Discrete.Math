#include <stdio.h>
#include <stdlib.h>

// H�m so s�nh hai so nguy�n d�ng cho Quicksort
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

// H�m kiem tra hai tap hop A v� B c� bang nhau kh�ng
int Check(int A[], int n, int B[], int m) {
    if (n != n) {
        return 0;  // A kh�c B v� so phan tu kh�c nhau
    }

    // Sap xep c�c tap hop A v� B
    qsort(A, n, sizeof(int), compare);
    qsort(B, m, sizeof(int), compare);

    // So s�nh t?ng ph?n t? c?a hai t?p h?p
    for (int i = 0; i < n; i++) {
        if (A[i] != B[i]) {
            return 0;  // A kh�c B v� ph?n t? kh�ng gi?ng nhau
        }
    }
    return 1;  // A = B
}

