#include<bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int c0 = count(s.begin(), s.end(), '0'), c1 = count(s.begin(), s.end(), '1');
    cout << (c0 == 0 || c1 == 0 || (c0 % 2 == c1 % 2 && min(c0, c1) > 1) ? "Bob" : "Alice") << '\n';
  }
}
