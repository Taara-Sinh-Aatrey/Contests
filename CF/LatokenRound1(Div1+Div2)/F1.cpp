/**
 *    author:  Taara Sinh Aatrey
 *    created: 14.06.2021 10:10:23
**/

#include <bits/stdc++.h>
#include <iterator>
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
    
    int n, m;
    cin >> n >> m;
    
    vector<string> s(n);
    for(int i = n - 1; i >= 0; i--) {
        cin >> s[i];
    }

    vector<int> a(m);
    cin >> a;
    
    vector<vector<int>> vec(m);
    for(int j = 0; j < m; j++) {
        for(int i = 0; i < n; i++) {
            if(s[i][j] == '#') {
                vec[j].emplace_back(i);
            }
        }
    }    
    
    map<int, int> ans;
        
    for(int j = 0; j < m; j++) {
        if(a[j] == 0) {
            ans[-2] = ans[-2] = 0;
            continue;
        }
        
        if(j == 0) {
            ans[vec[j][a[j] - 1]] = 1;
            continue;
        }
        
        map<int, int> nans;
        
        for(auto [val, op]: ans) {
        
            int idx = upper_bound(vec[j].begin(), vec[j].end(), val + 1) - vec[j].begin();
            int cur = -2;
            if(idx != 0) {
                idx--;
                int i = idx;
                while(i < int(vec[j].size()) && vec[j][i] == vec[j][idx] + i - idx) {
                    i++;
                }
                i--;
                cur = vec[j][i];
            }
            
            if(nans.count(cur)) {
                amin(nans[cur], op + (vec[j][a[j] - 1] > cur));
            }
            else {
                nans[cur] = op + (vec[j][a[j] - 1] > cur);
            }
            
            idx = upper_bound(vec[j - 1].begin(), vec[j - 1].end(), vec[j].back()) - vec[j - 1].begin();
            cur = -2;
            if(idx != 0) {
                idx--;
                int i = idx;
                while(i < int(vec[j - 1].size()) && vec[j - 1][i] == vec[j - 1][idx] + i - idx) {
                    i++;
                }
                i--;
                cur = vec[j - 1][i];
            }
            
            if(nans.count(vec[j].back())) {
                amin(nans[vec[j].back()], 1 + max<int>(0, op - (val <= cur)));
            }
            else {
                nans[vec[j].back()] = op + (val > cur);
            }
            
            
        }
        
        ans = nans;
    }
    
    int answer = INF;
    
    for(auto [val, op] : ans) {
        amin(answer, op);
    }
    
    cout << answer << '\n';
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