#include <bits/stdc++.h>
using namespace std;

template <typename T>
T inverse(T a, T m) {
    T mod = m;
    T u = 0, v = 1;
    while (a != 0) {
        T t = m / a;
        m -= t * a; swap(a, m);
        u -= t * v; swap(u, v);
    }
    assert(m == 1);
    if(u < 0) {
        u += mod;
    }
    return u;
}

// encrypts given plaintext into ciphertext using given apphine cipher pair
string encrypt(string s, int k1, int k2) {
    string t;
    for(int i = 0; i < s.size(); i++) {
        t += char('a' + ((s[i] - 'a') * k1 + k2) % 26);
    }
    return t;
}

// decrypts given ciphertext into plaintext using given apphine cipher pair
string decrypt(string s, int k1, int k2) {
    string t;
    for(int i = 0; i < s.size(); i++) {
        t += char('a' + ((s[i] - 'a' - k2 + 26) % 26 * inverse(k1, 26)) % 26);
    }
    return t;
}

// finds value of apphine cipher pair using a known pair of (plaintext, ciphertext)
pair<int, int> learn(string s, string t) {
    assert(s.size() == t.size());
    for (int k1 = 0; k1 < 26; k1++) {
        for (int k2 = 0; k2 < 26; k2++) {
            bool ok = true;
            for (int i = 0; i < s.size(); i++) {        
                if(t[i] != char('a' + ((s[i] - 'a') * k1 + k2) % 26)) {
                    ok = false;
                    break;
                }
            }
            if (ok) return pair(k1, k2);
        }
    }
    assert(false);
}


void solve() {
    // learn k1 and k2 from a known pair of (plaintext, ciphertext)
    auto [k1, k2] = learn("cjqv", "abcz");
    
    // now use the known value of k1 and k2 for encryption and decryption
    cout << encrypt("hello", k1, k2) << '\n';
    cout << decrypt("xeffy", k1, k2) << '\n';
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;

    for (int tt = 1; tt <= t; tt++) {
        solve();
    }
    
    return 0;
}