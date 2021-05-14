#include<bits/stdc++.h>
using namespace std;

#define int long long

bool dfs(int u, vector<vector<int>>& g, vector<bool>& vis, vector<bool>& act, vector<int>& topo) {
    vis[u] = true;
    act[u] = true;
    bool ok = false;
    for(int i = 0; i < (int) g[u].size(); i++) {
        int v = g[u][i];
        if(!vis[v]) {
            ok = ok | dfs(v, g, vis, act, topo);
        } else if(act[v]) {
            return true;
        }
    }

    topo.push_back(u);

    act[u] = false;
    return ok;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> g(n);
    vector<bool> vis(n, false), act(n, false);

    string s;
    cin >> s;

    vector<int> x(m), y(m);
    for(int i = 0; i < m; i++) {
        cin >> x[i];
        x[i]--;
    }
    for(int i = 0; i < m; i++) {
        cin >> y[i];
        y[i]--;
    }

    for(int i = 0; i < m; i++) {
        g[x[i]].push_back(y[i]);
    }

    bool cycle = false;

    vector<int> topo;


    for(int i = 0; i < n; i++) {
        if(!vis[i]) {
            cycle = cycle | dfs(i, g, vis, act, topo);
        }
    }
    reverse(topo.begin(), topo.end());

    vector<vector<int>> freq(n, vector<int>(26, 0));

    int ans = -1;
    if(!cycle) {
        for(int it = 0; it < n; it++) {
            int u = topo[it];
            freq[u][s[u] - 'a']++;

            int cur = 0;
            for(int j = 0; j < 26; j++) {
                cur = max(cur, freq[u][j]);
            }

            ans = max(ans, cur);

            for(int i = 0; i < g[u].size(); i++) {
                int v = g[u][i];
                for(int j = 0; j < 26; j++) {
                    freq[v][j] += freq[u][j];
                }
            }
        }
    }

    cout << ans << '\n';

    return 0;
}