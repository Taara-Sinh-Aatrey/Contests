#include "bits/stdc++.h"
using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    vector<int> starting_index;
    for (int i = 0; i < n; i++) {
        starting_index.emplace_back(s.size());
        string t;
        cin >> t;
        s += t;   
    }
    int q;
    cin >> q;
    while(q--) {
        int l, r, k;
        cin >> l >> r >> k;
        --l, --r, --k;
        cout << s[starting_index[l] + k] << '\n';
    }
}