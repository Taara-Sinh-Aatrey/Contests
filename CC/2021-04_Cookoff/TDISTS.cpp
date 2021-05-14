#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve(int tt) {
    int x, y;
    cin >> x >> y;

    if(y & 1) {
        cout << "NO\n";
        return;
    }


    // 2 * a * b = y, a^2 + b^2 = x
    y /= 2;

    bool ok = false;

    int a = -1, b = -1;
    for(int i = 1; i * i <= y; i++) {
        if(y % i == 0) {
            int j = y / i;
            if(i * i + j * j == x) {
                a = i, b = j;
                ok = true;
                break;
            }
        }
    }

    if(!ok) {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";

    cout << a + b << '\n';

    for(int i = 2; i <= b + 1; i++) {
        cout << 1 << " " << i << '\n';
    }

    for(int i = b + 2; i < b + 2 + a - 1; i++) {
        cout << 2 << " " << i << '\n';
    }


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

