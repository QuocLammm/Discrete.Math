#include <stdio.h>

void printCombination(int arr[], int n, int k) {
    int i, j;
    
    int index[k];
    for (i = 0; i < k; i++) {
        index[i] = i;
    }
    
    // In to hop ban dau
    for (i = 0; i < k; i++) {
        printf("%d ", arr[index[i]]);
    }
    printf("\n");
    
    // Tìm to hop lien sau và in ra
    while (1) {
        i = k - 1;
        while (i >= 0 && index[i] == n - k + i) {
            i--;
        }
        if (i < 0) {
            break;
        }
        index[i]++;
        for (j = i + 1; j < k; j++) {
            index[j] = index[j - 1] + 1;
        }
        
        // In to hop moi tìm du?c
        for (i = 0; i < k; i++) {
            printf("%d ", arr[index[i]]);
        }
        printf("\n");
    }
}

int main() {
    int n, k;
    printf("Nhap so nguyên duong n: "); scanf("%d", &n);
    printf("Nhap so nguyên duong k: "); scanf("%d", &k);
    int arr[n];
    int i;
    for (i = 0; i < n; i++) {
        arr[i] = i + 1;
    }
    
    printCombination(arr, n, k);
    
    return 0;
}

