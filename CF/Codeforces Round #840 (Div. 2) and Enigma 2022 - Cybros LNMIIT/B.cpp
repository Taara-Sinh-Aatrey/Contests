/**
 *    author:  Taara Sinh Aatrey
 *    created: 27.12.2022 16:08:57
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
    int testcases;
    cin >> testcases;
    for (int caseno = 1; caseno <= testcases; caseno++) {
        int n, k;
        cin >> n >> k;
        vector<pair<int, int>> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i].first;
        }
        multiset<int> powers;
        for (int i = 0; i < n; i++) {
            cin >> a[i].second;
            powers.emplace(a[i].second);
        }
        sort(a.begin(), a.end());
        int ptr = 0;
        int damage_so_far = 0;
        while (ptr < n && k > 0) {
            damage_so_far += k;
            while (ptr < n && a[ptr].first <= damage_so_far) {
                powers.erase(powers.find(a[ptr].second));
                ptr++;
            }
            if (ptr < n) {
                k -= *powers.begin();
            }
        }
        cout << (ptr == n ? "YES" : "NO") << '\n';
    }
    return 0;
}