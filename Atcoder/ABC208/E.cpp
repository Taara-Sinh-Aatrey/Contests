/**
 *    author:  Taara Sinh Aatrey
 *    created: 04.07.2021 22:26:39
**/

#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
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
const int mod = 1e9 + 7;  const int N = 2e5 + 5;

void solve() {
    
    int n, k;
    cin >> n >> k;
    
    const int INF = k + 1;
    
    string s = to_string(n);
    map<int, int> mp;
    int equal_p = 1;
    
    for(int it = 0; s[it]; it++) {
        int d = s[it] - '0';
        
        map<int, int> nmp;
        
        // less -> less
        for(auto& [x, y] : mp) {
            for(int i = 0; i < 10; i++) {
                int p = min(x * i, INF);
                nmp[p] += y;
            }    
        }
        
        // equal -> less
        for(int i = (it == 0); i < d; i++) {
            int p = min(equal_p * i, INF);
            nmp[p]++;
        }
        
        // 1 to 9
        if(it != 0) {
            for(int i = 1; i < 10; i++) {
                int p = min(i, INF);
                nmp[p]++;
            }
        }
        
        mp = nmp;
        
        equal_p *= d;
    }
    
    int ans = equal_p <= k;
    for(auto& [x, y] : mp) {
        if(x <= k) {
            ans += y;
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
