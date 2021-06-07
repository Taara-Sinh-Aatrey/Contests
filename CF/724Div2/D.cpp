/**
 *    author:  Taara Sinh Aatrey
 *    created: 06.06.2021 20:51:32
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

    int n;
    cin >> n;

    vector<int> a(n);
    cin >> a;

    auto [mn, mx] = minmax_element(a.begin(), a.end());

    if(n == 1) {
        cout << "YES" << '\n';
        return;
    }

    set<int> st{a[0]};
    int prv = a[0];
    for(int i = 1; i < n; i++) {
        if(a[i] == prv) {
            continue;
        }

        bool ok = false;

        auto it = st.upper_bound(a[i]);
        if(it != st.end() && *it == prv) {
            ok = true;
        }

        it = st.lower_bound(a[i]);
        if(it != st.begin() && *prev(it) == prv) {
            ok = true;
        }

        if(!ok) {
            cout << "NO" << '\n';
            return;
        }

        st.insert(a[i]);
        prv = a[i];
    }

    
    cout << "YES" << '\n';

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

/*
6 2 1 
----
  1 1

*/