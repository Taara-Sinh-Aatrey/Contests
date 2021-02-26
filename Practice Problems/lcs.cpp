#include<bits/stdc++.h>
using namespace std;

string s, t;
int n, m;

// returns {no of common subsequence, set of common subseuences} of length l
pair<int, vector<pair<string, int>>> brute(int l) {
    auto count_frequency = [&](string S, int N) { 
        map<string, int> mp;
        for(int mask = 0; mask < (1 << N); mask++) {
            if(__builtin_popcount(mask) != l) continue;
            string cand = "";
            for(int i = 0; i < N; i++) {
                if(mask >> i & 1) {
                    cand += S[i];
                }
            }
            mp[cand]++;
        }
        return mp;
    };
    map<string, int> mp1 = count_frequency(s, n), mp2 = count_frequency(t, m);
    vector<pair<string, int>> AllStrings;
    int ret = 0;
    for(auto p: mp1) {
        int cur = p.second * mp2[p.first];
        if(cur == 0) continue;
        ret += cur;
        AllStrings.push_back(make_pair(p.first, cur));
    }
    return make_pair(ret, AllStrings);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    auto add = [&](pair<int, int> a, pair<int, int> b) {
        if(a < b) {
            swap(a, b);
        }
        if(a.first == b.first) {
            a.second += b.second;
        }
        return a;
    };

    auto sub = [&](pair<int, int> a, pair<int, int> b) {
        assert(a >= b);
        if(a.first == b.first) {
            a.second -= b.second;
        }
        return a;
    };

    cin >> s >> t;
    n = s.length(), m = t.length();
    vector<vector<pair<int, int>>> dp(n + 1, vector<pair<int, int>>(m + 1, make_pair(0, 1)));
    // dp[i][j].first is the length of lcs(i, j) and dp[i][j].second is the number of such strings

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(s[i - 1] == t[j - 1]) {
                dp[i][j] = {dp[i - 1][j - 1].first + 1, dp[i - 1][j - 1].second};
                dp[i][j] = add(dp[i][j], dp[i - 1][j]);
                dp[i][j] = add(dp[i][j], dp[i][j - 1]);
            } else {
                dp[i][j] = add(dp[i - 1][j], dp[i][j - 1]);
                dp[i][j] = sub(dp[i][j], dp[i - 1][j - 1]);
            }
        }
    }

    // assert to make sure that dp[n][m].second == brute(dp[n][m].first)
    auto [NoOfSub, AllStrings] = brute(dp[n][m].first);
    assert(dp[n][m].second == NoOfSub);

    // printing length of lcs(n, m) and number of such strings
    cout << "Length of LCS : " << dp[n][m].first << "\n";
    cout << "No of distinct LCS : " << (int) AllStrings.size() << '\n';
    cout << "Total no of LCS : " << NoOfSub << "\n";

    cout << "\nList of all LCS and its frequency :- \n";
    for(auto [a, f]: AllStrings) {
        cout << a << " " << f << "\n";
    }
}