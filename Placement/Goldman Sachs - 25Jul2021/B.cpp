#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ll n;
    cin >> n;
    
    vector<array<ll, 2>> vec(n);
    for(ll i = 0; i < n; i++) {
        for(ll j = 0; j < 2; j++) {
            cin >> vec[i][j];
        }
    }
    
    function<void(int)> dfs = [&](int i) {
        for(ll j = 0; j < 2; j++) {
            if(vec[i][j] <= 0) {
                vec[i][j] = -vec[i][j];
            }
            else {
                ll nxt = vec[i][j] - 1;
                dfs(nxt);
                vec[i][j] = 2 * max(vec[nxt][0], vec[nxt][1]);
            }
        }
    };
    
    dfs(0);
    
    ll ans = 2 * max(vec[0][0], vec[0][1]);
    
    vector<ll> ret;
    while(ans > 0) {
        ret.emplace_back(ans % 2);
        ans /= 2;
    }
    
    reverse(ret.begin(), ret.end());
    
    for(auto& x : ret)  {
        cout << x;
    }
    
    return 0;
}

