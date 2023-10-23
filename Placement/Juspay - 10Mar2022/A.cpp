#include "bits/stdc++.h"
using namespace std;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
    }
    map<int, vector<pair<int, int>>> g;
    int m;
    cin >> m;
    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].emplace_back(w, v);
    }
    int s, t;
    cin >> s >> t;
    map<int, int> d;
    d[s] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.emplace(0, s);
    while (!pq.empty()) {
        auto &p = pq.top();
        int dis = p.first, u = p.second;
        pq.pop();
        if (dis > d[u])
            continue;
        for (auto &q : g[u]) {
            int w = q.first, v = q.second;
            if (d.count(v) && d[v] <= dis + w)
                continue;
            d[v] = dis + w;
            pq.emplace(d[v], v);
        }
    }
    if (!d.count(t)) {
        d[t] = -1;
    }
    cout << d[t];
    return 0;
}