#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> data(n);

    for (int i = 0; i < n; ++i) {
        cin >> data[i].first >> data[i].second;
    }

    // Sắp xếp giảm dần theo value, sau đó giảm dần theo key nếu value bằng nhau
    sort(data.begin(), data.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        if (a.second != b.second) {
            return a.second > b.second;
        }
        return a.first > b.first;
        });

    // In danh sách đã sắp xếp
    for (const auto& item : data) {
        cout << item.first << " " << item.second << endl;
    }

    return 0;
}

