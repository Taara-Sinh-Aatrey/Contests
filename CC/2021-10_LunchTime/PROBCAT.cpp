#include<bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
   int x;
   cin >> x;
   if (x < 100) {
    cout << "Easy";
   }
   else if (x < 200) {
    cout << "Medium";
   }
   else {
    cout << "Hard";
   }
   cout << '\n';
  }
  return 0;
}