/*
    
Dependencies:
Sieve

*/ 

// no of integers in [l, r] which are coprime with n
int coprime(int n, int l, int r) {
    vector<int> p;
    int num = n;
    while(num > 1) {
        int factor = spf[num];
        int cnt = 0;
        while(spf[num] == factor) {
            num /= spf[num];
            cnt++;
        }
        p.emplace_back(factor);
    }

    int sum = 0;
    for (int mask = 1; mask < 1 << p.size(); mask++) {
        int mult = 1, bits = 0;
        for (int i = 0; i < p.size(); i++)
            if (mask >> i & 1) {
                bits ^= 1;
                mult *= p[i];
            }

        int cur = r / mult - (l - 1) / mult;
        if (bits & 1) {
            sum += cur;
        }
        else {
            sum -= cur;
        }
    }

    return r - l + 1 - sum;
}
