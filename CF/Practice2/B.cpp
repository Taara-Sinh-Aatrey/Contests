/**
 *    author:  Taara Sinh Aatrey
 *    created: 21.08.2022 23:32:46
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
    int n;
    cin >> n;
    map<int, int> cnt;
    bool ok = true;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        int x = s == "bronze" ? 1 : (s == "silver" ? 2 : 4);
        cnt[x]++;
        x--;
        while (x >= 2 && cnt[2] > 0) {
            x -= 2;
            cnt[2]--;
        }
        while (x >= 1 && cnt[1] > 0) {
            x--;
            cnt[1]--;
        }
        if (x != 0) {
            ok = false;
        }
    }
    cout << (ok ? "YES" : "NO") << '\n';
    return 0;
}