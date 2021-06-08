/**
 *    author:  Taara Sinh Aatrey
 *    created: 08.06.2021 14:31:44
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

    int A, B;
    cin >> A >> B;

    vector<vector<long double>> dp(A + 1, vector<long double>(B + 1, 0));

    dp[A][B] = 1;

    for(int a = A; a >= 0; a--) {
        for(int b = B; b >= 2; b--) {
            long double p = dp[a][b];
            p *= b / (a + b);
            p *= (b - 1) / (a + b - 1);
            if(a >= 1) {
                dp[a - 1][b - 2] += p * (a - 1) / (a + b - 2);
            }
            if(b >= 3) {
                dp[a][b - 3] += p * (b - 2) / (a + b - 2);
            }
        }
    }

    long double ans = 0;

    for(int a = 1; a <= A; a++) {
        for(int b = 0; b <= B; b++) {
            ans += dp[a][b] * a / (a + b);
        }
    }
    cout << fixed << setprecision(12) << ans;

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

