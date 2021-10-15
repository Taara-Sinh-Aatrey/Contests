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
const int inf = 1e18L + 5, mod = 1e9 + 7, N = 3e5 + 5;

void solve() {

    int n, m;
    scan(n, m);
    map<int,  int> mp;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        mp[x]++;
    }
    vector<int> pref(N), cnt(N);
    for(int i = 1; i < N; i++) {
        pref[i] = pref[i - 1] + mp[i] * i;
        cnt[i] = cnt[i - 1] + mp[i];
    }
    
    int ans = 1;
    int cur;
    for(int i = 2; i < N; i++)  {
        cur = 0;
        for(int j = 0; j < N; j += i) {
            cur += (cnt[min(N - 1, j + i)] - cnt[j]) * (j + i) - (pref[min(N - 1, j + i)] - pref[j]); 
        }
        if(cur <= m) {
            ans = i;
        }
    }
    if(ans == N - 1) {
        assert(m >= cur);
        m -= cur;
        ans += m / n;
    }
    print(ans);
}

signed main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;

    for (int tt = 1; tt <= t; tt++) {
        solve();
    }

    return 0;
}