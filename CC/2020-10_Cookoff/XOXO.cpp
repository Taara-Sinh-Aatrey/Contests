#include<bits/stdc++.h>
using namespace std;

#define ar array<ll, 2>
#define ll long long
#define in insert
#define pb push_back
#define vt vector
#define P_Q(x) priority_queue<x>
#define p_q(x) priority_queue<x, vector<x>, greater<x>>
#define For(i, n) for(ll i = 0; i < n; i++)
#define Rev(i, n) for(ll i = n-1; i >= 0; i--)
#define FOR(i, n) for(ll i = 1; i <= n; i++)
#define REV(i, n) for(ll i = n; i >= 1; i--)
#define Rep(i,a,b) for(ll i = a; i <= b; i++)
#define all(x) (x).begin(),(x).end()
#define sz(x) (ll) (x).size()

const ll mod = 1e9L + 7;
const ll INF = 1e18L + 5;
const ll mxN = 3e5 + 10;
ll n, k, x;
vt<ll> dp;

void solve(){
    cin >> n >> k >> x;
    cout << (dp[k] <= n ? "YES" : "NO") << '\n';
}

int main()
{
    ios::sync_with_stdio(0);  cin.tie(0);
    dp = vector<ll>(mxN);
    ll bound = 1;
    for (ll i = 1; i < mxN; i++) {
        dp[i] = 1 + i;
        while ((bound + 1) * (bound + 1) <= i) {
            ++bound;
        }
        for (ll x = bound; x >= 1; x--) {
            ll y = i / x;
            dp[i] = min(dp[i], dp[i - x * y] + x + y);
        }
    }
    ll t = 1;
    cin >> t;
    FOR(tt, t) solve();
    return 0;
}