/**
 *    author:  Taara Sinh Aatrey
 *    created: 27.05.2021 12:35:40
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


class fenwick {
public:
    int n;
    vector<int> tree;
    // original array should follow 0 based indexing
    fenwick() {

    }

    fenwick(int _n) {
        n = _n;
        tree.resize(n + 1, 0);
    }

    fenwick(vector<int>& arr) {
        n = arr.size();
        tree.resize(n + 1, 0);
        for(int i = 0; i < n; i++) {
            modify(i, arr[i]);
        }
    }

    void modify(int idx, int val) {
        idx += 1;
        while(idx <= n) {
            tree[idx] += val;
            idx += idx & (-idx);
        }
    } 

    int get(int idx) {
        idx += 1;
        int ret = 0;
        while(idx > 0) {
            ret += tree[idx];
            idx -= idx & (-idx);
        }
        return ret;
    }
};

const int mod = 1e9 + 7;
const int INF = 1e18L + 5;
const int N = 2e5 + 5;

void solve() {

    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    cin >> a;

    fenwick f(a);

    while(q--) {
        int t, l, r;
        cin >> t >> l >> r;
        l--;
        if(t == 1) {
            f.modify(l, r - a[l]);
            a[l] = r;
        }
        else {
            r--;
            cout << f.get(r) - (l > 0 ? f.get(l - 1) : 0) << '\n';
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