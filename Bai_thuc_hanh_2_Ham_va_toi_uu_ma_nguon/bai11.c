#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, M;
    cin >> N;

    vector<int> A(N + 1);
    for (int i = 0; i <= N; ++i) {
        cin >> A[i];
    }

    cin >> M;

    vector<int> B(M + 1);
    for (int i = 0; i <= M; ++i) {
        cin >> B[i];
    }

    int degree = N + M - 1;
    vector<int> C(degree + 1, 0);

    for (int i = 0; i <= N; ++i) {
        for (int j = 0; j <= M; ++j) {
            C[i + j] += A[i] * B[j];
        }
    }

    int result = 0;
    for (int i = 0; i <= degree; ++i) {
        result ^= C[i];
    }

    cout << result << endl;

    return 0;
}

