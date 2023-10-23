#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// functions: set.insert(val), *(set.find_by_order(order-1)), set.order_of_key(val)
// less_equal for multiset

const int lvl = 19;

vector<vector<int>> p(lvl, vector<int>(n, -1));
vector<int> depth(n, 0);

function<void(int, int)> dfs = [&] (int u, int par) {
    p[0][u] = par;
    depth[u] = par == -1 ? 0 : depth[par] + 1;
    
    for (auto& v : g[u]) {
        if (v == par) continue;
        dfs(v, u);
    }    
};
dfs(0, -1);


for (int i = 1; i < lvl; i++) {
    for (int node = 0; node < n; node++) {
        if (p[i - 1][node] != -1) {
            p[i][node] = p[i - 1][p[i - 1][node]];
        }
    }
}

auto go_up = [&] (int node, int dis) {
    for (int i = lvl - 1; i >= 0; i--)
        if (node >= 0 && (dis >> i & 1))
            node = p[i][node];
    return node;
};

auto find_lca = [&] (int u, int v) {
    if (depth[u] > depth[v]) { 
        swap(u, v);
    }

    v = go_up(v, depth[v] - depth[u]);

    if (u == v) 
        return u;

    for (int i = lvl - 1; i >= 0; i--) {
        if (p[i][u] != p[i][v]){
            u = p[i][u];
            v = p[i][v];
        }
    }
    return p[0][u];
};