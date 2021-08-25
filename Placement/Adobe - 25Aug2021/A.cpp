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


int fatigueFactor(int n, int m, vector<int> x) {
    #define ll long long
    ll low = -4e9, high = 4e9;
    m *= 2;
    
    ll ans = LLONG_MAX;
    while(low <= high) {
        ll mid1 = (low + high) / 2;
        
        auto fun = [&](ll cur) {
            ll cost = 0;
            for(ll i = 0; i < n; i++) {
                cost = max(cost, abs(2 * x[i] - cur));
                cur += m;
            }
            return cost;
        };
        
        ll cost1 = fun(mid1);
        
        ll mid2 = mid1 + 1;
        ll cost2 = fun(mid2);
        while(cost2 == cost1) {
            mid2++;
            cost2 = fun(mid2);
        }
        
        ans = min(cost1, cost2);
        if(cost2 < cost1) {
            low = mid2 + 1;
        }
        else {
            high = mid1 - 1;
        }
    }
    
    return ans;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << fatigueFactor(4, 2, {1, 2, 3, 4}) << endl;
    cout << fatigueFactor(4, 2, {1, 2, 4, 3}) << endl;
    cout << fatigueFactor(5, 3, {2, 5, 7, 10, 12}) << endl;
    
    return 0;
}
