/**
 *    author:  Taara Sinh Aatrey
 *    created: 02.09.2021 19:52:16
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
    
    int n, m, k, s;
    cin >> n >> m >> k >> s;
    
    auto read = [&](int sz) {
        vector<int> vec(k);
        cin >> vec;
        int w, x, y, z;
        cin >> w >> x >> y >> z;
        for(int i = k; i < sz; i++) {
            vec.emplace_back((w * vec[i - 2] + x * vec[i - 1] + y) % z + 1);
        }
        return vec;
    };
    auto a = read(n), b = read(m);
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    int lo = 0, hi = 5e8;
    while(lo <= hi) {
        int mid = (lo + hi) >> 1;
        if([&](){
            int i = 0, j = 0;
            while(i < n) {
                int cap = mid;
                int farthest = 0;
                while(j < m && b[j] < a[i]) {
                    int diff = a[i] - b[j];
                    amax(farthest, diff);
                    j++;
                }
                cap -= farthest;
                if(cap < 0) {
                    return false;
                }
                while(j < m && b[j] - a[i] + min(b[j] - a[i], farthest) <= cap) {
                    j++;
                }
                i++;
            }
            return j == m;
        }()) {
            hi = mid - 1;
        }
        else {
            lo = mid + 1;
        }
    }
    
    cout << lo << '\n';
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        cerr << tt << " ";
        cout << "Case #" << tt << ": ";
        solve();
    }
    
    return 0;
}