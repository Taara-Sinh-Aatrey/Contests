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
    map<int, int> x, y;
    vector<pair<int, int>> p(k);
    for(int i = 0; i < n; i++) {
        int w;
        scan(w);
        x[w] = 1;
    }
    for(int i = 0; i < m; i++) {
        int w;
        scan(w);
        y[w] = 1;
    }
    scan(p);
    int ans = k * (k - 1);
    
    /*
    parallel
    --------------
                  |
                  |
                  |
                  |
                  ----------------
                  
                  and
                  
    --------------------------------
    */
    
    for(int rep = 0; rep < 2; rep++) {
        vector<pair<int, int>> vec;
        for(int i = 0; i < k; i++) {
            if(y.count(p[i].second) && !x.count(p[i].first)) {
                vec.emplace_back(p[i]);
            }
        }
        sort(vec.begin(), vec.end());
        int i = -1;
        for(auto& [xx, val] : x) {
            map<int, int> mp;
            int j = i;
            while(j + 1 < vec.size() && vec[j + 1].first < xx) {
                mp[vec[j + 1].second]++;
                j++;
            }
            for(auto& [yy, f] : mp) {
                ans -= f * (f - 1);
            }
            ans -= 2 * (j - i) * (vec.size() - 1 - j);
            i = j;
        }
        for(auto& [xx, yy] : p) {
            swap(xx, yy);
        }
        swap(x, y);
    }
    
    /*    
    perpendicular
    ----------------------
                         |
                         |
                         |
                         |
                         |
                         
            and
    |
    |
    |
    |
    |
    |____________________
    */    
    vector<int> cnt(2);
    for(int i = 0; i < k; i++) {
        bool xok = x.count(p[i].first), yok = y.count(p[i].second);
        cnt[0] += xok;
        cnt[1] += yok;
    }
    for(int i = 0; i < k; i++) {
        bool xok = x.count(p[i].first), yok = y.count(p[i].second);
        if(xok && yok) ans -= k - 1;
        else if(xok) ans -= cnt[1];
        else if(yok) ans -= cnt[0];
    }
    print(ans / 2);
}

signed main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        solve();
    }

    return 0;
}

// (1, 6) (1, 7)
// (3, 4) (3, 5)
// (4, 3) (4, 5)
// (5, 3) (5, 4)
// (6, 1)
// (7, 1)

