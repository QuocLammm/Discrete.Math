#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;

struct Task {
    int tg;
    int machineIndex;
};

bool compareTasks(Task a, Task b) {
    return a.tg > b.tg;
}

// Hàm tính thời gian hoàn thành tối ưu
int TinhTime(vector<Task>& scheduledTasks, vector<vector<int>>& tg) {
    int i;
    int n = scheduledTasks.size(); // Số lượng chi tiết
    int m = tg[0].size(); // Số lượng máy móc

    vector<int> machineTimes(m, 0); // Lưu trữ thời gian hoàn thành trên từng máy móc

    for (i = 0; i < n; ++i) {
        int taskIndex = scheduledTasks[i].machineIndex;
        int machineTime = machineTimes[taskIndex];
        int processingTime = scheduledTasks[i].tg;
        machineTimes[taskIndex] = max(machineTime, machineTime + processingTime);
    }

    return *max_element(machineTimes.begin(), machineTimes.end());
}

// Hàm nhánh cận giải bài toán lập lịch gia công chi tiết
void LLNC(vector<Task>& tasks, int currentValue, int& minValue, vector<Task>& scheduledTasks, vector<vector<int>>& processingTimes) {
    if (tasks.empty()) {
        int completionTime = TinhTime(scheduledTasks, processingTimes);
        minValue = min(minValue, completionTime);
        return;
    }

    for (int i = 0; i < tasks.size(); ++i) {
        int taskProcessingTime = tasks[i].tg;
        int taskMachineIndex = tasks[i].machineIndex;

        if (currentValue + taskProcessingTime >= minValue) {
            continue;
        }

        scheduledTasks.push_back(tasks[i]);
        tasks.erase(tasks.begin() + i);

        LLNC(tasks, currentValue + taskProcessingTime, minValue, scheduledTasks, processingTimes);

        tasks.insert(tasks.begin() + i, scheduledTasks.back());
        scheduledTasks.pop_back();
    }
}

// Hàm giải bài toán lập lịch gia công chi tiết bằng phương pháp nhánh cận
int GiaiLLNC(vector<Task>& tasks, vector<vector<int>>& processingTimes) {
    int minValue = numeric_limits<int>::max();
    vector<Task> scheduledTasks;
    sort(tasks.begin(), tasks.end(), compareTasks);

    LLNC(tasks, 0, minValue, scheduledTasks, processingTimes);
    return minValue;
}

int main() {
    int n, m;
    cout << "Nhap so luong chi tiet: ";
    cin >> n;
    cout << "Nhap so luong may moc: ";
    cin >> m;

    vector<vector<int>> processingTimes(n, vector<int>(m));
    vector<Task> tasks;

    cout << "Nhap thoi gian gia cong cho tung chi tiet tren moi may moc:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> processingTimes[i][j];
            tasks.push_back({ processingTimes[i][j], j });
        }
    }
    cout << "Thoi gian hoan thanh toi uu: " << GiaiLLNC(tasks, processingTimes) << endl;

    return 0;
}
