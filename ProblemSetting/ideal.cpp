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
    vector<int> pref(n + 1, 0);
    for(int i = 1; i <= n; i++) {
    	pref[i] = pref[i - 1] + a[i - 1];
    }
    int q;
    cin >> q;
    while(q--) {
    	int l, r, x;
    	cin >> l >> r >> x;
    	int idx = lower_bound(pref.begin(), pref.begin() + l, x) - pref.begin();
    	if(idx < l) {
    		cout << idx << '\n';
    		continue;
    	}
    	int offset = pref[r] - pref[l - 1];
    	idx = lower_bound(pref.begin() + r + 1, pref.end(), x + offset) - pref.begin();
    	if(idx <= n) {
    		cout << idx << '\n';
    		continue;
    	}
    	cout << -1 << '\n';
    }
    return 0;
}
