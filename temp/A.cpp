#include "bits/stdc++.h"
using namespace std;

template <typename T, typename T1, typename... Tail> T amin(T& a, T1 b, Tail... c) { if(b < a) a = b; if constexpr (sizeof...(c) != 0) { amin(a, c...); } return a; } template <typename T, typename T1, typename... Tail> T amax(T& a, T1 b, Tail... c) { if(b > a) a = b; if constexpr (sizeof...(c) != 0) { amax(a, c...); } return a; }

#ifdef LOCAL
#include "debug.hpp"
#else
#define dbg(...)
#endif

#define ll int64_t
const ll inf = 1e18L + 5, mod = 1e9 + 7, N = 2e5 + 5;



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    Solution ob;
    
    
    return 0;
}