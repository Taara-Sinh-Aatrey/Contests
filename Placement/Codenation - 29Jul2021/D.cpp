#include "bits/stdc++.h"
using namespace std;

int64_t inverse(int64_t a, int64_t m) {
    if(a == 0) return 0;
    int64_t MOD = m;
    int64_t u = 0, v = 1;
    while (a != 0) {
        int64_t t = m / a;
        m -= t * a; swap(a, m);
        u -= t * v; swap(u, v);
    }
    assert(m == 1);
    u %= MOD;
    if(u < 0) u += MOD;
   return u;
}

int solve(int A, int B, int C) {
#define int int64_t
    // P(x) = 1 + D(x-1) * (x-2)......* (x-A)
    const int mod = 1e9 + 7;
    int val = 1;
    for (int i = 1; i <= A; i++) {
        val *= (A + 1 - i);
        val %= mod;
    }
    // 1 + D * val = B => D = (B - 1) / val
    int D = (B - 1) * inverse(val, mod) % mod;
    int ans = 1;
    for (int i = 1; i <= A; i++) {
        ans *= (A + C - i);
        ans %= mod;
    }
    ans = (ans * D % mod + 1) % mod;
    return ans;
#undef int
}

int main() {
    cout << solve(1, 2, 3) << endl;
    cout << solve(2, 2, 2) << endl;
    return 0;
}