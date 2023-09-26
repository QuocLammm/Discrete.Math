#include <stdio.h>

#define MAX_DIGITS 500000

void multiply(int result[], int *resultSize, int num) {
    int carry = 0;

    for (int i = 0; i < *resultSize; i++) {
        int product = result[i] * num + carry;
        result[i] = product % 10;
        carry = product / 10;
    }

    while (carry) {
        result[*resultSize] = carry % 10;
        carry = carry / 10;
        (*resultSize)++;
    }
}

void calculateFactorial(int n) {
    int result[MAX_DIGITS] = {0};
    result[0] = 1;
    int resultSize = 1;

    for (int i = 2; i <= n; i++) {
        multiply(result, &resultSize, i);
    }
    for (int i = resultSize - 1; i >= 0; i--) {
        printf("%d", result[i]);
    }
    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n);
    calculateFactorial(n);
    return 0;
}

