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
    
    string s;
    cin >> s;
    
    string ans = "";
    map<char, int> p;
    int x = 0;
    while(true) {
        int n = s.size();
        set<char> st;
        vector<int> d(n);
        for(int i = n - 1; i >= x; i--) {
            if(!p[s[i]]) {
                st.insert(s[i]);
            }
            d[i] = st.size();
        }
                
        if(st.empty()) break;
        int distinct = st.size();
        pair<char, int> mn{'z', INF};
        int mx = 0;
        for(int i = x; i < n && d[i] == distinct; i++) {
            if(p[s[i]]) {
                continue;
            }
            amax(mx, i);
        }
        
        map<char, int> mp;
        map<char, int> tmp;
        int taken = -1;
        for(int i = x; i <= mx; i++) {
            if(p[s[i]]) {
                mp[s[i]]++;
                for(char ch = s[i] + 1; ch <= 'z'; ch++) {
                    mp[ch] = 0;
                }
            }
            else {
                if(tmp.empty()) {
                    tmp = mp;
                    taken = i;
                    tmp[s[i]]++;
                    for(char ch = s[i] + 1; ch <= 'z'; ch++) {
                        tmp[ch] = 0;
                    }
                }
                else {
                    auto cur = mp;
                    cur[s[i]]++;
                    for(char ch = s[i] + 1; ch <= 'z'; ch++) {
                        cur[ch] = 0;
                    }
                    
                    for(char ch = 'a'; ch <= 'z'; ch++) {
                        if(tmp[ch] == cur[ch]) {
                            continue;
                        }
                        if(tmp[ch] < cur[ch]) {
                            tmp = cur;
                            taken = i;
                        }
                        break;
                    }
                }
            }
        }
        
        p[s[taken]] = 1;
        
        for(auto [ch, f] : tmp) {
            while(f--) {
                ans += ch;
            }
        }
        
        x = taken + 1;
        
        
    }
    
    cout << ans << '\n';
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