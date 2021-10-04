#include "bits/stdc++.h"
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<pair<int, int>>> g(n);
        for(int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v, --u, --v;
            g[u].emplace_back(v, i);
            g[v].emplace_back(u, i);
        }
        vector<long long> area(n);
        long long total_area = 0;
        for (int i = 0; i < n; i++) {
            cin >> area[i];
            total_area += area[i];
        }
        pair<long long, int> ans{-1, -1};
        function<void(int, int)> dfs = [&](int u, int par) {
            int idx = -1;
            for(auto& p : g[u]) {
                int v = p.first;
                if(v == par) {
                    idx = p.second;
                    continue;                   
                }
                dfs(v, u);
                area[u] += area[v];
            }
            if (idx == -1) return;
            pair<long long, int> cur = {abs(total_area - 2 * area[u]), idx};
            if (ans.first == -1 || cur < ans) {
                ans = cur;
            }
        };
        dfs(0, -1);
        cout << 1 + ans.second << '\n';
    }
    return 0;
}