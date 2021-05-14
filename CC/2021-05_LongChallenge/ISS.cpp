#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 4e6 + 8;

vector<int> ans(N / 4);
vector<int> factors[N];
vector<int> cnt(N, 0);
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

void factorise(int num, vector<int>& vec) {
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
    sort(vec.rbegin(), vec.rend());
};


void solve(int tt) {
    int k;
    cin >> k;
    cout << ans[k] << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    sieve();

    for(int i = 1; i < N / 4; i++) {
        ans[i] = 0;
    }

    for(int i = 1; i < N; i += 2) {
        factorise(i, factors[i]);
    }

    for(int k = 1; k < N / 4; k++) {
        for(auto& factor: factors[4 * k + 1]) {
            int x = max<int>(1, (factor - 1) / 2);
            int tot = 2 * k - (x - 1);
            assert(factor > 0);
            cnt[factor] += 1 + (tot - 1) / factor;
            ans[k] += factor * cnt[factor];
            for(auto& f2: factors[factor]) {
                if(f2 != factor) {
                    cnt[f2] -= cnt[factor];
                }
            }
            cnt[factor] = 0;
        }
    }

    for(int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
    

    return 0;
}