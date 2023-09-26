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

// Hàm thêm mot canh vào do thi
void add(int start, int end) {
    if (start >= 0 && start < dinh && end >= 0 && end < dinh) {
        MTK[start][end] = 1;
    }
}

// Hàm kiem tra xem do thi có ton tai khuyen ?
int KT() {
    for (int i = 0; i < dinh; i++) {
        if (MTK[i][i] == 1) {
            return 1; // Co khuyen
        }
    }
    return 0; // Không có khuyên
}

// Hàm kiem tra xem do thi la có huong hay vo huong?
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

// Hàm tínnh bậc vào của một đỉnh -- tổng cột--
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

// Hàm tính tong bac cua do thi
int Sum() {
    int S = 0;
    for (int i = 0; i < dinh; i++) {
        int bac_v = 0;
        int bac_r = 0;

        for (int j = 0; j < dinh; j++) {
            bac_v += MTK[j][i];
            bac_r += MTK[i][j];
        }
        S += (bac_v + bac_r);
    }
    return S;
}

// Hàm tinh so canh cua do thi
int CountC() {
    if(KTVH()==1){
    int C1 = 0;
    for (int i = 0; i < dinh; i++) {
        for (int j = 0; j < dinh; j++) {
            if (MTK[i][j] >= 1) {
                C1+= MTK[i][j];
            }
        }
    }
    return C1;
    }
    else{
        int C=0;
        for (int i = 0; i < dinh; i++) {
            for (int j = 0; j < dinh; j++) {
                if(MTK[i][j] >= 1) 
                    C+= MTK[i][j];
            }
        }
    return (float)C/2;
    }
}

// Hàm tính so cung cua do thi
int CountA() {
    int A = 0;
    for (int i = 0; i < dinh; i++) {
        for (int j = 0; j < dinh; j++) {
            if (MTK[i][j] == 1 && MTK[j][i] == 1) {
                A++;
            }
        }
    }
    return A;
}


void B1_1(){
	int num; // So dinh
    printf("Nhap so dinh: "); scanf("%d", &num);
    Create(num); // Khoi tao do thi
    printf("Nhap ma tran ke:\n");
    for (int i = 0; i < num; i++) {
        for (int j = 0; j < num; j++) {
            scanf("%d", &MTK[i][j]);
        }
    }
    if (KT() == 1) {
        printf("Do thi co ton tai khuyen.\n");
    } else {
        printf("Do thi khong co khuyen.\n");
    }
}

void B1_2(){
	// int num;
    // printf("Nhap so dinh: ");scanf("%d", &num);
    // Create(num); 
    // printf("Nhap ma tran ke:\n");
    // for (int i = 0; i < num; i++) {
    //     for (int j = 0; j < num; j++) {
    //         scanf("%d", &MTK[i][j]);
    //     }
    // }
    if (KTVH() == 1) {
        printf("Do thi co huong.\n");
    } else {
        printf("Do thi vo huong.\n");
    }
}

void B1_3(){
	int num;
    printf("Nhap so dinh: ");scanf("%d", &num);
    Create(num); 
    printf("Nhap ma tran ke:\n");
    for (int i = 0; i < num; i++) {
        for (int j = 0; j < num; j++) {
            scanf("%d", &MTK[i][j]);
        }
    }
    printf("Bac cua cac dinh:\n");
    for (int i = 0; i < num; i++) {
        printf("Dinh %d: Bac vao = %d, Bac ra = %d\n", i, inDegree(i), outDegree(i));
    }
}

void B1_4(){
	// int num;
    // printf("Nhap so dinh: ");scanf("%d", &num);
    // Create(num); 
    // printf("Nhap ma tran ke:\n");
    // for (int i = 0; i < num; i++) {
    //     for (int j = 0; j < num; j++) {
    //         scanf("%d", &MTK[i][j]);
    //     }
    // }
    printf("Tong bac cua do thi: %d\n", Sum());
}

void B1_5(){
	// int num;
    // printf("Nhap so dinh: ");scanf("%d", &num);
    // Create(num); 
    // printf("Nhap ma tran ke:\n");
    // for (int i = 0; i < num; i++) {
    //     for (int j = 0; j < num; j++) {
    //         scanf("%d", &MTK[i][j]);
    //     }
    // }
    printf("So canh: %d\n", CountC()); // vô hướng
    printf("So cung: %d\n", CountA()); // có hướng
}

int main() {
	printf("------------------Bai 1.1 --------------------\n");
    //B1_1();
    printf("------------------Bai 1.2 --------------------\n");
    //B1_2();
    printf("------------------Bai 1.3 --------------------\n");
	B1_3();
    printf("------------------Bai 1.4 --------------------\n");
	B1_4();
    printf("------------------Bai 1.5 --------------------\n");
    B1_5();
    
    return 0;
}

