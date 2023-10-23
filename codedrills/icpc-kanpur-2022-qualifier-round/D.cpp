/**
 *    author:  Taara Sinh Aatrey
 *    created: 31.03.2023 12:23:15
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
    int n, k;
    cin >> n >> k;
    k /= 2;
    vector<int> a(n);
    for (auto &x : a) {
        cin >> x;
    }
    if (k == 0) {
        cout << 0;
        return 0;
    }
    const int inf = 1e18L + 5;
    int min_center = k, max_center = n - 1 - k;
    dbg(min_center, max_center);
    int ans = 0;
    vector<int> Leftmost_taken(2, inf);
    vector<int> Rightmost_taken(2, -inf);
    vector<int> Total_count(2, 0);
    map<int, int> count[2];
    for (int i = 0; i < n; i++) {
        if (i <= min_center) {
            continue;
        }
        
        map<int, int> &cnt = count[i % 2];
        int &leftmost_taken = Leftmost_taken[i % 2];
        int &rightmost_taken = Rightmost_taken[i % 2];
        int &total_count = Total_count[i % 2];
        
        int max_d = min(i - min_center, k);
        int min_d = max<int>(i - max_center, 1);
        int leftmost_possible = i - max_d * 2;
        int rightmost_possible = i - min_d * 2;
        
        if (leftmost_possible > leftmost_taken) {
            cnt[a[leftmost_taken]]--;
            total_count--;
            if (total_count == 0) {
                leftmost_taken = inf;
                rightmost_taken = -inf;
            }
            else {
                leftmost_taken = leftmost_possible;
            }
        }
        
        if (leftmost_possible < leftmost_taken) {
            cnt[a[leftmost_possible]]++;
            total_count++;
            leftmost_taken = leftmost_possible;
        }
        
        if (rightmost_possible > rightmost_taken) {
            if (rightmost_possible != leftmost_possible) {
                cnt[a[rightmost_possible]]++;
                total_count++;
            }
            rightmost_taken = rightmost_possible;
        }
        else if (rightmost_possible < rightmost_taken) {
            if (rightmost_taken > leftmost_taken) {                                 
                cnt[a[rightmost_taken]]--;
                total_count--;
                if (total_count == 0) {
                    leftmost_taken = inf;
                    rightmost_taken = -inf;
                }
            }
            rightmost_taken = rightmost_possible;   
        }
        
        dbg(leftmost_possible, rightmost_possible);
        ans += total_count - cnt[a[i]];
        dbg(i, total_count, a[i], cnt);
    }
    cout << ans;
    return 0;
}