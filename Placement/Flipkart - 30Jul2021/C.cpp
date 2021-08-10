#include <bits/stdc++.h>
using namespace std;

#define int int64_t
const int mod = 1e9 + 7; const int INF = 1e18L + 5; const int N = 2e5 + 5;

int shortRoute(int n, int a, int b, int k, vector<vector<int>> vec) {
    
    k = min(k, n - 1);
    
    vector<vector<pair<int, int>>> g(n);
    for(auto& x : vec) {
        g[x[0]].emplace_back(x[2], x[1]);
        g[x[1]].emplace_back(x[2], x[0]);
    }
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> d(n, INF);
    d[a] = 0;
    pq.emplace(0, a);
    
    auto fun = [&]() {
        while(!pq.empty()) {
            auto [dis, u] = pq.top();
            pq.pop();
            if(d[u] < dis) {
                continue;
            }
            for(auto& [w, v] : g[u]) {
                if(d[v] > d[u] + w) {
                    d[v] = d[u] + w;
                    pq.emplace(d[v], v);
                }
            }
        }   
    };
    
    fun();
    
    while(k--) {
        auto nd = d;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for(int u = 0; u < n; u++) {
            for(auto& [w, v] : g[u]) {
                nd[v] = min(nd[v], d[u]);
            }
        }
        
        d = nd;
        
        fun();
    }
    
    return d[b];
}

signed main()
{
    cout << shortRoute(5, 0, 3, 1, {{0, 1, 1}, {0, 4, 1}, {1, 2, 2}, {2, 3, 4}, {4, 3, 7}}) << endl;
    
    return 0;
}