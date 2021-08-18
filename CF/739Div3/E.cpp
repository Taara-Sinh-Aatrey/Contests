/**
 *    author:  Taara Sinh Aatrey
 *    created: 19.08.2021 00:09:26
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
    
    string s;
    cin >> s;
    int n = s.size();
    
    set<int> st;
    vector<pair<char, int>> idx;
    map<char, int> f;
    for(int i = n - 1; i >= 0; i--) {
        if(!st.count(s[i])) {
            st.insert(s[i]);
            idx.emplace_back(i, s[i]);
        }
        f[s[i]]++;
    }
    reverse(idx.begin(), idx.end());
    
    int distinct = idx.size();
    int len = 0;
    for(int i = 0; i < distinct; i++) {
        char ch = idx[i].second;
        
        if(f[ch] % (i + 1) != 0) {
            cout << -1 << '\n';
            return;
        }
        
        len += f[ch] / (i + 1);
    }
    
    string rem = s.substr(0, len);
    string t;
    string ord;
    for(int i = 0; i < distinct; i++) {
        t += rem;
        ord += idx[i].second;
        rem.erase(remove(rem.begin(), rem.end(), idx[i].second), rem.end());
    }
    
    if(s != t) {
        cout << -1 << '\n';
        return;
    }
    
    cout << s.substr(0, len) << " " << ord << '\n';
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