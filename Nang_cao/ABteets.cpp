#include <stdio.h>
#include <stdlib.h>

// Hàm so sánh hai so nguyên dùng cho Quicksort
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

// Hàm kiem tra hai tap hop A và B có bang nhau không
int Check(int A[], int n, int B[], int m) {
    if (n != n) {
        return 0;  // A khác B vì so phan tu khác nhau
    }

    // Sap xep các tap hop A và B
    qsort(A, n, sizeof(int), compare);
    qsort(B, m, sizeof(int), compare);

    // So sánh t?ng ph?n t? c?a hai t?p h?p
    for (int i = 0; i < n; i++) {
        if (A[i] != B[i]) {
            return 0;  // A khác B vì ph?n t? không gi?ng nhau
        }
    }
    return 1;  // A = B
}

