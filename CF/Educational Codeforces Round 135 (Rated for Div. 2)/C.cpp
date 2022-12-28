#include "bits/stdc++.h"
using namespace std;

#ifdef AATREY_DEBUG
#include "debug.hpp"
#else
#define dbg(...)
#endif

int solve(vector<int> &a, int b) {
#define int int64_t
    int n = a.size();
    int suff = n - 1;
    while (suff - 1 >= 0 && abs(a[suff - 1] - a[suff]) <= b) {
        suff--;
    }
    int pref = 0;
    while (pref + 1 < n && abs(a[pref + 1] - a[pref]) <= b) {
        pref++;
    }
    const int inf = 1e9 + 5;
    vector<pair<int, int>> inc, dec;
    int ans = n - 1;
    for (int i = n - 1; i >= 0; i--) {
        if (i <= pref) {
            int j = inf;
            int h = a[i] + b;
            auto it = lower_bound(inc.rbegin(), inc.rend(), pair<int, int>(a[i], -1));
            if (it != inc.rend() && it->first <= h) {
                j = min(j, it->second);
            }
            int l = a[i] - b;
            auto jt = upper_bound(dec.begin(), dec.end(), pair<int, int>(a[i], inf));
            if (jt != dec.begin() && prev(jt)->first >= l) {
                jt = prev(jt);
                j = min(j, jt->second);
            }
            if (j != inf) {
                ans = min(ans, j - i - 1);
            }
        }
        
        if (i >= suff) {
            while (!inc.empty() && inc.back().first <= a[i]) {
                inc.pop_back();
            }
            inc.emplace_back(a[i], i);
            //     i+5    i+3     i
            //          <      <
            while (!dec.empty() && dec.back().first >= a[i]) {
                dec.pop_back();
            }
            dec.emplace_back(a[i], i);
            //     i+5    i+3    i
            //          >      >
        }
    }
    return ans;
    return 0;
#undef int
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int b;
    cin >> b;
    cout << solve(a, b) << endl;
    return 0;
}