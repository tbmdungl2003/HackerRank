#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<int> b(m);
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }

    long long mod = 1e9 + 7;
    vector<vector<long long>> dp(2, vector<long long>(m + 1, 0));

    for (int i = 1; i <= n; ++i) {
        int current = i % 2;
        int prev = (i - 1) % 2;
        for (int j = 1; j <= m; ++j) {
            // Công thức đúng:
            // dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] (nếu A[i-1] != B[j-1])
            // dp[i][j] = dp[i-1][j] + dp[i][j-1] + 1           (nếu A[i-1] == B[j-1])
            long long val = (dp[prev][j] + dp[current][j - 1] - dp[prev][j - 1] + mod) % mod;
            if (a[i - 1] == b[j - 1]) {
                val = (val + dp[prev][j - 1] + 1) % mod;
            }
            dp[current][j] = val;
        }
    }

    cout << dp[n % 2][m] << endl;

    return 0;
}