#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 100005;

struct Node {
    long long total_cost;
    int item_count;
};


class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        int k = 0; // Con trỏ cho vị trí hợp lệ tiếp theo
        for (int n : nums) {
            if (k < 2 || n > nums[k - 2]) {
                nums[k] = n;
                k++;
            }
        }
        return k; // Trả về số lượng phần tử không trùng lặp
    }
};

int a[MAXN];
Node tree[4 * MAXN];
int n, q;

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

int query(int node_idx, int L, int R, int query_L, int query_R, long long& money) {
    if (L > query_R || R < query_L || money == 0) {
        return 0;
    }

    if (query_L <= L && R <= query_R) {
        if (money >= tree[node_idx].total_cost) {
            money -= tree[node_idx].total_cost;
            return tree[node_idx].item_count;
        }
        
        if (L == R) {
            return 0;
        }
    }

    int M = L + (R - L) / 2;
    int items_bought = 0;

    items_bought += query(2 * node_idx, L, M, query_L, query_R, money);
    items_bought += query(2 * node_idx + 1, M + 1, R, query_L, query_R, money);

    return items_bought;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> q;

    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    build(1, 1, n);

    for (int i = 0; i < q; ++i) {
        long long x;
        int p;
        cin >> x >> p;

        cout << query(1, 1, n, p, n, x) << "\n";
    }

    return 0;
}