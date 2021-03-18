#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {

        int n;
        cin >> n;
        vector<int> a(n);
        bool ok = true;
        int mn = 2e18, mx = -2e18;
        for(auto &x: a) {
            cin >> x;
            mn = min(mn, x);
            mx = max(mx, x);
            if((x == 0) || (x & (x - 1))) {
                ok = false;
            }
        }

        if(mn == mx) {
            if(mn == 0) {
                cout << n * (n + 1) / 2 << '\n';
            } else {
                cout << 0 << '\n';
            }
            continue;
        }

        int ans = n * (n - 1) / 2;

        if(ok) {
            for(int i = 0; i < n;) {
                int j = i;
                while(j < n && a[i] == a[j]) {
                    j++;
                }
                int cnt = j - i;
                ans -= cnt * (cnt - 1) / 2;
                i = j;
            }

            cout << ans << '\n';
            continue;
        }

        vector<pair<int, int>> b;
        for(int i = 0; i < n; i++) {
            if(b.empty() || b.back().first != a[i]) {
                b.emplace_back(a[i], 1);
            } else {
                b.back().second++;
            }
        }

        int m = (int) b.size();

        vector<vector<int>> bit(m, vector<int>(60, 0));
        vector<vector<array<int, 3>>> vec(m + 1);
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < 60; j++) {
                if(i > 0) {
                    bit[i][j] = bit[i - 1][j];
                } 
                bit[i][j] += (b[i].first >> j & 1);
            }
        }

        ans = n * (n + 1) / 2;

        stack<int> st;

        auto evaluate = [&](int i, int x, int y, int AND, int OR) {
            int j = x;
            int val = 0;
            for(; j <= y; j++) {
                AND &= b[j].first;
                OR |= b[j].first;
                if((AND ^ OR) >= b[x].first) {
                    break;
                }
                val += b[j].second;
            }

            if(x < j) {
                vec[i].push_back({x, j - 1, val});
                if(x == i) {
                    ans -= b[i].second * (b[i].second + 1) / 2 - b[i].second * b[i].second;
                }
            }

            ans -= val * b[i].second;
        };

        for(int i = m - 1; i >= 0; i--) {

            int nxt = m;
            while(!st.empty() && b[st.top()].first <= b[i].first) {
                vec[st.top()].clear();
                st.pop();
            }
            if(!st.empty()) {
                nxt = st.top();
            } 
            st.push(i);

            evaluate(i, i, nxt - 1, b[i].first, b[i].first);

            for(auto pp : vec[nxt]) {
                int x = pp[0], y = pp[1], val = pp[2];
                int AND = 0, OR = 0;
                for(int z = 0; z < 60; z++) {
                    int diff = bit[x][z] - (i > 0 ? bit[i - 1][z] : 0);
                    if(diff == x - i + 1) {
                        AND |= 1LL << z;
                    }
                    if(diff > 0) {
                        OR |= 1LL << z;
                    }
                }

                if(AND == b[x].first && OR == b[x].first) {
                    vec[i].push_back(pp);
                    ans -= b[i].second * val;
                } else {
                    evaluate(i, x, y, AND, OR);
                }
            }

        }

        cout << ans << '\n';

    }
    return 0;
}


