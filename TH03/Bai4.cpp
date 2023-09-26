#include <stdio.h>

// Hàm tính hệ số thứ n của dãy số
int heSoThuN(int n) {
    if (n == 0) {
        return 1;
    } else if (n == 1) {
        return 2;
    } else if (n == 2) {
        return 3;
    } else {
        int a = 3;
        int b = 2;
        int c = 1;
        int A;

        for (int i = 3; i <= n; i++) {
            A = a + 2 * b + 3 * c; // công thức tổng quát

            // Cập nhật các hệ số
            c = b;
            b = a;
            a = A;
        }

        return A;
    }
}

int main() {
    int n;
    printf("Nhap n (n >= 3): ");
    scanf("%d", &n);

    if (n >= 3) {
        printf("He so thu %d caa day so la: %d\n", n, heSoThuN(n));
    } else {
        printf("Nhap n lon hon hoac = 3.\n");
    }

    return 0;
}
