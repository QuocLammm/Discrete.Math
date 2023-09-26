#include <stdio.h>
#define MAX 100
// DFS đồ thị liên thông. 
int MTK[MAX][MAX]; // Ma tran ke
int dinh; // So dinh trong do thi
int tich[MAX]; // Mảng đánh dấu các đỉnh đã được duyệt

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

// Hàm DFS để duyệt đồ thị
void DFS(int start) {
    tich[start] = 1; // Đánh dấu đỉnh đã duyệt

    for (int i = 0; i < dinh; i++) {
        if (MTK[start][i] && !tich[i]) { // Nếu có cạnh nối từ đỉnh start tới đỉnh i và đỉnh i chưa được duyệt
            DFS(i); // Tiếp tục duyệt đỉnh i
        }
    }
}

// Hàm kiểm tra tính liên thông của đồ thị
int Check() {
    // Khởi tạo mảng visited
    for (int i = 0; i < dinh; i++) {
        tich[i] = 0;
    }
    // Duyệt đỉnh đầu tiên (đỉnh 0)
    DFS(0);
    // Kiểm tra xem tất cả các đỉnh đã được duyệt hay chưa
    for (int i = 0; i < dinh; i++) {
        if (!tich[i]) {
            return 0; // Trả về 0 nếu có đỉnh nào chưa được duyệt
        }
    }
    return 1; // Trả về 1 nếu tất cả các đỉnh đã được duyệt, tức là đồ thị liên thông
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
    if (Check()) {
        printf("lien thong");
    } else {
        printf("khong lien thong");
    }
}