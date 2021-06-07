/**
 *    author:  Taara Sinh Aatrey
 *    created: 22.05.2021 20:56:15
**/

#include <bits/stdc++.h>
using namespace std;

#define int int64_t

template <typename T1, typename T2>
istream& operator>>(istream& in, pair<T1, T2>& a) {
    in >> a.first >> a.second;
    return in;
}
template <typename T1, typename T2>
ostream& operator<<(ostream& out, pair<T1, T2>& a) {
    out << a.first << " " << a.second;
    return out;
}
template <class A, size_t S>
istream& operator>>(istream& in, array<A, S>& a) {
    for (A& x : a) in >> x;
    return in;
}
template <class A, size_t S>
ostream& operator<<(ostream& out, array<A, S>& a) {
    bool f = false;
    for (A& x : a) {
        if (f) out << " ";
        out << x;
        f = true;
    }
    return out;
}
template <typename T>
istream& operator>>(istream& in, vector<T>& a) {
    for (T& x : a) in >> x;
    return in;
}
template <typename T>
ostream& operator<<(ostream& out, vector<T>& a) {
    bool f = false;
    for (T& x : a) {
        if (f) out << " ";
        out << x;
        f = true;
    }
    return out;
}
void out(bool ok, bool cap = true) {
    if (cap) cout << (ok ? "YES" : "NO") << '\n';
    else cout << (ok ? "Yes" : "No") << '\n';
}
template <typename T, typename T1>
T amax(T& a, T1 b) {
    if (b > a) a = b;
    return a;
}
template <typename T, typename T1>
T amin(T& a, T1 b) {
    if (b < a) a = b;
    return a;
}


const int mod = 1e9 + 7;
const int INF = 1e18L + 5;
const int N = 2e5 + 5;

int intime[N], outtime[N], nodesAtLevel[N], depth[N], nodeAt[2 * N], answer[N];
vector<vector<int>> g(N);

inline int gilbertOrder(int x, int y, int pow, int rotate) {
    if (pow == 0) {
        return 0;
    }
    int hpow = 1 << (pow-1);
    int seg = (x < hpow) ? (
        (y < hpow) ? 0 : 3
    ) : (
        (y < hpow) ? 1 : 2
    );
    seg = (seg + rotate) & 3;
    const int rotateDelta[4] = {3, 0, 0, 1};
    int nx = x & (x ^ hpow), ny = y & (y ^ hpow);
    int nrot = (rotate + rotateDelta[seg]) & 3;
    int subSquareSize = 1LL << (2 * pow - 2);
    int ans = seg * subSquareSize;
    int add = gilbertOrder(nx, ny, pow-1, nrot);
    ans += (seg == 1 || seg == 2) ? add : (subSquareSize - add - 1);
    return ans;
}
 
struct Query {
    int l, r, idx, d;
    int ord;
 
    inline void calcOrder() {
        ord = gilbertOrder(l, r, 21, 0);
    }
}q[N];
 
inline bool operator<(const Query &a, const Query &b) {
    return a.ord < b.ord;
}

int timer = 0;  

void dfs(int u) {
    nodeAt[timer] = u;
    intime[u] = timer++;
    for(int v: g[u]){
        depth[v] = 1 + depth[u];
        dfs(v);
    }
    nodeAt[timer] = u;
    outtime[u] = timer++;
}

void solve() {

    int n, m;
    cin >> n;
    for(int u = 1; u < n; u++) {
        int p;
        cin >> p;
        p--;
        g[p].emplace_back(u);
    }

    dfs(0);

    cin >> m;

    for(int i = 0; i < m; i++) {
        int u, d;
        cin >> u >> d;
        u--;
        q[i].l = intime[u];
        q[i].r = outtime[u];
        q[i].idx = i;
        q[i].d = d;
        q[i].calcOrder();
    }

    sort(q, q + m);

    int curL = q[0].l, curR = q[0].l - 1;

    for(int i = 0; i < m; i++) {
        int l = q[i].l, r = q[i].r, d = q[i].d;
        while(curL < l) {
            nodesAtLevel[depth[nodeAt[curL]]]--;
            curL++;
        }
        while(curL > l) {
            curL--;
            nodesAtLevel[depth[nodeAt[curL]]]++;
        }
        while(curR < r) { 
            curR++;
            nodesAtLevel[depth[nodeAt[curR]]]++;
        }
        while(curR > r) { 
            nodesAtLevel[depth[nodeAt[curR]]]--;
            curR--;
        }
        answer[q[i].idx] = nodesAtLevel[d] / 2;
    }

    for(int i = 0; i < m; i++) {
        cout << answer[i] << '\n';
    }
    

}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;

    for (int tt = 1; tt <= t; tt++) {
        solve();
    }
    
    return 0;
}