// HimanShu09 //
#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define MOD 1000000007
#define int int64_t

const long long inf = (long long)(1e18) + 10;
const double dinf = 99999999999999999.0;
const double pie = 3.1415926535;

#define read(arr) for(auto &x : arr) cin>>x;
#define print(arr) for(auto &x: arr) cout<<x<<" "; cout<<endl;
vector<string> split(string s)
{
    vector<string>words; 
    stringstream ss(s); 
    string word; 
    while(ss >> word) words.push_back(word);
    return words;
}
#define str(x) string(1,x)
long long Power(long long a,long long p);

#define BITS 64
#define binary(n) std::bitset<BITS>(n).to_string()
#define setBits(n) std::bitset<BITS>(n).count()

#define all(arr) arr.begin(), arr.end()

mt19937 tourist(chrono::steady_clock::now().time_since_epoch().count());
#define random(x, y) uniform_int_distribution<int>(x, y)(tourist)

#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define Google(t) cout << "Case #" << t << ": ";

const int d4i[4]={-1, 0, 1, 0}, d4j[4]={0, 1, 0, -1};
const int d8i[8]={-1, -1, 0, 1, 1, 1, 0, -1}, d8j[8]={0, 1, 1, 1, 0, -1, -1, -1};



void solve()
{
    int n,m;
    cin>>n>>m;

    vector<vector<int>>g(n+1);
    while(m--)
    {
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    while(true)
    {
        int X= random(1,n);

        vector<vector<int>>lv;
        lv.push_back({X});
        queue<int>q;
        q.push(X);
        vector<int>vis(n+1);
        vis[X]=true;

        while(true)
        {
            vector<int>temp;
            while(!q.empty())
            {
                int node = q.front();
                q.pop();
                for(auto x: g[node])
                {
                    if(vis[x])
                        continue;
                    vis[x]=true;
                    temp.push_back(x);
                }
            }
            if(temp.size() == 0)
                break;
            queue<int>haha;
            for(auto x: temp)
                haha.push(x);
            lv.push_back(temp);
            swap(q,haha);
        }
        
        int sq = ceil(sqrt(n));
        
        // dp[i] -> last level i => {nodes picked, previous level of i}
        
        vector<pair<int, int>> dp(lv.size());
        set<pair<int, int>> st;
        dp[0] = {lv[0].size(), -1};
        // st => {i-2*sq-1, .......i-1} => {nodes_picked, index}
        st.emplace(dp[0].first, 0);
        for (int i = 1; i < lv.size(); i++) {
            if (st.size() > 2 * sq + 1) {
                st.erase({dp[i - 2 * sq - 2].first, i - 2 * sq - 2});
            }
            auto [picked, prev_level] = *st.begin();
            dp[i] = {picked + lv[i].size(), prev_level};
            st.emplace(dp[i].first, i);
        }
        int k = lv.size() - 1;
        for (int kk = max<int>(0, lv.size() - 1 - sq); kk < lv.size(); kk++) {
            if (dp[kk].first < dp[k].first) {
                k = kk;
            }
        }
        if (dp[k].first > sq) {
            continue;
        }
        vector<int> nodes;
        while (k != -1) {
            // cerr << "k = " << k << " " << dp[k].first << " " << dp[k].second << endl;
            for (auto &x : lv[k]) {
                nodes.emplace_back(x);
            }
            k = dp[k].second;
        }
        assert(nodes.size() <= sq);
        cout<<nodes.size()<<endl;
        for(auto x: nodes)
            cout<<x<<" ";
        cout<<endl;
        break;
    }
}

int32_t main()
{
    fastIO;
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++)
    {
        //Google(tt);
        solve();
    }

    return 0;
}
long long Power(long long a,long long b)
{
    long long res = 1;
    while(b  > 0)
    {
        if(b%2 == 0)
        {
            a = a*a;
            b/=2;
        }
        else
        {
            res = res*a;
            b--;
        }
    }
    return res;
}