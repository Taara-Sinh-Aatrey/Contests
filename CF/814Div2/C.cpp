/**
 *    author:  Taara Sinh Aatrey
 *    created: 16.08.2022 22:42:15
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
    for (int tt = 1; tt <= t; tt++) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            --a[i];
        }
        vector<int> ans(k);
        vector<pair<int, int>> q(k);
        for (auto &[x, y] : q) {
            cin >> x >> y;
            --x;
        }
        vector<int> ord(k);
        iota(ord.begin(), ord.end(), 0);
        sort(ord.begin(), ord.end(), [&] (auto &x, auto &y) {
            return q[x].second < q[y].second;
        });
        vector<int> wins(n);
        int rounds = 0, winner = 0;
        for (auto &i : ord) {
            int q_round = q[i].second;
            while (rounds < q_round && a[winner] < n - 1) {
                rounds++;
                winner = a[winner] > a[rounds] ? winner : rounds;
                wins[winner]++;
            }
            wins[winner] += q_round - rounds;
            ans[i] = wins[q[i].first];
            rounds = q_round;
        }
        for (auto &x : ans) {
            cout << x << '\n';        
        }
    }
    return 0;
}