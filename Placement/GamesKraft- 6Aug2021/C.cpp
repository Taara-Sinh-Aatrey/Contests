#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll taxiDriver(vector<ll> pickup, vector<ll> drop, vector<ll> tip) {
    ll n = pickup.size();
    vector<ll> order(n);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&](ll i, ll j) {
        if(drop[i] == drop[j]) {
            return pickup[i] < pickup[j];
        }
        return drop[i] < drop[j];
    });
    
    map<ll, ll> mp;
    mp[0] = 0;
    
    ll ans = 0;
    
    for(auto& i : order) {
        auto it = mp.upper_bound(pickup[i]);
        it--;
        
        auto it2 = mp.upper_bound(drop[i]);
        it2--;
        mp[drop[i]] = max(it->second + drop[i] - pickup[i] + tip[i], it2->second);
        
        ans = max(ans, mp[drop[i]]);
    }
    
    return ans;
}

int main()
{
    cout << taxiDriver({1, 4}, {5, 6}, {2, 5}) << endl;
    cout << taxiDriver({0, 4, 5}, {3, 5, 7}, {1, 2, 2}) << endl;
    cout << taxiDriver({0, 2, 9, 10, 11, 12}, {5, 9, 11, 11, 14, 17}, {1, 2, 3, 2, 2, 1}) << endl;
    cout << taxiDriver({1, 4, 7}, {5, 7, 11}, {0, 0, 0}) << endl;
    
    return 0;
}