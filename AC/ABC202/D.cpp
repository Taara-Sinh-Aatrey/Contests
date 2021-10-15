/**
 *    author:  Taara Sinh Aatrey
 *    created: 22.05.2021 20:09:52
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
template <typename T, typename T1>
T amax(T& a, T1 b) {
    if (b > a) a = b;
    return a;
}
template <typename T, typename T1>
T amin(T& a, T1 b) {
    if (b < a) a = b;
    return a;
}


const int mod = 1e9 + 7;
const int INF = 4e18L + 5;
const int N = 2e5 + 5;

int fac[65][65];

void solve() {

    int a, b, k;
    cin >> a >> b >> k;
    k--;

    int n = a + b;
    string ans(n, '?');


    for(int i = 0; i < n; i++) {
        // try putting b here
        int tot = n - (i + 1);
        int smaller = tot == 0 ? 0 : fac[tot][b];
        if(a > 0 && (smaller > k || b == 0)) {
            // put a
            ans[i] = 'a';
            a--;
        }
        else {
            // put b
            k -= smaller;
            ans[i] = 'b';
            b--;
        }
        // cerr << k << endl;
    }


    assert(k == 0);

    cout << ans;

}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    fac[0][0] = 1;
    for(int n = 1; n <= 60; n++) {
        fac[n][0] = 1;
        for(int r = 1; r <= n; r++) {
            fac[n][r] = min(fac[n - 1][r - 1] + fac[n - 1][r], INF);
        }
    }

    int t = 1;

    for (int tt = 1; tt <= t; tt++) {
        solve();
    }
    
    return 0;
}
