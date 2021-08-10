/*
ID: taarasi1
TASK: ariprog
LANG: C++14             
*/

#include <bits/stdc++.h>
using namespace std;

template<typename A, typename B> istream& operator>>(istream &is, pair<A, B> &p) { return is >> p.first >> p.second;} template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> istream& operator>>(istream &is, T_container &v) { for (T& x : v) is >> x; return is;} bool debug;
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return debug ? os << '(' << p.first << ", " << p.second << ')' : os << p.first << " " << p.second;} template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { if(debug) { os << "{"; string sep; for (const T &x : v) os << sep << x, sep = ", "; os << '}'; } else { bool f = false; for (const T &x : v) { if(f) {os << " ";} os << x, f = true; } } return os;}
template <typename T, typename T1, typename... Tail> T amin(T& a, T1 b, Tail... c) { if(b < a) a = b; if constexpr (sizeof...(c) != 0) { amin(a, c...); } return a; } template <typename T, typename T1, typename... Tail> T amax(T& a, T1 b, Tail... c) { if(b > a) a = b; if constexpr (sizeof...(c) != 0) { amax(a, c...); } return a; }
void dbg_out() { cerr << endl; } template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#ifdef ONLINE_JUDGE
#define dbg(...)
#else
#define dbg(...) cerr << "[" << #__VA_ARGS__ << "]:", debug = true, dbg_out(__VA_ARGS__), debug = false
#endif

#define int int64_t
const int mod = 1e9 + 7; const int INF = 1e18L + 5; const int N = 2e5 + 5;

void solve() {
    int n, m;
    cin >> n >> m;
    
    const int MAX = m * m * 2;
    
    vector<bool> present(MAX + 1);
    
    for(int i = 0; i <= m; i++) {
        for(int j = 0; j <= i; j++) {
            present[i * i + j * j] = true;
        }
    }
        
    vector<pair<int, int>> ans;
    
    for(int i = 0; i <= MAX; i++) {
        if(!present[i]) {
            continue;
        }
        for(int d = 1; i + d * (n - 1) <= MAX; d++) {
            bool AP = true;
            for(int j = 0; j < n; j++) {
                if(!present[i + j * d]) {
                    AP = false;
                    break;
                }
            }
            if(AP) {
                ans.emplace_back(d, i);
            }
        }
    }
    
    sort(ans.begin(), ans.end());
    
    if(ans.empty()) {
        cout << "NONE" << '\n';
    }
    
    for(auto& [a, b] : ans) {
        cout << b << " " << a << '\n';
    }
    
}

signed main()
{
#ifndef LOCAL
    freopen("ariprog.in", "r", stdin);
    freopen("ariprog.out", "w", stdout);
#endif

    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
    
    return 0;
}