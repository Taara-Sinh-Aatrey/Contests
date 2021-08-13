#include <bits/stdc++.h>
using namespace std;

#define int int64_t
const int mod = 1e9 + 7; const int INF = 1e18L + 5; const int N = 2e5 + 5;

#define ld long double

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int q;
    cin >> q;
    
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    cin >> n;
    vector<ld> b(n);
    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }
    
    map<int, ld> mp;
    for(int i = 0; i < n; i++) {
        if(b[i] <= 0) {
            continue;
        }
        mp[a[i]] = b[i];
    }
    
    cout << fixed << setprecision(2);
    
    if(mp.count(q)) {
        cout << mp[q] << '\n';
    }
    else if(mp.size() == 1) {
        cout << mp.begin()->second << '\n';
    }
    else if(q > mp.rbegin()->first) {
        auto [a, b] = *prev(prev(mp.end()));
        auto [c, d] = *prev(mp.end());
        ld m = (d - b) / (c - a);
        cout << b + m * (q - a) << '\n';
    }
    else if(q < mp.begin()->first) {
        auto [a, b] = *mp.begin();
        auto [c, d] = *next(mp.begin());
        ld m = (d - b) / (c - a);
        cout << b + m * (q - a) << '\n';
    }
    else {
        auto j = mp.upper_bound(q);
        auto i = j;
        i--;
        auto [a, b] = *i;
        auto [c, d] = *j;
        ld m = (d - b) / (c - a);
        cout << b + m * (q - a) << '\n';
    }
    
    return 0;
}