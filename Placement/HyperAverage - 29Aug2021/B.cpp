#include <bits/stdc++.h>
using namespace std;

#define int int64_t
const int mod = 1e9 + 7; const int INF = 1e18L + 5; const int N = 2e5 + 5;

signed main()
{
    string s;
    cin >> s;

    int n = s.size();
    
    vector<int> idx[26];
    for(int i = 0; i < n; i++) {
        idx[s[i] - 'A'].emplace_back(i);
    }
    for(int i = 0; i < 26; i++) {
        idx[i].emplace_back(n);
    }
    
    int ans = INF;
    for(int i = n - 1; i >= 0; i--) {
        if(s[i] != 'A') continue;
        int j = i;
        for(int ch = 1; ch < 26; ch++) {
            if(j == n) break;
            j = *upper_bound(idx[ch].begin(), idx[ch].end(), j);
        }
        if(j != n) {
            ans = min(ans, j - i + 1);
        }
    }
    
    cout << ans << '\n';
    
    return 0;
}