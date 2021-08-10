/**
 *    author:  Taara Sinh Aatrey
 *    created: 30.07.2021 20:13:53
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
    
    int W, H;
    cin >> W >> H;
    
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    
    tie(x1, x2) = make_tuple(min(x1, x2), max(x1, x2));
    tie(y1, y2) = make_tuple(min(y1, y2), max(y1, y2));
    
    int w1 = x2 - x1;
    int h1 = y2 - y1;
    
    int w2, h2;
    cin >> w2 >> h2;
    
    if(W < (w1 + w2) && H < (h1 + h2)) {
        cout << -1 << '\n';
        return;
    }
    
    int ans = INF;
    
    if(H >= h1 + h2) {
        int f;
        if(y2 > H - h2) {
            f = y2 - (H - h2);
        }
        else {
            f = 0;
        }
        amin(ans, f * f);
        
        if(y1 < h2) {
            f = h2 - y1;
        }
        else {
            f = 0;
        }
        amin(ans, f * f);
    }
    
    if(W >= (w1 + w2)) {
        int s;
        if(x1 < w2) {
            s = w2 - x1;
        }
        else {
            s = 0;
        }
        amin(ans, s * s);
        
        if(x2 > W - w2) {
            s = x2 - (W - w2);
        }
        else {
            s = 0;
        }
        amin(ans, s * s);
    }
    
    cout << fixed << setprecision(12) << sqrtl(ans) << '\n';
    
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