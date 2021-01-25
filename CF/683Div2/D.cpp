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
const ll mxN = 2e5 + 1;

ll n, m;
string s, t;

void solve(){
	cin >> n >> m >> s >> t;
	ll dp[n + 1][m + 1];
	For(i, n + 1){
		dp[i][0] = 0;
	}
	For(i, m + 1){
		dp[0][i] = 0;
	}
	ll ans = 0;
	FOR(i, n){
		FOR(j, m){
			dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) - 1;
			if(s[i - 1] == t[j - 1]){
				dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 2);
			}else{
				dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] - 2);
			}
			dp[i][j] = max(dp[i][j], 0ll);
			ans = max(ans, dp[i][j]);
		}
	}
	cout << ans;
}

int main()
{
    ios::sync_with_stdio(0);  cin.tie(0);
    solve();
    return 0;
}