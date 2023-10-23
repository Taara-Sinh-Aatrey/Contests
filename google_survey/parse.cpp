/**
 *    author:  Taara Sinh Aatrey
 *    created: 14.07.2023 11:54:00
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
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    getline(cin, s);
    cout << s << endl;
    int n = s.size();
    int i = 0;
    while (i < n) {
        while (i < n && s.substr(i, 6) != "<span>") {
            i++;
        }
        i += 6;
        int j = i;
        while (j < n && s.substr(j, 7) != "</span>") {
            j++;
        }
        if (j < n) cout << s.substr(i, j - i) << endl;
        i = j + 7;
    }
    return 0;
}