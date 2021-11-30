#include<bits/stdc++.h>
using namespace std;

#define ll long long

const ll N = 1e5 + 1;

vector<ll> spf(N, 0);
vector<bool> prime(N, true);
vector<ll> primes;
void sieve() {
  prime[0] = prime[1] = false;
  for(ll i = 2; i < N; i++) {
    if(prime[i]) {
      spf[i] = i;
      primes.push_back(i);
    }
    ll prod;
    for(ll j = 0; j < (ll) primes.size() && primes[j] <= spf[i] && (prod = primes[j] * i) < N; j++) {
      spf[prod] = primes[j];
      prime[prod] = false;
    }
  }
}

void factorise(ll num, vector<ll> &factors) {
  while(num > 1) {
    ll factor = spf[num];
    while(spf[num] == factor) {
      num /= spf[num];
    }
    factors.emplace_back(factor);
  }
};

class dsu {
public:
    vector<ll> p, sz;
    ll n;

    dsu(ll _n) : n(_n) {
        p.resize(n);
        sz.resize(n, 1);
        iota(p.begin(), p.end(), 0);
    }

    inline ll get(ll x) {
        return (x == p[x] ? x : (p[x] = get(p[x])));
    }

    inline bool unite(ll x, ll y) {
        x = get(x);
        y = get(y);
        if (x != y) {
            p[x] = y;
            sz[y] += sz[x];
            sz[x] = 0;
            return true;
        }
        return false;
    }
};

int main() {
  ll t;
  cin >> t;
  sieve();
  vector<vector<ll>> factors(N);
  for (ll i = 1; i < N; i++) {
    factorise(i, factors[i]);
  }
  while (t--) {
    ll n, k;
    cin >> n >> k;
    dsu d(n);
    vector<ll> idx(n + 1, -1);
    for (ll i = 2; i <= n; i++) {
      for (auto &p : factors[i]) {
        if (idx[p] == -1)
          idx[p] = i;
        else
          d.unite(idx[p] - 1, i - 1);
      }
    }
    auto &p = d.p;
    vector<vector<ll>> cc(n);
    for (ll i = 0; i < n; i++) {
      cc[d.get(i)].emplace_back(i);
    }
    ll mx = 0;
    vector<ll> poss(k + 1, -1);
    poss[0] = 0;
    for (ll i = 0; i < n; i++) {
      ll x = cc[i].size();
      if (x == 0) continue;
      for (ll j = min(mx, k - x); j >= 0; j--) {
        if (poss[j] == -1) continue;
        if (poss[j + x] == -1)
          poss[j + x] = i;
      }
      mx += x;
    }
    if (poss[k] != -1) {
      cout << "Yes" << '\n';
      while (k > 0) {
        ll i = poss[k];
        for (auto &x : cc[i]) {
          cout << x+1 << " ";
        }
        k -= cc[i].size();
      }
      cout << '\n';
    }
    else {
      cout << "No" << '\n';
    }
  }
}