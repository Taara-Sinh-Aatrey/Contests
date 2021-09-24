#include "bits/stdc++.h"
using namespace std;

#define ll long long

int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll n, k, m;
        cin >> n >> m >> k;
        vector<ll> last(n + 1);
        iota(last.begin(), last.end(), 0);
        for (ll i = 0; i < m; i++) {
            ll pos;
            cin >> pos;
            last[pos] = -1;    
        }
        vector<ll> cost(k + 1);
        for (ll i = 1; i <= k; i++) {
            cin >> cost[i];
        }
        if(last[0] == -1) {
            cout << -1 << '\n';
            continue;
        }
        for (ll i = 0; i <= n; i++) {
            if(last[i] == -1) {
                last[i] = last[i - 1];
            }
        }
        const ll inf = 1e18L;
        ll best = inf;
        for(int f = 1; f <= k; f++) {
            int ans = 0;
            int pos = 0;
            bool ok = true;
            while(pos < n) {
                if(last[pos] <= pos - f) {
                    ok = false;
                    break;
                }
                pos = last[pos];
                // cerr << "fuel = " << f << " pos = " << pos << endl;
                pos += f;
                ans++;
            }
            // cerr << "ok = " << ok << " ans = " << ans << endl;
            if(ok) best = min(best, ans * cost[f]);
        }
        if(best >= inf) best = -1;
        cout << best << '\n';
    }
    return 0;
}