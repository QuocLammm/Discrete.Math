#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1000000; // Giá trị vô cùng (đại diện cho khoảng cách vô hạn)

// Hàm tính toán chi phí của tuyến đường từ thành phố hiện tại tới thành phố tiếp theo
int TTCP(vector<vector<int>>& graph, int src, int dest) {
    if (src >= 0 && src < graph.size() && dest >= 0 && dest < graph.size()) {
        return graph[src][dest];
    }
    return INF;
}

// Hàm nhánh cận giải bài toán người bán hàng
void NCBH(vector<vector<int>>& graph, vector<int>& path, vector<bool>& visited, int currentCost, int& minCost, int currentVertex) {
    int n = graph.size();
    if (currentVertex == n) {
        // Nếu đã đi qua tất cả các thành phố, cập nhật giá trị chi phí nhỏ nhất
        minCost = min(minCost, currentCost + TTCP(graph, path[currentVertex - 1], path[0]));
        return;
    }

    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            int temp = currentCost + TTCP(graph, path[currentVertex - 1], i);
            if (temp < minCost) {
                path[currentVertex] = i;
                visited[i] = true;
                NCBH(graph, path, visited, temp, minCost, currentVertex + 1);
                visited[i] = false;
            }
        }
    }
}

// Hàm giải bài toán người bán hàng bằng nhánh cận
int TSB(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> path(n);
    vector<bool> visited(n, false);
    int currentCost = 0;
    int minCost = INF;

    // Bắt đầu từ thành phố 0
    path[0] = 0;
    visited[0] = true;
    NCBH(graph, path, visited, currentCost, minCost, 1);

    return minCost;
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
    cout << "Khoang cach ngan nhat can di qua tat ca cac thanh pho: " << TSB(graph) << endl;

    return 0;
}
