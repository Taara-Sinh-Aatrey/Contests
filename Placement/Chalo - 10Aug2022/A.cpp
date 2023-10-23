#include "bits/stdc++.h"
using namespace std;


int solve(int n, int k, vector<int> a) {
#define int int64_t
const int inf = 1e17L + 50;
    sort(a.begin(), a.end(), greater<int>());
    reverse(a.begin(), a.end());
    function<int(int, int)> bs = [&] (int ll, int hh) -> int {
        if (ll > hh) return ll;
        int mid = (ll + hh) / 2;
        auto check = [&] () {       
            int last = -inf;
            int cnt = 0;
            for (auto &x : a) {
                if (last < x - mid) {
                    cnt++;
                    last = x + mid;
                }
            }
            return cnt <= k;
        };
        if (!check()) {
            return bs(mid + 1, hh);
        }
        else {
            return bs(ll, mid - 1);
        }
    };
    return bs(0, 1e9);
#undef int
}

int main() {
    cout << solve(6, 3, {9, 63, 22, 2, 15, 58});
    return 0;
}