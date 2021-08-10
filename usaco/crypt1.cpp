/*
ID: taarasi1
TASK: crypt1
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
    int n;
    cin >> n;
    vector<int> a(n);
    cin >> a;
    
    set<int> s(a.begin(), a.end());
    
    int ans = 0;
    
    for(int i = 100; i <= 999; i++) {
        for(int j = 10; j <= 99; j++) {
            int p1 = i * (j % 10);
            int p2 = i * (j / 10);
            int p = i * j;
            if(!(100 <= p1 && p1 <= 999 && 100 <= p2 && p2 <= 999)) {
                continue;
            }
            auto good = [&] (int num)  {
                bool ok = true;
                while(num > 0) {
                    if(!s.count(num % 10)) {
                        ok = false;
                        break;
                    }
                    num /= 10;
                }
                return ok;
            };
            ans += good(i) && good(j) && good(p1) && good(p2) && good(p);
        } 
    }
    
    cout << ans << '\n';
}

signed main()
{
#ifndef LOCAL
    freopen("crypt1.in", "r", stdin);
    freopen("crypt1.out", "w", stdout);
#endif

    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
    
    return 0;
}