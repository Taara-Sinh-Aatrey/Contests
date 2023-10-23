#include "bits/stdc++.h"
using namespace std;

template <typename T, typename U> istream& operator>>(istream &is, pair<T, U> &p) { return is >> p.first >> p.second; }
template <typename T, typename U> ostream& operator<<(ostream &os, const pair<T, U> &p) { return os << p.first << " " << p.second; }
template <typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> istream &operator>>(istream &is, T_container &v) { for (T &x : v) is >> x; return is; }
template <typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream &operator<<(ostream &os, const T_container &v) { bool f = false; for (const T &x : v) { if (f) os << " "; os << x; f = true; } return os; }
void scan() {} template <typename Head, typename ...Tail> void scan(Head &H, Tail &...T) { cin >> H; scan(T...); }
void print() { cout << "\n"; } template <typename Head> void print(const Head &H) { cout << H << "\n"; } template <typename Head, typename ...Tail> void print(const Head &H, const Tail &...T) { cout << H << " "; print(T...); }
template <typename T, typename T1, typename... Tail> T amin(T& a, T1 b, Tail... c) { if(b < a) a = b; if constexpr (sizeof...(c) != 0) { amin(a, c...); } return a; } template <typename T, typename T1, typename... Tail> T amax(T& a, T1 b, Tail... c) { if(b > a) a = b; if constexpr (sizeof...(c) != 0) { amax(a, c...); } return a; }

#ifdef LOCAL
#include "debug.hpp"
#else
#define dbg(...)
#endif

#define int int64_t
const int inf = 1e18L + 5, mod = 1e9 + 7, N = 2e5 + 5;

void solve() {
    int N, M, E;
    cin >> N >> M >> E;
    vector<pair<int, int>> edges(E);
    cin >> edges;
    int q;
    cin >> q;
    vector<int> Q(q);
    cin >> Q;
    reverse(Q.begin(), Q.end());
    set<int> ignore;
    for (auto &x : Q) {
        ignore.emplace(--x);
    }
    class dsu {
    public:
        vector<int> p, city, powerplant;
        int cc;
        int n;
        int electrified = 0;

        dsu(int _n) : n(_n) {
            cc = n;
            p.resize(n);
            iota(p.begin(), p.end(), 0);
            city.resize(n);
            powerplant.resize(n);
        }

        inline int get(int x) {
            return (x == p[x] ? x : (p[x] = get(p[x])));
        }

        inline bool unite(int x, int y) {
            x = get(x), y = get(y);
            if (x == y)
                return false;
            if (powerplant[x] < powerplant[y])
                swap(x, y);
            if (powerplant[x] > 0 && powerplant[y] == 0) electrified += city[y];
            p[y] = x;
            city[x] += city[y];
            powerplant[x] += powerplant[y];
            cc--;
            return true;
        }
        
        void unite(const vector<pair<int, int>>& edges) {
            for (auto &[u, v] : edges)
                unite(u, v);
        }
        
        void unite(const vector<int> &U, const vector<int> &V) {
            int m = U.size();
            assert(int(V.size()) == m);
            for (int i = 0; i < m; i++)
                unite(U[i], V[i]);
        }
    };
    dsu d(N + M);
    for (int i = 0; i < N; i++) d.city[i] = 1;
    for (int i = N; i < N + M; i++) d.powerplant[i] = 1;
    for (int i = 0; i < E; i++) {
        --edges[i].first, --edges[i].second;
        if (!ignore.count(i)) d.unite(edges[i].first, edges[i].second);
    }
    vector<int> ans;
    for (auto &edge : Q) {
        ans.emplace_back(d.electrified);
        d.unite(edges[edge].first, edges[edge].second);
    }
    reverse(ans.begin(), ans.end());
    for (auto &electrified_city : ans) print(electrified_city);
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    for (int tt = 1; tt <= t; tt++) {
        solve();
    }
    return 0;
}