#include <iostream>
#include <vector>
using namespace std;

// Hàm giải bài toán lập lịch gia công chi tiết bằng quy hoạch động
int GiaiLLQH(vector<vector<int>>& tg) {
    int n = tg.size(); // Số lượng chi tiết
    int m = tg[0].size(); // Số lượng máy móc

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + tg[i - 1][j - 1];
        }
    }

    return dp[n][m];
}

int main() {
    int n, m;
    cout << "Nhap so luong chi tiet: ";
    cin >> n;
    cout << "Nhap so luong may moc: ";
    cin >> m;

    vector<vector<int>> tg(n, vector<int>(m));

    cout << "Nhap thoi gian gia cong cho tung chi tiet tren moi may moc:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> tg[i][j];
        }
    }

    cout << "Thoi gian hoan thanh toi uu: " << GiaiLLQH(tg) << endl;

    return 0;
}