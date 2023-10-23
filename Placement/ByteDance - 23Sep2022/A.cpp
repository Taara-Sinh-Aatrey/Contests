#include "bits/stdc++.h"
using namespace std;

#define int int64_t

int inverse(int a, int m) {
    if(a == 0) return 0;
    int MOD = m;
    int u = 0, v = 1;
    while (a != 0) {
        int t = m / a;
        m -= t * a; swap(a, m);
        u -= t * v; swap(u, v);
    }
    if (m != 1) {
        return -1;
    }
    u %= MOD;
    if(u < 0) u += MOD;
    return u;
}

signed main() {
    int a, n, r;
    cin >> a >> n >> r;
    int inv = inverse(a, n);
    if (inv == -1) {
        cout << -1 << '\n';
        return 0;
    }
    int m = r * inv % n;
    cout << m << '\n';
    return 0;
}