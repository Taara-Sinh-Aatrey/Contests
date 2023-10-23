#include "bits/stdc++.h"
using namespace std;

long long solve(long long n, vector<string> A) {
    #define int int64_t
    map<char, int> coeffs;
    map<char, bool> f;
    set<char> st;
    int ans = 0;
    for (auto &s : A) {
        reverse(s.begin(), s.end());
        if (isalpha(s.back()))
            f[s.back()] = true;
        int p = 1;
        for (auto &ch : s) {
            if (isalpha(ch)) {
                st.emplace(ch);
                coeffs[ch] += p;
            }
            else {
                ans += (ch - '0') * p;
            }
            p *= 10;
        }
    }
    vector<pair<int, char>> co;
    for (auto &[ch, coeff] : coeffs) {
        co.emplace_back(coeff, ch);
    }
    pair<int, int> p;
    sort(co.begin(), co.end());
    for (auto &[coeff, ch] : co) {
        if (!f.count(ch)) {
            p = {coeff, ch};
        }
    }
    int d = st.size() == f.size() ? st.size() : (st.size() - 1);
    for (auto &[coeff, ch] : co) {
        if (ch == p.second && st.size() != f.size()) {
            continue;
        }
        ans += d * coeff;
        d--;
    }
    return ans;
#undef int
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << solve(2, {"A1A", "2AB"}) << '\n';
    cout << solve(3, {"CB", "BC", "BAB"}) << '\n';
    cout << solve(3, {"A1A3", "AAB", "BD1"}) << '\n';
    return 0;
}