/**
 *    author:  Taara Sinh Aatrey
 *    created: 21.08.2022 09:22:41
**/

#include "bits/stdc++.h"

using namespace std;

#ifdef AATREY_DEBUG
#include "debug.hpp"
#else
#define dbg(...)
#endif


int main() {
#define int int64_t
    ios::sync_with_stdio(0);
    cin.tie(0);
    int testcases;
    cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++) {
        cout << "Case #" << tt << ": ";
        auto fun = [&] (string &s) {
            int n = s.size();
            string t = s;
            reverse(t.begin(), t.end());
            const int p = 31;
            const int m = 1e9 + 9;
            int hash_value = 0;
            int p_pow = 1;
            vector<int> Hash(n + 1);
            for (int i = 0; i < n; i++) {
                hash_value = (hash_value + (t[i] - 'a' + 1) * p_pow) % m;
                Hash[i + 1] = hash_value;
                p_pow = (p_pow * p) % m;
            }
            vector<bool> palindrome(n + 1);
            hash_value = 0;
            int ans = n;
            for (int i = n - 1; i > 0; i--) {
                int len = n - i;
                hash_value = ((hash_value * p % m) + (s[i] - 'a' + 1) % m) % m;
                if (Hash[len] == hash_value) {
                    palindrome[len] = true;
                }
            }
            return palindrome;
        };
        int n;
        cin >> n;
        string s;
        cin >> s;
        auto p1 = fun(s);
        string t = s;
        reverse(t.begin(), t.end());
        auto p2 = fun(t);
        int ans = n;
        for (int len = 1; len <= n; len++) {
            if (p1[len] && p2[n - len]) {
                ans = min(ans, n - len);
            }
        }
        for (int i = ans - 1; i >= 0; i--) {
            cout << t[i];
        }
        cout << '\n';
    }
    return 0;
#undef int
}