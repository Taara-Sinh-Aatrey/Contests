#include <bits/stdc++.h>
using namespace std;

#define int int64_t
const int mod = 1e9 + 7; const int INF = 1e18L + 5; const int N = 2e5 + 5;

void solve() {
    
    int n;
    cin >> n;
    
    int q;
    cin >> q;
    
    set<int> row, col;
    
    int ans = n * n;
    while(q--) {
        int r, c;
        cin >> r >> c;
        
        if(!row.count(r)) {
            row.insert(r);
            ans -= n - int(col.size());
        }
        
        if(!col.count(c)) {
            col.insert(c);
            ans -= n - int(row.size());
        }
        
        cout << ans << ' ';
    }
    
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