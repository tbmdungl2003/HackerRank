#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

const int MAXN = 100005;
long long a[MAXN];
int parent[MAXN];
long long segment_sum[MAXN];
bool active[MAXN];
int p[MAXN];
int n;

// Hàm tìm gốc của tập hợp chứa v (có nén đường đi)
int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

// Hàm hợp nhất hai tập hợp chứa a và b
void union_sets(int a, int b, long long &current_max) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        // Gộp tập hợp nhỏ vào tập hợp lớn hơn (tuỳ chọn, ở đây gộp b vào a)
        parent[b] = a;
        segment_sum[a] += segment_sum[b];
        current_max = max(current_max, segment_sum[a]);
    }
}

int main() {
    // Tối ưu nhập xuất
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        parent[i] = i;
        segment_sum[i] = a[i];
        active[i] = false;
    }
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }

    vector<long long> results;
    long long current_max = 0;
    results.push_back(0); // Kết quả sau khi bo xì người cuối cùng là 0

    // Duyệt ngược từ người bị bo xì cuối cùng đến người bị bo xì thứ 2
    for (int i = n - 1; i > 0; --i) {
        int u = p[i];
        active[u] = true;
        current_max = max(current_max, segment_sum[u]);

        // Kiểm tra và gộp với người bên trái
        if (u > 1 && active[u - 1]) {
            union_sets(u - 1, u, current_max);
        }
        // Kiểm tra và gộp với người bên phải
        if (u < n && active[u + 1]) {
            union_sets(u, u + 1, current_max);
        }
        results.push_back(current_max);
    }

    // In kết quả theo thứ tự ngược lại
    reverse(results.begin(), results.end());
    for (long long val : results) {
        cout << val << "\n";
    }

    return 0;
}