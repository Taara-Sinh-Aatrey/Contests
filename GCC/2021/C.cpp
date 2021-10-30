 #include "bits/stdc++.h"
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
using namespace std;

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    int a[n], b[m];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    int ans = 0;
    int sum = 0;
    for (int i = 0, j = -1; i < n; i++) {
        sum += a[i];
        while (j >= 0 && sum > k) {
            sum -= b[j];
            j--;
        }
        while (j + 1 < m && sum + b[j + 1] <= k) {
            j++;
            sum += b[j];
        }
        if (sum > k) break;
        ans =  max(ans, i + j + 2);
    }
    cout << ans;
    return 0;
}