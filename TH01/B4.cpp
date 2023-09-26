#include <stdio.h>

int main() {
    int i, j, k;
    
    for (i = 0; i <= 4; i++) {
        for (j = 0; j <= 4 - i; j++) {
            k = 4 - i - j;
            printf("So but chi mau xanh: %d, mau do: %d, mau vang: %d\n", i, j, k);
        }
    }
    
    return 0;
}

