#include <stdio.h>
#define MAX_SIZE 100

int TimHT(int n, int MTK[][MAX_SIZE], int k, int v_i, int v_j) {
    if (k == 0) {
        // Nếu độ dài hành trình là 0, chỉ đếm nếu đỉnh xuất phát và đỉnh kết thúc trùng nhau
        return (v_i == v_j) ? 1 : 0;
    }

    int num = 0;
    for (int i = 0; i < n; i++) {
        // Kiểm tra xem có cạnh nối từ đỉnh v_i tới đỉnh i hay không
        if (MTK[v_i][i] == 1) {
            // Đệ quy tính số hành trình từ đỉnh i tới đỉnh v_j với độ dài giảm đi 1
            num += TimHT(n, MTK, k - 1, i, v_j);
        }
    }
    return num;
}

int main() {
    int n;
    scanf("%d", &n);
    int MTK[MAX_SIZE][MAX_SIZE];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &MTK[i][j]);
        }
    }

    int k, v_i, v_j;
    scanf("%d %d %d", &k, &v_i, &v_j);
    printf("%d", TimHT(n, MTK, k, v_i, v_j));

    return 0;
}