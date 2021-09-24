#include "bits/stdc++.h"
using namespace std;

signed main() {
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    vector<int> cost(26);
    for (int i = 0; i < 26; i++) {
        cin >> cost[i];
    }
    int ans = 0;
    for(int free = 0; free < 26; free++) {
        int temp = cost[free];
        cost[free] = 0;
        int j = 0;
        int cur = 0;
        for (int i = 0; i < n; i++) {
            cur += cost[s[i] - 'a'];
            while(cur > m) {
                cur -= cost[s[j] - 'a'];
                j++;
            }
            ans = max(ans, i - j + 1);
        }
        cost[free] = temp;
    }
    cout << ans << '\n';
    return 0;
}