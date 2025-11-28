#include <iostream>
#include <vector>
#include <map>
#include <numeric>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::map<long long, long long> slime_counts;
    for (int i = 0; i < n; ++i) {
        long long size, count;
        std::cin >> size >> count;
        slime_counts[size] = count;
    }

    for (auto it = slime_counts.begin(); it != slime_counts.end(); ++it) {
        long long size = it->first;
        long long count = it->second;

        if (count >= 2) {
            long long new_slimes = count / 2;
            long long new_size = size * 2;

            slime_counts[new_size] += new_slimes;

            it->second = count % 2;
        }
    }

    long long total_slimes = 0;
    for (auto const& [size, count] : slime_counts) {
        total_slimes += count;
    }

    std::cout << total_slimes << std::endl;

    return 0;
}
