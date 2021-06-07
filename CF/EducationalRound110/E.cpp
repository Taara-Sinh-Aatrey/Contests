/**
 *    author:  Taara Sinh Aatrey
 *    created: 04.06.2021 21:32:25
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

    int q;
    cin >> q;

    vector<int> gold(q + 1), cost(q + 1);
    cin >> gold[0] >> cost[0];

    vector<int> org = gold;

    const int lvl = 19;

    vector<vector<int>> p(q + 1, vector<int>(lvl, -1));

    for(int i = 1; i <= q; i++) {
        int t;
        cin >> t;
        if(t == 1) {
            int par, g, c;
            cin >> par >> g >> c;
            p[i][0] = par;
            gold[i] = org[i] = org[par] + g;
            cost[i] = c;
            for(int j = 1; j < lvl; j++) {
                int x = p[i][j - 1];
                if(x != -1) {
                    p[i][j] = p[x][j - 1];
                }
            }
        }
        else {
            int u, need;
            cin >> u >> need;
            int bought = 0, expense = 0;
            int root = u;
            for(int j = lvl - 1; j >= 0; j--) {
                int x = p[root][j];
                if(x != -1 && gold[x] > 0) {
                    root = x;
                }
            }
            if(gold[root] == 0) {
                cout << 0 << " " << 0 << endl;
                continue;
            }
            int r = p[root][0];
            int sub = org[root] - gold[root];
            if(sub == 0 && r >= 0) {
                root = r;
                r = p[root][0];
                sub = org[root] - gold[root];
            }
            int bot = u;
            for(int j = lvl - 1; j >= 0; j--) {
                int x = p[bot][j];
                if(x != -1 && org[x] - sub >= need) {
                    bot = x;
                }
            }
            // cout << "i = " << i << " " << bot << " " << root << endl;
            bool flg = true;
            while(true) {
                int tp = p[bot][0];
                int me = org[bot] - sub - (tp >= 0 ? (org[tp] == gold[tp] ? org[tp] - sub : gold[tp]) : 0);
                // cout << me << endl;
                if(flg) {
                    int rem = max<int>(org[bot] - sub - (r >= 0 ? gold[r] : 0) - need, 0);
                    expense += (me - rem) * cost[bot];
                    bought += me - rem;
                    gold[bot] = rem;
                    flg = false;
                }
                else {
                    bought += me;
                    expense += me * cost[bot];
                    gold[bot] = 0;
                }
                if(bot == root) {
                    break;
                }
                bot = tp;
            };
            cout << bought << " " << expense << endl;
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