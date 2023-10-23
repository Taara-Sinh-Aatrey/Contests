#include "bits/stdc++.h"

using namespace std;

#ifdef AATREY_DEBUG
#include "debug.hpp"
#else
#define dbg(...)
#endif

long long solution(vector<int> towers) {
    int n = towers.size();
    long long ans = 1e18L + 5;
    for (int rep = 0; rep < 2; rep++) {
        int mx = 0;
        for (int i = 0; i < n; i++) {
            mx = max(mx, towers[i] - i);
        }
        long long cur = 0;
        for (int i = 0; i < n; i++) {
            cur += mx - (towers[i] - i);
        }
        ans = min(ans, cur);
        reverse(towers.begin(), towers.end());
    }
    return ans;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    dbg(solution({1, 4, 3, 2}));
    dbg(solution({5, 7, 9, 4, 11}));
    return 0;
}