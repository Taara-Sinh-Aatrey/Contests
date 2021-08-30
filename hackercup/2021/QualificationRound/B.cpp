/**
 *    author:  Taara Sinh Aatrey
 *    created: 27.08.2021 22:59:52
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
    
    int n;
    cin >> n;
    
    vector<string> s(n);
    cin >> s;
    
    map<int, int> mp;
    set<pair<int, int>> st;
    
    for(int r = 0; r < n; r++) {
        bool ok = true;
        int cnt = 0;
        int cw = -1;
        for(int c = 0; c < n; c++) {
            if(s[r][c] == '.') {
                cnt++;
                cw = c;
            }
            if(s[r][c] == 'O') {
                ok = false;
                break;
            }
        }
        
        if(!ok) continue;
        mp[cnt]++;
        if(cnt == 1) {
            st.emplace(r, cw);
        }
    }
    
    for(int c = 0; c < n; c++) {
        bool ok = true;
        int cnt = 0;
        int rw = -1;
        for(int r = 0; r < n; r++) {
            if(s[r][c] == '.') {
                cnt++;
                rw = r;
            }
            if(s[r][c] == 'O') {
                ok = false;
                break;
            }
        }
        
        if(!ok) continue;
        mp[cnt]++;
        if(cnt == 1) {
            st.emplace(rw, c);
        }
    }
    
    if(mp.empty()) {
        cout <<  "Impossible" << '\n';
        return;
    }
    
    auto it = mp.begin();
    cout << it->first << ' ';
    if(it->first == 1) {
        cout << st.size() << '\n';
    }
    else {
        cout << it->second << '\n';
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        cout << "Case #" << tt << ": ";
        solve();
    }
    
    return 0;
}