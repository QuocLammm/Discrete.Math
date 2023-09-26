#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Item {
    int weight;
    int value;
};

bool compareItems(Item a, Item b) {
    return (a.value / a.weight) > (b.value / b.weight);
}

// Hàm tính tổng giá trị của các vật phẩm đã được chọn
int TT(vector<Item>& selectedItems) {
    int totalValue = 0;
    for (const auto& item : selectedItems) {
        totalValue += item.value;
    }
    return totalValue;
}

// Hàm nhánh cận giải bài toán xếp ba lô
void NCBL(int W, vector<Item>& items, int currentValue, int currentWeight, int& maxValue, vector<Item>& selectedItems, int index) {
    if (index >= items.size()) {
        maxValue = max(maxValue, currentValue);
        return;
    }

    if (currentWeight + items[index].weight <= W) {
        selectedItems.push_back(items[index]);
        NCBL(W, items, currentValue + items[index].value, currentWeight + items[index].weight, maxValue, selectedItems, index + 1);
        selectedItems.pop_back();
    }

    NCBL(W, items, currentValue, currentWeight, maxValue, selectedItems, index + 1);
}

// Hàm giải bài toán xếp ba lô bằng phương pháp nhánh cận
int GiaiBLNC(int W, vector<Item>& items) {
    int maxValue = 0;
    vector<Item> selectedItems;
    NCBL(W, items, 0, 0, maxValue, selectedItems, 0);
    return maxValue;
}

int main() {
    int W, n;
    cout << "Nhap suc chua cua ba lo: ";
    cin >> W;
    cout << "Nhap so luong vat pham: ";
    cin >> n;

    vector<Item> items(n);

    cout << "Nhap trong luong va gia tri cua cac vat pham:" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> items[i].weight >> items[i].value;
    }

    sort(items.begin(), items.end(), compareItems);
    cout << "Gia tri lon nhat co the dat duoc: " << GiaiBLNC(W, items) << endl;

    return 0;
}
