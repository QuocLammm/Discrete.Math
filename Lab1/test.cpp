#include <stdio.h>
#define MAX_SIZE 100

void phephop(int A[], int n, int B[], int m, int resultSet[], int *s) {
    int i, j, k;
    *s = 0;
    for (i = 0; i < n; i++) {
        resultSet[*s] = A[i];
        (*s)++;
    }
    for (i = 0; i < m; i++) {
        int flag = 0;
        for (j = 0; j < *s; j++) {
            if (B[i] == resultSet[j]) {
                flag = 1;
                break;
            }
        }
        if (!flag) {
            resultSet[*s] = B[i];
            (*s)++;
        }
    }
  	for (i = 0; i < *s - 1; i++) {
        for (j = i + 1; j < *s; j++) {
            if (resultSet[i] > resultSet[j]) {
                int temp = resultSet[i];
                resultSet[i] = resultSet[j];
                resultSet[j] = temp;
            }
        }
    }
}

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
    int A[MAX_SIZE], B[MAX_SIZE], resultSet[MAX_SIZE], intersection[MAX_SIZE];
    int n, m, s=0, i;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }
    scanf("%d", &m);
    for (i = 0; i < m; i++) {
        scanf("%d", &B[i]);
    }
  	for (int i = 0; i < n; i++) {
        if (check(A[i], B, m)) {
            intersection[s++] = A[i];
        }
    }
    if (s == 0) {
        printf("none\n");
    } else {
        for (int i = 0; i < s; i++) {
            printf("%d ", intersection[i]);
        }
        printf("\n");
    }
    phephop(A, n, B, m, resultSet, &s);
    sortArray(resultSet, s); // S?p x?p k?t qu? c?a phephop theo th? t? tang d?n
    for (i = 0; i < s; i++) {
        printf("%d ", resultSet[i]);
    }
    return 0;
}

