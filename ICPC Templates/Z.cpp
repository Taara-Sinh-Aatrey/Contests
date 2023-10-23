vector<int> p_pow, invp_pow;
// Polynomial Rolling Hash
class Hash {
public:
    const int p = 31;
    const int invp = 838709685;
    const int mod = 1e9 + 9;
    int n;
    string s;
    vector<int> h;

    Hash (string _s) : s(_s) {
        assert(invp * 1LL * p % mod == 1);
        n = s.size();
        if (p_pow.empty()) {
            p_pow.resize(1, 1);
            invp_pow.resize(1, 1);
        }
        while (p_pow.size() < n) {
            p_pow.emplace_back(p_pow.back() * 1LL * p % mod);
            invp_pow.emplace_back(invp_pow.back() * 1LL * invp % mod);
        }
        compute_hash();
    }

    void compute_hash() {
        h.resize(n);
        for (int i = 0; i < n; i++) {
            h[i] = ((i > 0 ? h[i - 1] : 0) + (s[i] - 'a' + 1) * 1LL * p_pow[i]) % mod;
        }
    }

    int get (int i = 0, int j = -1) {
        if (j == -1) 
            j = n - 1;
        return (h[j] - (i > 0 ? h[i - 1] : 0) + mod) * 1LL *  invp_pow[i] % mod;
    }

};