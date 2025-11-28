#include <iostream>

using namespace std;

long long next_val(long long current, long long p, long long q, long long mod) {
    return (current * p + q) % mod;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, s, p, q;
    cin >> n >> s >> p >> q;

    long long mod = 1LL << 31;

    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }
    if (n == 1) {
        cout << n << endl;
        return 0;
    }

    long long tortoise = s;
    long long hare = s;
    long long count = 0;

    for (long long i = 0; i < n; ++i) {
        tortoise = next_val(tortoise, p, q, mod);
        hare = next_val(next_val(hare, p, q, mod), p, q, mod);
        if (tortoise == hare) {
            count = 1;
            tortoise = s;
            while (tortoise != hare) {
                tortoise = next_val(tortoise, p, q, mod);
                hare = next_val(hare, p, q, mod);
                count++;
            }
            cout << count << endl;
            return 0;
        }
    }
    cout << n << endl;

    return 0;
}
