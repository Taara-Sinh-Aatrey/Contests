/**
 *    author:  Taara Sinh Aatrey
 *    created: 31.05.2021 09:41:05
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
const int INF = 1e18L + 5;
const int N = 2e5 + 5;

void solve() {

    int n, k;
    cin >> n >> k;

    int med = (k * k + 1) / 2;

    vector<vector<int>> a(n, vector<int>(n));
    cin >> a;
    auto check = [&](int cand) {
        vector<vector<int>> b(n + 1, vector<int>(n + 1));
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                b[i][j] = b[i - 1][j] + b[i][j - 1] - b[i - 1][j - 1] + (a[i - 1][j - 1] <= cand);
            }
        }

        for(int r2 = k; r2 <= n; r2++) {
            for(int c2 = k; c2 <= n; c2++) {
                int r1 = r2 - k;
                int c1 = c2 - k;
                int sum = b[r2][c2] - b[r1][c2] - b[r2][c1] + b[r1][c1];
                if(sum >= med) {
                    return true;
                }
            }
        }

        return false;
    };

    int lo = 0, hi = 1e9;
    while(lo <= hi) {
        int mid = (lo + hi) >> 1;
        if(check(mid)) {
            hi = mid - 1;
        }
        else {
            lo = mid + 1;
        }
    }

    cout << lo;

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