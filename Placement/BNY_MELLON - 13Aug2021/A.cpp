#include <bits/stdc++.h>
using namespace std;

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> pref(n, 1), suff(n, 1);
    for(int i = 1; i < n; i++) {
        if(a[i] >= a[i - 1]) {
            pref[i] += pref[i - 1];
        }
    }
    
    for(int i = n - 2; i >= 0; i--) {
        if(a[i] >= a[i + 1]) {
            suff[i] += suff[i + 1];
        }
    }
    
    int ans = 0;
    for(int i = 0; i < n; i++) {
        ans = max(ans, pref[i] + suff[i] - 1);
    }
    
    cout << ans << '\n';
    
    return 0;
}