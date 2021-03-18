#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, H, x;
    cin >> n >> H >> x;

    vector<int> a(n);
    for(auto& ele: a) {
        cin >> ele;
    }

    cout << (x + *max_element(a.begin(), a.end()) >= H ? "YES" : "NO") << '\n';    

    return 0;
}