/**
 *    author:  Taara Sinh Aatrey
 *    created: 26.03.2021 10:04:53
**/

// #undef _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    map<int, int> mp;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        mp[x]++;
    }

    priority_queue<int> pq;

    for(auto& p: mp) {
        pq.emplace(p.second);
    }

    while(pq.size() > 1) {
        int f = pq.top();
        pq.pop();
        int s = pq.top();
        pq.pop();
        f--, s--;
        if(f > 0) 
            pq.emplace(f);
        if(s > 0)
            pq.emplace(s);
    }

    cout << (pq.empty() ? 0 : pq.top()) << '\n';
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        solve();
    }
    return 0;
}

