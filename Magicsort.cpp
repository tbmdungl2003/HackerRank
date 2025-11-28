#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

// Hàm để tính tổng các chữ số của một số
int sum_digits(int n) {
    int sum = 0;
    std::string s = std::to_string(n);
    for (char c : s) {
        sum += c - '0';
    }
    return sum;
}

// Hàm so sánh tùy chỉnh cho std::sort
bool custom_compare(int a, int b) {
    int sum_a = sum_digits(a);
    int sum_b = sum_digits(b);

    // Quy tắc 1: So sánh tổng các chữ số
    if (sum_a != sum_b) {
        return sum_a < sum_b;
    }

    // Quy tắc 2: Nếu tổng bằng nhau, so sánh giá trị của số
    return a < b;
}

int main() {
    // Tăng tốc độ I/O
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }

    // Sắp xếp vector bằng hàm so sánh tùy chỉnh
    std::sort(numbers.begin(), numbers.end(), custom_compare);

    // In ra kết quả
    for (int i = 0; i < n; ++i) {
        std::cout << numbers[i] << (i == n - 1 ? "" : " ");
    }
    std::cout << std::endl;

    return 0;
}
