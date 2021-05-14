#include<bits/stdc++.h>
using namespace std;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
int rand(int a, int b) { return uniform_int_distribution<int>(a, b)(rng); }

#define int long long

const int N = 5e5 + 5;

vector<int> factors[N];
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

void factorise(int num) {
    vector<int> &vec = factors[num];
    vec.emplace_back(1);
    while(num > 1) {
        int sz = (int) vec.size();
        int factor = spf[num];
        int p = 1;
        while(spf[num] == factor) {
            num /= factor;
            p *= factor;
            for(int i = sz - 1; i >= 0; i--) {
                vec.emplace_back(vec[i] * p);
            }
        }
    }
    sort(vec.begin(), vec.end());
};

void solve(int tt) {
    int n, m;
    cin >> n >> m;

    int ans = 0;
    for(int b = 2; b <= min(n, m); b++) {
        int x = m - m % b;
        ans += lower_bound(factors[x].begin(), factors[x].end(), b) - factors[x].begin();
    }

    if(m + 1 <= n) {
        ans += (m + n - 1) * (n - m) / 2;
    }

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    sieve();

    for(int i = 1; i < N; i++) {
        factorise(i);
    }

    int t;
    cin >> t;

    for(int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
    

    return 0;
}