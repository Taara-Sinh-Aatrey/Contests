/**
 *    author:  Taara Sinh Aatrey
 *    created: 06.06.2021 18:23:51
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


const int mod = 998244353;
const int INF = 1e18L + 5;
const int N = 2e5 + 5;

vector<vector<int>> mul(const vector<vector<int>>& a, const vector<vector<int>>& b) {
    assert(a.size() > 0 && b.size() > 0 && a[0].size() == b.size());
    int n = a.size(), m = b[0].size();
    vector<vector<int>> c(n, vector<int>(m, 0));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++){
            for(int k = 0; k < b.size(); k++) {
                c[i][j] += (a[i][k] * b[k][j]) % mod;
                if(c[i][j] >= mod) {
                    c[i][j] -= mod;
                }
            }
        }
    }
    return c;
}
 
vector<vector<int>> power(vector<vector<int>> a, int b) {
    int n = int(a.size());
    vector<vector<int>> res(n, vector<int>(n));
    for(int i = 0; i < n; i++) {
        res[i][i] = 1;
    } 
    while(b > 0) {
        if(b & 1) {
            res = mul(res, a);
        }
        a = mul(a, a);
        b >>= 1;
    }
    return res;
}

void solve() {

    int h, w;
    cin >> h >> w;

    vector<vector<int>> F(1 << h, vector<int>(1 << h, 0));


    for(int mask = 0; mask < 1 << h; mask++) {
        vector<int> a;
        for(int i = 0; i < h; i++) {
            if(mask >> i & 1) continue;
            a.emplace_back(i);
        }

        int n = int(a.size());

        function<void(int, int)> rec = [&](int i, int cur_mask) {
            if(i == n) {
                F[mask][cur_mask]++;
                return;
            }
            rec(i + 1, cur_mask);
            rec(i + 1, cur_mask | (1 << a[i]));
            if(i + 1 < n && a[i + 1] == a[i] + 1) {
                rec(i + 2, cur_mask);
            }
        };

        rec(0, 0);
    }

    vector<vector<int>> init(1 << h, vector<int>(1, 0));
    init[0][0] = 1;
    cout << mul(power(F, w), init)[0][0] << '\n';

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