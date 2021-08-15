/**
 *    author:  Taara Sinh Aatrey
 *    created: 14.08.2021 21:21:40
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

struct P {
    int64_t x, y;
    void read() {
        cin >> x >> y;
        // scanf();
        // overload the >> operator for point
    }
    P operator - (const P& b) const {
        return  P{x - b.x, y - b.y};
        // default constructor
    }
    // const after () means that I myself am constant, i.e., I have called this function
    // and receieved some argument/s but I am not going to change my own value
    void operator -= (const P& b) {
        x -= b.x;
        y -= b.y;
    }
    int64_t operator * (const P& b) const {
        return x * b.y - y * b.x;
    }
    int64_t crosswrtme(const P& b, const P& c) const {
        return (b - *this) * (c - *this);
    }
    // cross product wrt to me, if -ve then b more on left than c
};

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
int rand(int a, int b) { return uniform_int_distribution<int>(a, b)(rng); }


void solve() {
    
    int pb, bt, tp;
    cin >> pb >> bt >> tp;
    
    vector<vector<int>> d = {{0, pb, tp}, {pb, 0, bt}, {tp, bt, 0}};
    
    int area = 0;
    
    vector<P> ans;
    
    int diff = 1e9;
    
    // auto solve = [&](int bx, int by) {
    //     if(bx < 0 || by < 0) return;
    //     int tx = ((tp + py + px) - (bt + by - bx)) / 2;
    //     int ty = ((tp + py + px) + (bt + by - bx)) / 2;
    //     vector<P> pt(3);
    //     pt[0].x = 0, pt[0].y = 0;
    //     pt[1].x = bx, pt[1].y = by;
    //     pt[2].x = tx, pt[2].y = ty;
        
    //     if(pt[2].y - pt[2].x != bt + by - bx || pt[2].y + pt[2].x != tp + py + px) {
    //         return;
    //     }
        
    //     if(pt[0].x > pt[2].x || pt[2].x > pt[1].x || pt[2].y < max(pt[0].y, pt[1].y)) {
    //         return;
    //     }
        
    //     int cur = 0;
    //     int mnx = INF, mxx = -INF, mny = INF, mxy = -INF;
    //     for (int i = 0; i < 3; i++) {
    //         cur += pt[i] * pt[(i + 1) % 3];
    //         amin(mnx, pt[i].x);
    //         amax(mxx, pt[i].x);
    //         amin(mny, pt[i].y);
    //         amax(mxy, pt[i].y);
    //         // here we have taken origin as the Nail/pivot point for calculating
    //         // the area (and thus for cross product)
    //     }
        
    //     if(mxx - mnx + 1 > diff || mxy - mny + 1 > diff) {
    //         return;
    //     }
        
    //     for (int i = 0; i < 3; i++) {
    //         pt[i].x = pt[i].x - mnx + 1;
    //         pt[i].y = pt[i].y - mny + 1;
    //         // here we have taken origin as the Nail/pivot point for calculating
    //         // the area (and thus for cross product)
    //     }
        
    //     cur = abs(cur);
        
    //     if(area <= cur) {
    //         ans = pt;
    //         area = cur;
    //     }
    // };

    
    auto fun = [&](int i, int j, int k) {
        vector<P> pt(3);
        pt[i].x = 0, pt[i].y = 0;
        pt[j].x = d[i][j], pt[j].y = 0;
        pt[k].x = ((d[k][i] + pt[i].y + pt[i].x) - (d[k][j] + pt[j].y - pt[j].x)) / 2;
        pt[k].y = ((d[k][i] + pt[i].y + pt[i].x) + (d[k][j] + pt[j].y - pt[j].x)) / 2;
        
        if(abs(pt[k].x - pt[i].x) + abs(pt[k].y - pt[i].y) != d[k][i]) {
            return;
        }
        if(abs(pt[k].x - pt[j].x) + abs(pt[k].y - pt[j].y) != d[k][j]) {
            return;
        }
                
        int cur = 0;
        for (int i = 0; i < 3; i++) {
            cur += pt[i] * pt[(i + 1) % 3];
        }
        
        cur = abs(cur);
        
        if(cur > area) {
            ans = pt;
            area = cur;
        }
    };
     
    // bx - x + y - by = bt;
    // y - x = bt + by - bx
    
    // x - px + y - py = tp;
    // y + x = tp + py + px
    
    fun(0, 1, 2);
    fun(0, 2, 1);
    fun(1, 2, 0);
    
    if(area > 0) {
        cout << "YES" << '\n';
        for(int i = 0; i < 3; i++) {
            cout << ans[i].x + 1 << " " << ans[i].y + 1 << '\n';
        }
    }
    else {
        cout << "NO" << '\n';
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