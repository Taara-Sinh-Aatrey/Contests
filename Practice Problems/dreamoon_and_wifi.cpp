/**
 *    author:  Taara Sinh Aatrey
 *    created: 03.06.2021 21:40:55
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

    int f = 0;
    for(char& ch: s) {
        f += (ch == '+' ? 1 : -1);
    }

    cin >> s;
    int cnt = 0;
    for(int i = 0; s[i]; i++) {
        if(s[i] == '?') {
            cnt++;
        }
        else {
            f += (s[i] == '+' ? -1 : 1);
        }
    }

    // x+ (cnt-x)-
    // x+x-cnt = 2x-cnt = f
    // x = (cnt + f) / 2

    cout << fixed << setprecision(12);

    int x = cnt + f;
    if(x % 2 == 1 || x < 0 || x / 2 > cnt) {
        cout << 0;
        return;
    }
    x /= 2;
    long double ans = 1;
    for(int i = 1; i <= cnt; i++) {
        ans *= i;
    }
    for(int i = 1; i <= x; i++) {
        ans /= i;
    }
    for(int i = 1; i <= cnt - x; i++) {
        ans /= i;
    }

    ans /= 1 << cnt;

    cout << ans;

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