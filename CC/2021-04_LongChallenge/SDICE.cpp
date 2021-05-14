#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve(int tt) {
    int n;
    cin >> n;

    int lookup[] = {0, 20, 18 + 18, 18 + 15 + 18};

    cout << n / 4 * 44 + lookup[n % 4] + (4 - n % 4) * 4 * (n >= 4) << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    for(int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
    

    return 0;
}