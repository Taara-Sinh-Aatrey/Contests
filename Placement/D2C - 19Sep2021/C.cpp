#include "bits/stdc++.h"
using namespace std;

int main() {
    int n, m, x;
    cin >> n >> m >> x;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> b;
    for(int i = 0; i < n - 1; i++) {
        int ops = max( (abs(a[i+1]-a[i])+x-1) / x - 1, 0);
        m -= ops;
        if(m < 0) {
            cout << -1;
            return 0;
        }
        b.emplace_back(a[i]);
        while(ops--) {
            b.emplace_back(b.back() + (a[i + 1] > a[i] ? 1 : -1) * x);
        }
    }
    b.emplace_back(a.back());
    for(int i = 0; i < b.size(); i++) {
        cout << b[i] << " \n"[i + 1 == b.size()]; 
    }
    return 0;
}