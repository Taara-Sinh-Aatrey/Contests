#include <bits/stdc++.h>
using namespace std;

#define int int64_t

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto& x: a) {
    	cin >> x;
    }
    int q;
    cin >> q;
    while(q--) {
    	int l, r, x;
    	cin >> l >> r >> x;
        l--, r--;
    	int sum = 0, i = 0;
        while(i < l && sum < x) {
            sum += a[i];
            i++;
        }
        if(sum >= x) {
            cout << i << '\n';
            continue;
        }
        i = r + 1;
        while(i < n && sum < x) {
            sum += a[i];
            i++;
        }
        if(sum >= x) {
            cout << i << '\n';
            continue;
        }
        cout << -1 << '\n';
    }
    return 0;
}
