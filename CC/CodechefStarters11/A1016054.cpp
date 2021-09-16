#include<bits/stdc++.h>
#include <vector>

using namespace std;
#define int int64_t
const int N = 1e5 + 5;
vector<int> spf(N, 0);
vector<bool> prime(N, true);
vector<int> primes;
void sieve() {
    prime[0] = prime[1] = false;
    for(int i = 2; i < N; i++) {
        if(prime[i]) {
            spf[i] = i;
            primes.push_back(i);
        }
        int prod;
        for(int j = 0; j < (int) primes.size() && primes[j] <= spf[i] && (prod = primes[j] * i) < N; j++) {
            spf[prod] = primes[j];
            prime[prod] = false;
        }
    }
}
void factorise(int num, vector<int>& factors) {
    factors = {1};
    while(num > 1) {
        int factor = spf[num];
        int cnt = 0;
        int p = 1;
        int sz = factors.size();
        while(spf[num] == factor) {
            num /= factor;
            p *= factor;
            for(int i = 0; i < sz; i++) {
              factors.emplace_back(factors[i] * p);
            }
            cnt++;
        }
    }
};
const int mod = 1e9 + 7;
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while(t--) {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    vector<int> idx(n + 1);
    for(int i = 0; i < n; i++) {
      cin >> a[i];
    }
  }
  return 0;
}