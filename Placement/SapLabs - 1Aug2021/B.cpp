#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    map<int, int> a, tot;
    
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a[x]++;
        tot[x]++;
    }
    
    for(int i = 0; i < m; i++) {
        int x;
        cin >> x;
        tot[x]++;
    }
    
    int ans = 0;
    for(auto it = tot.begin(); it != tot.end(); it++) {
        int x = it->first, f = it->second;
        if(a[x] == 0 || a[x] == f) {
            ans += f;
        }
    }
    
    cout << ans << '\n';
    
    return 0;
}