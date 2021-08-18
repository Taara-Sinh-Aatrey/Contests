/**
 *    author:  Taara Sinh Aatrey
 *    created: 14.05.2021 00:49:19
**/

// #undef _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

template <typename A, typename B>
string to_string(pair<A, B> p);

string to_string(const string& s) { return '"' + s + '"'; }

string to_string(const char* s) { return to_string((string) s); }

string to_string(const char& ch) { return "'" + string(1, ch) + "'"; }

string to_string(bool b) { return (b ? "true" : "false"); }

string to_string(vector<bool> v) {
    bool first = true;
    string res = "{";
    for (int i = 0; i < static_cast<int>(v.size()); i++) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(v[i]);
    }
    res += "}";
    return res;
}
template <typename A>
string to_string(A v) {
    bool first = true;
    string res = "{";
    for (const auto& x : v) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(x);
    }
    res += "}";
    return res;
}
template <typename A, typename B>
string to_string(pair<A, B> p) {
    return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << " " << to_string(H);
    debug_out(T...);
}
#ifndef ONLINE_JUDGE
#define dbg(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define dbg(...) 42
#endif

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
    int n, m;
    cin >> n >> m;
    vt<int> a(n);
    cin >> a;

    for(int i = 1; i < n; i++) {
        if(a[i] != 0 && a[i - 1] != 0 && abs(a[i] - a[i - 1]) > 1) {
            cout << 0;
            return;
        }
    }

    int ans = 1;

    for(int i = 0; i < n; ) {
        if(a[i] > 0) { 
            i++;
            continue;
        }
        int j = i;
        while(j < n && a[j] == 0) {
            j++;
        }

        // i j-1
        vt<int> dp(m + 1, 0);
        if(i > 0) {
            dp[a[i - 1]] = 1;
        } else {
            for(int k = 1; k <= m; k++) {
                dp[k] = 1;
            }
        }

        for(int k = i + (i == 0); k <= j - (j == n); k++) {
            vt<int> ndp(m + 1, 0);
            for(int x = 1; x <= m; x++) {
                if(x > 1)
                    ndp[x - 1] = (ndp[x - 1] + dp[x]) % mod;
                ndp[x] = (ndp[x] + dp[x]) % mod;
                if(x + 1 <= m)
                    ndp[x + 1] = (ndp[x + 1] + dp[x]) % mod;
            }
            dp = ndp;
        }

        int cur = 0;
        if(j < n) {
            cur = dp[a[j]];
        } else {
            for(int x = 1; x <= m; x++) {
                cur = (cur + dp[x]) % mod;
            }
        }

        ans = (ans * cur) % mod;

        i = j;

    }

    cout << ans;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;

    for (int tt = 1; tt <= t; tt++) {
        // cout << "Case #" << tt << ": ";
        solve();
    }
    return 0;
}



/*
4 _ _ _  
_ _ 5

6 _ _ _ _ 8

dp[6] = 1

ndp[i] = dp[i - 1] + dp[i] + dp[i + 1]

dp[5] = 6
dp[6] = 6
dp[7] = 6

ndp[4] = 6
ndp[5] = 12
ndp[6] = 18

*/
