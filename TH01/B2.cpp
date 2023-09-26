#include <stdio.h>

void printSolutions(int x, int y, int z) {
    printf("%d + %d + %d = 1000\n", x, y, z);
}

void findSolutions() {
    int x, y, z;
    
    for (x = 0; x <= 1000; x++) {
        for (y = 0; y <= 1000 - x; y++) {
            z = 1000 - x - y;
            if (z >= 0) {
                printSolutions(x, y, z);
            }
        }
    }
}

int main() {
    findSolutions();
    return 0;
}


