#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> a[3], n(3);

    for(int i = 0; i < 3; i++) {
        cin >> n[i];
    }

    for(int i = 0; i < 3; i++) {
        
        a[i].resize(n[i]);

        for(auto &x: a[i]) {
            cin >> x;
        }

        reverse(a[i].begin(), a[i].end());
        a[i].insert(a[i].begin(), 0);

        for(int j = 1; j <= n[i]; j++) {
            a[i][j] += a[i][j - 1];
        }
    }

    const int INF = 1e9;
    while(true) {
        int mn = INF;
        for(int i = 0; i < 3; i++) {
            assert(!a[i].empty());
            if(a[i].back() < mn) {
                mn = a[i].back();
            }
        }
        bool ok = true;
        for(int i = 0; i < 3; i++) {
            while(a[i].back() > mn) {
                a[i].pop_back();
            }
            if(a[i].back() != mn) {
                ok = false;
            }
        }
        if(ok) {
            cout << mn;
            return 0;
        }
    }

    assert(false);


    return 0;
}   