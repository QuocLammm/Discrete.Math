#include <stdio.h>
#define MAX 100

int MTK[MAX][MAX]; // Ma tran ke
int dinh; // So dinh trong do thi

// Hàm khoi tao ma tran ke
void Create(int num) {
    dinh = num;
    
    // Khoi tao tat ca các phan tu trong ma tran là 0
    for (int i = 0; i < dinh; i++) {
        for (int j = 0; j < dinh; j++) {
            MTK[i][j] = 0;
        }
    }
}

// Hàm tính bậc vào của một đỉnh -- tổng cột--
int inDegree(int k) {
    int bac = 0;
    for (int i = 0; i < dinh; i++) {
        bac += MTK[i][k];
    }
    return bac;
}

// Hàm tính bậc ra cua mot dinh -- tổng hàng--
int outDegree(int k) {
    int bac = 0;
    for (int i = 0; i < dinh; i++) {
        bac += MTK[k][i];
    }
    return bac;
}

int main() {
    int num;
    scanf("%d", &num);
    Create(num); 
    for (int i = 0; i < num; i++) {
        for (int j = 0; j < num; j++) {
            scanf("%d", &MTK[i][j]);
        }
    }

    // Kiểm tra đồ thị có hướng hay vô hướng
    int isDirected = 0; // 0: vô hướng, 1: có hướng
    for (int i = 0; i < num; i++) {
        for (int j = i + 1; j < num; j++) {
            if (MTK[i][j] != MTK[j][i]) {
                isDirected = 1;
                break;
            }
        }
        if (isDirected)
            break;
    }

    // In kết quả cho đồ thị vô hướng
    if (!isDirected) {
        for (int i = 0; i < num; i++) {
            printf("%d", inDegree(i));
            if (i < num - 1)
                printf(";");
        }
        printf("\n");
    }
    // In kết quả cho đồ thị có hướng
    else {
        for (int i = 0; i < num; i++) {
            printf("%d", outDegree(i));
            if (i < num - 1)
                printf(";");
        }
        printf("\n");
        for (int i = 0; i < num; i++) {
            printf("%d", inDegree(i));
            if (i < num - 1)
                printf(";");
        }
        printf("\n");
    }

    return 0;
}
