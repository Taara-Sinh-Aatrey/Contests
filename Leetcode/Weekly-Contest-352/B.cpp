/**
 *    author:  Taara Sinh Aatrey
 *    created: 06.07.2023 11:04:57
**/

#include "bits/stdc++.h"

using namespace std;

#ifdef AATREY_DEBUG
#include "debug.hpp"
#else
#define dbg(...)
#endif

#define int int64_t

bool sieve_run = false;
const int N = 1e6 + 5;
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

class Solution {
public:
    vector<vector<int>> findPrimePairs(int n) {
        if (!sieve_run) {
            sieve();
            sieve_run = true;
        }
        vector<vector<int>> ans;
        for (int i = 2; i * 2 <= n; i++) {
            if (prime[i] && prime[n - i]) {
                ans.emplace_back(vector<int>{i, n - i});
            }
        }
        return ans;
    }
};

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    return 0;
}