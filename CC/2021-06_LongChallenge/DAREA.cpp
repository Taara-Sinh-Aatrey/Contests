/**
 *    author:  Taara Sinh Aatrey
 *    created: 06.06.2021 09:30:17
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

    vector<pair<int, int>> p(n);
    cin >> p;

    auto solve = [&] {

        int ans = INF;
        sort(p.begin(), p.end());

        vector<int> pref_mn(n), pref_mx(n);
        for(int i = 0; i < n; i++) {
            pref_mn[i] = min(p[i].second, i > 0 ? pref_mn[i - 1] : INF);
            pref_mx[i] = max(p[i].second, i > 0 ? pref_mx[i - 1] : 0);
        }

        vector<int> suff_mn(n), suff_mx(n);
        for(int i = n - 1; i >= 0; i--) {
            suff_mn[i] = min(p[i].second, i + 1 < n ? suff_mn[i + 1] : INF);
            suff_mx[i] = max(p[i].second, i + 1 < n ? suff_mx[i + 1] : 0);
        }

        for(int i = 0; i < n; i++) {
            int cur = (p[i].first - p[0].first) * (pref_mx[i] - pref_mn[i]);
            if(i + 1 < n) {
                cur += (p[n - 1].first - p[i + 1].first) * (suff_mx[i + 1] - suff_mn[i + 1]);
            }
            amin(ans, cur);
        }
        
        for(int i = 0; i < n; i++) {
            swap(p[i].first, p[i].second);
        }

        return ans;
    };

    int ans = min(solve(), solve());

    cout << ans << '\n';

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