#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const ll mod = 998244353;

ll power(ll a, ll b){
    ll ans = 1;
    while(b > 0) {
        if(b % 2 == 1) {
            ans = ans * a % mod;
        }
        a = a * a;
        a %= mod;
        b /= 2;
    }
    return ans;
}

// This code has been taken from https://cp-algorithms.com/algebra/fft.html

void fft(vector<ll> & a, bool invert) {
    ll n = a.size();
    // assert((n & (n - 1)) == 0);
    // in other words n is power of 2
    // We write mod = c. 2^k + 1
    // So this fft function works only if input size <= 2 ^ k
    // for mod = 998244353, k = 23, so input size can be as large as 8e6
    // assert((mod - 1) % n == 0);
    // root is nth root of unity under primitive field of mod
    // root = g ^ (mod - 1) / n, for mod = 998244353, g = 3 works well
    ll root = power(3, (mod - 1) / n);
    ll inv = power(root, mod - 2);
    for (ll i = 1, j = 0; i < n; i++) {
        ll b = n >> 1;
        for (; j & b; b >>= 1)
            j ^= b;
        j ^= b;

        if (i < j)
            swap(a[i], a[j]);
    }

    for (ll len = 2; len <= n; len <<= 1) {
        ll wlen = invert ? inv : root;
        for (ll i = len; i < n; i <<= 1)
            wlen = wlen * wlen % mod;

        for (ll i = 0; i < n; i += len) {
            ll w = 1;
            for (ll j = 0; j < len / 2; j++) {
                ll u = a[i+j], v = a[i+j+len/2] * w % mod;
                a[i+j] = u + v < mod ? u + v : u + v - mod;
                a[i+j+len/2] = u - v >= 0 ? u - v : u - v + mod;
                w = w * wlen % mod;
            }
        }
    }

    if (invert) {
        ll n_1 = power(n, mod - 2);
        for (ll & x : a) {
            x = x * n_1 % mod;
        }
    }
}

vector<ll> multiply(vector<ll> const& a, vector<ll> const& b) {
    vector<ll> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    ll n = 1;
    while (n < (ll) a.size() + (ll) b.size()) 
        n <<= 1;
    fa.resize(n);
    fb.resize(n);

    fft(fa, false);
    fft(fb, false);
    for (ll i = 0; i < n; i++)
        fa[i] = fa[i] * fb[i] % mod;
    fft(fa, true);
    return fa;
}
    
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n; cin >> n;
    vector<ll> cnt(30, 0), ans(n + 1, 0), fac(n + 1, 0), inv(n + 1, 0);
    fac[0] = 1; inv[0] = 1;

    for(ll i = 1; i <= n; i++) {
        fac[i] = (i * fac[i - 1]) % mod;
        inv[i] = power(fac[i], mod - 2);
    }

    auto choose = [&](ll N, ll R) {
        if(N < R) {
            return 0LL;
        }
        return fac[N] * inv[R] % mod * inv[N - R] % mod;
    };

    for(ll i = 0; i < n; i++) {
        ll num; cin >> num;
        for(ll b = 0; b < 30; b++) {
            if(num >> b & 1) {
                cnt[b]++;
            }
        }
    }

    for(ll b = 0; b < 30; b++) {
        ll set_bit = cnt[b];
        ll unset_bit = n - set_bit;
        if(set_bit == 0) {
            continue;
        }
        ll z = power(2, b);
        vector<ll> A(set_bit + 1), B(unset_bit + 1);

        for(ll i = 1; i <= set_bit; i++) {
            if(i % 2 == 0) {
                A[i] = 0;
            } else {
                A[i] = z * choose(set_bit, i) % mod;
            }
        }
        for(ll i = 0; i <= unset_bit; i++) {
            B[i] = choose(unset_bit, i);
        }

        auto c = multiply(A, B);
        for(ll i = 0; i <= n; i++) {
            ans[i] += c[i];
        }
    }

    vector<ll> pref(n + 1, 0);

    for(ll i = 1; i <= n; i++) {
        pref[i] = pref[i - 1] + ans[i];
        pref[i] %= mod;
    }

    ll q, m; cin >> q;
    for(int i = 0; i < q; i++) {
        cin >> m; cout << pref[m] << endl ;
    }

    return 0;
}

