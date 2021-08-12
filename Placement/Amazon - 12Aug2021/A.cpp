#include <bits/stdc++.h>
using namespace std;

#define ll int64_t
const ll INF = 1e9;

ll solve(string s, int k) {
    ll n = s.size();
    ll ans = 0;
    
    if(k == 0) {
        return 0;
    }
    
    set<ll> st;
    vector<ll> last(26, INF);
    ll j = 0;
    
    for(ll i = 0; i < n; i++) {
        last[s[i] - 'a'] = i;
        st.insert(s[i] - 'a');
                
        if(st.size() > k) {
            ll idx = min_element(last.begin(), last.end()) - last.begin();
            j = last[idx] + 1;
            st.erase(idx);
            last[idx] = INF;
        }
        
        if(st.size() == k) {
            ll idx = min_element(last.begin(), last.end()) - last.begin();
            ans += (last[idx] - j + 1);
        }
        
    }
    
    return ans;
    
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << solve("pqpqs", 2) << endl;
    cout << solve("abcad", 0) << endl;
    cout << solve("", 1) << endl;
    
    return 0;
}