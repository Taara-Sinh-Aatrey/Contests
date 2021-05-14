#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve(int tt) {
    map<int, int> mp;
    int n, x;
    cin >> n >> x;
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        mp[x]++;
    }

    vector<int> freq;
    for(auto [x, f] : mp) {
        freq.push_back(f);
    }

    sort(freq.rbegin(), freq.rend());

    for(auto &f: freq) {
        int need = min(x, f - 1);
        f -= need;
        x -= need;
    }
    for(auto &f: freq) {
        int need = min(x, f);
        f -= need;
        x -= need;
    }

    int ans = 0;
    for(auto &f: freq) {
        ans += !!f;
    }

    cout << ans << '\n';
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