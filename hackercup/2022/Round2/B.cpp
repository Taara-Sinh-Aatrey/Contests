/**
 *    author:  Taara Sinh Aatrey
 *    created: 25.09.2022 00:31:38
**/

#include "bits/stdc++.h"

using namespace std;

#ifdef AATREY_DEBUG
#include "debug.hpp"
#else
#define dbg(...)
#endif


#define int int64_t

struct metal {
    int a, b, x, y;
};

const int mod = 1e9 + 7;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int testcases;
    cin >> testcases;
    for (int caseno = 1; caseno <= testcases; caseno++) {
        // cerr << testcases << endl;
        cout << "Case #" << caseno << ": ";
        int n, k;
        cin >> n >> k;
        vector<metal> a(n);
        map<int, vector<int>> mp;
        for (int i = 0; i < n; i++) {
            cin >> a[i].a >> a[i].b >> a[i].x >> a[i].y;
        }
        sort(a.begin(), a.end(), [&] (auto &x, auto &y) {
            return x.a < y.a;
        });
        for (int i = 0; i < n; i++) {
            mp[a[i].b].emplace_back(i);
        }
        multiset<int, greater<int>> ms{0};
        vector<multiset<int, greater<int>>> profits(n, ms);
        for (auto &[day, vec] : mp) {
            sort(vec.begin(), vec.end(), [&] (auto &i, auto &j) {
                return a[i].y < a[j].y;
            });
        }
        auto consider = [&] (multiset<int, greater<int>> &st, int p) {  
            st.emplace(p);
            if (st.size() > k) {
                st.erase(prev(st.end()));
            }
        };
        multiset<int, greater<int>> ans;
        for (int i = n - 1; i >= 0; i--) {
            int cnt = 0;
            for (auto &p : profits[i]) {
                if (cnt >= k) {
                    break;
                }
                for (auto &j : mp[a[i].a]) {
                    int p_here = a[i].x - a[j].y;
                    if (p_here <= 0) {
                        break;
                    }
                    cnt++;
                    consider(profits[j], p + p_here);
                }
            }
            for (auto &p : profits[i]) {
                consider(ans, p);
            }
            profits[i] = {};
        }
        int sum = 0;
        for (auto &x : ans) {
            sum += x;
            sum %= mod;
        }
        cout << sum << '\n';
    }
    return 0;
}