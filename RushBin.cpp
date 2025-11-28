#include <iostream>
#include <algorithm>

using namespace std;

void solve() {
    long long n, m, x, y;
    cin >> n >> m >> x >> y;

    long long dx = n - 1;
    long long dy = m - 1;

    if (dx > dy) swap(dx, dy);

    if (dx == 0) {
        cout << dy * x << endl;
        return;
    }

    long long ans = (dx + dy) * x;

    long long way2 = dx * y + (dy - dx) * x;
    ans = min(ans, way2);

    long long rem = dy - dx;
    long long way3;
    
    if (rem % 2 == 0) {
        way3 = dy * y;
    } else {
        way3 = (dy - 1) * y + x;
    }
    
    ans = min(ans, way3);

    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}