#include <bits/stdc++.h>
using namespace std;

#define int int64_t
const int mod = 1e9 + 7; const int INF = 1e18L + 5; const int N = 2e5 + 5;

void solve() {
    
    int a, b, k;
    cin >> a >> b >> k;
    
    if(k > 2) k = 2;
    
    if(k == 1) {
        cout << (a & b) << '\n';
    }
    else {
        cout << ((a & b) | b) << '\n';
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