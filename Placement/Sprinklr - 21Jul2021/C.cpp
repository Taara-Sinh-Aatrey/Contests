#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
        
    ll n, m;
    cin >> n >> m;
    
    vector<ll> a(n);
    for(auto& x: a) {
        cin >> x;
    }
    a.insert(a.begin(), 0);
        
    ll idx = -1;
    for(ll i = 1; i <= n; i++) {
        if(a[i] == m) {
            idx = i;
            a[i] = 0;
        }
        else if(a[i] < m) {
            a[i] = -1;
        }
        else {
            a[i] = 1;
        }
    }
        
    for(ll i = 1; i <= n; i++) {
        a[i] += a[i - 1];
    }
    
    map<ll, vector<ll>> mp;
    for(ll i = 0; i <= n; i++) {
        mp[a[i]].emplace_back(i);
    }
    
    ll ans = 0;
    for(ll i = 0; i < idx; i++) {
        auto& vec = mp[a[i]];
        ans += vec.end() - lower_bound(vec.begin(), vec.end(), idx);
    }
    
    for(ll i = 0; i < idx; i++) {
        auto& vec = mp[a[i] + 1];
        ans += vec.end() - lower_bound(vec.begin(), vec.end(), idx);
    }
    
    cout << ans << '\n';
    
    
    return 0;
}