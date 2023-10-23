/**
 *    author:  Taara Sinh Aatrey
 *    created: 15.08.2022 01:49:53
**/

#include "bits/stdc++.h"

using namespace std;

#ifdef AATREY_DEBUG
#include "debug.hpp"
#else
#define dbg(...)
#endif

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<vector<int>>> a(2, vector<vector<int>>(n, vector<int>(m)));
        vector<vector<multiset<int>>> ms(2, vector<multiset<int>>(2));
        for (int rep = 0; rep < 2; rep++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    cin >> a[rep][i][j];
                    ms[rep][(i + j) & 1].emplace(a[rep][i][j]);
                }
            }
        }
        cout << ((min(n, m) == 1 && a[0] == a[1]) || (min(n, m) > 1 && ms[0] == ms[1]) ? "YES" : "NO") << '\n';
    }
    return 0;
}