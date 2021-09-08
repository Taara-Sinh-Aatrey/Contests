#include <bits/stdc++.h>
using namespace std;

/*
a * s + b * t = __gcd(a, b) = g
auto [g, s, t] = extended_gcd(a, b);
*/
tuple<int, int, int> extended_gcd(int a, int b) {
    int x = 1, x1 = 0, y = 0, y1 = 1;
    while (b > 0) {
        int q = a / b;
        tie(x, x1) = make_tuple(x1, x - q * x1);
        tie(y, y1) = make_tuple(y1, y - q * y1);
        tie(a, b) = make_tuple(b, a - q * b);
    }
    return make_tuple(a, x, y);
}

int inverse(int a, int p) {
    int inv = get<1>(extended_gcd(a, p));
    if(inv < 0) inv += p;
    return inv;
}

void solve() {
    
    cout << inverse(13, 72) << '\n';
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