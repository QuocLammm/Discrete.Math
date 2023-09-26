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

int KTVH() {
    for (int i = 0; i < dinh; i++) {
        for (int j = 0; j < dinh; j++) {
            if (MTK[i][j] != MTK[j][i]) {
                return 1; // Co huong
            }
        }
    }
    return 0; // Vo huong
}

int main(){
    int num;
    scanf("%d", &num);
    Create(num); 
    for (int i = 0; i < num; i++) {
        for (int j = 0; j < num; j++) {
            scanf("%d", &MTK[i][j]);
        }
    }
    if (KTVH() == 1) {
        printf("co_huong");
    } else {
        printf("vo_huong");
    }
}