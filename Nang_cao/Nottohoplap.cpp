#include <stdio.h>

int countNonNegativeSolutions(int targetSum) {
    int dp[4][targetSum + 1];
    int i, j, k;

    for (i = 0; i < 4; i++) {
        for (j = 0; j < targetSum + 1; j++) {
            dp[i][j] = 0;
        }
    }

    dp[0][0] = 1;

    for (i = 1; i < 4; i++) {
        for (j = 0; j < targetSum + 1; j++) {
            for (k = 0; k < j + 1; k++) {
                dp[i][j] += dp[i - 1][j - k];
            }
        }
    }
    return dp[3][targetSum];
}

int main() {
    int targetSum = 10;
    int numSolutions = countNonNegativeSolutions(targetSum);
    printf("Number of non-negative solutions: %d\n", numSolutions);

    return 0;
}

