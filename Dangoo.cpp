#include <iostream>
#include <string>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;

    int max_level = -1;

    for (int i = 0; i < n; ++i) {
        if (s[i] == 'o') {
            int start_index = i;
            int current_level = 0;
            while (i < n && s[i] == 'o') {
                current_level++;
                i++;
            }

            bool has_adjacent_dash = false;
            if (start_index > 0 && s[start_index - 1] == '-') {
                has_adjacent_dash = true;
            }
            if (i < n && s[i] == '-') {
                has_adjacent_dash = true;
            }

            if (has_adjacent_dash) {
                max_level = std::max(max_level, current_level);
            }
            i--; // Quay lại một bước để vòng lặp for không bỏ sót ký tự
        }
    }

    std::cout << max_level << std::endl;

    return 0;
}
