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

void solve() {

    int n, m, k;
    scan(n, m, k);
    --k;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            a[i][j] = s[j] == 'X'; 
        }
    }
    int tot = 0;
    for (int j = 0; j < m; j++) {
        tot += a[k][j];        
    }
    int ans = tot;
    
    vector<vector<int>> up(n, vector<int>(m)), down(n, vector<int>(m));
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            up[i][j] = a[i][j];
            if(i > 0) {
                up[i][j] += up[i - 1][j];
            }
        }
        for (int i = n - 1; i >= 0; i--) {
            down[i][j] = a[i][j];
            if(i + 1 < n) {
                down[i][j] += down[i + 1][j];
            }
        }
    }
    
    for (int i = k; i >= -1; i--) {
        int cur = 0;
        for (int j = 0; j < m; j++) {
            if(down[max<int>(0, i)][j] > n - 1- k) {
                cur++;
            }
            else if(i >= 0 && a[i][j] == 1) {
                cur++;
            }
        }
        ans = min(ans, cur + (k - i));
    }
    
    for (int i = k; i <= n; i++) {
        int cur = 0;
        for (int j = 0; j < m; j++) {
            if(up[min(n - 1, i)][j] > k) {
                cur++;
            }
            else if(i < n && a[i][j] == 1) {
                cur++;
            }
        }
        ans = min(ans, cur + (i - k));
    }
    print(ans);
}

signed main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        cout << "Case #" << tt << ": ";
        solve();
    }

    return 0;
}