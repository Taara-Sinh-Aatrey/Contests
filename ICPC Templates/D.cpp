// Code of fft taken from https://cp-algorithms.com/algebra/fft.html
// And modified as per my use 

ll primeRoot(ll p = mod, ll x = 0) {
    vll v;
    ll t = p - 1;
    for (ll i = 2; i <= t; i++) {
        if (i * i > t) {
            break;
        }
        if (t % i == 0) {
            v.pb((p - 1) / i);
            while (t % i == 0) {
                t /= i;
            }
        }
    }
    if (t > 1) {
        v.pb((p - 1) / t);
    }
    for (ll i = x + 1; i < p; i++) {
        ll flag = 0;
        for (ll j = 0; j < (ll)v.size(); j++) {
            if (powerM(i, v[j], p) == 1) {
                flag = 1;
                break;
            }
        }
        if (flag == 0) {
            return i;
        }
    }
    return 0;
}

void fft(vector<int> & a, bool invert) {
    int n = a.size();
    // assert((n & (n - 1)) == 0);
    // in other words n is power of 2
    // We write mod = c. 2^k + 1
    // So this fft function works only if input size <= 2 ^ k
    // for mod = 998244353, k = 23, so input size can be as large as 8e6
    // assert((mod - 1) % n == 0);
    // root is nth root of unity under primitive field of mod
    // root = g ^ (mod - 1) / n, for mod = 998244353, g = 3 works well
    int root = Pow(3, (mod - 1) / n);
    int inv = Pow(root, mod - 2);
    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1)
            j ^= bit;
        j ^= bit;

        if (i < j)
            swap(a[i], a[j]);
    }

    for (int len = 2; len <= n; len <<= 1) {
        int wlen = invert ? inv : root;
        for (int i = len; i < n; i <<= 1)
            wlen = wlen * wlen % mod;

        for (int i = 0; i < n; i += len) {
            int w = 1;
            for (int j = 0; j < len / 2; j++) {
                int u = a[i+j], v = a[i+j+len/2] * w % mod;
                a[i+j] = u + v < mod ? u + v : u + v - mod;
                a[i+j+len/2] = u - v >= 0 ? u - v : u - v + mod;
                w = w * wlen % mod;
            }
        }
    }

    if (invert) {
        int n_1 = Pow(n, mod - 2);
        for (int & x : a) {
            x = x * n_1 % mod;
        }
    }
}

void multiply(vector<int> const& a, vector<int> const& b, vector<int> &c) {
    // c = a * b
    vector<int> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;
    while (n < (int) a.size() + (int) b.size()) 
        n <<= 1;
    fa.resize(n);
    fb.resize(n);
    c.resize(n);

    fft(fa, false);
    fft(fb, false);
    for (int i = 0; i < n; i++)
        c[i] = fa[i] * fb[i] % mod;
    fft(c, true);
}