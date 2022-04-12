// #include <algorithm>
// #include <array>
// #include <bitset>
// #include <cassert>
// #include <chrono>
// #include <cmath>
// #include <cstring>
// #include <functional>
// #include <iomanip>
// #include <iostream>
// #include <map>
// #include <numeric>
// #include <queue>
// #include <random>
// #include <set>
// #include <vector>
// using namespace std;

// template <typename T, typename U> istream& operator>>(istream &is, pair<T, U> &p) { return is >> p.first >> p.second; }
// template <typename T, typename U> ostream& operator<<(ostream &os, const pair<T, U> &p) { return os << p.first << " " << p.second; }
// template <typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> istream &operator>>(istream &is, T_container &v) { for (T &x : v) is >> x; return is; }
// template <typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream &operator<<(ostream &os, const T_container &v) { bool f = false; for (const T &x : v) { if (f) os << " "; os << x; f = true; } return os; }
// void scan() {} template <typename Head, typename ...Tail> void scan(Head &H, Tail &...T) { cin >> H; scan(T...); }
// void print() { cout << "\n"; } template <typename Head> void print(const Head &H) { cout << H << "\n"; } template <typename Head, typename ...Tail> void print(const Head &H, const Tail &...T) { cout << H << " "; print(T...); }
// template <typename T, typename T1, typename... Tail> T amin(T& a, T1 b, Tail... c) { if(b < a) a = b; if constexpr (sizeof...(c) != 0) { amin(a, c...); } return a; } template <typename T, typename T1, typename... Tail> T amax(T& a, T1 b, Tail... c) { if(b > a) a = b; if constexpr (sizeof...(c) != 0) { amax(a, c...); } return a; }

// #ifdef LOCAL
// #include "debug.hpp"
// #else
// #define dbg(...)
// #endif

// template <typename T, class F = function<T(const T&, const T&)>>
// class SparseTable {
// public:
//     int n;
//     vector<vector<T>> mat;
//     F func;

//     SparseTable(const vector<T>& a, const F& f) : func(f) {
//         n = static_cast<int>(a.size());
//         int max_log = 64 - __builtin_clzll(n);
//         mat.resize(max_log);
//         mat[0] = a;
//         for (int j = 1; j < max_log; j++) {
//             mat[j].resize(n - (1 << j) + 1);
//             for (int i = 0; i <= n - (1 << j); i++) {
//                 mat[j][i] = func(mat[j - 1][i], mat[j - 1][i + (1 << (j - 1))]);
//             }
//         }
//     }

//     T get(int from, int to) const {
//         assert(0 <= from && from <= to && to <= n - 1);
//         int lg = 64 - __builtin_clzll(to - from + 1) - 1;
//         return func(mat[lg][from], mat[lg][to - (1 << lg) + 1]);
//     }
// };

// #define int int64_t
// const int inf = 1e18L + 5, mod = 1e9 + 7, N = 2e5 + 5;

// void solve() {
//     int n;
//     scan(n);
//     vector<int> a(n);
//     scan(a);
//     SparseTable st(a, [&](const int& i, const int& j) {
//         return gcd(i, j);
//     });
//     vector<int> ans(n);
//     int ops = 0;
//     int lst = -1;
//     for (int i = 0; i < n; i++) {
//         int low = lst + 1, high = i;
//         bool ok = true;
//         while (low <= high) {
//             int mid = (low + high) / 2;
//             int len = i - mid + 1;
//             int g = st.get(mid, i);
//             if (len == g) {
//                 ok = false;
//                 break;
//             }
//             else if (len > g) {
//                 low = mid + 1;
//             }
//             else {
//                 high = mid - 1;
//             }
//         }
//         if (!ok) {
//             ops++;
//             lst = i;
//         }
//         ans[i] = ops;
//     }
//     print(ans);
// }

// signed main() {
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
//     int t = 1;
//     for (int tt = 1; tt <= t; tt++) {
//         solve();
//     }
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
#define int int64_t
#define pb push_back
#define vec vector<int>
#define vpl vector<pair<int, int>>
#define fastInOut ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define F first
#define S second
#define flush cout<<endl;
#define endl "\n" 
#define yes cout<<"YES"<<endl; 
#define no cout<<"NO"<<endl; 
#define all(v) v.begin(),v.end()


void solve()
{
   int n = 2e5;
   // cout << n << '\n';
   // cin>>n;
   vec a(n);
   for(int i=0;i<n;i++)
   {
       // cin>>a[i];
    if (i == 0)
        a[i] = 1e9;
    else
        a[i] = 1e9;
    // cout << a[i] << " \n"[i == n - 1];
   }

   int curr=0,len=0;
   int op=0;
   int prev=0;
   int gc=0;
   int xxx = 0;
   for(int i=0;i<n;i++)
   {

            int g=0,ind=i;
            int l=1;
            gc=__gcd(gc,a[i]);
            
            if(gc<=ind-prev+1)
            while(ind>=prev)
            {
                xxx++;
                g=__gcd(g,a[ind]);
                if(g==l)
                {
                    op++;
                    prev=i+1;
                    gc=0;
                    break;
                }
                if(g<l)
                {
                    break;
                }
                
                ind--;
                l++;
            }
            cout<<op<<' ';
   }
   cout << '\n' << xxx;


}

int32_t main()
{
#ifdef LOCAL
    freopen("out", "w", stdout);
#endif
  fastInOut;

  int t=1;
//   cin >> t;

  for(int i=1;i<=t;i++)
   {
      solve();
   }

}