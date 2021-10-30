#include "bits/stdc++.h"
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
using namespace std;

void fastscan(int &number)
{
    register int c;
    number = 0;  
    c = getchar();
    for (; (c > 47 && c < 58); c=getchar())
        number = number * 10 + c - 48;
}

int main() {

    // ios::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
    int money;
    fastscan(money);
    vector<pair<int, int>> a;
    int cnt = 0;
    register int c;
    while (true) {
        cnt++;
        int number = 0;
        c = getchar();
        for (; (c > 47 && c < 58); c=getchar()) {
            number = number * 10 + c - 48;
        }
        a.emplace_back(number, cnt);
        if (c == 10 || c == -1) break;
    }
    sort(a.begin(), a.end());
    int ans = 0;
    for (auto it = a.begin(), jt = a.begin(); it != a.end(); ) {
        jt = it;
        int val = it->first;
        int f = 0;
        while (jt != a.end() && jt->first == val) {
            f += jt->second;
            jt++;
        }
        if (money <= 0) break;
        int take = min(money / val, f);
        ans += take;
        money -= take * val;
        it = jt;
    }
    cout << ans;
    return 0;
}