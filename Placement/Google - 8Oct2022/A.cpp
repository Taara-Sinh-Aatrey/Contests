/**
 *    author:  Taara Sinh Aatrey
 *    created: 08.10.2022 14:22:45
**/

#include "bits/stdc++.h"

using namespace std;

#ifdef AATREY_DEBUG
#include "debug.hpp"
#else
#define dbg(...)
#endif


long long solve(int n, long long m, vector<long long> A) {
#define int long long
    int low = 1, high = *max_element(A.begin(), A.end());
    while (low <= high) {
        int mid = (low + high) / 2;
        int req = 0;
        for (auto &x : A) {
            req += (x + mid - 1) / mid;
        }
        if (req <= m) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    } 
    return low;   
#undef int
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // cout << solve(4, 5, {5, 6, 3, 8}) << '\n';
    // cout << solve(3, 6, {3, 4, 5}) << '\n';
    // cout << solve(4, 5, {10, 5, 6, 2}) << '\n';
    cout << solve(2, 11, {6, 1}) << '\n';
    return 0;
}