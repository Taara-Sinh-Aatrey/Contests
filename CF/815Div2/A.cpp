/**
 *    author:  Taara Sinh Aatrey
 *    created: 21.08.2022 21:34:00
**/

#include "bits/stdc++.h"

using namespace std;

#ifdef AATREY_DEBUG
#include "debug.hpp"
#else
#define dbg(...)
#endif

#define int int64_t

template<typename T, typename T1, typename... Tail> 
T lcm(T a, T1 b, Tail... c) { 
    T L = a / gcd(a, b) * b;
    if constexpr (sizeof...(c) != 0) 
        L = lcm(L, c...);
    return L;
}

void normalise(int &a, int &b) {
    int g = gcd(a, b);
    a /= g, b /= g;
}

template<typename T, typename T1, typename... Tail> 
T gcd(T a, T1 b, Tail... c) { 
    return gcd(gcd(a, b), c...); 
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);int t;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        normalise(a, b);
        normalise(c, d);
        int L = lcm(b, d);
        a *= L / b, b = L;
        c *= L / d, d = L;
        cout << (a == c ? 0 : (min(a, c) == 0 || (max(a, c) % min(a, c) == 0) ? 1 : 2)) << '\n';
    }
    return 0;
}