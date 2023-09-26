#include <stdio.h>
#include <stdbool.h>

bool check(double a, double b) {
    // Kiem tra neu a khác 0, hàm f(x) có dang ax^2 + bx + c
    if (a != 0) {
        return true; // Hàm f(x) là hàm bac 2 và luon toànn ánh
    }
    // Kiem tra neu a = 0 và b khác 0, h�m f(x) có dang bx + c
    if (b != 0) {
        return true; // Hàm f(x) là hàm bac 1 và luôn toàn ánh
    }
    return false; // Kiem tra neu a = b = 0, hàm f(x) có dang c
    			  // Hàm f(x) là hàm hang ss, chi toàn ánh neu c khác 0
}

int main() {
    double a, b, c;
    printf("Nhap gia tri a, b, c: \n");
    scanf("\n%lf %lf %lf", &a, &b, &c);
    if (check(a, b)) {
        printf("Hàm f(x) là mot hàm toàn ánh.\n");
    } else {
        printf("Hàm f(x) không phai là hàm toàn ánh.\n");
    }
    return 0;
}

