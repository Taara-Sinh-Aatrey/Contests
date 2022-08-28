#include "bits/stdc++.h"

using namespace std;

#ifdef AATREY_DEBUG
#include "debug.hpp"
#else
#define dbg(...)
#endif

int main() {
#define int int64_t
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector<array<int, 3>> Q(q);
    vector<int> limit(n, (1LL << 31) - 1);
    for (int i = 0; i < q; i++) {
        int l, r, x;
        cin >> l >> r >> x, --l, --r;
        if (l > r) swap(l, r);
        Q[i] = {l, r, x};
        limit[l] &= x;
        limit[r] &= x;
    }
    vector<int> a(n);
    // must have
    for (auto &[l, r, x] : Q) {
        a[r] |= x & (~limit[l]);
        a[l] |= x & (~limit[r]);
    }
    // put remaining at min(l, r)
    sort(Q.begin(), Q.end());
    for (auto &[l, r, x] : Q) {
        a[r] |= x & (~(a[l] | a[r]));
    }
    for (auto &x : a) {
        cout << x << " ";
    }
    return 0;
#undef int
}