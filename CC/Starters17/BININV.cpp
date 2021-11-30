#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
  ll t;
  cin >> t;
  while (t--) {
    ll n, m;
    cin >> n >> m;
    vector<string> s(n);
    for (auto &st : s)
      cin >> st;
    sort(s.begin(), s.end(), [&] (auto &x, auto &y) {
      vector<ll> a(2), b(2);
      for (ll i = 0; x[i]; i++)
        a[x[i] - '0']++;  
      for (ll i = 0; y[i]; i++)
        b[y[i] - '0']++;
      return a[1] * b[0] < b[1] * a[0];
    });
    ll inv = 0, ones = 0;
    for (auto &st : s) {
      for (auto &ch : st) {
        if (ch == '0')
          inv += ones;
        else
          ones++;
      }
    }
    cout << inv << '\n';
  }
}