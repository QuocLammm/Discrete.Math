#include <iostream>
#include <vector>
using namespace std;

// Hàm giải bài toán xếp ba lô bằng quy hoạch động
int GiaiBLQH(int W, vector<int>& cannang, vector<int>& values) {
    int n = cannang.size();
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int w = 1; w <= W; ++w) {
            if (cannang[i - 1] <= w) {
                dp[i][w] = max(dp[i - 1][w], values[i - 1] + dp[i - 1][w - cannang[i - 1]]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][W];
}

int main() {
    int W, n;
    cout << "Nhap suc chua cua ba lo: ";
    cin >> W;
    cout << "Nhap so luong vat pham: ";
    cin >> n;

    vector<int> cannang(n);
    vector<int> values(n);

    cout << "Nhap trong luong va gia tri cua cac vat pham:" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> cannang[i] >> values[i];
    }
    cout << "Gia tri lon nhat co the dat duoc: " << GiaiBLQH(W, cannang, values) << endl;

    return 0;
}
