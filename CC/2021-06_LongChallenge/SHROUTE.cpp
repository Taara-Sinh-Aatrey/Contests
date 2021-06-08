/**
 *    author:  Taara Sinh Aatrey
 *    created: 06.06.2021 09:09:25
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

    int n, m;
    cin >> n >> m;

    vector<int> a, b;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if(x == 1) {
            a.emplace_back(i);
        }
        else if(x == 2) {
            b.emplace_back(i);
        }
    }

    // cout << a << " " << b << endl;
    while(m--) {
        int x;
        cin >> x, --x;

        int ans = INF;
        if(!a.empty()) {
            auto it = upper_bound(a.begin(), a.end(), x);
            if(it != a.begin()) {
                it = prev(it);
                amin(ans, x - *it);
            }
        } 
        if(!b.empty()) {
            auto it = lower_bound(b.begin(), b.end(), x);
            if(it != b.end()) {
                amin(ans, *it - x);
            }
        }

        if(ans >= INF) {
            ans = -1;
        }

        if(x == 0) {
            ans = 0;
        }

        cout << ans << " \n"[m == 0];
    }

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