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


void dfs(int v,int u)
{
    p[u][v] = 1;
    for(int w: adj[v])
    {
        if(!p[u][w])
            dfs(w, u);
    }
}

int main()
{
FIO

    ll t;   cin >> t;
    Rep(tt,1,t)
    {
        cout << "Case #" << tt << ":\n";
        cin >> n;
        memset(p, 0, sizeof(p));
        For(n) cin >> I[i], p[i][i] = 1, adj[i].clear();
        For(n) cin >> O[i];
        For(n)
        {
            if(O[i] == 'N')
                continue;
            for(int j : {i-1, i+1})
            {
                if(j < 0 || j >= n) continue;
                if(I[j] == 'Y')
                {
                    adj[i].pb(j);
                }
            }
        }

        For(n)
        {
            dfs(i, i);
            Rep(j,0,n-1)
            {
                cout << (p[i][j] ? 'Y' : 'N');
            }
            cout << endl;
        }

    }
    
    return 0;
}