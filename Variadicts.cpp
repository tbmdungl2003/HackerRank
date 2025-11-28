#include <iostream>
using namespace std;

// --- PHẦN BỔ SUNG BẮT ĐẦU ---

// Trường hợp cơ sở: Khi không còn bit nào, giá trị là 0.
template <bool... digits>
int reversed_binary_value() {
    return 0;
}

// Trường hợp đệ quy: Tách bit đầu tiên ra và xử lý phần còn lại.
template <bool first, bool... rest>
int reversed_binary_value() {
    return first + 2 * reversed_binary_value<rest...>();
}
// --- PHẦN BỔ SUNG KẾT THÚC ---

template <int n, bool...digits>
struct CheckValues {
  	static void check(int x, int y)
  	{
    	CheckValues<n-1, 0, digits...>::check(x, y);
    	CheckValues<n-1, 1, digits...>::check(x, y);
  	}
};

template <bool...digits>
struct CheckValues<0, digits...> {
  	static void check(int x, int y)
  	{
    	int z = reversed_binary_value<digits...>();
    	std::cout << (z+64*y==x);
  	}
};

int main()
{
  	int t; std::cin >> t;

  	for (int i=0; i!=t; ++i) {
		int x, y;
    	cin >> x >> y;
    	CheckValues<6>::check(x, y);
    	cout << "\n";
  	}
}