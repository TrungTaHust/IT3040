#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
	int val1, val2;
	cin >> val1 >> val2;

	vector<vector<int>> a = {
		{1, 3, 7},
		{2, 3, 4, val1},
		{9, 8, 15},
		{10, val2},
	};

	// Sắp xếp các vector trong a theo tổng các phần tử giảm dần
	sort(a.begin(), a.end(), [](const vector<int>& v1, const vector<int>& v2) {
		int sum1 = accumulate(v1.begin(), v1.end(), 0);
		int sum2 = accumulate(v2.begin(), v2.end(), 0);
		return sum1 > sum2;
		});

	for (const auto& v : a) {
		for (int it : v) {
			cout << it << ' ';
		}
		cout << endl;
	}

	return 0;
}