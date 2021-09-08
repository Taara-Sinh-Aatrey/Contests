/**
 *    author:  Taara Sinh Aatrey
 *    created: 01.09.2021 21:40:28
**/

#include <bits/stdc++.h>
#include <unordered_map>
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
const int mod = 1e9 + 7; const int INF = 1e18L + 5; const int N = 5e7 + 105;

void solve() {
    
    int n, k;
    cin >> n >> k;
    
    dbg(n, k);
    
    vector<int> x(k);
    cin >> x;
    int ax, bx, cx, dx;
    cin >> ax >> bx >> cx >> dx;
    
    vector<int> w(k);
    cin >> w;
    int aw, bw, cw, dw;
    cin >> aw >> bw >> cw >> dw;
    
    vector<int> y(k);
    cin >> y;
    int ay, by, cy, dy;
    cin >> ay >> by >> cy >> dy;
    
    for(int i = k; i < n; i++) {
        x.emplace_back((ax * x[i - 2] + bx * x[i - 1] + cx) % dx + 1);
        w.emplace_back((aw * w[i - 2] + bw * w[i - 1] + cw) % dw + 1);
        y.emplace_back((ay * y[i - 2] + by * y[i - 1] + cy) % dy + 1);
    }
    
    int ans = 0;
    int p = 1;
    unordered_map<int, int> mp;
    set<pair<int, int>> st;
    st.emplace(-INF, -INF);
    st.emplace(INF, INF);
    
    auto add = [&](int lo, int hi) {
        ans += abs(mp[lo] - mp[lo - 1]);
        ans += abs(mp[hi] - mp[hi + 1]);    
    };
    auto sub = [&](int lo, int hi) {
        ans -= abs(mp[lo] - mp[lo - 1]);
        ans -= abs(mp[hi] - mp[hi + 1]);    
    };
    
    for(int i = 0; i < n; i++) {
        int lo = x[i], hi = x[i] + w[i] - 1;
        
        // split the overlapping segment
        auto it = prev(st.upper_bound(pair(lo, -1)));
        {
            int x = it->second;
            if(x >= lo) {
                auto tmp = *it;
                st.erase(it);
                st.emplace(tmp.first, lo - 1);
                mp[lo - 1] = mp[tmp.first];
                mp[lo] = mp[tmp.first];
                st.emplace(lo, tmp.second);
            }
        }
            
        // split the overlapping segment
        auto jt = prev(st.upper_bound(pair(hi + 1, -1)));
        {
            int x = jt->second;
            if(x > hi) {
                auto tmp = *jt;
                st.erase(jt);
                st.emplace(tmp.first, hi);
                mp[hi] = mp[tmp.first];
                mp[hi + 1] = mp[tmp.first];
                st.emplace(hi + 1, tmp.second);
            }
        }
        
        
        // remove the old segments between [lo, hi]
        it = st.upper_bound(pair(lo, -1));
        jt = st.upper_bound(pair(hi + 1, -1));
        auto kt = it;
        while(kt != jt) {
            auto [l, h] = *kt;
            ans -= (h - l + 1) << 1;
            sub(l, h);
            mp[l] = 0;
            mp[h] = 0;
            add(l, h);
            kt++;
        }
        st.erase(it, jt);
        
        
        // process ith segment
        sub(x[i], x[i] + w[i] - 1);
        
        st.emplace(x[i], x[i] + w[i] - 1);
        mp[x[i]] = y[i];
        mp[x[i] + w[i] - 1] = y[i];
        ans += w[i] << 1;
        
        add(x[i], x[i] + w[i] - 1);
        
        p *= (ans % mod + mod) % mod;
        p %= mod;
    }
    
    cout << p << '\n';
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        dbg(tt);
        cout << "Case #" << tt << ": ";
        solve();
    }
    
    return 0;
}