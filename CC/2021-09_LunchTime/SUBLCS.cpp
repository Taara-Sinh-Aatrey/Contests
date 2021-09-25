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
    int n;
    scan(n);
    vector<int> a(n);
    vector<vector<int>> idxs(n);
    scan(a);
    for(int i = 0; i < n; i++) {
        a[i]--;
        idxs[a[i]].emplace_back(i);
    }
    vector<int> inc_p(n, 1), dec_p(n, 1), inc_s(n, 1), dec_s(n, 1);
    vector<int> vec;
    for (int i = 0; i < n; i++) {
        if(i == 0) {
            vec.emplace_back(a[i]);
        }
        else {
            int idx = upper_bound(vec.begin(), vec.end(), a[i]) - vec.begin();
            if(idx >= vec.size()) {
                vec.emplace_back(a[i]);
            }
            else {
                vec[idx] = a[i];
            }
            inc_p[i] = idx + 1;
        }
    }
    int len_inc = vec.size();
    
    vec.clear();
    for (int i = 0; i < n; i++) {
        if(i == 0) {
            vec.emplace_back(a[i]);
        }
        else {
            int idx = lower_bound(vec.rbegin(), vec.rend(), a[i]) - vec.rbegin() - 1;
            idx = vec.size() - 1 - idx;
            if(idx >= vec.size()) {
                vec.emplace_back(a[i]);
            }
            else {
                vec[idx] = a[i];
            }
            dec_p[i] = idx + 1;
        }
    }
    int len_dec = vec.size();
    // dbg(inc_p, dec_p);
    
    vec.clear();
    for (int i = n - 1; i >= 0; i--) {
        if(i == n - 1) {
            vec.emplace_back(a[i]);
        }
        else {
            int idx = upper_bound(vec.begin(), vec.end(), a[i]) - vec.begin();
            if(idx >= vec.size()) {
                vec.emplace_back(a[i]);
            }
            else {
                vec[idx] = a[i];
            }
            inc_s[i] = idx + 1;
        }
    }
    
    vec.clear();
    for (int i = n - 1; i >= 0; i--) {
        if(i == n - 1) {
            vec.emplace_back(a[i]);
        }
        else {
            int idx = lower_bound(vec.rbegin(), vec.rend(), a[i]) - vec.rbegin() - 1;
            idx = vec.size() - 1 - idx;
            if(idx >= vec.size()) {
                vec.emplace_back(a[i]);
            }
            else {
                vec[idx] = a[i];
            }
            dec_s[i] = idx + 1;
        }
    }
    // dbg(len_inc, len_dec);
    // dbg(dec_p);
    // dbg(inc_s);
    int ans = 0;
    for(int i = 0; i < n; i++) {
        vector<int> L(1, 0);
        for (auto& j : idxs[i]) {
            bool ok = true;
            ok &= inc_p[j] + dec_s[j] - 1 == len_inc;
            ok &= inc_s[j] + dec_p[j] - 1 == len_dec;
            L.emplace_back(L.back());
            if(ok) {
                L.back()++;
            }
            else {
                L.back() = 0;
            }
        }
        ans = max(ans, *max_element(L.begin(), L.end()));
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
        solve();
    }

    return 0;
}