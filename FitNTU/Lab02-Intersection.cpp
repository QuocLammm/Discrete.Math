#include <stdio.h>
#define MAX_SIZE 100

int check(int n, int arr[], int len) {
    for (int i = 0; i < len; i++) {
        if (arr[i] == n) {
            return 1; 
        }
    }
    return 0; 
}

void sortArray(int arr[], int len) {
    for (int i = 0; i < len - 1; i++) {
        for (int j = 0; j < len - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int A[MAX_SIZE], B[MAX_SIZE], intersection[MAX_SIZE];
    int n, m, s = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &B[i]);
    }
    for (int i = 0; i < n; i++) {
        if (check(A[i], B, m)) {
            intersection[s++] = A[i];
        }
    }
    sortArray(intersection, s);
    if (s == 0) {
        printf("none\n");
    } else {
        for (int i = 0; i < s; i++) {
            printf("%d ", intersection[i]);
        }
        printf("\n");
    }
    return 0;
}

