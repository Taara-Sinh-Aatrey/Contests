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

int main()
{
    int n;
    cin >> n;
    // y = (yy/xx) x + c    
    // y xx = yy x + c xx
    vector<pair<int, int>> pts(n);
    map<array<int, 3>, set<pair<int, int>>> pt;
    set<pair<int, array<int, 3>>> st;
    for(int i = 0; i < n; i++) {
        cin >> pts[i].first >> pts[i].second;
        for(int j = 0; j < i; j++) {
            int xx = pts[i].first - pts[j].first; 
            int yy = pts[i].second - pts[j].second;
            int g = __gcd(xx, yy);
            yy /= g;
            xx /= g;
            array<int, 3> ar = {xx, yy, pts[i].second * xx - pts[i].first * yy};
            pt[ar].insert(pts[i]);
            pt[ar].insert(pts[j]);
        }
    }
    for(auto it = pt.begin(); it != pt.end(); it++) {
        int sz = it->second.size();
        st.insert({sz, it->first});
    }
    int ans = 0;
    while(!st.empty()) {
     auto it = prev(st.end());
     int sz = it->first;
     auto ar1 = it->second;
     if(sz == 0) break;
     st.erase(it);
     ans++;
     auto& vec = pt[ar1];
     for(auto& P : vec) {
        int x = P.first, y = P.second;
         for(int i = 0; i < n; i++) {
             if(pts[i] == P) continue;
             int xx = pts[i].first - x; 
             int yy = pts[i].second - y;
             int g = __gcd(xx, yy);
             yy /= g;
             xx /= g;
             array<int, 3> ar = {xx, yy, pts[i].second * xx - pts[i].first * yy};
             if(ar == ar1) continue;
             st.erase({pt[ar].size(), ar});
             auto it = pt[ar].find(pts[i]);
             if(it != pt[ar].end()) pt[ar].erase(it);
             it = pt[ar].find({x, y});
             if(it != pt[ar].end()) pt[ar].erase(it);
             st.emplace(pt[ar].size(), ar);
         }
     }
    }
    cout << ans;
    return 0;
}
