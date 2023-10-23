#include "bits/stdc++.h"
using namespace std;

int main() {
#define int int64_t
    int n, k;
    cin >> n >> k;
    map<int, vector<pair<int, int>>> mp;
    for (int i = 0; i < n; i++) {
        int start, end, table;
        cin >> start >> end >> table;
        mp[table].emplace_back(end, start);
    }
    int ans = 0;
    for (auto it = mp.begin(); it != mp.end(); it++) {
        auto &vec = it->second;
        sort(vec.begin(), vec.end());
        int cur = 1;
        for (int i = 0; i < vec.size(); i++) {
            int end = vec[i].first, start = vec[i].second;
            if (start >= cur) {
                cur = end;
                ans++;
            }
        }
    }
    cout << ans;
    return 0;
#undef int
}