#include <stdio.h>
#include <stdbool.h>
#define max 100

int G[max][max];
int n; // số đỉnh của đồ thị

// Tô màu đồ thị vô hướng G sử dụng thuật toán Welsh-Powell
void tomau_dothi() {
    int colors[max] = {0}; // Mảng chứa màu của từng đỉnh, mặc định là 0
    int demcolor = 0; // Số lượng màu đã sử dụng
    for (int i = 0; i < n; i++) {
        if (colors[i] == 0) {
            demcolor++;
            colors[i] = demcolor;
            for (int j = i + 1; j < n; j++) {
                if (G[i][j] == 0 && colors[j] == 0) {
                    colors[j] = demcolor;
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        printf("dinh %d: mau %d\n", i, colors[i]);
    }
    printf("K - sac = %d\n", demcolor);
}

int main() {
    printf("Nhap so dinh cua do thi: "); scanf("%d", &n);
    printf("Nhap ma tran ke:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &G[i][j]);
        }
    }
    tomau_dothi();
    return 0;
}
