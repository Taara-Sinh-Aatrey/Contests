#include "bits/stdc++.h"
using namespace std;

#define ll long long

int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll n, k;
        cin >> n >> k;
        vector<ll> a(n);
        for (ll i = 0; i < n; i++) {
            cin >> a[i];
        }
        vector<ll> sum = a;
        ll ans = 0;
        for (ll i = n - 1; i >= 0; i--) {
            if(i + k < n) {
                ans += sum[i + k] * a[i];
                sum[i] += sum[i + k];
            }
        }
        cout << ans << '\n';
    }
    return 0;
}