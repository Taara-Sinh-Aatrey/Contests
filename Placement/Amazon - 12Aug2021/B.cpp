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

#define ll long long

ll solve(int n, vector<ll> a, ll m) {
    
    map<ll, ll> f;
    for(auto& x : a) {
        f[x]++;
    }
    
    ll ans = 0;
    
    for(auto i = f.rbegin(); i != f.rend(); i++) {
        ll hi = i->first;
        ll lo = 1;
        auto j = i;
        j++;
        if(j != f.rend()) {
            lo = j->first + 1;
        }
        
        int low = lo;
        
        lo = max(lo, hi - (m / i->second) + 1);
        ans += (lo + hi) * (hi - lo + 1) / 2 * i->second;
        m -= (hi - lo + 1) * i->second;
        
        if(lo > low) {
            assert(m < i->second);
            ans += (lo - 1) * m;
            m = 0;
        }
        
        f[low - 1] += i->second;
    }
    
    return ans;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cout << solve(2, {3, 5}, 6) << endl;
    
    return 0;
}