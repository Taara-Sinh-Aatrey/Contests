/**
 * the_hyp0cr1t3
 * 30.08.2022 01:23:14
**/
#ifdef W
    #include <k_II.h>
#else
    #include <bits/stdc++.h>
    using namespace std;
#endif

int main() {
#if __cplusplus > 201703L
    namespace R = ranges;
#endif
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int tests; cin >> tests;
    while(tests--) [&] {
        int i, N, K;
        cin >> N >> K;

        vector<int> deg(N);
        vector<vector<int>> adj(N);
        while(K--) {
            int u, v; cin >> u >> v;
            ++deg[--u]; ++deg[--v];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int min_v = min_element(deg.begin(), deg.end()) - deg.begin();

        vector<int> leaders, col(N, -1);
        vector<bool> mark(N, false);
        mark[min_v] = true;
        for(int u: adj[min_v]) {
            if(deg[u] == deg[min_v])
                mark[u] = true;
            else
                leaders.push_back(u);
        }

        if(leaders.size() != 1) {
            leaders = adj[min_v];
            leaders.push_back(min_v);
        } else {
            for(int u: adj[leaders[0]])
                if(!mark[u]) leaders.push_back(u);
        }

        int M = 0;
        for(int l: leaders) col[l] = M++;

        for(int l: leaders)
            for(int u: adj[l])
                if(col[u] == -1) col[u] = col[l];

        // cout << M << '\n';
        // for(i = 0; i < N; i++)
        //     cout << col[i] + 1 << " \n"[i + 1 == N];
        // for(i = 0; i < M; i++)
        //     cout << leaders[i] + 1 << " \n"[i + 1 == M];
    }();

}