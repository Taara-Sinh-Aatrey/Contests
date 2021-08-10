#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ll t = 1;
    cin >> t;

    while(t--) {
        
        ll n;
        cin >> n;
        
        map<ll, ll> mp;
        for(ll i = 0; i < n; i++) {
            ll a, b;
            cin >> a >> b;
            
            mp[a] += b;
        }
        
        ll ans = 0;
        
        pair<ll, ll> left{0, 0};
        
        for(auto i = mp.rbegin(); i != mp.rend(); i++) {
            auto& [a, b] = *i;
            
            if(b < 2) {
                continue;
            }
            
            if(left.second >= 2) {
                ans += (a + left.first) * 2;
                b -= 2;
                left = {0, 0};
            }
            
            ans += (b / 4) * 4 * a;
            
            b = b % 4;
            
            if(b >= 2) {
                left = {a, b};
            }
            
        }
        
        cout << ans << '\n';
        
        
    }
    
    return 0;
}

