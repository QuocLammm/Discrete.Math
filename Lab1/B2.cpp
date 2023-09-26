#include <stdio.h>
#define MAX_SIZE 100

void phephop(int A[], int n, int B[], int m, int resultSet[], int *s) {
    int i, j, k;
    *s = 0;

    // hop cac phan tu cua A vao KQ
    for (i = 0; i < n; i++) {
        resultSet[*s] = A[i];
        (*s)++;
    }
    //Kiem tra tung phan tu cua tap hop B
    for (i = 0; i < m; i++) {
        int flag = 0;
        // Kiem tra phan tu d� ton tai trong KQ hay chua?
        for (j = 0; j < *s; j++) {
            if (B[i] == resultSet[j]) {
                flag = 1;
                break;
            }
        }
        // Neu phan tu kh�ng ton tai th� them v�o tap KQ
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

int main() {
    int A[MAX_SIZE], B[MAX_SIZE], resultSet[MAX_SIZE];
    int n, m, s, i;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }
    scanf("%d", &m);
    for (i = 0; i < m; i++) {
        scanf("%d", &B[i]);
    }
    phephop(A, n, B, m, resultSet, &s);
    for (i = 0; i < s; i++) {
        printf("%d ", resultSet[i]);
    }
    return 0;
}

