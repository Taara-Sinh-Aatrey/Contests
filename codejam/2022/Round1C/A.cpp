#include "bits/stdc++.h"
#include <algorithm>
using namespace std;

template <typename T, typename U> istream& operator>>(istream &is, pair<T, U> &p) { return is >> p.first >> p.second; }
template <typename T, typename U> ostream& operator<<(ostream &os, const pair<T, U> &p) { return os << p.first << " " << p.second; }
template <typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> istream &operator>>(istream &is, T_container &v) { for (T &x : v) is >> x; return is; }
template <typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream &operator<<(ostream &os, const T_container &v) { bool f = false; for (const T &x : v) { if (f) os << " "; os << x; f = true; } return os; }
void scan() {} template <typename Head, typename ...Tail> void scan(Head &H, Tail &...T) { cin >> H; scan(T...); }
void print() { cout << "\n"; } template <typename Head> void print(const Head &H) { cout << H << "\n"; } template <typename Head, typename ...Tail> void print(const Head &H, const Tail &...T) { cout << H << " "; print(T...); }
template <typename T, typename T1, typename... Tail> T amin(T& a, T1 b, Tail... c) { if(b < a) a = b; if constexpr (sizeof...(c) != 0) { amin(a, c...); } return a; } template <typename T, typename T1, typename... Tail> T amax(T& a, T1 b, Tail... c) { if(b > a) a = b; if constexpr (sizeof...(c) != 0) { amax(a, c...); } return a; }

#ifdef LOCAL
#include "debug.hpp"
#else
#define dbg(...)
#endif

#define int int64_t
const int inf = 1e18L + 5, mod = 1e9 + 7, N = 2e5 + 5;

void solve() {
    int n;
    scan(n);
    vector<string> s(n);
    scan(s);
    map<char, vector<int>> comp, pref, suff;
    map<char, bool> restricted;
    for (int i = 0; i < n; i++) {
        if (*min_element(s[i].begin(), s[i].end()) == *max_element(s[i].begin(), s[i].end())) {
            comp[s[i][0]].emplace_back(i);
        }
        else {
            pref[s[i][0]].emplace_back(i);
            suff[s[i].back()].emplace_back(i);
            int beg = 0, end = s[i].size() - 1;
            while (beg < (int) s[i].size() && s[i][beg] == s[i][0]) {
                beg++;
            }
            while (end >= 0 && s[i][end] == s[i].back()) {
                end--;
            }
            for (int j = beg, k; j <= end; j = k) {
                k = j;
                while (k <= end && s[i][k] == s[i][j]) {
                    k++;
                }
                if (restricted[s[i][j]]) {
                    print("IMPOSSIBLE");
                    return;
                }
                restricted[s[i][j]] = true;
            }
        }
    }
    for (char ch = 'A'; ch <= 'Z'; ch++) {
        if (max(pref[ch].size(), suff[ch].size()) > 1 || (max({pref[ch].size(), suff[ch].size(), comp[ch].size()}) > 0 && restricted[ch])) {
            print("IMPOSSIBLE");
            return;
        }
    }
    vector<bool> done(n);
    map<char, bool> vis;
    vector<int> ans;
    for (char start = 'A'; start <= 'Z'; start++) {
        if (vis[start])
            continue;
        deque<int> dq;
        char ch = start;
        while (true) {
            vis[ch] = true;
            while (comp[ch].size()) {
                dq.push_back(comp[ch].back());
                done[comp[ch].back()] = true;
                comp[ch].pop_back();
            }
            char nch = ch;
            while (pref[ch].size()) {
                if (done[pref[ch].back()]) {
                    print("IMPOSSIBLE");
                    return;
                }
                done[pref[ch].back()] = true;
                dq.push_back(pref[ch].back());
                nch = s[pref[ch].back()].back();
                pref[ch].pop_back();
            }
            if (nch == ch) {
                break;
            }
            ch = nch;
        }
        // dbg(start, dq);
        ch = start;
        while (true) {
            vis[ch] = true;
            while (comp[ch].size()) {
                dq.push_front(comp[ch].back());
                done[comp[ch].back()] = true;
                comp[ch].pop_back();
            }
            char nch = ch;
            while (suff[ch].size()) {
                if (done[suff[ch].back()]) {
                    print("IMPOSSIBLE");
                    return;
                }
                done[suff[ch].back()] = true;
                dq.push_front(suff[ch].back());
                nch = s[suff[ch].back()].front();
                suff[ch].pop_back();
            }
            if (nch == ch) {
                break;
            }
            ch = nch;
        }
        for (auto &x : dq) {
            ans.emplace_back(x);
        }
        // dbg(start, dq);
    }
    if (ans.size() < n) {
        print("IMPOSSIBLE");
        return;
    }
    for (auto &x : ans) {
        cout << s[x];
    }
    // print("POSSIBLE");
    print();
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    scan(t);
    for (int tt = 1; tt <= t; tt++) {
        cout << "Case #" << tt << ": ";
        solve();
    }
    return 0;
}