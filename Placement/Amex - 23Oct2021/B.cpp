#include<bits/stdc++.h>
using namespace std;

#define int int64_t

int search (const function<bool(int)>& func, int lo = 0, int hi = 1e9) {
    if (lo > hi)
        return 0;
    int mid = (lo + hi) >> 1;
    if (func(mid))
        return max(mid, search(func, mid + 1, hi));
    else
        return search(func, lo, mid - 1);
}

void solve(int n, int x, vector<int> a, vector<int> b, int k) {
    int max_building = search ([&] (int mid) {
        int have = x;
        for (int i = 0; i < n; i++) {
            int need = max<int>(0, b[i] * mid - a[i]);
            have -= need;
        }
        return have >= 0;
    });
    cout << (max_building >= k ? 1 : 0) << " " << max_building << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve(3, 1, {6, 6, 6}, {2, 2, 2}, 5);
    solve(5, 2, {8,9,10,11,19}, {1,2,3,4,3}, 3);
    return 0;
}