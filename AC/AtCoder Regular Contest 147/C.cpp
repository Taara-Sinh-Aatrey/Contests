/**
 *    author:  Taara Sinh Aatrey
 *    created: 04.09.2022 18:20:18
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
    const int inf = 1e18L + 5;
    int n;
    cin >> n;
    int low = inf, high = -inf;
    vector<pair<int, int>> ranges(n);
    map<int, vector<int>> Ys;
    map<int, int> save;
    for (auto &[x, y] : ranges) {
        cin >> x >> y;
        low = min(low, x);
        high = max(high, y);
        Ys[x].emplace_back(y);
    }
    auto check = [&] (int median) {
        if (save.count(median)) {
            return save[median];
        }
        int ans = 0;
        map<int, int> freq;
        for (auto &[l, r] : ranges) {
            if (l <= median && median <= r) {
                freq[median]++;
            }
            else if (r < median) {
                freq[r]++;
            }
            else {
                freq[l]++;
            }
        }
        int pref_cnt = 0, pref_sum = 0;
        for (auto &[idx, cnt] : freq) {
            ans += (idx * pref_cnt - pref_sum) * cnt;
            pref_cnt += cnt;
            pref_sum += idx * cnt;
        }
        return save[median] = ans;
    };
    int cur = check(low);
    int best = cur;
    multiset<int> ms;
    int left = 0;
    int right = n;
    for (int y : Ys[low]) {
        ms.emplace(y);
        left++;
        right--;
    }
    for (int median = low + 1; median <= high; median++) {
        while (!ms.empty() && *ms.begin() < median) {
            ms.erase(ms.begin());
        }
        // dbg(left, ms.size(), right);
        cur += (left - ms.size()) * ms.size();
        cur -= right * ms.size();
        // dbg(median, cur, check(median));
        best = min(best, cur);
        for (int y : Ys[median]) {
            ms.emplace(y);
            left++;
            right--;
        }
    }
    cout << best;
    /*
    POC
    const int N = 1e2 + 1;
    vector<int> b(N);
    for (int i = 0; i < N; i++) {
        b[i] = check(i);
    }
    int i = 0;
    while (i + 1 < N && b[i + 1] <= b[i]) {
        i++;
    }
    int j = N - 1;
    while (j - 1 >= 0 && b[j - 1] <= b[j]) {
        j--;
    }
    assert(j <= i);
    */
    // int best = inf;
    // while (high - low >= 3) {
    //     int mid1 = low + (high - low) / 3;
    //     int mid2 = high - (high - low) / 3;
    //     int val1 = check(mid1);
    //     int val2 = check(mid2);
    //     best = min({best, val1, val2});
    //     if (val1 < val2) {
    //         high = mid2;
    //     }
    //     else {
    //         low = mid1;
    //     }
    // }
    // for (int x = low; x <= high; x++) {
    //     best = min(best, check(x));   
    // }
    // cout << best;
    return 0;
}
// (2/3)^x * 3e5 < 3