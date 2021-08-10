#include <algorithm>
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
    
    if(n == 1) {
        cout << 0 << '\n';
        return;
    }
    if(n == 2) {
        cout << (a[0] != a[1] ? 0 : -1) << '\n';
        return;
    }
    
    if(n == 3) {
        if(a[0] == a[2]) {
            if(a[0] != a[1]) {
                cout << 0 << '\n';
            }
            else if(a[0] != 0) {
                cout << 1 << '\n';
                cout << "1 3 2" << '\n';
            }
            else {
                cout << -1 << '\n';
            }
        }
        else if(a[1] == 0) {
            cout << 1 << '\n';
            if(a[0] != 0) {
                cout << "1 2 3" << '\n';
            }
            else {
                cout << "3 2 1" << '\n';
            }
        }
        else {
            cout << -1 << '\n';
        }
        return;
    }
    
    
    int x = max_element(a.begin(), a.end()) - a.begin();
    int y = x == n - 1 ? x - 1 : x + 1;
    if(a[x] == 0) {
        cout << -1 << '\n';
        return;
    }
    
    vector<int> b;
    
    for(int i = 0; i < n && int(b.size()) < 2; i++) {
        if(i != x && i != y) {
            b.emplace_back(i);
        }
    }
    
    cout << n + 1 << '\n';
    
    cout << x+1 << " " << y+1 << " " << b[0]+1 << '\n'; 
    cout << x+1 << " " << y+1 << " " << b[1]+1 << '\n'; 
    cout << b[0]+1 << " " << b[1]+1 << " " << y+1 << '\n'; 
    
    int i = x + 2;
    while(i < n) {
        cout << x+1 << " " << y+1 << " " << i+1 << '\n';
        i += 2;
    }
    
    i = x - 2;
    while(i >= 0) {
        cout << x+1 << " " << y+1 << " " << i+1 << '\n';
        i -= 2;
    }
    
    int z = x + 2 < n ? x + 2 : x - 2;
    i = x + 1;
    while(i < n) {
        if(i != y) {
            cout << x+1 << " " << z+1 << " " << i+1 << '\n';
        }
        i += 2;
    }
    
    i = x - 1;
    while(i >= 0) {
        if(i != y) {
            cout << x+1 << " " << z+1 << " " << i+1 << '\n';
        }
        i -= 2;
    }
    
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