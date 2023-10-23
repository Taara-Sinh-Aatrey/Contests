#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        cout << "Case #" << tt << ": ";
        vector<int> a(4);
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 4; j++) {
                int x;
                cin >> x;
                if (i == 0 || x < a[j]) {
                    a[j] = x;
                }
            }
        }
        vector<int> ans;
        int need = 1e6;
        for (int i = 0; i < 4; i++) {
            int take = min(need, a[i]);
            ans.emplace_back(take);
            need -= take;
        }
        if (need > 0) {
            cout << "IMPOSSIBLE\n";
            continue;
        }
        for (auto &x : ans) {
            cout << x << " ";
        }
        cout << '\n';
    }
    return 0;
}