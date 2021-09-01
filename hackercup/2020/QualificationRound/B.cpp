#include<bits/stdc++.h>
using namespace std;
#define ar array<ll, 2>
#define endl '\n'
#define ll long long
#define in insert
#define pb push_back
#define vt vector
#define vll vector<ll>
#define vvi vector<vi>
#define P_Q(x) priority_queue<x>
#define p_q(x) priority_queue<x, vector<x>, greater<x>>
#define Rep(i,a,b) for(int i=a;i<=b;i++)
#define Rev(i,a,b) for(ll i=a;i>=b;i--)
#define FOR(m) Rep(i,1,m)
#define For(m) Rep(i,0,m-1)
#define Rbl(x,a) for(auto &x : a)
#define FIO ios::sync_with_stdio(0);   cin.tie(0);
#define F first
#define S second
#define pii pair<int,int>
#define pll pair<ll,ll>
#define mp make_pair
#define vpii vector<pii>
#define vpll vector<pll>
#define all(x) (x).begin(),(x).end()
#define sz(x) (int) (x).size()
const ll INF = 0x3f3f3f3f3f3f3f3fll;
#define mod 1000000007

const int mxN = 51;
int n;
vt<int> adj[mxN];
vt<char> I(mxN), O(mxN);
bool p[mxN][mxN];

int main()
{
FIO

    ll t;   cin >> t;
    Rep(tt,1,t)
    {
        cout << "Case #" << tt << ": ";
        cin >> n;
        assert(n % 2);
        char a[n]; For(n) cin >> a[i];
        int c1 = 0, c2 = 0;
        For(n) c1 += (a[i] == 'A');
        c2 = n - c1;
        cout << (abs(c2-c1) == 1 ? 'Y' : 'N');
        cout << endl;
    }
    
    return 0;
}