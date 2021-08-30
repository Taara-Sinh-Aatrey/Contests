/**
 *    author:  Taara Sinh Aatrey
 *    created: 29.08.2021 20:10:23
**/

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
    
    int n;
    cin >> n;
    vector<int> a(n);
    cin >> a;
    
    int ans = INF;
    
    /*tourist approach
    
    taken even numbers and try placing it at all odd or all even positions
    why to even bother about odd numbers??
    
    same can be done with odd numbers*/
    
    for(int parity : {0, 1}) {
        vector<int> desired;
        for(int i = parity; i < n; i += 2) {
            desired.emplace_back(i);
        }
        
        vector<int> actual;
        for(int i = 0; i < n; i++) {
            if(a[i] % 2 == 0) {
                actual.emplace_back(i);
            }
        }
        
        if(desired.size() != actual.size()) continue;
        int cur = 0;
        for(int i = 0; i < desired.size(); i++) {
            cur += abs(desired[i] - actual[i]);
        }
        
        amin(ans, cur);
    }
    
    /*
    
    My approach: simple and nice but not better than tourist's approach
    
    for(int x = 0; x < 2; x++) {
        int c = 1, p = x;
        int cur = 0;
        for(int i = 0; i < n; i++) {
            if(a[i] % 2 == p) {
                c++;
            }
            else {
                cur += c - 1;
                if(c == 1) {
                    p ^= 1;
                }
                else {
                    c--;
                }
            }
        }
        if(c == 1) amin(ans, cur);
    }
    */
    
    if(ans >= INF) ans = -1;
    
    cout << ans << '\n';
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        solve();
    }
    
    return 0;
}