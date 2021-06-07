/**
 *    author:  Taara Sinh Aatrey
 *    created: 23.05.2021 09:18:29
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


const int mod = 1e9 + 7;
const int INF = 1e18L + 5;
const int N = 2e5 + 5;

void solve() {

    int m, n;
    cin >> m >> n;

    vector<int> t(n), z(n), y(n);
    for(int i = 0; i < n; i++) {
        cin >> t[i] >> z[i] >> y[i];
    }

    int low = 0, high = 1e9;
    vector<int> ans;
    int time = -1;

    while(low <= high) {
        int mid = (low + high) / 2;
        int balloons = 0;
        vector<int> vec;
        for(int i = 0; i < n; i++) {
            int time_period = z[i] * t[i] + y[i];
            int cycles = mid / time_period;
            int left = mid % time_period;
            int cur = cycles * z[i] + min(z[i], left / t[i]);
            vec.emplace_back(cur);
            balloons += cur;
        }
        if(balloons >= m) {
            for(int i = 0; i < n; i++) {
                int ex = min(balloons - m, vec[i]);
                vec[i] -= ex;
                balloons -= ex;
            }
            if(balloons == m) {
                time = mid;
                ans = vec;
            }
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    assert(time != -1);

    cout << time << '\n' << ans;

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