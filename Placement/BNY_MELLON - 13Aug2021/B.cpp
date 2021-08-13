#include <bits/stdc++.h>
using namespace std;

#define int int64_t

int st(vector<int> diff, int low, int high) {
    int ways = 0, n = diff.size();
    
    for (int i = 0; i < n; i++) {
        diff[i] *= -1;
    }
    
    vector<int> pref(n + 1, 0);
    for (int i = 0; i < n; i++) {
        pref[i + 1] = pref[i] + diff[i];
    }
    
    int mini = *min_element(pref.begin(), pref.end());
    int maxi = *max_element(pref.begin(), pref.end());    
    int thigh = high - mini, tlow = low - mini;
    int tthigh = high - maxi, ttlow = low - maxi;

    if (tlow > ttlow) {
        swap(thigh, tthigh);
        swap(tlow, ttlow);
    }
    
    return max<int>(0, (min<int>(thigh, tthigh) - ttlow) + 1);
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    return 0;
}