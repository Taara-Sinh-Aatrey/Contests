/**
 *    author:  Taara Sinh Aatrey
 *    created: 20.04.2021 22:13:06
**/

// #undef _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

#define int int64_t
#define ar array<int, 2>
#define pii pair<int, int>
#define pb push_back
#define vt vector
#define For(i, n) for (int i = 0; i < n; i++)
#define Rev(i, n) for (int i = n - 1; i >= 0; i--)
#define FOR(i, n) for (int i = 1; i <= n; i++)
#define REV(i, n) for (int i = n; i >= 1; i--)
#define Rep(i, a, b) for (int i = a; i <= b; i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define msb(x) (int) (31 - __builtin_clz(x))
#define lsb(x) __builtin_ctz(x)
template <typename T>
using mxpq = priority_queue<T>;
template <typename T>
using mnpq = priority_queue<T, vt<T>, greater<T>>;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
int rand(int a, int b) { return uniform_int_distribution<int>(a, b)(rng); }

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
istream& operator>>(istream& in, vt<T>& a) {
    for (T& x : a) in >> x;
    return in;
}
template <typename T>
ostream& operator<<(ostream& out, vt<T>& a) {
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
    int n;
    cin >> n;
    vt<int> a(n);
    cin >> a;

    vt<pii> le(n, {INF, 1}), ri(n, {INF, 1});

    for(int i = 1; i < n; i++) {
        int cd = a[i] - a[i - 1];
        if(cd == le[i - 1].first) {
            le[i] = {cd, le[i - 1].second + 1};
        } else {
            le[i] = {cd, 2};
        }
    }
    for(int i = n - 2; i >= 0; i--) {
        int cd = a[i + 1] - a[i];
        if(cd == ri[i + 1].first) {
            ri[i] = {cd, ri[i + 1].second + 1};
        } else {
            ri[i] = {cd, 2};
        }
    }

    int ans = 0;
    for(auto [cd, l] : le) {
        amax(ans, l);
    }

    for(auto [cd, l] : ri) {
        amax(ans, l);
    }

    for(int i = 0; i < n; i++) {
        if(i > 0) {
            amax(ans, le[i - 1].second + 1);
        }
        if(i + 1 < n) {
            amax(ans, ri[i + 1].second + 1);
        }
        if(i > 0 && i + 1 < n && (a[i + 1] - a[i - 1]) % 2 == 0) {
            int mid = (a[i + 1] + a[i - 1]) / 2;
            int cd = mid - a[i - 1];
            int cur = 3;
            if(le[i - 1].first == cd) {
                cur += le[i - 1].second - 1;
            }
            if(ri[i + 1].first == cd) {
                cur += ri[i + 1].second - 1;
            }
            amax(ans, cur);
        }
    }

    cout << ans << '\n';
}

signed main()
{

#ifdef LOCAL
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
#endif

    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        cout << "Case #" << tt << ": ";
        solve();
    }
    return 0;
}

