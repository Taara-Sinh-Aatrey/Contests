/**
 *    author:  Taara Sinh Aatrey
 *    created: 04.06.2021 20:21:29
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

    vector<int> a;

    int last = -1;

    for(int i = 0; i < n; i++) {
        if(s[i] == '?') continue;
        int val = s[i] - '0';
        int p = (val == i % 2);
        if(p != last) {
            a.emplace_back(i);
            last = p;
        }
    }

    if(a.empty()) {
        cout << n * (n + 1) / 2 << '\n';
        return;
    }

    int ans = 0;
    int m = int(a.size());
    vector<array<int, 4>> vec(m);
    for(int i = 0; i < int(a.size()); i++) {
        vec[i][1] = a[i];
        vec[i][3] = i + 1 < m ? a[i + 1] - 1 : n - 1;
    }

    vector<int> b;
    last = -1;
    for(int i = n - 1; i >= 0; i--) {
        if(s[i] == '?') continue;
        int val = s[i] - '0';
        int p = (val == i % 2);
        if(p != last) {
            b.emplace_back(i);
            last = p;
        }
    }
    for(int i = 0; i < int(b.size()); i++) {
        vec[m - 1 - i][2] = b[i];
        vec[m - 1 - i][0] = i + 1 < m ? b[i + 1] + 1 : 0;
    }

    for(int i = 0; i < m; i++) {
        auto [w, x, y, z] = vec[i];
        ans += (z - w + 1) * (z - w + 2) / 2;
        if(i != m - 1) {
            ans -= (z - y) * (z - y + 1) / 2;
        }
    }

    cout << ans << '\n';


}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        solve();
    }
    
    return 0;
}