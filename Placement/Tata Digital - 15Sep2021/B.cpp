#include "bits/stdc++.h"
using namespace std;

int main() {
    string S;
    getline(cin, S);
    int ans = 0;
    int last = 0;
    for(int i = 0; i <= S.size(); i++) {
        if(i == S.size() || S[i] == ' ') {
            if(last != i) {
                string s = S.substr(last, i - last);
                bool ok = true;
                for(int i = 0; i < s.size(); i++) {
                    if(s[i] == '-' || isalpha(s[i]) || (i + 1 == s.size() && (s[i] == ',' || s[i] == '.' || s[i] == '?' || s[i] == '!'))) {
                        continue;
                    }
                    ok = false;
                    break;
                }
                ans += ok;
            }
            last = i + 1;
        }
    }
    cout << ans;
}