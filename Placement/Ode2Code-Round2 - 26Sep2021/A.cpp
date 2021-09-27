#include "bits/stdc++.h"
using namespace std;

#define ll long long

int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll n, k;
        cin >> n >> k;
        vector<ll> wt(n);
        for (ll i = 0; i < n; i++) {
            cin >> wt[i];
        }
        vector<ll> taste(n);
        for (ll i = 0; i < n; i++) {
            cin >> taste[i];
        }
        multiset<pair<ll, ll>> st;
        for(ll i = n - 1; i >= 0; i--) {
            if(i + k + 1 < n) {
                st.erase(st.find({wt[i + k + 1], taste[i + k + 1]}));
            }
            if(!st.empty()) {
                taste[i] += prev(st.end())->second; 
            }
            st.emplace(wt[i], taste[i]);
        }
        cout << *max_element(taste.begin(), taste.end()) << '\n';
    }
    return 0;
}