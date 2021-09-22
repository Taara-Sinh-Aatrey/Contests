// tourist's solution
// understood this solution completely and hence submitting 
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<vector<int>> a(n);
  vector<int> c(n);
  for (int i = 0; i < n; i++) {
    cin >> c[i];
    a[i].resize(c[i]);
    for (int j = 0; j < c[i]; j++) {
      cin >> a[i][j];
    }
  }
  int m;
  cin >> m;
  vector<vector<int>> f(m, vector<int>(n));
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cin >> f[i][j];
      --f[i][j];
    }
  }
  sort(f.begin(), f.end());
  set<pair<int, vector<int>>> s;
  {
    int sum = 0;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
      sum += a[i].back();
      v[i] = c[i] - 1;
    }
    s.emplace(sum, v);
  }
  while (true) {
    assert(!s.empty());
    auto it = prev(s.end());
    int sum = it->first;
    vector<int> v = it->second;
    s.erase(it);
    auto iter = lower_bound(f.begin(), f.end(), v);
    if (iter == f.end() || *iter != v) {
      for (int i = 0; i < n; i++) {
        if (i > 0) {
          cout << " ";
        }
        cout << v[i] + 1;
      }
      cout << endl;
      break;
    }
    for (int i = n - 1; i >= 0; i--) {
      if (v[i] > 0) {
        int new_sum = sum - a[i][v[i]] + a[i][v[i] - 1];
        v[i] -= 1;
        s.emplace(new_sum, v);
        v[i] += 1;
      }
      // commenting this block slows the solution by 500ms
      // what the heck? how?
      if (v[i] < c[i] - 1) {
        break;
      }
      /*
      Example to understand what the above block is doing
      c = {9, 4, 3, 5, 2}
      initial v = {8, 3, 2, 4, 1}
      it will prevent {8, 3, 2, 3, 1} to transition into {8, 3, 1, 3, 1}
      and this is high level stuff
      because it is {8, 3, 1, 4, 1}'s responsibility
      so basically we are doing this to avoid pushing a sequence more than once
      NOT SO EASY TO DIGEST THIS THOUGH
      */
    }
  }
  return 0;
}
