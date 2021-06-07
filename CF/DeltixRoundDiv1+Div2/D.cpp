/**
 *    author:  Taara Sinh Aatrey
 *    created: 30.05.2021 21:15:45
**/

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

vector<pair<int, bitset<N>>> vec;
bitset<N> temp;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
int rand(int a, int b) { return uniform_int_distribution<int>(a, b)(rng); }

void solve() {

    int n, m, p;
    cin >> n >> m >> p;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for(int j = 0; j < m; j++) {
            if(s[j] == '1')
                a[i] |= 1LL << j;
        }
    }

    int best = 0, ans = 0;

    for(int it = 0; it < min<int>(n, 200); it++) {
        int idx = rand(0, n - 1);
        vector<int> bits;
        for(int b = 0; b < m; b++) {
            if(a[idx] >> b & 1) {
                bits.emplace_back(b);
            }
        }

        int sz = int(bits.size());
        vector<int> cnt(1 << sz);
        for(int i = 0; i < n; i++) {
            int mask = 0;
            for(int b = 0; b < sz; b++) {
                if(a[i] >> bits[b] & 1)
                    mask |= 1 << b;
            }
            cnt[mask]++;
        }

        for(int b = 0; b < sz; b++) {
            for(int mask = 0; mask < (1 << sz); mask++) {
                if(mask >> b & 1) {
                    cnt[mask ^ (1 << b)] += cnt[mask];
                }
            }
        }

        for(int mask = 0; mask < (1 << sz); mask++) {
            if(2 * cnt[mask] >= n && __builtin_popcountll(mask) > best) {
                best = __builtin_popcountll(mask);
                ans = 0;
                for(int b = 0; b < sz; b++) {
                    if(mask >> b & 1) {
                        ans |= 1LL << bits[b];
                    }
                }
            }
        }
    }

    for(int b = 0; b < m; b++) {
        cout << (ans >> b & 1);
    }

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