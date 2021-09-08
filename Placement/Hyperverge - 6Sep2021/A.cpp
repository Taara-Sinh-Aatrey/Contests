#include "bits/stdc++.h"
using namespace std;

#define int int64_t
const int mod = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    int ans = 0;
    for(int i = 0; i < n; i++) {
        int ai;
        cin >> ai;
        function<array<int, 4>(int)> rec = [&](int d) -> array<int, 4> {
            if(d == 0) return {0, 0, 0, 0};
            if(d == 1) return {3, 3, 2, 2};
            auto calc = [&](array<int, 4> a, array<int, 4> b) {
                array<int, 4> ret = {0, 0, 0, 0};
                for(int s1 = 0; s1 < 4; s1++) {
                    for(int s2 = 0; s2 < 4; s2++) {
                        ret[(s1 + s2) % 4] += a[s1] * b[s2] % mod;
                        ret[(s1 + s2) % 4] %= mod;
                    }
                }
                return ret;
            };
            auto arr = rec(d / 2);
            auto ret = calc(arr, arr);
            if(d & 1) ret = calc(ret, {3, 3, 2, 2});
            return ret;
        };
        auto arr1 = rec(ai);
        auto arr2 = rec(ai - 1);
        int cur = arr1[1] - arr2[1];
        if(cur < 0) cur += mod;
        ans += cur;
        if(ans >= mod) ans -= mod;
    }
    cout << ans << '\n';
}

signed main() {
    solve();
    return 0;
}