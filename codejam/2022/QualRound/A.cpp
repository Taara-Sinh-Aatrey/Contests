#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        cout << "Case #" << tt << ":\n";
        int r, c;
        cin >> r >> c;
        for (int i = 0; i <= 2 * r; i++) {
            for (int j = 0; j <= 2 * c; j++) {
                if (i <= 1 && j <= 1) {
                    cout << '.';
                    continue;
                }
                if (i % 2 == 0) {
                    cout << (j % 2 == 0 ? '+' : '-');
                }
                else {
                    cout << (j % 2 == 0 ? '|' : '.');
                }
            }
            cout << '\n';
        } 
    }
    return 0;
}