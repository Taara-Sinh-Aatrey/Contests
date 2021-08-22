/**
 *    author:  Taara Sinh Aatrey
 *    created: 22.08.2021 22:33:27
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
    vector<int> a(n + 1);
    
    vector<vector<int>> idx(n + 1);
    int w = 1;
    a[1] = 1;
    idx[1].emplace_back(1);
    
    for(int i = 2; i <= n; i++) {
        int low = 1, high = i - 1;
        int x = -1;
        while(low <= high) {
            int mid = (low + high) / 2;
            vector<int> temp;
            set<int> st;
            for(int j = mid; j < i; j++) {
                if(st.count(a[j])) continue;
                st.insert(a[j]);
                temp.emplace_back(j);
            }
            temp.emplace_back(i);
            cout << "? " << temp.size() << " ";
            cout << temp << endl;
            int res;
            cin >> res;
            assert(res != -1);
            if(res == 1) {
                high = mid - 1;
            }
            else {
                x = mid;
                low = mid + 1;
            }
        }
        
        if(x != -1) {
            a[i] = a[x];
        }
        else {
            w++;
            a[i] = w;
        }
    }
    
    a.erase(a.begin());
    cout << "! " << a << endl;
    int res;
    cin >> res;
    assert(res != -1);
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

// 1 2 1 1 2
// {1, 2, 1, 3, 4}