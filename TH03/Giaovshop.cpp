#include <stdio.h>

// Hàm để sắp xếp mảng tăng dần
void sortArray(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

// Hàm để tính phép giao của hai mảng A và B
void intersection(int A[], int nA, int B[], int nB) {
    int i = 0, j = 0;
    while (i < nA && j < nB) {
        if (A[i] < B[j]) {
            i++;
        } else if (A[i] > B[j]) {
            j++;
        } else {
            printf("%d ", A[i]);
            i++;
            j++;
        }
    }
    if (i == 0)
        printf("none\n");
    else
        printf("\n");
}

// Hàm để tính phép hợp của hai mảng A và B
void unionSet(int A[], int nA, int B[], int nB) {
    int i = 0, j = 0;
    while (i < nA && j < nB) {
        if (A[i] < B[j]) {
            printf("%d ", A[i]);
            i++;
        } else if (A[i] > B[j]) {
            printf("%d ", B[j]);
            j++;
        } else {
            printf("%d ", A[i]);
            i++;
            j++;
        }
    }
    while (i < nA) {
        printf("%d ", A[i]);
        i++;
    }
    while (j < nB) {
        printf("%d ", B[j]);
        j++;
    }
    printf("\n");
}

int main() {
    int nA, nB;
    scanf("%d", &nA);
    int A[nA];
    for (int i = 0; i < nA; i++) {
        scanf("%d", &A[i]);
    }
    
    scanf("%d", &nB);
    int B[nB];
    for (int i = 0; i < nB; i++) {
        scanf("%d", &B[i]);
    }
    
    // Sắp xếp mảng tăng dần để làm phép giao và hợp
    sortArray(A, nA);
    sortArray(B, nB);

    // Tính và in ra màn hình kết quả của phép giao và hợp
    intersection(A, nA, B, nB);
    unionSet(A, nA, B, nB);

    return 0;
}
