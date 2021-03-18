#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) {
        int c;
        cin >> c;
        int d = 31 - __builtin_clz(c) + 1;
        int both = ((1 << d) - 1) ^ c;
        int x = 1 << (d - 1), y = c ^ x;
        cout << (both + x) * (both + y) << '\n';
    }

    return 0;
}

