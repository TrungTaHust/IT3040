#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <cmath>
#include <ctime>
#include <cstdio>

using namespace std;

const int LIMIT = 100;
const int NUM_ITER = 100000;
const int NUM_INPUTS = NUM_ITER * 100;

double sigmoid_slow(double x) {
    return 1.0 / (1.0 + exp(-x));
}

double x[NUM_INPUTS];

// Khai báo biến và hằng số cần thiết
const double INV_PRECISION = 1.0 / 1000000.0;
const double RANGE = LIMIT / 20.0;
const int PRECISION = 1000000;

// Biến sẽ lưu trữ giá trị sigmoid(x) đã được tính sẵn
double sigmoid_values[NUM_INPUTS];

// Hàm chuẩn bị dữ liệu
void precalc() {
    for (int i = 0; i < NUM_INPUTS; ++i) {
        x[i] = RANGE * (rand() % PRECISION - rand() % PRECISION) * INV_PRECISION;
    }

    // Tính giá trị sigmoid(x) cho toàn bộ dữ liệu
    for (int i = 0; i < NUM_INPUTS; ++i) {
        sigmoid_values[i] = sigmoid_slow(x[i]);
    }
}

// Hàm tính sigmoid(x) nhanh
inline double sigmoid_fast(double x) {
    // Tính chỉ số trong mảng dựa trên giá trị x
    double index = (x - (-LIMIT)) / (2.0 * LIMIT) * NUM_INPUTS;

    // Lấy giá trị sigmoid(x) đã được tính sẵn
    int lower_index = floor(index);
    int upper_index = lower_index + 1;

    // Tính tỷ lệ trọng số giữa hai giá trị lân cận
    double weight = index - lower_index;

    // Tính xấp xỉ sigmoid(x) dựa trên tỷ lệ trọng số
    return (1.0 - weight) * sigmoid_values[lower_index] + weight * sigmoid_values[upper_index];
}

// Hàm đánh giá hiệu suất
double benchmark(double (*calc)(double), vector<double>& result) {
    const int NUM_TEST = 20;
    double taken = 0;
    result = vector<double>();
    result.reserve(NUM_ITER);
    int input_id = 0;
    clock_t start = clock();
    for (int t = 0; t < NUM_TEST; ++t) {
        double sum = 0;
        for (int i = 0; i < NUM_ITER; ++i) {
            double v = fabs(calc(x[input_id]));
            sum += v;
            if (t == 0) result.push_back(v);
            if ((++input_id) == NUM_INPUTS) input_id = 0;
        }
    }
    clock_t finish = clock();
    taken = (double)(finish - start);
    return taken;
}

// Hàm kiểm tra độ chính xác giữa hai vector
bool is_correct(const vector<double>& a, const vector<double>& b) {
    const double EPS = 1e-6;
    if (a.size() != b.size()) return false;
    for (int i = 0; i < a.size(); ++i) {
        if (fabs(a[i] - b[i]) > EPS) {
            return false;
        }
    }
    return true;
}

int main() {
    precalc();

    vector<double> a, b;
    double slow = benchmark(sigmoid_slow, a);
    double fast = benchmark(sigmoid_fast, b);

    double xval;
    scanf("%lf", &xval);
    printf("%.2f \n", sigmoid_fast(xval));

    if (is_correct(a, b) && (slow / fast > 1.3)) {
        printf("Correct answer! Your code is faster\n");
    }
    else {
        printf("Wrong answer or your code is not fast enough!\n");
    }

    return 0;
}
