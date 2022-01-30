#include "bits/stdc++.h"
using namespace std;

bool debug;
template <typename T, typename U> istream& operator>>(istream &is, pair<T, U> &p) { return is >> p.first >> p.second; }
template <typename T, typename U> ostream& operator<<(ostream &os, const pair<T, U> &p) { return debug ? os << "(" << p.first << ", " << p.second << ")" : os << p.first << " " << p.second; }
template <typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> istream &operator>>(istream &is, T_container &v) { for (T &x : v) is >> x; return is; }
template <typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream &operator<<(ostream &os, const T_container &v) { bool f = false; if(debug) { os << "["; for (const T &x : v) { if (f) os << ", "; os << x; f = true; } os << "]"; } else { for (const T &x : v) { if (f) os << " "; os << x; f = true; } } return os; }
void scan() {} template <typename Head, typename ...Tail> void scan(Head &H, Tail &...T) { cin >> H; scan(T...); }
void print() { cout << "\n"; } template <typename Head> void print(const Head &H) { cout << H << "\n"; } template <typename Head, typename ...Tail> void print(const Head &H, const Tail &...T) { cout << H << " "; print(T...); }
template <typename Head> void dbg_out(string var, const Head &H) { cerr << var << " = " << H << endl; } template <typename Head, typename ...Tail> void dbg_out(string var, const Head &H, const Tail &...T) { for (int i = 0, b = 0; i < int(var.size()); i++) { if (var[i] == '(' || var[i] == '{') { b++; } else if (var[i] == ')' || var[i] == '}') { b--; } else if (var[i] == ',' && b == 0) { cerr << var.substr(0, i) << " = " << H << " | "; dbg_out(var.substr(var.find_first_not_of(' ', i + 1)), T...); break; } } }
template <typename T, typename T1, typename... Tail> T amin(T& a, T1 b, Tail... c) { if(b < a) a = b; if constexpr (sizeof...(c) != 0) { amin(a, c...); } return a; } template <typename T, typename T1, typename... Tail> T amax(T& a, T1 b, Tail... c) { if(b > a) a = b; if constexpr (sizeof...(c) != 0) { amax(a, c...); } return a; }
#ifndef ONLINE_JUDGE
#define dbg(...) debug = true, dbg_out(#__VA_ARGS__, __VA_ARGS__), debug = false
#else
#define dbg(...)
#endif

#define int int64_t
const int inf = 1e18L + 5, mod = 1e9 + 7, N = 2e5 + 5;

void solve() {
    string s;
    scan(s);
    int n = s.size();
    vector<int> fst(26, -1), lst(26, -1);
    vector<vector<int>> occ(26);
    vector<array<int, 2>> twos;
    vector<array<int, 3>> threes;
    for (int i = 0; i < n; i++) {
        int ch = s[i] - 'a';
        if (fst[ch] == -1) {
            fst[ch] = i;
        }
        lst[ch] = i;
        occ[ch].emplace_back(i);
    }
    for (int i = 0; i < 26; i++) {
        if (fst[i] == -1) continue;
        for (int j = 0; j < 26; j++) {
            if (fst[j] == -1) continue;
            if (lst[i] < fst[j]) {
                twos.push_back({i, j});
            }
        }
    }
    for (int i = 0; i < 26; i++) {
        if (fst[i] == -1) continue;
        for (int j = 0; j < 26; j++) {
            if (fst[j] == -1) continue;
            if (i == j) continue;
            for (int k = 0; k < 26; k++) {
                if (fst[k] == -1) continue;
                if (i == k || j == k) continue;
                int x = fst[i], y = lst[j];
                auto it = lower_bound(occ[k].begin(), occ[k].end(), x);
                if (it != occ[k].end() && *it <= y) continue;
                threes.push_back({i, j, k});
            }
        }
    }

    int best = 0;
    for (int ch = 0; ch < 26; ch++) {
        if (fst[ch] == -1) continue;
        best++;
    } 
    function<void(vector<array<int, 2>>, vector<bool>, int)> rec = [&] (vector<array<int, 2>> vec, vector<bool> done, int ops) {
        if (vec.empty()) {
            int sz = threes.size();
            int mx = 0;
            for (int mask = 0; mask < 1 << sz; mask++) {
                vector<bool> taken(26);
                bool ok = true;
                int cnt = 0;
                for (int i = 0; i < sz; i++) {
                    if (mask >> i & 1) {
                        auto &[x, y, z] = threes[i];
                        if (done[x] || done[y] || done[z] || taken[x] || taken[y] || taken[z]) {
                            ok = false;
                            break;
                        }
                        taken[x] = taken[y] = taken[z] = true;
                        cnt += 3;
                    }
                }
                if (ok) amax(mx, cnt);
            }
            int rem = 0;
            for (int ch = 0; ch < 26; ch++) {
                if (done[ch] || fst[ch] == -1) continue;
                rem++;
            }
            rem -= mx;
            amin(best, ops + rem + mx / 3 * 2);
        }
        else {
            for (auto &[x, y] : vec) {
                if (done[x] || done[y]) continue;
                vector<array<int, 2>> ntwos;
                for (auto &[w, z] : vec) {
                    if (w == x || z == y)
                        continue;
                    ntwos.push_back({w, z});
                }
                done[x] = done[y] = true;
                rec(ntwos, done, ops + 1);
                done[x] = done[y] = false;
            }
        }
    };
    vector<bool> done(26, false);
    rec(twos, done, 0);
    print(best);
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