/**
 *    author:  Taara Sinh Aatrey
 *    created: 16.08.2022 00:58:05
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
    int n, m, k;
    cin >> n >> m >> k;
    const int N = 1e7 + 1;
    vector<int> f(N), g(N);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        f[x]++;
    }
    vector<int> shop(m);
    for (int i = 0; i < m; i++) {
        cin >> shop[i];
        g[shop[i]]++;
    }
    vector<int> ord(m);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&] (auto &x, auto &y) {
        return shop[x] > shop[y];
    });
    vector<int> needs;
    for (int i = 0; i < N; i++) {
        if (f[i] < k) {
            needs.emplace_back(i);
        }
        while (f[i] > k && !needs.empty()) {
            int take = min<int64_t>(f[i] - k, k - f[needs.back()]);
            f[needs.back()] += take;
            f[i] -= take;
            if (f[needs.back()] == k) needs.pop_back();
        }
    }
    needs = {};
    int ans = 0;
    for (int i = 0; i < N; i++) {
        if (f[i] > k) {
            cout << -1;
            return 0;
        }
        if (f[i] < k) {
            needs.emplace_back(i);
        }
        while (g[i] > 0 && !needs.empty()) {
            int take = min<int64_t>(g[i], k - f[needs.back()]);
            f[needs.back()] += take;
            g[i] -= take;
            ans += take;
            if (f[needs.back()] == k) needs.pop_back();
        }
    }
    cout << ans << '\n';
    for (int i = 0; i < ans; i++) {
        cout << ord[i] + 1 << " ";
    }
    return 0;
}