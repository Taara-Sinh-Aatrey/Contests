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

  int n, m, k;
  cin >> n >> m >> k;
  int r1, c1, r2, c2;
  cin >> r1 >> c1 >> r2 >> c2;

  int h = r2 - r1 + 1;
  int w = c2 - c1 + 1;

  int mn = min({r2, n + 1 - r1, c2, m + 1 - c1});

  auto div = [&](int x) { return (x + k - 1) / k; };

  int ans = 0;
  if (r1 == 1 || r2 == n || c1 == 1 || c2 == m) {
    if (r1 != 1) {
      ans += div(w);
    }
    if (r2 != n) {
      ans += div(w);
    }
    if (c1 != 1) {
      ans += div(h);
    }
    if (c2 != m) {
      ans += div(h);
    }
  } else {
    ans = div(min(r2, n + 1 - r1)) + div(h) + 2 * div(w);
    amin(ans, div(min(c2, m + 1 - c1)) + 2 * div(h) + div(w));
  }

  int x = max<int>(0, h - 1) / k;
  int y = max<int>(0, w - 1) / k;

  ans += min(div(h) * (w - 1) + div(w) * x + w * (h - 1 - x),
             div(h) * y + h * (w - 1 - y) + div(w) * (h - 1));

  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  cin >> t;

  for (int tt = 1; tt <= t; tt++) {
    cout << "Case #" << tt << ": ";
    solve();
  }

  return 0;
}