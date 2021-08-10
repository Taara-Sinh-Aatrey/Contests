#include<bits/stdc++.h>
using namespace std;

#define int int64_t

signed main() {
    
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    cin >> m >> n;

    for(int i = 0; i < m; i++) {
        int mx = -1e18;

        for(int i = 0; i < n; i++) {
            int num;
            cin >> num;
            mx = max(mx, num);
        }
        if(i > 0) {
            cout << " ";
        }
        cout << mx;
    }
    cout << '\n';
}

