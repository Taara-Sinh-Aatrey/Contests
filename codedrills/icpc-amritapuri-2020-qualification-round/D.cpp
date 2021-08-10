/**
 *    author:  Taara Sinh Aatrey
 *    created: 07.08.2021 19:58:29
**/

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

void solve() {
    
    int n, q;
    cin >> n >> q;
    
    vector<string> s(n);
    cin >> s;
    
    vector<int> F(26, 0);
    
    vector<vector<int>> LIS(26, vector<int>(26, 0));
    
    for(int i = 0; i < n; i++) {
        vector<vector<int>> lis(26, vector<int>(26, 0));
        vector<int> f(26, 0);
        
        for(int j = 0; j < s[i].size(); j++) {
            
            auto nlis = lis;
            int x = s[i][j] - 'a';
            
            f[x]++;
            
            for(int c1 = 0; c1 <= x; c1++) {
                for(int c2 = c1; c2 <= x; c2++) {
                    amax(nlis[c1][x], lis[c1][c2] + 1);
                }
            }
            
            lis = nlis;
        }
                
        for(int c1 = 0; c1 < 26; c1++) {
            for(int c2 = c1; c2 < 26; c2++) {
                amax(LIS[c1][c2], lis[c1][c2]);
            }
        }
        
        for(int c1 = 0; c1 < 26; c1++) {
            amax(F[c1], f[c1]);
        }
    }
        
    for(int c1 = 0; c1 < 26; c1++) {
        for(int c2 = c1; c2 < 26; c2++) {
            for(int c3 = 0; c3 <= c1; c3++) {
                for(int c4 = c2; c4 < 26; c4++) {
                    amax(LIS[c3][c4], LIS[c1][c2]);
                }
            }
        }
    }
        
    int answer = 0;
    
    vector<vector<vector<int>>> ans(27, vector<vector<int>>(26, vector<int>(26, 0)));
    ans[1] = LIS;
    
    for(int x = 2; x <= 26; x++) {
        for(int i = 0; i < 26; i++) {
            for(int j = i; j < 26; j++) {
                for(int k = i; k <= j; k++) {
                    amax(ans[x][i][j], ans[x - 1][i][k] + LIS[k][j], LIS[i][k] + ans[x - 1][k][j]);
                }
            }
        }
    }
    
    for(int c1 = 0; c1 < 26; c1++) {
        for(int x = 0; x <= 26; x++) {
            for(int y = 0; y <= 26; y++) {
                if(x + y > q) {
                    continue;
                }
                amax(answer, ans[x][0][c1] + (q - x - y) * F[c1] + ans[y][c1][25]);
            }
        }
    }
    
    cout << answer << '\n';

}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        solve();
    }
    
    return 0;
}