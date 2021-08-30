/**
 *    author:  Taara Sinh Aatrey
 *    created: 29.08.2021 22:17:42
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
    
    auto qor = [&](int i, int j) {
        cout << "or " << i << " " << j << endl;
        int res;
        cin >> res;
        return res;
    };
    auto qand = [&](int i, int j) {
        cout << "and " << i << " " << j << endl;
        int res;
        cin >> res;
        return res;
    };
    
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    
    for(int i = 1; i <= n; i += 2) {
        
        // 2 queries to find the singleton element
        if(i + 1 > n) {
            int OR = qor(i - 1, i);
            int AND = qand(i - 1, i);
            
            for(int b = 0; b <= 30; b++) {
                if(AND >> b & 1) {
                    a[i] |= 1 << b;
                }
                else if(!(OR >> b & 1)) {
                }
                else {
                    if(a[i - 1] >> b & 1) {
                    }
                    else {
                        a[i] |= 1 << b;
                    }
                }
            }
            continue;
        }
        
        
        // 4 queries to find a pair
        int OR = qor(i, i + 1);
        int AND = qand(i, i + 1);
        
        // we need another number 'j' to extract info about i and i+1
        int j = i + 2;
        if(i + 2 > n) {
            j = i - 1;
        }
        int and1 = qand(i, j);
        int or2 = qor(i + 1, j);
        
        for(int b = 0; b <= 30; b++) {
            
            if(AND >> b & 1) { // both are 1
                a[i] |= 1 << b;
                a[i + 1] |= 1 << b;
            }
            else if(!(OR >> b & 1)) { // both are 0
            }
            else { // check if (i is 1 and j is 0) or the other way around
                
                int o1 = and1 >> b & 1;
                int o2 = or2 >> b & 1;
                
                if(o1 == o2) { // i is 1, j is 0
                    a[i] |= 1 << b;
                }
                else {
                    if(o1 == 1) { // i is 1, j is 0
                        a[i] |= 1 << b;
                    }
                    else { // i is 0, j is 1
                        a[i + 1] |= 1 << b; 
                    }
                }
            }
        }        
    }
    
    a.erase(a.begin());
    
    sort(a.begin(), a.end());
    cout << "finish " << a[k - 1] << endl;
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