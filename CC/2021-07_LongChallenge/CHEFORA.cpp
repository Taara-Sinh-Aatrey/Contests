/**
 *    author:  Taara Sinh Aatrey
 *    created: 03.07.2021 10:44:49
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
const int mod = 1e9 + 7; const int INF = 1e18L + 5; const int N = 1e5 + 5;

int a[N], pref[N];

int Pow(int a, int b, int P = mod){
    int res = 1;
    while(b > 0) {
        if(b & 1) res = res * a % P;
        a = a * a % P;
        b >>= 1;
    }
    return res;
}

void solve() {
    
    int l, r;
    cin >> l >> r, --l, --r;
    cout << Pow(a[l], pref[r] - pref[l]) << '\n';
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;
        
    for(int it = 0; it < N; it++) {
            
        string s = to_string(it > 0 ? a[it - 1] + 1 : 1);
        int sz = s.size();
        if(sz % 2 == 0) {
            s = "1" + string(sz, '0');
            sz++;
        }
        for(int i = sz - 1; i >= 0; ) {
            int j = sz - 1 - i;
            if(s[j] < s[i]) {
                s[i] = s[j];
                for(int x = i - 1; x >= j; x--) {
                    if(s[x] != '9') {
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
            i--;
        }
        int val = 0;
        for(int i = sz - 1; i >= 0; i--) {
            val = val * 10 + (s[i] - '0');
        }
        
        a[it] = val;
        
        pref[it] = a[it] + (it > 0 ? pref[it - 1] : 0);
        
    }

    for (int tt = 1; tt <= t; tt++) {
        solve();
    }
    
    return 0;
}