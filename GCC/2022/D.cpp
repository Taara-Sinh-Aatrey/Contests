/**
 *    author:  Taara Sinh Aatrey
 *    created: 21.10.2022 06:25:42
**/

#include "bits/stdc++.h"

using namespace std;

#ifdef AATREY_DEBUG
#include "debug.hpp"
#else
#define dbg(...)
#endif

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    string names[n];
    for (auto &name : names) {
        cin >> name;
    }
    map<int, set<string>> people;
    const int inf = 1e18L + 5;
    int mn = inf, mx = -inf;
    for (int i = 0; i < n; i++) {
        int start, end;
        cin >> start >> end;
        mn = min(mn, start);
        mx = max(mx, end);
        for (int x = start; x < end; x++) {
            people[x].emplace(names[i]);
        }
    }
    for (int x = mn; x < mx; x++) {
        if (!people.count(x)) {
            people[x] = {};
        }
    }
    int cnt = 0;
    for (map<int, set<string>>::iterator it = people.begin(), jt; it != people.end(); it = jt) {
        jt = it;
        while (jt != people.end() && it->second == jt->second) {
            jt++;
        }
        cnt++;
    }
    cout << cnt << '\n';
    for (map<int, set<string>>::iterator it = people.begin(), jt; it != people.end(); it = jt) {
        jt = it;
        while (jt != people.end() && it->second == jt->second) {
            jt++;
        }
        cout << it->first << " " << prev(jt)->first + 1 << " " << it->second.size() << " ";
        bool first = true;
        for (auto &person : it->second) {
            if (!first) {
                cout << " ";
            }
            cout << person;
            first = false;
        }
        cout << '\n';
    }
    return 0;
}