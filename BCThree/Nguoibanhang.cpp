#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1e9;

// Hàm quy hoạch động TSP
int tsp(vector<vector<int>>& graph, vector<vector<int>>& dp, int mask, int pos) {
    int n = graph.size();
    if (mask == (1 << n) - 1) {
        return graph[pos][0];
    }

    if (dp[mask][pos] != -1) {
        return dp[mask][pos];
    }

    int ans = INF;
    for (int i = 0; i < n; ++i) {
        if ((mask & (1 << i)) == 0) {
            ans = min(ans, graph[pos][i] + tsp(graph, dp, mask | (1 << i), i));
        }
    }
    return dp[mask][pos] = ans;
}

// Hàm giải bài toán người bán hàng bằng quy hoạch động
int GiaiTSP(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<vector<int>> dp(1 << n, vector<int>(n, -1));
    return tsp(graph, dp, 1, 0);
}

int main() {
        int n;
    cout << "Nhap so luong thanh pho: ";
    cin >> n;

    if (n <= 0) {
        cout << "So luong thanh pho phai lon hon 0." << endl;
        return 1;
    }

    vector<vector<int>> graph(n, vector<int>(n, 0));
    cout << "Nhap khoang cach giua cac thanh pho (nhap " << INF << " neu khong co duong di):" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> graph[i][j];
        }
    }
    cout << "Khoang cach ngan nhat can di qua tat ca cac thanh pho: " << GiaiTSP(graph) << endl;

    return 0;
}
