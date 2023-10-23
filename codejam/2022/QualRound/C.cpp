#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        cout << "Case #" << tt << ": ";
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto &x : a) {
            cin >> x;
        }
        sort(a.begin(), a.end());
        int count = 0;
        for (int i = 0; i < n; i++) {
            count += count < a[i];
        }
        cout << count << '\n';
    }
    return 0;
}