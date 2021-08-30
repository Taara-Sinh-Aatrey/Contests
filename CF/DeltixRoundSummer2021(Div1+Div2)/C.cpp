/**
 *    author:  Taara Sinh Aatrey
 *    created: 29.08.2021 20:31:55
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
    
    for(int i = 1; i < n; i += 2) {
        a[i] = -a[i];
    }
    
    int ans = 0;
    
    for(int i = 0; i < n; i += 2) {
        int cur = 0;
        int mn = INF;
        for(int j = i + 1; j < n; j++) {
            if(cur + a[i] < 0) break;
            amin(mn, cur);
            if(j % 2 == 1) {
                int x = a[i];
                int y = -a[j];
                int now = cur;
                
                // make the min prefix equal to 0
                x += mn;
                now -= mn;
                
                int add = 0;
                
                assert(now >= 0);
                // 'now' can be >= 0, if it is > 0, we need to take some ')' from 'j' to make it 0
                // if it is at all possible
                if(now > 0) {
                    y -= now;
                    add += y >= 0;
                }
                
                // now that 'now' is already 0, we can recreate zeroes in max<int>(0, min(x, y)) ways
                // take z amount of '(' and z amount of ')'
                // z can't exceed x or y
                add += max<int>(0, min(x, y));
                ans += add;
            }
            cur += a[j];
        }
    }
    
    cout << ans << '\n';
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

/*
[i, j]: 0 5
[i, j]: 1 4
[i, j]: 2 3
[i, j]: 8 9
[i, j]: 8 17
[i, j]: 10 17
[i, j]: 11 14
[i, j]: 11 16
[i, j]: 12 13
[i, j]: 15 16

*/