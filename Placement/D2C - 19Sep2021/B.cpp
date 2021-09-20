#include "bits/stdc++.h"
using namespace std;

int main() {
    int num;
    cin >> num;
    int d = 0;
    int n = num;
    while(n > 0) {
        d++;
        n /= 10;
    }
    int ans= 0;
    for(int i = 1; i <= d; i += 2) {
        int cur = 9;
        for(int j = 2; j <= i; j++) {
            cur *= 10;
        }
        if(i == d) {
            cur /= 9;
            cur--;
            cur = num - cur;
        }
        ans += cur;
    }
    cout << ans << '\n';
    return 0;
}