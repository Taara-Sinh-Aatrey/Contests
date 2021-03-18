#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for(auto &x: a) {
            cin >> x;
        }
        sort(a.begin(), a.end());

        int steps = 0;
        bool valid = true;
        for(int i = 0; i < n; i++) {
            if(a[i] > i + 1) {
                valid = false;
                break;
            }
            steps += i + 1 - a[i];
        }

        cout << (steps % 2 && valid ? "First" : "Second") << '\n';
    }

    return 0;
}