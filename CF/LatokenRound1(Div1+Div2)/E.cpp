/**
 *    author:  Taara Sinh Aatrey
 *    created: 14.06.2021 09:31:21
**/

#include <bits/stdc++.h>
using namespace std;

template<typename A, typename B> istream& operator>>(istream &is, const pair<A, B> &p) { return is >> p.first >> p.second;} template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> istream& operator>>(istream &is, T_container &v) { for (T& x : v) is >> x; return is;} bool debug;
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return debug ? os << '(' << p.first << ", " << p.second << ')' : os << p.first << " " << p.second;} template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { if(debug) { os << "{"; string sep; for (const T &x : v) os << sep << x, sep = ", "; os << '}'; } else { bool f = false; for (const T &x : v) { if(f) {os << " ";} os << x, f = true; } } return os;}
template <typename T, typename T1, typename... Tail> T amin(T& a, T1 b, Tail... c) { if(b < a) a = b; if constexpr (sizeof...(c) != 0) { amin(a, c...); } return a; } template <typename T, typename T1, typename... Tail> T amax(T& a, T1 b, Tail... c) { if(b > a) a = b; if constexpr (sizeof...(c) != 0) { amax(a, c...); } return a; }
void dbg_out() { cerr << endl; } template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#ifdef ONLINE_JUDGE
#define dbg(...)
#else
#define dbg(...) cerr << "[" << #__VA_ARGS__ << "]:", debug = true, dbg_out(__VA_ARGS__), debug = false
#endif

#define int int64_t
const int mod = 1e9 + 7; const int INF = 1e18L + 5; const int N = 2e5 + 5;

void solve() {
    
    int n, k;
    cin >> n >> k;
    
    // d[i] represents no of moves to reach a state where i elements have odd frequency
    vector<int> d(n + 1, INF);
    vector<int> p(n + 1, -1);
    vector<int> Remove(n + 1, -1);
    d[0] = 0;
    
    queue<int> q;
    q.emplace(0);
    
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        
        // remove represents the no of elements whose frequency will become even from odd
        for(int remove = 0; remove <= u; remove++) {
            // take represents the no of elements whose frequency will become odd from even
            int take = k - remove;
            if(take < 0 || take > n - u) {
                continue;
            }
            int v = u - remove + take;
            if(d[v] > d[u] + 1) {
                q.emplace(v);
                d[v] = d[u] + 1;
                p[v] = u;
                Remove[v] = remove;
            }
        }
    }
    
    if(d[n] >= INF) {
        cout << -1 << endl;
        return;
    }
    
    vector<int> seq;
    for(int i = n; i > 0; i = p[i]) {
        seq.emplace_back(Remove[i]);
    }
    
    reverse(seq.begin(), seq.end());
    
    vector<int> freq(n, 0);
    
    int ans = 0;
    
    for(int remove : seq) {
        int take = k - remove;
        // to move from previous state to current state, we need to remove 'remove' and take 'take'
        
        vector<int> qry;
        
        for(int i = 0; i < n; i++) {
            if(freq[i] % 2 == 1 && remove > 0) {
                qry.emplace_back(i + 1);
                freq[i]--;
                remove--;
            }
            else if(freq[i] % 2 == 0 && take > 0) {
                qry.emplace_back(i + 1);
                freq[i]++;
                take--;
            }
        }
        
        cout << "? " << qry << endl;
        int ret;
        cin >> ret;
        
        ans ^= ret;
    }
    
    cout << "! " << ans << endl;
    
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;

    for (int tt = 1; tt <= t; tt++) {
        solve();
    }
    
    return 0;
}