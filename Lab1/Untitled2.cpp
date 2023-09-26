#include <stdio.h>
#define MAX_SIZE 100

void findIntersection(int A[], int n, int B[], int m) {
    int intersection[MAX_SIZE];
    int s = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (A[i] == B[j]) {
                intersection[s++] = A[i];
                break;
            }
        }
    }

    if (s == 0) {
        printf("none\n");
    } else {
        // Sort the intersection array in ascending order
        for (int i = 0; i < s - 1; i++) {
            for (int j = i + 1; j < s; j++) {
                if (intersection[i] > intersection[j]) {
                    int temp = intersection[i];
                    intersection[i] = intersection[j];
                    intersection[j] = temp;
                }
            }
        }

        for (int i = 0; i < s; i++) {
            printf("%d ", intersection[i]);
        }
        printf("\n");
    }
}

void findUnion(int A[], int n, int B[], int m) {
    int unionSet[MAX_SIZE];
    int s = 0;

    // Copy elements of set A to the unionSet
    for (int i = 0; i < n; i++) {
        unionSet[s++] = A[i];
    }

    // Add elements of set B to the unionSet if they are not already in it
    for (int i = 0; i < m; i++) {
        int flag = 0;
        for (int j = 0; j < s; j++) {
            if (B[i] == unionSet[j]) {
                flag = 1;
                break;
            }
        }
        if (!flag) {
            unionSet[s++] = B[i];
        }
    }

    // Sort the unionSet array in ascending order
    for (int i = 0; i < s - 1; i++) {
        for (int j = i + 1; j < s; j++) {
            if (unionSet[i] > unionSet[j]) {
                int temp = unionSet[i];
                unionSet[i] = unionSet[j];
                unionSet[j] = temp;
            }
        }
    }

    for (int i = 0; i < s; i++) {
        printf("%d ", unionSet[i]);
    }
    printf("\n");
}

int main() {
    int A[MAX_SIZE], B[MAX_SIZE];
    int n, m;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &B[i]);
    }
    findIntersection(A, n, B, m);
    findUnion(A, n, B, m);

    return 0;
}
