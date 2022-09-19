/**
 *    author:  Taara Sinh Aatrey
 *    created: 18.09.2022 23:02:07
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
        cout << "Case #" << caseno << ": ";
        int d, n, x;
        cin >> d >> n >> x;
        vector<int> Q(n), L(n), V(n);
        for (int i = 0; i < n; i++) {
            cin >> Q[i] >> L[i] >> V[i];
        }
        vector<int> ord(n);
        iota(ord.begin(), ord.end(), 0);
        sort(ord.begin(), ord.end(), [&] (auto &i, auto &j) {
            return L[i] < L[j];
        });
        priority_queue<pair<int, int>> pq; 
        int ans = 0;
        for (int it = 0; it < n; it++) {
            int i = ord[it];
            int after = it + 1 < n ? L[ord[it + 1]] : d;
            int slots = (after - L[i]) * x;
            pq.emplace(V[i], Q[i]);
            while (slots > 0 && !pq.empty()) {
                auto top = pq.top(); 
                pq.pop();
                int take = min(top.second, slots);
                top.second -= take;
                slots -= take;
                ans += take * top.first;
                if (top.second > 0)
                    pq.emplace(top);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}