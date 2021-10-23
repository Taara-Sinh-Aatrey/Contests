#include<bits/stdc++.h>
using namespace std;

#define int int64_t

int slotWheels(vector<string> spin) {
    int n = spin.size();
    int m = spin[0].size();
    vector<int> a[n];
    for (int i = 0; i < n; i++) {
        for (char &ch : spin[i]) {
            a[i].emplace_back(ch - '0');
        }
        sort(a[i].begin(), a[i].end());
    }
    int sum = 0;
    while(m--) {
        int mx = 0;
        for (int i = 0; i < n; i++) {
            mx = max(mx, a[i].back());
            a[i].pop_back();
        }
        sum += mx;
    }
    return sum;
}

signed main() {
    cout << slotWheels({"137", "364", "115", "724"}) << endl;
    cout << slotWheels({"712", "246", "365", "312"}) << endl;
    return 0;
}