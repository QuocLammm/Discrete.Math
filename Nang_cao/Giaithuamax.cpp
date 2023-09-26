#include <stdio.h>

void calculateFactorial(int n) {
    int result[100000];
    result[0] = 1;
    int resultSize = 1;

    for (int i = 2; i <= n; i++) {
        int carry = 0;
        for (int j = 0; j < resultSize; j++) {
            int product = result[j] * i + carry;
            result[j] = product % 10;
            carry = product / 10;
        }
        while (carry) {
            result[resultSize] = carry % 10;
            carry = carry / 10;
            resultSize++;
        }
    }

    for (int i = resultSize - 1; i >= 0; i--) {
        printf("%d", result[i]);
    }
    printf("\n");
}

int main() {
    int n = 10000;
    calculateFactorial(n);

    return 0;
}

