/**
 *    author:  Taara Sinh Aatrey
 *    created: 21.10.2022 07:34:16
**/

#include "bits/stdc++.h"

using namespace std;

#ifdef AATREY_DEBUG
#include "debug.hpp"
#else
#define dbg(...)
#endif

signed main() {
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]), --a[i];
    }
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        if (ans[i])
            continue;
        int j = i, cnt = 0;
        do {
            cnt++;
            j = a[j];
        } while (j != i);
        j = i;
        do {
            ans[j] = cnt;
            j = a[j];
        } while (j != i);
    }
    for (auto &x : ans) {
        cout << x << " ";
    }
    return 0;
}