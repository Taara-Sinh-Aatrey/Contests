#include <bits/stdc++.h>

using namespace std;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
template<typename T>
T rand(T a, T b) { return uniform_int_distribution<T>(a, b)(rng); }

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  cout << t << '\n';
  while(t--) {
    const long long MAX = 1e12;
    long long num = rand(2LL, MAX);
    long long l = rand(2LL, 2LL);   
    long long r = rand(2LL, MAX);    
    cout << num << " " << l << " " << r << '\n';
  }
  return 0;
}