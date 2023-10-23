vector<int> spf(N, 0);
vector<int> unique_primes(N, 0);
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
    for(int i = 2; i < N; i++) {
        int p = spf[i];
        unique_primes[i] = unique_primes[i / p] + ((i / p) % p != 0);
    }
}

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