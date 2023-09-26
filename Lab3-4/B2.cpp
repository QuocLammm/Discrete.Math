#include <stdio.h>
#define MAX 100

int MTK[MAX][MAX]; // Ma tran liên thuoc dinh-canh
int dinh; // So dinh trong do thi

// Hàm khoi tao ma tran liên thuoc dinh-canh
void CreateMT(int num) {
    dinh = num;
    
    // Khoi tao tat ca cac phan tu trong ma tran l� 0
    for (int i = 0; i < dinh; i++) {
        for (int j = 0; j < dinh; j++) {
            MTK[i][j] = 0;
        }
    }
}

// Hàm thêm mot canh vào do thi
void add_C(int start, int end) {
    if (start >= 0 && start < dinh && end >= 0 && end < dinh) {
        MTK[start][end] = 1;
        MTK[end][start] = 1;
    }
}

// Hàm hien thi ma tran lien thuoc dinh - canh
void PrintMT() {
    printf("Ma tran lien thuoc dinh-canh:\n");
    for (int i = 0; i < dinh; i++) {
        for (int j = 0; j < dinh; j++) {
            printf("%d ", MTK[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int num = 5; // so dinh
    CreateMT(num); // Khoi tao do thi

    // Thêm các canh vào do thi
    add_C(1, 2);
    add_C(1, 3);
    add_C(1, 4);
    add_C(2, 3);
    add_C(2, 4);
    add_C(2, 5);
    add_C(3, 4);
    add_C(3, 5);
    add_C(4, 5);
    
    // Hien thi do thi
    PrintMT();
    return 0;
}

