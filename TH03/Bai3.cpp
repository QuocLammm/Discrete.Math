

// float check(int year) {
//     if (year < 12 && year >= 6) {
//         return 0.066f;
//     } else if (year < 6 && year >= 3) {
//         return 0.056f;
//     } else {
//         return 0.046f;
//     }
// }

// float calculateInterest(float allmoney, int count, int month) {
//     float lai = 0.076f;
//     allmoney = powf(1 + lai, count) * allmoney;
//     lai = check(month);
//     allmoney = (1 + lai) * allmoney;
//     return allmoney;
// }

// float TinhTien(float year, float allmoney) {
//     int count = (int)year;
//     int month = (int)((year - count) * 12);
//     return calculateInterest(allmoney, count, month);
// }

// int main() {
//     float year, money;
//     scanf("%f %f", &year, &money);
//     printf("%.6f\n", TinhTien(year, money));
    
//     return 0;
// }


#include <stdio.h>
#include <math.h>

int main() {
    int n;
    double M, ls;

    printf("Nhập số tháng, số tiền gốc ban đầu và lãi suất tiết kiệm (cách nhau bằng khoảng trắng): ");
    scanf("%d %lf %lf", &n, &M, &ls);

    double total_amount = M * pow(1 + ls / 100, n);
    printf("Số tiền nhận được sau %d tháng: %.6lf\n", n, total_amount);

    return 0;
}
