#include<bits/stdc++.h>
using namespace std;

#define int long long

const char F = 'X', S = 'O', T = '_';

void solve(int tt) {
    vector<string> s(3);
    map<char, int> cnt;
    for(auto& st: s) {
        cin >> st;
        for(auto& ch: st) {
            cnt[ch]++;
        }
    }
    int diff = cnt[F] - cnt[S];

    map<char, bool> win;
    for(int i = 0; i < 3; i++) {
        if(s[i][0] == s[i][1] && s[i][1] == s[i][2] && s[i][0] != T) {
            win[s[i][0]] = true;
        }
        if(s[0][i] == s[1][i] && s[1][i] == s[2][i] && s[0][i] != T) {
            win[s[0][i]] = true;
        }
    }
    if(s[0][0] == s[1][1] && s[1][1] == s[2][2] && s[1][1] != T) {
        win[s[1][1]] = true;
    }
    if(s[0][2] == s[1][1] && s[1][1] == s[2][0] && s[1][1] != '_') {
        win[s[1][1]] = true;
    }

    bool invalid = (win[F] && win[S]) || diff > 1 || diff < 0;
    invalid |= (diff == 0 && win[F]) || (diff == 1 && win[S]);
    if(invalid) {
        cout << 3 << '\n';
        return;
    }

    if(win[F] || win[S] || cnt[T] == 0) {
        cout << 1 << '\n';
        return;
    }

    cout << 2 << '\n';
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