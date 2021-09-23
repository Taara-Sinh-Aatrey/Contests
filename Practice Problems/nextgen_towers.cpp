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

class Solution {
public:
    int maxTowers(int N, int M, vector<vector<int>> connections, int X){
        vector<vector<int>> g(N);
        for (auto& e : connections) {
            g[e[0]].emplace_back(e[1]);
            g[e[1]].emplace_back(e[0]);
        }
        int cc;
        vector<bool> vis(N);
        function<void(int)> dfs = [&](int u) {
            vis[u] = true;
            cc++;
            for(auto& v : g[u]) {
                if(vis[v]) continue;
                dfs(v);
            }    
        };

        bitset<10001> sum;
        sum[0] = 1;
        for (int i = 0; i < N; i++) {
            if (vis[i]) continue;
            cc = 0;
            dfs(i);
            sum |= sum << cc;
        }
        
        for (int i = X; i >= 0; i--) {
            if(sum[i]) {
                return i;
            }
        }
        assert(false);
    }
};

signed main() {
    Solution ob;
    print(ob.maxTowers(4, 2, {{1, 2}, {0, 3}}, 3));
    print(ob.maxTowers(4, 3, {{0, 1}, {1, 2}, {2, 3}}, 3));

    return 0;
}

