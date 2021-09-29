#include "bits/stdc++.h"
using namespace std;

long carParkingRoof(vector<long> cars, int k) {
    sort(cars.begin(), cars.end());
    const long inf = 1e18L + 5;
    long ans = inf;
    for (int i = k - 1; i < cars.size(); i++) {
        ans = min(ans, cars[i] - cars[i + 1 - k] + 1);
    }
    return ans;
}

int main() {
    cout << carParkingRoof({2, 10, 8, 17}, 3);
    return 0;
}