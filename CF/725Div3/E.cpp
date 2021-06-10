/**
 *    author:  Taara Sinh Aatrey
 *    created: 10.06.2021 20:50:29
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

    map<string, pair<int, pair<string, string>>> mp;

    int ans = 0;
    while(n--) {
        string a, eq, b;
        cin >> a >> eq >> b;

        if(eq == "=") {
            string c;
            cin >> c >> c;
            auto [v1, p1] = mp[b];
            auto [v2, p2] = mp[c];
            string s = p1.second + p2.first;
            int l = int(s.size()), x = 0;
            for(int i = 0; i + 4 <= l; i++) {
                if(s.substr(i, 4) == "haha") {
                    x++;
                }
            }
            l = int(p2.first.size()); 
            int i = 0;
            while(i < l && int(p1.first.size()) < 3) {
                p1.first += p2.first[i];
                i++;
            }

            l = int(p1.second.size()); 
            i = 0;
            while(i < l && int(p2.second.size()) < 3) {
                p2.second = p1.second[i] + p2.second;
                i++;
            }


            mp[a] = {v1 + v2 + x, {p1.first, p2.second}};
        }
        else {

            int l = int(b.size());
            int p = 0;
            for(int i = 0; i + 4 <= l; i++) {
                p += b.substr(i, 4) == "haha";
            }
            mp[a] = {p, {b.substr(0, min<int>(3, l)), b.substr(l - min<int>(3, l), min<int>(3, l))}}; 
        }

        if(n == 0) {
            cout << mp[a].first << '\n';
        }
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