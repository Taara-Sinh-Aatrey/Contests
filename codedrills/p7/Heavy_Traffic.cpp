/**
 *    author:  Taara Sinh Aatrey
 *    created: 25.05.2021 18:31:58
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


const int mod = 1e9 + 7;
const int INF = 1e18L + 5;
const int N = 2e5 + 5;

void solve() {

    int m, n;
    cin >> m >> n;

    vector<int> p(m), x(n), v(n);
    cin >> p >> x >> v;

    bool ok = true;

    vector<vector<int>> pos(m), neg(m);

    for(int i = 0; i < n; i++) {
        auto it = lower_bound(p.begin(), p.end(), x[i]) - p.begin();
        if(p[it] == x[i]) {
            // ignore
        }
        else if(v[i] < 0) {
            neg[it].emplace_back(i);
        }
        else {
            pos[it].emplace_back(i);
        }
    }

    for(int it = 0; it < m; it++) {
        if(!pos[it].empty()) {
            sort(pos[it].begin(), pos[it].end(), [&](int i, int j) {
                return x[i] > x[j];
            });
        }
        if(!neg[it].empty()) {
            sort(neg[it].begin(), neg[it].end(), [&](int i, int j) {
                return x[i] < x[j];
            });
        }

        if(!pos[it].empty() && !neg[it].empty() && x[pos[it].back()] < x[neg[it].back()]) {
            ok = false;
            break;
        }
    }

    for(int it = 0; it < m; it++) {
        bool flg = true;
        for(int i = 1; i < int(pos[it].size()); i++) {
            int a = pos[it][i];
            int b = pos[it][i - 1];
            int da = p[it] - x[a];
            int db = p[it] - x[b];
            int va = v[a], vb = v[b];
            // da/va > db/vb
            if(da * vb < db * va) {
                flg = false;
                break;
            }
        }
        if(it != 0) {
            for(int i = 1; i < int(neg[it].size()); i++) {
                int a = neg[it][i];
                int b = neg[it][i - 1];
                int da = x[a] - p[it - 1];
                int db = x[b] - p[it - 1];
                int va = -v[a], vb = -v[b];
                // da/va > db/vb
                if(da * vb < db * va) {
                    flg = false;
                    break;
                }
            }
        }

        if(!flg) {
            ok = false;
            break;
        }
    }

    out(ok);

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