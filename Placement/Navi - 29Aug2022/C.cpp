#include "bits/stdc++.h"
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int low = 0, high = n / 2;
    while (low <= high) {
        int mid = (low + high) / 2;
        bool ok = true;
        for (int i = 0, j = n - mid; i < mid; i++, j++) {
            ok &= a[j] >= a[i] + k;
        }
        if (ok) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    cout << high << '\n';
    return 0;
}