/*
ID: taarasi1
TASK: dualpal
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

void solve() {
    int n, m;
    cin >> n >> m;
    
    vector<int> ans;
    
    while(ans.size() < n) {
        
        map<int, int> mp;
        
        for(int b = 2; b <= 10; b++) {
            auto map = [&](int d) {
                if(d < 10) {
                    return char('0' + d);
                }
                d -= 10;
                return char('A' + d);
            };
            
            auto get = [&](int num)  {
                string s;
                while(num > 0) {
                    s += map(num % b);
                    num /= b;
                }
                return s;
            };
            
            string s = get(m + 1);
            int sz = s.size();
            for(int i = 0; i < sz / 2; ) {
                int j = sz - 1 - i;
                if(s[j] < s[i]) {
                    s[i] = s[j];
                    for(int x = i + 1; x <= j; x++) {
                        if(s[x] - '0' != b - 1) {
                            s[x]++;
                            break;
                        }
                        else {
                            s[x] = '0';
                        }
                    }                    
                    continue;
                }
                else if(s[j] > s[i]) {
                    s[i] = s[j];
                }
                i++;
            }
            int val = 0;
            for(int i = sz - 1; i >= 0; i--) {
                val = val * b + (s[i] - '0');
            }
            mp[val]++;
        }
        
        int val, f;

        for(auto& [x, y] : mp) {
            val = x;
            f = y;
            break;
        }
        
        if(f >= 2) {
            ans.emplace_back(val);
        }
        m = val;
    }
    
    for(int i = 0; i < n; i++) {
        cout << ans[i] << '\n';
    }
}

signed main()
{
#ifndef LOCAL
    freopen("dualpal.in", "r", stdin);
    freopen("dualpal.out", "w", stdout);
#endif

    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
    
    return 0;
}