#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 100005;

// Cấu trúc của một nút trong Segment Tree
struct Node {
    long long total_cost;
    int item_count;
};

vector<int> a;
Node tree[4 * MAXN];

// Hàm xây dựng cây
void build(int node_idx, int L, int R) {
    if (L == R) {
        tree[node_idx] = { (long long)a[L], 1 };
        return;
    }
    int M = L + (R - L) / 2;
    build(2 * node_idx, L, M);
    build(2 * node_idx + 1, M + 1, R);
    tree[node_idx].total_cost = tree[2 * node_idx].total_cost + tree[2 * node_idx + 1].total_cost;
    tree[node_idx].item_count = tree[2 * node_idx].item_count + tree[2 * node_idx + 1].item_count;
}

// Hàm truy vấn chính
int query(int node_idx, int L, int R, int query_L, int query_R, long long& money) {
    // Nếu đoạn của nút không giao với đoạn truy vấn, hoặc hết tiền, thì không mua được gì
    if (L > query_R || R < query_L || money == 0) {
        return 0;
    }

    // Nếu đoạn của nút nằm hoàn toàn trong đoạn truy vấn
    if (query_L <= L && R <= query_R) {
        // Tối ưu hóa: Nếu đủ tiền mua hết cả đoạn của nút này
        if (money >= tree[node_idx].total_cost) {
            money -= tree[node_idx].total_cost;
            return tree[node_idx].item_count;
        }
        // Nếu là nút lá mà không đủ tiền mua
        if (L == R) {
            return 0;
        }
    }

    // Trường hợp phức tạp: đi sâu vào các con
    int M = L + (R - L) / 2;
    int items_bought = 0;

    // Luôn đi vào con trái trước
    items_bought += query(2 * node_idx, L, M, query_L, query_R, money);
    
    // Sau đó đi vào con phải với số tiền còn lại
    items_bought += query(2 * node_idx + 1, M + 1, R, query_L, query_R, money);

    return items_bought;
}

int main() {
    // Tăng tốc độ nhập xuất
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int n, q;
    cin >> n >> q;
 
    a.resize(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
 
    // Xây dựng cây phân đoạn
    build(1, 1, n);
 
    // Xử lý các truy vấn
    for (int i = 0; i < q; ++i) {
        long long x;
        int p;
        cin >> x >> p;
 
        cout << query(1, 1, n, p, n, x) << "\n";
    }
 
    return 0;
}