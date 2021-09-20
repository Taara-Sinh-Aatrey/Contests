#include "bits/stdc++.h"
using namespace std;

signed main() {
    
    int n;
    vector<int> a(n);
    const int N = 1e5 + 5;
    map<int, int> cnt;
    for(int i = 0; i < n; i++) {
        cnt[a[i] - 1]++;
        cnt[a[i]]++;
        cnt[a[i] + 1]++;
    }
    int ans = 0;
    for(auto& p : cnt) {
        ans = max(ans, p.second);
    }
    cout << ans << '\n';
    return 0;
}