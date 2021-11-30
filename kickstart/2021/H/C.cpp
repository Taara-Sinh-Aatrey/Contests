#include "bits/stdc++.h"
using namespace std;

bool debug;
template <typename T, typename U> istream& operator>>(istream &is, pair<T, U> &p) { return is >> p.first >> p.second;}
template <typename T, typename U> ostream& operator<<(ostream &os, const pair<T, U> &p) { return debug ? os << "(" << p.first << ", " << p.second << ")" : os << p.first << " " << p.second; }
template <typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> istream &operator>>(istream &is, T_container &v) { for (T &x : v) is >> x; return is; }
template <typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream &operator<<(ostream &os, const T_container &v) { bool f = false; if(debug) { os << "{"; for (const T &x : v) { if (f) os << ", "; os << x; f = true; } os << "}"; } else { for (const T &x : v) { if (f) os << " "; os << x; f = true; } } return os; }
void scan() {} template <typename Head, typename ...Tail> void scan(Head &H, Tail &...T) { cin >> H; scan(T...); }
void print() { cout << "\n"; } template <typename Head> void print(const Head &H) { cout << H << "\n"; } template <typename Head, typename ...Tail> void print(const Head &H, const Tail &...T) { cout << H << " "; print(T...); }
template <typename T, typename T1, typename... Tail> T amin(T& a, T1 b, Tail... c) { if(b < a) a = b; if constexpr (sizeof...(c) != 0) { amin(a, c...); } return a; } template <typename T, typename T1, typename... Tail> T amax(T& a, T1 b, Tail... c) { if(b > a) a = b; if constexpr (sizeof...(c) != 0) { amax(a, c...); } return a; }
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
    string s;
    scan(n, s);
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        a[i] = s[i] - '0';
    vector<int> nxt(n), prv(n);
    vector<bool> erased(n, false);
    for (int i = 0; i < n; i++) {
        nxt[i] = i + 1;
        prv[i] = i - 1;
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (int i = 0; i < n - 1; i++) {
        if (a[i + 1] == (a[i] + 1) % 10)
            pq.emplace(a[i], i);
    }
    while (!pq.empty()) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> npq;
        while (!pq.empty()) {
            // i j k l
            // current pair : (j, k), updated result on k
            // next pairs to consider : (i, k) and (k, l)
            auto [val, j] = pq.top();
            pq.pop();
            int k = nxt[j], i = prv[j];
            if (val != a[j] || a[k] != (a[j] + 1) % 10 || erased[j] || erased[k]) continue;
            a[k] = (a[j] + 2) % 10;
            
            // update connections, that is, make i and k adjacent (since j erased)
            erased[j] = true;
            prv[k] = i;
            if (i >= 0) nxt[i] = k;
            
            if (i >= 0 && a[k] == (a[i] + 1) % 10) {
                // insert (i, k) pair
                if (a[i] > val)
                    pq.emplace(a[i], i);
                else
                    npq.emplace(a[i], i);
            }
            int l = nxt[k];
            if (l < n && !erased[l] && a[l] == (a[k] + 1) % 10) {
                // insert (k, l) pair
                if (a[k] > val)
                    pq.emplace(a[k], k);
                else
                    npq.emplace(a[k], k);
            }
        }
        swap(pq, npq);
    }
    for (int i = 0; i < n; i++) {
        if (erased[i]) continue;
        cout << a[i];
    }
    cout << '\n';
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



