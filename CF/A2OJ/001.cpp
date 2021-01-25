#include<bits/stdc++.h>
using namespace std;

#define ar array<ll, 2>
#define ll long long
#define in insert
#define pb push_back
#define vt vector
template <typename T> using mxpq = priority_queue<T>;
template <typename T> using mnpq = priority_queue<T, vt<T>, greater<T>>;
#define For(i, n) for(ll i = 0; i < n; i++)
#define Rev(i, n) for(ll i = n-1; i >= 0; i--)
#define FOR(i, n) for(ll i = 1; i <= n; i++)
#define REV(i, n) for(ll i = n; i >= 1; i--)
#define Rep(i,a,b) for(ll i = a; i <= b; i++)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int) (x).size()

const ll mod = 1e9L + 7;
const ll INF = 1e18L + 5;
const ll mxN = 1e5 + 1;

ll low, high, k;
vt<ll> dp(mxN);
vt<ll> pref(mxN);

void solve(){
    cin >> low >> high;
    cout << (pref[high] - pref[low - 1] + mod) % mod << '\n';
}

int main()
{
    ios::sync_with_stdio(0);  cin.tie(0);
    ll t = 1;
    cin >> t >> k;
    dp[0] = 1;
    pref[0] = 0;
    FOR(i, mxN - 1){
        dp[i] = dp[i - 1];
        if(i - k >= 0){
            dp[i] += dp[i - k];
        }
        dp[i] %= mod;
        pref[i] = pref[i - 1] + dp[i];
        pref[i] %= mod;
    }
    FOR(tt, t) solve();
    return 0;
}