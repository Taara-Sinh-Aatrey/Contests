/**
 *    author:  Taara Sinh Aatrey
 *    created: 20.08.2022 17:31:51
**/

#include "bits/stdc++.h"

using namespace std;

#ifdef AATREY_DEBUG
#include "debug.hpp"
#else
#define dbg(...)
#endif

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.rbegin(), a.rend());
    a.resize(3);
    string ans = "";
    for (int first = 0; first < 3; first++) {
        for (int second = 0; second < 3; second++) {
            if (first == second) continue;
            int third = 0 + 1 + 2 - first - second;
            string s = to_string(a[first]) + to_string(a[second]) + to_string(a[third]);
            ans = max(ans, s); 
        }
    }
    cout << ans;
    return 0;
}