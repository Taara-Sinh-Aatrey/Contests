/**
 *    author:  Taara Sinh Aatrey
 *    created: 20.06.2021 15:51:15
**/

#include <bits/stdc++.h>
#include <iterator>
#include <type_traits>
using namespace std;

template<typename A, typename B> istream& operator>>(istream &is, const pair<A, B> &p) { return is >> p.first >> p.second;} template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> istream& operator>>(istream &is, T_container &v) { for (T& x : v) is >> x; return is;} bool debug;
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
    int n, k, x;
    cin >> n >> k >> x;
    
    vector<int> a(n);
    cin >> a;
    
    sort(a.begin(), a.end());
    
    vector<pair<int, int>> b;
    for(int i = 0; i < n; i++) {
        if(b.empty() || a[i] > b.back().second + x) {
            b.emplace_back(a[i], a[i]);
        }
        else {
            b.back().second = a[i];
        }
    }
    
    int m = int(b.size());
    
    vector<int> c; 
    
    for(int i = 1; i < m; i++) {
        int mn = b[i - 1].second;
        int mx = b[i].first;
        int gap = (mx - mn + x - 1) / x - 1;
        c.emplace_back(gap);
    }
    
    sort(c.begin(), c.end());
    
    int ans = m;
    for(auto& x : c) {
        if(x <= k) {
            ans--;
            k -= x;
        }
        else {
            break;
        }
    }
    
    cout << ans;
    
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