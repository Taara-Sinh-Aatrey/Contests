#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    while(T--) {

        string s;
        cin >> s;

        int ans = 0;
        for(int i = 0; s[i]; i++) {
            if(s[i] == '1' && (!s[i + 1] || s[i + 1] == '0')) {
                ans++;
            }
        }

        cout << ans << '\n';
    }
    

    return 0;
}