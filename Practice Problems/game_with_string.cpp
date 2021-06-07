/**
 *    author:  Taara Sinh Aatrey
 *    created: 04.06.2021 12:47:33
**/

#include <bits/stdc++.h>
using namespace std;

#define int int64_t

template <typename T1, typename T2>
istream& operator>>(istream& in, pair<T1, T2>& a) {
    in >> a.first >> a.second;
    return in;
}
template <typename T1, typename T2>
ostream& operator<<(ostream& out, pair<T1, T2>& a) {
    out << a.first << " " << a.second;
    return out;
}
template <class A, size_t S>
istream& operator>>(istream& in, array<A, S>& a) {
    for (A& x : a) in >> x;
    return in;
}
template <class A, size_t S>
ostream& operator<<(ostream& out, array<A, S>& a) {
    bool f = false;
    for (A& x : a) {
        if (f) out << " ";
        out << x;
        f = true;
    }
    return out;
}
template <typename T>
istream& operator>>(istream& in, vector<T>& a) {
    for (T& x : a) in >> x;
    return in;
}
template <typename T>
ostream& operator<<(ostream& out, vector<T>& a) {
    bool f = false;
    for (T& x : a) {
        if (f) out << " ";
        out << x;
        f = true;
    }
    return out;
}
void out(bool ok, bool cap = true) {
    if (cap) cout << (ok ? "YES" : "NO") << '\n';
    else cout << (ok ? "Yes" : "No") << '\n';
}
template <typename T, typename T1, typename... Tail>
T amax(T& a, T1 b, Tail... c) {
    if(b > a) a = b;
    if constexpr (sizeof...(c) != 0) {
        amax(a, c...);
    }
    return a;
}
template <typename T, typename T1, typename... Tail>
T amin(T& a, T1 b, Tail... c) {
    if(b < a) a = b;
    if constexpr (sizeof...(c) != 0) {
        amin(a, c...);
    }
    return a;
}


const int mod = 1e9 + 7;
const int INF = 1e18L + 5;
const int N = 2e5 + 5;

void solve() {

    string s;
    cin >> s;

    int n = int(s.size());
    map<char, vector<int>> mp;
    for(int i = 0; i < n; i++) {
        mp[s[i]].emplace_back(i);
    }

    long double ans = 0;
    for(char ch = 'a'; ch <= 'z'; ch++) {
        vector<vector<int>> cnt(n, vector<int>(26, 0));
        for(auto& i: mp[ch]) {
            for(int k = 1; k < n; k++) {
                int j = i + k;
                if(j >= n) j -= n;
                cnt[k][s[j] - 'a']++;
            }
        }
        int mx = 0;
        for(int k = 1; k < n; k++) {
            int c = 0;
            for(int j = 0; j < 26; j++) {
                if(cnt[k][j] == 1) {
                    c++;
                }
            }
            amax(mx, c);
        }
        ans += mx;
    }

    ans /= n;

    cout << fixed << setprecision(15) << ans;

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