#include <bits/stdc++.h>
using namespace std;

void solve() {
    vector<string> bitcoins = {"DOGECOIN", "SOLANA",  "XRP",    "ETHEREUM",
                               "TETHER",   "BITCOIN", "BINANCE"};
    string str;
    cin >> str;
    vector<int> total(26, 0);
    for (auto &ch : str) {
        total[ch - 'A']++;
    }
    for (auto &bitcoin : bitcoins) {
        vector<int> cnt(26, 0);
        for (auto &ch : bitcoin) 
            cnt[ch - 'A']++;
        int mn = 1e9 + 5;
        for (int ch = 0; ch < 26; ch++) {
            if (cnt[ch] == 0) continue;
            mn = min(mn, total[ch] / cnt[ch]);
        }
        for (int ch = 0; ch < 26; ch++) {
            total[ch] -= mn * cnt[ch];
        }
        cout << mn << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}