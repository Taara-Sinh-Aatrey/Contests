#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve(int tt) {
    int n, q;
    cin >> n >> q;

    vector<int> cnt(31, 0);
    vector<int> a(n);

    int ans = 0;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;

        a[i] = x;

        for(int j = 0; j < 31; j++) {
            if(x >> j & 1) {
                cnt[j]++;
                ans |= (1LL << j);
            }
        }
    }

    cout << ans << '\n';
    while(q--) {
        ans = 0;
        int x, v;
        cin >> x >> v;
        x--;

        for(int j = 0; j < 31; j++) {
            if(a[x] >> j & 1) {
                cnt[j]--;
            }
            if(v >> j & 1) {
                cnt[j]++;
            }
            
            if(cnt[j] > 0) {
                ans |= (1LL << j);
            }
        }

        a[x] = v;

        cout << ans << '\n';
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