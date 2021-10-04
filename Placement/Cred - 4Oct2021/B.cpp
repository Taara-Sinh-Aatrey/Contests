#include "bits/stdc++.h"
using namespace std;

int perfectSubstring(string s, int k) {
    int n = s.size();
    int ans = 0;
    vector<vector<int>> occ(10);
    vector<int> start(n, -1);
    vector<int> masks(n, -1);
    for (int i = 0; i < n; i++) {
        int d = s[i] - '0';
        occ[d].emplace_back(i);
        if (occ[d].size() < k) continue;
        int j = occ[d][occ[d].size() - k];
        int mask = 1 << d;
        int taken_cnt = 1;
        bool ok = true;
        while (true) {
            int new_mask = 0;
            for (int d2 = 0; d2 < 10; d2++) {
                if (!(mask >> d2 & 1) && !occ[d2].empty() && occ[d2].back() > j) {
                    new_mask |= 1 << d2;
                    if (occ[d2].size() < k) {
                        ok = false;
                        break;
                    }
                    j = min(j, occ[d2][occ[d2].size() - k]);
                }
            }
            if (!ok) break;
            if (new_mask == 0) break;
            mask |= new_mask;
        }
        if (!ok || __builtin_popcount(mask) * k != (i - j + 1)) continue;
        start[i] = j;
        masks[i] = mask;
        
        int mask_so_far = 0;
        int end = i;
        while (end >= 0 && start[end] >= 0 && (mask_so_far & masks[end]) == 0) {
            ans++;
            mask_so_far |= masks[end];
            end = start[end] - 1;
        }
    }
    return ans;
}

int main() {
    cout << perfectSubstring("01001", 1) << endl;
    return 0;
}