/**
 *    author:  Taara Sinh Aatrey
 *    created: 17.05.2021 15:42:13
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

class fenwick {
public:
    int n;
    vector<int> tree;
    // original array should follow 0 based indexing
    fenwick(vector<int>& arr) {
        n = arr.size();
        tree.resize(n + 1, 0);
        for(int i = 0; i < n; i++) {
            modify(i, arr[i]);
        }
    }

    fenwick() {

    }

    fenwick(int _n) {
        n = _n;
        tree.resize(n + 1, 0);
    }

    void modify(int idx, int val) {
        idx += 1;
        while(idx <= n) {
            tree[idx] += val;
            idx += idx & (-idx);
        }
    } 

    int query(int idx) {
        idx += 1;
        int ret = 0;
        while(idx > 0) {
            ret += tree[idx];
            idx -= idx & (-idx);
        }
        return ret;
    }
};

void solve() {

    int k;
    cin >> k;
    string s;
    cin >> s;

    {
        string t = "";
        for(int i = 0; i < k; i++) {
            t = t + s;
        }

        s = t;
    }

    int n = int(s.size());
    vector<vector<int>> vec(26);
    for(int i = 0; i < n; i++) {
        vec[s[i] - 'a'].emplace_back(i);
    }


    vector<fenwick> f(26);
    for(int i = 0; i < 26; i++) {
        f[i] = fenwick(int(vec[i].size()));
    }

    vector<bool> taken(n, false);
    int q;
    cin >> q;
    while(q--) {
        int idx;
        char x;
        cin >> idx >> x;
        int ch = x - 'a';
        idx--;
        
        int low = 0, high = int(vec[ch].size());
        while(low <= high) {
            int mid = (low + high) / 2;
            int gap = mid + 1 - f[ch].query(mid);
            if(gap >= idx + 1) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        taken[vec[ch][low]] = true;
        f[ch].modify(low, 1);
    }

    for(int i = 0; i < n; i++) {
        if(!taken[i]) {
            cout << s[i];
        }
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
