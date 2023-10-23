#include "bits/stdc++.h"
using namespace std;

int main() {
#define int int64_t
    int n, m;
    cin >> n >> m;
    vector<int> b(n), c(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    int low = 0, high = 0;
    for (int i = 0; i < n; i++) {
        cin >> c[i];
        high = max(high, b[i] * c[i]);
    }
    while (low <= high) {
        int mid = (low + high) / 2;
        int need = 0;
        for (int i = 0; i < n; i++) {
            int max_b = mid / c[i];
            need += max(0LL, b[i] - max_b); 
        }
        if (need > m) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    cout << low;
    return 0;
#undef int
}