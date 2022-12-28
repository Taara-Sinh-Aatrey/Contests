/**
 *    author:  Taara Sinh Aatrey
 *    created: 18.12.2022 02:11:27
**/

#include "bits/stdc++.h"

using namespace std;

#ifdef AATREY_DEBUG
#include "debug.hpp"
#else
#define dbg(...)
#endif

#define int int64_t

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int testcases;
    cin >> testcases;
    for (int caseno = 1; caseno <= testcases; caseno++) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int sum = s[0] - '0';
        for (int i = 1; i < n; i++) {
            int ch = s[i] - '0';
            if (sum == 1) {
                cout << '-';
                sum -= ch;
            }
            else {
                cout << '+';
                sum += ch;
            }
        }
        cout << '\n';
    }
    return 0;
}