/**
 *    author:  Taara Sinh Aatrey
 *    created: 20.08.2022 17:44:14
**/

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
    const int log = 40;
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    // int ans = 0;
    for (int bit = log; bit >= 0; bit--) {
        vector<array<int, 3>> b;
        int magic = (1LL << (bit + 1)) - 1;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] >> bit & 1) {
                b.push_back({0, -(a[i] & ((1LL << (bit)) - 1)), a[i]});
                continue;
            }
            int req_ops = (1LL << bit) - (a[i] & magic);
            b.push_back({req_ops, -(a[i] & ((1LL << (bit)) - 1)), a[i]});
        }
        if (a.size() > k) {
            sort(b.begin(), b.end());
            int total_ops = 0;
            for (int i = 0; i < k; i++) {
                total_ops += b[i][0];
            }
            if (total_ops <= m) {
                m -= total_ops;
                a.clear();
                for (int i = 0; i < k || (i < n && b[i][0] == 0); i++) {
                    a.emplace_back(b[i][2]);
                    if (b[i][0] != 0)
                        a[i] += (1LL << bit) - (a[i] & magic);
                }
            }
        }
        else {
            int total_ops = 0;
            for (int i = 0; i < k; i++) {
                total_ops += b[i][0];
            }
            if (total_ops <= m) {
                m -= total_ops;
                for (int i = 0; i < k; i++) {
                    if (b[i][0] != 0)
                        a[i] += (1LL << bit) - (a[i] & magic);
                }
            }
        }
    }
    int ans = a[0];
    for (int i = 1; i < k; i++) {
        ans &= a[i];
    }
    cout << ans;
    return 0;
#undef int
}

/*
5903 5243 7271 4440 7964 7751 4296 4149
[, , , 6704, , , , ]

*/