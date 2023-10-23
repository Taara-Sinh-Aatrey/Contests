#include "bits/stdc++.h"
using namespace std;

#define int int64_t
const int inf = 1e18L + 5, mod = 1e9 + 7, N = 2e5 + 5;

int n;
vector<vector<int>> capacity;
vector<vector<int>> adj;
vector<int> nodes;
vector<int> ans;

const int INF = 1e18L + 5;

int bfs(int s, int t, vector<int>& parent) {
    fill(parent.begin(), parent.end(), -1);
    parent[s] = -2;
    queue<pair<int, int>> q;
    q.push({s, INF});

    while (!q.empty()) {
        int cur = q.front().first;
        int flow = q.front().second;
        q.pop();

        for (int next : adj[cur]) {
            if (parent[next] == -1 && capacity[cur][next]) {
                parent[next] = cur;
                int new_flow = min(flow, capacity[cur][next]);
                if (next == t) {
                    ans.emplace_back(nodes[parent[t]]);
                    return new_flow;
                }
                q.push({next, new_flow});
            }
        }
    }

    return 0;
}

int maxflow(int s, int t) {
    int flow = 0;
    vector<int> parent(n);
    while (true) {
        int new_flow = bfs(s, t, parent); 
        if (new_flow == 0)
            break;
        flow += new_flow;
        int cur = t;
        while (cur != s) {
            int prev = parent[cur];
            capacity[prev][cur] -= new_flow;
            capacity[cur][prev] += new_flow;
            cur = prev;
        }
    }

    return flow;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    nodes.resize(n);
    map<int, int> id;
    for (int i = 0; i < n; i++) {
        cin >> nodes[i];
        id[nodes[i]] = i;
    }
    adj.resize(n);
    capacity.resize(n, vector<int>(n, 0));
    int m;
    cin >> m;
    while (m--) {
        int u, v;
        cin >> u >> v;
        u = id[u];
        v = id[v];
        capacity[u][v]++;
        adj[u].emplace_back(v);
    }
    int s, t;
    cin >> s >> t;
    s = id[s];
    t = id[t];
    maxflow(s, t);
    sort(ans.begin(), ans.end());
    for (auto &x : ans)
        cout << x << " ";
    return 0;
}