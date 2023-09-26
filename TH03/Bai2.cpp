#include <stdio.h>

// Hàm tính số hạng thứ n của dãy Fibonacci
unsigned long long int fibonacci(int n) {
    unsigned long long int fib[n + 1];
    fib[0] = 0;
    fib[1] = 1;

    // Nếu n < 2, số hạng thứ n sẽ là n chính nó
    if (n < 2) {
        return fib[n];
    }

    for (int i = 2; i <= n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    return fib[n];
}

int main() {
    int n;
    printf("Nhap so N: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("so N khong am.\n");
    } else {
        printf("So hang thu %d cua day Fibonacci la: %llu\n", n, fibonacci(n));
    }
    return 0;
}




