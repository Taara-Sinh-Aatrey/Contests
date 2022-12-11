/**
 *    author:  Taara Sinh Aatrey
 *    created: 10.12.2022 21:08:13
**/

#include "bits/stdc++.h"

using namespace std;

#ifdef AATREY_DEBUG
#include "debug.hpp"
#else
#define dbg(...)
#endif

#define int int64_t

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    multiset<int> top, bottom;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (i < k) {
            top.insert(a[i]);
            sum += a[i];
        }
        else {
            bottom.insert(a[i]);
            if (i >= m) {
                auto it = top.find(a[i - m]);
                if (it != top.end()) {
                    sum -= *it;
                    top.erase(it);
                }
                else {
                    it = bottom.find(a[i - m]);
                    bottom.erase(it);
                }
            }
            while (!bottom.empty() && !top.empty() && *bottom.begin() < *top.rbegin()) {
                int x = *top.rbegin(); 
                top.erase(prev(top.end()));
                sum -= x;
                int y = *bottom.begin(); 
                bottom.erase(bottom.begin());
                top.emplace(y);
                sum += y;
                bottom.emplace(x);
            }
            while (top.size() < k) {
                top.emplace(*bottom.begin());
                sum += *bottom.begin();
                bottom.erase(bottom.begin());
            }
        }
        if (i >= m - 1) {
            cout << sum << " ";
        }
    }
    return 0;
}