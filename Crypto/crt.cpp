#include <bits/stdc++.h>
using namespace std;

bool debug; template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return debug ? os << '(' << p.first << ", " << p.second << ')' : os << p.first << " " << p.second;} template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { if(debug) { os << "{"; string sep; for (const T &x : v) os << sep << x, sep = ", "; os << '}'; } else { bool f = false; for (const T &x : v) { if(f) {os << " ";} os << x, f = true; } } return os;}

int inverse(int a, int m) {
    if(a == 0) return 0;
    int temp = m;
    int u = 0, v = 1;
    while (a != 0) {
        int t = m / a;
        m -= t * a; swap(a, m);
        u -= t * v; swap(u, v);
    }
    if(u < 0) {
        u += temp;
    }
    return u;
}

class CRT {
public:

    // While declaring CRT, vector of primes must be passed to the constructor
    // call get function with vector of remainders to get back the number
    
    int n;
    vector<int> m;

    CRT(vector<int> p) {
        m = p;
        n = (int) m.size();
    }

    // (rem, mod)
    pair<int, int> get(vector<int> r) {
        assert(r.size() == m.size());
        int n = int(r.size());
        // Contracts: 0 <= r0 < m0
        int r0 = 0, m0 = 1;
        for (int i = 0; i < n; i++) {
            assert(m[i] >= 1);
            int r1 = (r[i] % m[i] + m[i]) % m[i], m1 = m[i];
            if (m0 < m1) {
                swap(r0, r1);
                swap(m0, m1);
            }
            if (m0 % m1 == 0) {
                if (r0 % m1 != r1) return {0, 0};
                continue;
            }

            int g = __gcd(m0, m1), im = inverse(m0, m1);
            int u1 = (m1 / g);
            if ((r1 - r0) % g) return {0, 0};
            int x = (r1 - r0) / g % u1 * im % u1;

            r0 += x * m0;
            m0 *= u1;
            if (r0 < 0) r0 += m0;
        }
        return {r0, m0};
        // m0 == 0 means no solution exists
    }
};

void solve() {
    
    cout << CRT({3, 5, 7}).get({1, 4, 6}) << '\n';
    cout << CRT({6, 9, 15}).get({2, 5, 7}) << '\n';
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