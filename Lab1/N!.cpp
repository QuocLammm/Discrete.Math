#include <stdio.h>
#include <gmp.h>

void calculateFactorial(int n) {
    mpz_t result;
    mpz_init(result); // Khởi tạo biến kết quả

    mpz_fac_ui(result, n); // Tính giai thừa của n và lưu kết quả vào biến result

    // In kết quả
    printf("Giai thua cua %d la:\n", n);
    mpz_out_str(stdout, 10, result); // In kết quả dưới dạng chuỗi số hệ thập phân
    printf("\n");

    // Giải phóng bộ nhớ
    mpz_clear(result);
}

int main() {
    int n;
    printf("Nhap vao mot so nguyen: ");
    scanf("%d", &n);

    calculateFactorial(n);

    return 0;
}
