class graph{
public: 
    int n; // number of nodes
    int e; // number of edges
    int cc; // number of connected components
    int scc; // number of strongly connected components
    vector<vector<pair<int, int>>> g, rg; // adjacency list, reverse adjacency list
    vector<int> value; // value of each node of graph (usually given in the input)
    vector<int> bfs_dist, depth, dijkstra_dist, topo_order;
    vector<int> when; // when[u] represents the scc which u is a part of
    vector<int> cnt; // count of nodes (or anything similar) for every scc
    vector<vector<int>> sccs; // scc[i] contains all the nodes which are part of ith scc

    graph(int _n){
        n = _n;
        g.resize(n + 1);
        e = 0;
    }

    // sets value of each node
    void set_value(vector<int> a) {
        value = a;
    }

    /* weight should be set to 0 or 1 or any neutral value
    if weight is not given as a input */

    void add(int u, int v, int w, bool directed = false) {
        e++;
        g[u].emplace_back(w, v);
        if(!directed) {
            g[v].emplace_back(w, u);
        }
    }

    void bfs(vector<int> src) {
        bfs_dist.resize(n + 1, INF);
        queue<int> q;
        for(int ele: src) {
            q.push(ele);
            bfs_dist[ele] = 0;
        }

        while(!q.empty()) {
            int u = q.front();
            q.pop();
            for(auto& [w, v]: g[u]) {
                if(bfs_dist[v] > bfs_dist[u] + w) {
                    bfs_dist[v] = bfs_dist[u] + w;
                    q.push(v);
                }
            }
        }
    }

    void dfs(int u, int p = -1) {
        if(p == -1) {
            depth.resize(n + 1, -1);
            depth[u] = 0;
        }

        for(auto& [v, w]: g[u]){
            if(depth[v] == -1) {
                depth[v] = depth[u] + w;
                dfs(v, u);
            }
        }
    }

    void dijkstra(vector<int> src) {
        dijkstra_dist.resize(n + 1, INF);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for(int ele: src){
            pq.emplace(0, ele);
            dijkstra_dist[ele] = 0;
        }
        while(!pq.empty()){
            auto [dist, u] = pq.top();
            pq.pop();
            if(dist > dijkstra_dist[u]) {
                continue;
            }
            for(auto& [v, w]: g[u]) {
                if(dijkstra_dist[v] > dist + w) {
                    dijkstra_dist[v] = dist + w;
                    pq.emplace(dijkstra_dist[v], v);
                }
            }
        }
    }

    bool toposort() {
        topo_order.clear();
        vector<int> vis(n, false), act(n, false);

        function<bool(int)> Dfs = [&](int u) -> int {
            vis[u] = act[u] = true;
            for (auto& [w, v]: g[u]) {
                if(act[v]) {
                    return false;
                } else if(!vis[v]) {
                    if(!Dfs(v)) {
                        return false;
                    }
                }
            }
            act[u] = false;
            topo_order.emplace_back(u);
            return true;
        };

        for(int u = 0; u < n; u++) {
            if(!vis[u]) {
                if(!Dfs(u)) {
                    return false;
                }
            }
        } 
        reverse(topo_order.begin(), topo_order.end());
        return true;
    }

    void get_scc() {
        sccs.clear();
        scc = 0;
        topo_order.clear();
        when.assign(n, -1);
        vector<int> vis(n, false);
        rg.assign(n, vector<pair<int, int>>());
        for(int u = 0; u < n; u++) {
            for(auto& [w, v]: g[u]) {
                rg[v].emplace_back(w, u);
            }
        }

        function<void(int)> Dfs = [&](int u) {
            vis[u] = true;
            for (auto& [w, v]: g[u]) {
                if(!vis[v]) {
                    Dfs(v);
                }
            }
            topo_order.emplace_back(u);
        };

        for(int u = 0; u < n; u++) {
            if(!vis[u]) {
                Dfs(u);
            }
        } 
        reverse(topo_order.begin(), topo_order.end());

        function<void(int)> dfs = [&](int u) {
            vis[u] = true;
            sccs[scc].emplace_back(u);
            when[u] = scc;
            if(!value.empty()) {
                cnt[scc] += value[u];
            }
            for (auto& [w, v]: rg[u]) {
                if(!vis[v]) {
                    cnt[scc] += w;
                    dfs(v);
                }
            }
        };

        vis.assign(n, false);
        for(auto u: topo_order) {
            if(!vis[u]) {
                cnt.emplace_back(0);
                sccs.emplace_back(vector<int>());
                dfs(u);
                scc++;
            }
        }
    };

};