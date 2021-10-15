#include <bits/stdc++.h>

using namespace std;
#define int int64_t

struct pt{
  int x, y;
};

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while(t--) {
    int n;
    cin >> n;
    vector<pt> pts(n);
    for(int i = 0; i < n; i++) {
      cin >> pts[i].x;
      pts[i].x *= 2;
    }    
    for(int i = 0; i < n; i++) {
      cin >> pts[i].y;
      pts[i].y *= 2;
    }
    vector<array<int, 3>> lines;
    for(int i = 0; i < n; i++) {
      int x = pts[i].x, y = pts[i].y;
      lines.push_back({1, 1, x + y});
      lines.push_back({1, -1, x - y});
      lines.push_back({0, 1, y});
      lines.push_back({1, 0, x});
    }
    auto inter = pts;
    const int MAX = 1e18L + 5;
    for(int i = 0; i < 4 * n; i++) {
      for(int j = i + 1; j < 4 * n; j++) {
        auto [a1, b1, c1] = lines[i];
        auto [a2, b2, c2] = lines[j];
        if((a1 == 0 && a2 == 0) || (b1 == 0 && b2 == 0)) continue;
        if(a1 == a2 && b1 == b2) continue;
        int x = MAX, y = MAX;
        if(a1 == 0) {
          swap(a1, a2);
          swap(b1, b2);
          swap(c1, c2);
        }
        if(a2 == 0) y = c2;
        if(b1 == 0) {
          swap(a1, a2);
          swap(b1, b2);
          swap(c1, c2);          
        } 
        if(b2 == 0) x = c2;
        if(y == MAX) {
          y = (c1 - c2) / (b1 - b2);
        }
        if(x == MAX) {
          x = (c1 - b1 * y) / a1;
        }
        inter.push_back({x, y});
      }
    }
    int best = MAX, X = -1, Y = -1;
    for(auto [x, y] : inter) {
      int ans = 0;
      for(int i = 0; i < n; i++) {
          int dx = abs(pts[i].x - x);
          int dy = abs(pts[i].y - y);
          ans += !!dx + !!dy;
          ans -= (dx == dy && !!dx);
      }
      if(ans < best) {
          best = ans;
          X = x, Y = y;
      }
    }
    cout << best << '\n';
  }
  return 0;
}
