#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, k;
    std::cin >> n >> k;

    if (n <= 1) { 
        std::cout << "-1 -1" << std::endl;
        return 0;
    }

    int min_candies = -1;
    int max_candies = -1;

    int estimated_c = (k * n) / (n - 1);
    for (int total_candies = k; total_candies <= estimated_c + n; ++total_candies) {
        int teo_share = total_candies / n;

        if (total_candies - teo_share == k) {
            if (min_candies == -1) {
                min_candies = total_candies;
            }
            max_candies = total_candies;
        }
    }

    std::cout << min_candies << " " << max_candies << std::endl;

    return 0;
}
