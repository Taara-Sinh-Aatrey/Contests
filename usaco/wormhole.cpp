/*
ID: taarasi1
TASK: wormhole
LANG: C++14             
*/

#include <bits/stdc++.h>
using namespace std;

template<typename A, typename B> istream& operator>>(istream &is, pair<A, B> &p) { return is >> p.first >> p.second;} template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> istream& operator>>(istream &is, T_container &v) { for (T& x : v) is >> x; return is;} bool debug;
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

// int coordinate_compress(vector<pair<int, int>> a) {
//     set<int> s;
//     for(auto [x, y]: a) {
//         s.insert(x);
//         s.insert(y);
//     }
//     map<int, int> mp;
//     int cnt = 0;
//     for(auto& x: s) {
//         dbg(x, cnt);
//         mp[x] = cnt++;
//     }
//     return int(s.size());
// }

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    cin >> a;
    
    // coordinate_compress(a);
    
    sort(a.begin(), a.end());
    
    int ans = 0;
    
    vector<int> G(n, -1);
    for(int i = 0; i < n; i++) {
        int mn = -1;
        for(int j = 0; j < n; j++) {
            if(a[j].first <= a[i].first || a[j].second != a[i].second) {
                continue;
            }
            if(mn == -1 || a[j].first < a[mn].first) {
                mn = j;
            }
        }
        G[i] = mn;
        // if(mn != -1) {
        //     dbg(i, mn);
        // }
    }
    
    
    vector<bool> vis(n, false);
    vector<int> vec;
    function<void(int)> dfs = [&](int u) {
        vis[u] = true;
        vec.emplace_back(u);
        
        for(int v = 0; v < n; v++) {
            if(vis[v]) continue;
            vis[v] = true;
            vec.emplace_back(v);
            
            if(vec.size() == n) {
                vector<int> pair(n);
                bool ok = false;
                for(int i = 0; i < n; i += 2) {
                    pair[vec[i]] = vec[i + 1];
                    pair[vec[i + 1]] = vec[i];
                }
                vector<int> pr;
                for(int i = 0; i < n; i++) {
                    vector<bool> seen(2 * n, false);
                    int x = i;
                    int f = 0;
                    vector<int> p;
                    
                    while(x != -1) {
                        p.emplace_back(x);
                        if(seen[2 * x + f]) {
                            ok = true;
                            pr = p;
                            break;
                        }
                        seen[2 * x + f] = true;
                        if(f == 0) {
                            x = pair[x];
                        }
                        else {
                            x = G[x];
                        }
                        f ^= 1;
                    }
                    if(ok) {
                        // dbg(i, vec, pr);
                        break;
                    }
                }
                ans += ok;
            }
            else {
                for(int _v = 0; _v < n; _v++) {
                    if(vis[_v]) {
                        continue;
                    }
                    dfs(_v);
                    break;
                }
            }
            vec.pop_back();
            vis[v] = false;
        }
        
        vec.pop_back();
        vis[u] = false;
    };
    
    dfs(0);
    
    cout << ans << '\n';
}

signed main()
{
#ifndef LOCAL
    freopen("wormhole.in", "r", stdin);
    freopen("wormhole.out", "w", stdout);
#endif

    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
    
    return 0;
}

/*
6 
6 0 
1 0 
2 0 
7 0 
4 5 
3 0 

*/