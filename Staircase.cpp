#include <iostream>

void staircase(int n) {
    // Vòng lặp ngoài để duyệt qua từng hàng (bậc thang)
    for (int i = 1; i <= n; ++i) {
        // Vòng lặp con để in các khoảng trắng
        // Ở hàng thứ i, có n-i khoảng trắng
        for (int j = 0; j < n - i; ++j) {
            std::cout << " ";
        }

        // Vòng lặp con để in các ký tự '#'
        // Ở hàng thứ i, có i ký tự '#'
        for (int k = 0; k < i; ++k) {
            std::cout << "#";
        }

        // Xuống dòng để bắt đầu hàng mới
        std::cout << std::endl;
    }
}

int main() {
    int n;
    std::cin >> n;
    staircase(n);
    return 0;
}
