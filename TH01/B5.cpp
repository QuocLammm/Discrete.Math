#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printPermutations(int arr[], int n) {
    int i, j, k;
    
    printf("Cac hoan vi cua tap {1, 2, ..., %d} la:\n", n);
    
    // In hoán v? ban d?u
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    // Tìm hoán vi lien sau và in ra
    while (1) {
        i = n - 2;
        while (i >= 0 && arr[i] >= arr[i + 1]) {
            i--;
        }
        if (i < 0) {
            break;
        }
        j = n - 1;
        while (arr[j] <= arr[i]) {
            j--;
        }
        swap(&arr[i], &arr[j]);
        k = i + 1;
        j = n - 1;
        while (k < j) {
            swap(&arr[k], &arr[j]);
            k++;
            j--;
        }
        
        // In hoán vi moi tìm duoc
        for (i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
}

int main() {
    int n;
    
    printf("Nhap so nguyên duong n: ");
    scanf("%d", &n);
    
    int arr[n];
    int i;
    for (i = 0; i < n; i++) {
        arr[i] = i + 1;
    }
    
    printPermutations(arr, n);
    
    return 0;
}

