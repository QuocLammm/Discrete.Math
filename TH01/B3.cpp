#include <stdio.h>
int findSolutions() {
	int count = 0;
    
    for (int x1 = 4; x1 <= 20; x1++) {
        for (int x2 = 3; x2 <= 20 - x1; x2++) {
            for (int x3 = 6; x3 <= 20 - x1 - x2; x3++) {
                int x4 = 20 - x1 - x2 - x3;
                if (x4 >= -2) {
                    count++;
                }
            }
        }
    }
    return count;
}

int main() {  	
    printf("So nghiem nguyen cua pt: %d", findSolutions());
    return 0;
}






