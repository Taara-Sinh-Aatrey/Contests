#include "bits/stdc++.h"
using namespace std;

#define int int64_t

signed main() {
    int t;
    cin >> t;
    while (t--) {
        int n, solar_cap, fuel;
        cin >> n >> solar_cap >> fuel;
        int solar = solar_cap;
        string sunlight;
        cin >> sunlight;
        int x = 0;
        for (; x < n; x++) {
            if (sunlight[x] == '1' && solar < solar_cap && fuel > 0) {
                fuel--;
                solar++;
            }
            else if (solar > 0) {
                solar--;
            }
            else if (fuel > 0) {
                fuel--;
            }
            else {
                break;
            }
        }
        cout << x << '\n';
    } 
    return 0;
}