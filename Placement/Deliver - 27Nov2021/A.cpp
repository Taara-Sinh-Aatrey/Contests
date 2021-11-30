#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) {
        cin >> x;
    }
    sort(a.rbegin(), a.rend());
    int ans = 0;
    int lo = 0, hi = accumulate(a.begin(), a.end(), 0LL);
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        int x = 0;
        for (int i = 0; i < n; i++) {
            x += min(a[i], (mid + 1) / 2);
        }
        if (x >= mid) {
            ans = mid;
            lo = mid + 1;
        }
        else {
            hi = mid - 1;
        }
    }
    cout << ans << '\n';
    return 0;
}