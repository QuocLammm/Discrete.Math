#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Hàm đếm số lần xuất hiện của các kí tự chữ cái Latin
void demVaHienThiKyTu(char* cau) {
    int count[26] = {0}; // Mảng để đếm số lần xuất hiện của các kí tự chữ cái Latin

    // Đếm số lần xuất hiện của các kí tự chữ cái Latin
    for (int i = 0; i < strlen(cau); i++) {
        if (isalpha(cau[i])) {
            char ch = toupper(cau[i]);
            count[ch - 'A']++;
        }
    }

    // Hiển thị kết quả đếm theo thứ tự từ điển
    printf("So lan xuat hien chu cai Latin:\n");
    for (int i = 0; i < 26; i++) {
        if (count[i] > 0) {
            printf("%c: %d\n", 'A' + i, count[i]);
        }
    }
}

// Hàm liệt kê tất cả các hoán vị từ kí tự duy nhất xuất hiện trong câu
void lietKeHoanVi(char* cau, char* chuoiHoanVi, int* mark, int index) {
    if (index == strlen(chuoiHoanVi)) {
        printf("%s\n", chuoiHoanVi);
        return;
    }

    for (int i = 0; i < strlen(cau); i++) {
        if (mark[i] == 0) {
            chuoiHoanVi[index] = cau[i];
            mark[i] = 1;
            lietKeHoanVi(cau, chuoiHoanVi, mark, index + 1);
            mark[i] = 0;
        }
    }
}

int main() {
    char cau[1000];
    printf("Nhap cau text: ");
    fgets(cau, sizeof(cau), stdin);

    // Đếm số lần xuất hiện của các kí tự chữ cái Latin
    demVaHienThiKyTu(cau);

    // Tạo chuỗi duy nhất từ các kí tự trong câu (loại bỏ các kí tự không phải chữ cái Latin)
    char chuoiDuyNhat[26] = {0};
    int mark[26] = {0}; // Mảng đánh dấu để sử dụng trong hoán vị
    int index = 0;
    for (int i = 0; i < strlen(cau); i++) {
        if (isalpha(cau[i])) {
            char ch = toupper(cau[i]);
            if (mark[ch - 'A'] == 0) {
                chuoiDuyNhat[index] = ch;
                mark[ch - 'A'] = 1;
                index++;
            }
        }
    }

    // Liet ke tat ca cac hoan vi tu chuoi duy nhat
    printf("\nAll hoan vi:\n");
    char chuoiHoanVi[26] = {0};
    lietKeHoanVi(chuoiDuyNhat, chuoiHoanVi, mark, 0);

    return 0;
}
