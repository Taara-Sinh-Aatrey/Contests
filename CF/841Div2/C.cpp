/**
 *    author:  Taara Sinh Aatrey
 *    created: 28.12.2022 13:54:57
**/

#include "bits/stdc++.h"

using namespace std;

#ifdef AATREY_DEBUG
#include "debug.hpp"
#else
#define dbg(...)
#endif

#define int int64_t

const int N = 262144;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> perfect_squares;
    for (int i = 0; i * i < N; i++) {
        perfect_squares.emplace_back(i * i);
    }
    int testcases;
    cin >> testcases;
    for (int caseno = 1; caseno <= testcases; caseno++) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto &x : a) {
            cin >> x;
        }
        vector<int> cnt(2 * n + 1);
        cnt[0] = 1;
        int Xor = 0;
        int ans = n * (n + 1) / 2;
        for (int i = 0; i < n; i++) {
            Xor ^= a[i];
            for (auto &ps : perfect_squares) {
                int nXor = Xor ^ ps;
                if (nXor <= 2 * n)
                    ans -= cnt[nXor];
            }
            cnt[Xor]++;
        }
        cout << ans << '\n';
    }
    return 0;
}