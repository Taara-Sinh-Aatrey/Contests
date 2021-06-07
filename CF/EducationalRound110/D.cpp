/**
 *    author:  Taara Sinh Aatrey
 *    created: 04.06.2021 21:00:36
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

    int MAX = (1 << n) - 1;

    string s;
    cin >> s;

    vector<pair<int, int>> vec;
    int sum = 0;
    for(int i = n - 1; i >= 0; i--) {
        int cur = 1 << i;
        sum += cur;
        vec.emplace_back(sum, cur);
    }

    auto nxt = [&](int match) {
        pair<int, int> x = {match, 0};
        auto [last, len] = *lower_bound(vec.begin(), vec.end(), x);
        int start = last - len + 1;
        return last + (match - start + 2) / 2;
    };
    auto prv = [&](int match) {
        pair<int, int> x = {match, 0};
        auto [last, len] = *lower_bound(vec.begin(), vec.end(), x);
        int start = last - len + 1;
        int prev_start = start - 2 * len;
        return prev_start + (match - start) * 2;
    };

    vector<int> win(MAX + 1);
    for(auto& [last, len] : vec) {
        int start = last - len + 1;
        for(int i = start; i <= last; i++) {
            int prev = prv(i);
            int l = 1, r = 1;
            if(prev > 0) {
                l = win[prev];
                r = win[prev + 1];
            }
            if(s[i - 1] == '0') {
                win[i] = l;
            }
            else if(s[i - 1] == '1') {
                win[i] = r;
            }
            else {
                win[i] = l + r;
            }
        }
    }

    int q;
    cin >> q;
    while(q--) {
        int i;
        char ch;
        cin >> i >> ch;
        s[i - 1] = ch;
        while(i <= MAX) {
            int prev = prv(i);
            int l = 1, r = 1;
            if(prev > 0) {
                l = win[prev];
                r = win[prev + 1];
            }
            if(s[i - 1] == '0') {
                win[i] = l;
            }
            else if(s[i - 1] == '1') {
                win[i] = r;
            }
            else {
                win[i] = l + r;
            }
            i = nxt(i);
        }
        cout << win[MAX] << '\n';
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