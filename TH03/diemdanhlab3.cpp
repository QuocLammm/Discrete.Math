#include <stdio.h>

int VR(int h, int s) {
    if (h == 0) {
        return s;
    } else {
        return VR(h - 1, s * 2);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%d",VR(n,1));
    return 0;
}

