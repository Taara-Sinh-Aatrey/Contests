#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve(int tt) {
    string s;
    cin >> s;

    int n = (int) s.length();

    if(*min_element(s.begin(), s.end()) == *max_element(s.begin(), s.end())) {
        cout << (char) (s[0] ^ '0' ^ '1') << '\n';
        return;
    }

    string ans = "";
    vector<bool> changeable;

    int i = 0;
    while(i < n && s[i] == '0') i++;

    assert(i < n);
    ans += "1";
    changeable.push_back(0);

    i++;

    while(i <= n) {
        if(i == n) {
            ans += "0";
            changeable.push_back(0);
            break;
        }

        int j = i;
        while(j < n && s[j] == s[i]) {
            j++;
        }

        if(j == n || j - i > 1) {
            ans += (char) (s[i] ^ '0' ^ '1');
            changeable.push_back(0);
        } else {
            ans += s[j];
            changeable.push_back(1);
        }

        i = j + 1;
    }
    
    n = (int) ans.length();

    for(int i = n - 1; i >= 0; i--) {
        if(ans[i] == '1' && changeable[i] && ans[i + 1] != '1') {
            ans[i] = '0';
        }
    }

    cout << ans << '\n';

}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    for(int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
    

    return 0;
}

/*

    1 01 01 01

    4 length string

    1 0/1 0/1 0/1

    input : 10001011101101

    1 0001 01 110 110 1
    1  1    1  0   0  0

    All 5 length strings are possible

    6 length string is the answer

    111000
      *






*/