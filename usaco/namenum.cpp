/*
ID: taarasi1
TASK: namenum
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
    ifstream fin("dict.txt");
    string s;
    set<string> st;
    map<string, bool> mp;
    vector<string> D = {"", "", "ABC", "DEF", "GHI", "JKL", "MNO", "PRS", "TUV", "WXY"};
          
    while (getline (fin, s)) {
        st.insert(s);
        while(!s.empty()) {
            mp[s] = true;
            s.pop_back();
        }
    }
    
    int n;
    cin >> n;
    
    vector<string> ans({""});
    
    s = to_string(n);
    reverse(s.begin(), s.end());
    n = stoll(s);
    for(; n > 0; n /= 10) {
        int d = n % 10;
        vector<string> nans;
        for(int j = 0; j < 3; j++) {
            for(auto s : ans) {
                s += D[d][j];
                if(mp[s]) {
                    nans.emplace_back(s);       
                }
            }
        }
        ans = nans;
    }
        
    int c = 0;
    
    set<string> print(ans.begin(), ans.end());
    
    for(auto& s : print) {
        if(st.count(s)) {
            c = 1;
            cout << s << '\n';
        }
    }
    
    if(c == 0) {
        cout << "NONE" << '\n';
    }
    
}

signed main()
{
#ifndef LOCAL
    freopen("namenum.in", "r", stdin);
    freopen("namenum.out", "w", stdout);
#endif

    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
    
    return 0;
}