/**
 *    author:  Taara Sinh Aatrey
 *    created: 11.07.2021 10:31:56
**/

#include <bits/stdc++.h>
#include <ratio>
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
    
    vector<vector<int>> a(3, vector<int>(3));
    
    cin >> a[0] >> a[1][0] >> a[1][2] >> a[2];
    
    auto get = [&]() {
        int ret = 0;
        for(int i = 0; i < 3; i++) {
            ret += (a[i][1] - a[i][0] == a[i][2] - a[i][1]);
            ret += (a[1][i] - a[0][i] == a[2][i] - a[1][i]);
        }
        ret += (a[1][1] - a[0][0] == a[2][2] - a[1][1]);
        ret += (a[1][1] - a[0][2] == a[2][0] - a[1][1]);
        return ret;
    };
    
    int ans = 0;
    a[1][1] = (a[1][0] + a[1][2]) / 2;
    amax(ans, get());
    
    a[1][1] = (a[0][1] + a[2][1]) / 2;
    amax(ans, get());
    
    a[1][1] = (a[0][0] + a[2][2]) / 2;
    amax(ans, get());
    
    a[1][1] = (a[0][2] + a[2][0]) / 2;
    amax(ans, get());
    
    cout << ans << '\n';
    
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;
    
    string s;
    getline(cin, s);
    for (int tt = 1; tt <= t; tt++) {
        cout << "Case #" << tt << ": ";
        solve();
    }
    
    return 0;
}