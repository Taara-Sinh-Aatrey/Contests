#include "bits/stdc++.h"
using namespace std;

bool debug;
template <typename T, typename U> istream& operator>>(istream &is, pair<T, U> &p) { return is >> p.first >> p.second;}
template <typename T, typename U> ostream& operator<<(ostream &os, const pair<T, U> &p) { return debug ? os << "(" << p.first << ", " << p.second << ")" : os << p.first << " " << p.second; }
template <typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> istream &operator>>(istream &is, T_container &v) { for (T &x : v) is >> x; return is; }
template <typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream &operator<<(ostream &os, const T_container &v) { bool f = false; if(debug) { os << "{"; for (const T &x : v) { if (f) os << ", "; os << x; f = true; } os << "}"; } else { for (const T &x : v) { if (f) os << " "; os << x; f = true; } } return os; }
void scan() {} template <typename Head, typename ...Tail> void scan(Head &H, Tail &...T) { cin >> H; scan(T...); }
void print() { cout << "\n"; } template <typename Head> void print(const Head &H) { cout << H << "\n"; } template <typename Head, typename ...Tail> void print(const Head &H, const Tail &...T) { cout << H << " "; print(T...); }
void dbg_out() { cerr << "\n"; } template <typename Head, typename ...Tail> void dbg_out(const Head &H, const Tail &...T) { cerr << " " << H; dbg_out(T...); }
#ifndef ONLINE_JUDGE
#define dbg(...) cerr << "[" << #__VA_ARGS__ << "]:", debug = true, dbg_out(__VA_ARGS__), debug = false
#else
#define dbg(...)
#endif

#define int int64_t
const int inf = 1e18L + 5, mod = 1e9 + 7, N = 2e5 + 5;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
int rand(int a, int b) { return uniform_int_distribution<int>(a, b)(rng); }

vector<int> gen_vec(int n, int lo = 0, int hi = 1e9) {
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        a[i] = rand(lo, hi);
    }
    return a;
}

vector<pair<int, int>> gen_tree_edges(int n) {
    vector<pair<int,int>> edges;
    for (int i = 2; i <= n; ++i) {
        edges.emplace_back(rand(1, i - 1), i);
    }
    vector<int> perm(n + 1); // re-naming vertices
    for (int i = 1; i <= n; i++) {
        perm[i] = i;
    }
    shuffle(perm.begin() + 1, perm.end(), rng);
    shuffle(edges.begin(), edges.end(), rng); // random order of edges
    for (auto &[a, b] : edges) {
        if (rand(0, 1) == 1) {
            swap(a, b); // random order of two vertices
        }
        a = perm[a];
        b = perm[b];
    }
    return edges;
}

void solve() {
    int n = rand(1, 10);
    print(n);
    auto a = gen_vec(n, -10, 10);
    print(a);
}

signed main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    print(t);

    for (int tt = 1; tt <= t; tt++) {
        solve();
    }

    return 0;
}