#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

#define int int64_t
const int inf = 1e18L + 5, mod = 1e9 + 7, N = 2e5 + 5;

int solve (vector<int> A, int m) {
    int n = int(A.size());

    if(n < m) {
        return -1;
    }
    int low = *max_element(A.begin(), A.end()), high = 1e9;
    while(low <= high) {
        int mid = (low + high) / 2;
        int p = 1;
        int i = 0, cur = 0;
        while(i < n) {
            cur += A[i];
            if(cur > mid) {
                cur = A[i];
                p++;
            }
            i++;
        }
        if(p > m) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    return low;
}

signed main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int m;
        cin >> m;
        cout << solve(a, m) << '\n';
    }
    return 0;
}