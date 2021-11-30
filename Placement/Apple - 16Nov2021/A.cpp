#include "bits/stdc++.h"
using namespace std;

#define int int64_t

signed main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    int m;
    cin >> m;
    sort(a.begin(), a.end());
    int lo = 0, hi = a.back() - a.front();
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        int l = 1, prev = a[0];
        for (int i = 1; i < n; i++) {
            if (a[i] >= prev + mid) {
                l++;
                prev = a[i];
            }
        }
        if (l >= m) {
            lo = mid + 1;
        }
        else {
            hi = mid - 1;
        }
    }
    cout << hi;
    return 0;
}