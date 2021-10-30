#include "bits/stdc++.h"
using namespace std;

int MinBalance(int N, int M, int K, vector<int> U, vector<int> V, vector<int> A) {
    vector<vector<int>> g(N);
    for (int i = 0; i < M; i++) {
        --U[i], --V[i];
        g[U[i]].emplace_back(V[i]);
        g[V[i]].emplace_back(U[i]);
    }
    const int inf = 1e9 + 5;
    vector<vector<int>> sum_down(N, vector<int>(K + 1, 0));
    function<void(int, int)> dfs_down = [&](int u, int par) {
        sum_down[u][0] = A[u];
        for(int i = 0; i < g[u].size(); i++) {
            int v = g[u][i];
            if(v == par) continue;
            dfs_down(v, u);
            for (int i = 0; i < K; i++) {
                sum_down[u][i + 1] += sum_down[v][i];
            }
        }
    };
    dfs_down(0, -1);
    vector<vector<int>> sum_up(N, vector<int>(K + 1, 0));
    function<void(int, int)> dfs_up = [&](int u, int par) {
        for(int i = 0; i < g[u].size(); i++) {
            int v = g[u][i];
            if(v == par) continue;
            for (int i = 0; i < K; i++) {
                sum_up[v][i + 1] += sum_down[u][i];
                if (i > 0) {
                    sum_up[v][i + 1] -= sum_down[v][i - 1];
                }
                sum_up[v][i + 1] += sum_up[u][i];
            }
            dfs_up(v, u);
        }
    };
    dfs_up(0, -1);
    int mn = inf, mx = -inf;
    for (int u = 0; u < N; u++) {
        int cur = 0;
        for (int i = 0; i <= K; i++) {
            cur += sum_down[u][i] + sum_up[u][i];
        }
        mn = min(mn, cur);
        mx = max(mx, cur);
    }
    return mx - mn;
 }

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << MinBalance(1, 0, 3, {}, {}, {7}) << endl;
    cout << MinBalance(2, 1, 0, {1}, {2}, {5, 7}) << endl;
    cout << MinBalance(3, 2, 1, {1, 2}, {2, 3}, {5, 6, 8}) << endl;
    return 0;
}