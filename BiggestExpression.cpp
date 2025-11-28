#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    int k;
    std::cin >> n >> k;

    std::vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    long long max_value = a[0];
    std::vector<long long> remaining_numbers;
    for (int i = 1; i < n; ++i) {
        remaining_numbers.push_back(a[i]);
    }
    std::sort(remaining_numbers.begin(), remaining_numbers.end());

    int num_to_subtract = (n - 1) - k;
    for (int i = 0; i < num_to_subtract; ++i) {
        max_value -= remaining_numbers[i];
    }
    for (int i = num_to_subtract; i < n - 1; ++i) {
        max_value += remaining_numbers[i];
    }

    std::cout << max_value << std::endl;

    return 0;
}
