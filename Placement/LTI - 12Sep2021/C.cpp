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


int stairs(int n, int p, int f, int u, int d) {
    const int inf = 1e9;
    vector<int> dis(n + 1, inf);
    queue<int> q;
    q.emplace(p);
    dis[p] = 0;
    while(!q.empty()) {
        auto x = q.front();
        q.pop();
        for(int y : {x + u, x - d}) {
            if(y < 1 || y > n) continue;
            if(dis[y] > dis[x] + 1) {
                dis[y] = dis[x] + 1;
                q.emplace(y);
            }
        }
    }
    return (dis[f] >= inf ? -1 : dis[f]);
}

signed main() {
    
    cout << stairs(8, 1, 6, 2, 1) << endl;
    cout << stairs(9, 3, 5, 3, 2) << endl;
    
    return 0;
}