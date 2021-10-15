/**
 *    author:  Taara Sinh Aatrey
 *    created: 06.06.2021 17:48:51
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

    vector<vector<pair<int, pair<int, int>>>> g(n);
    for(int i = 0; i < m; i++) {
        int u, v, a, b;
        cin >> u >> v >> a >> b, --u, --v;
        g[u].push_back({v, {a, b}});
        g[v].push_back({u, {a, b}});
    }

    vector<int> d;
    // auto check = [&]() {

        d.assign(n, INF);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.emplace(0, 0);
        d[0] = 0;

        while(!pq.empty()) {
            auto [t, u] = pq.top();
            pq.pop();
            if(t > d[u]) {
                continue;
            }

            for(auto [v, w]: g[u]) {
                auto [a, b] = w;
                int best = INF;
                // function<void(int, int)> search = [&](int low, int high) {
                int low = 0, high = 1e9;
                    while (low <= high) {
                        int mid = (low + high) / 2;
                        int cand1 = t + mid + a + b / (t + mid + 1);
                        int iter = 1;
                        int cand2 = cand1;
                        while(true) {
                            cand2 = t + mid + iter + a + b / (t + mid + iter + 1);
                            if(cand2 != cand1) {
                                break;
                            }
                            iter++;
                        }
                        if(cand1 > cand2) {
                            amin(best, cand2);
                            low = mid + iter + 1;
                        }
                        else  {
                            assert(cand1 < cand2);
                            amin(best, cand1);
                            high = mid - 1;
                        }
                    }
                // };
                // search(0, 1e18);
                if(best < d[v]) {
                    d[v] = best;
                    pq.emplace(d[v], v);
                }
            }
        }
    // };

    // check(0);

    if(d[n - 1] >= INF) {
        cout << -1;
        return;
    }

    int best = d[n - 1];

    

    cout << best;

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