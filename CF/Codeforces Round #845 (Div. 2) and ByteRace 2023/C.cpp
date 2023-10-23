/**
 *    author:  Taara Sinh Aatrey
 *    created: 23.01.2023 01:06:51
**/

#include "bits/stdc++.h"

using namespace std;

#ifdef AATREY_DEBUG
#include "debug.hpp"
#else
#define dbg(...)
#endif

#define int int64_t

const int N = 1e5 + 5;

vector<int> cnt(N);

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
        int64_t prod;
        for(int j = 0; j < (int) primes.size() && primes[j] <= spf[i] && (prod = primes[j] * int64_t(i)) < N; j++) {
            spf[prod] = primes[j];
            prime[prod] = false;
        }
    }
}

void prime_factorise(int num, vector<pair<int, int>> &prime_factors) {
    while(num > 1) {
        int factor = spf[num];
        int cnt = 0;
        while(spf[num] == factor) {
            num /= factor;
            cnt++;
        }
        prime_factors.emplace_back(factor, cnt);
    }
};

void factorise(int num, vector<int> &factors) {
    factors.emplace_back(1);
    while(num > 1) {
        int factor = spf[num];
        int cnt = 0;
        int p = 1;
        int sz = factors.size();
        while(spf[num] == factor) {
            num /= factor;
            p *= factor;
            for (int i = 0; i < sz; i++) {
                factors.emplace_back(factors[i] * p);
            }
            cnt++;
        }
    }
};

vector<vector<int>> factors(N);

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int testcases;
    cin >> testcases;
    sieve();
    for (int i = 1; i < N; i++) {
        factorise(i, factors[i]);
    }
    for (int caseno = 1; caseno <= testcases; caseno++) {
        int n, m;
        cin >> n >> m;
        map<int, int> a;
        int mx = 0;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            a[x] = 1;
            mx = max(mx, x);
        }
        set<int> st;
        auto add = [&] (int x) {
            if (!a.count(x)) {
                return;
            }
            for (auto &y : factors[x]) {
                if (y > m) {
                    continue;
                }
                if (cnt[y] == 0) {
                    st.insert(y);
                }
                cnt[y]++;
            }
        };
        auto check = [&] (int x) {
            if (!a.count(x)) {
                return true;
            }
            for (auto &y : factors[x]) {
                if (y > m) {
                    continue;
                }
                if (cnt[y] <= 1) {
                    return false;
                }
            }
            return true;
        };
        auto remove = [&] (int x) {
            if (!a.count(x)) {
                return;
            }
            for (auto &y : factors[x]) {
                if (y > m) {
                    continue;
                }
                cnt[y]--;
            }
        };
        const int inf = 1e18L + 5;
        int ans = inf;
        int j = 1;
        for (int i = 1; i <= mx; i++) {
            add(i);
            while (j <= i && check(j)) {
                remove(j);
                j++;
            }
            if (st.size() == m) {
                ans = min(ans, i - j);
            }
        }
        while (j <= mx) {
            remove(j);
            j++;
        }
        cout << (ans < inf ? ans : -1) << '\n';
    }
    return 0;
}