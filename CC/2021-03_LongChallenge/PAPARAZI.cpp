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
        vector<int> h(n);
        for(int i = 0; i < n; i++) {
            cin >> h[i];
        }

        int ans = 1;
        vector<int> st{0};
        auto check = [&](int i, int j, int dx, int dy) {
            return (h[i] - h[j]) * dx <= dy * (i - j);
        };
        for(int i = 1; i < n; i++) {
            int dy = h[i] - h[i - 1], dx = 1;
            while(st.size() > 1 && check(i, st[st.size() - 2], dx, dy)) {
                int j = st[st.size() - 2];
                dy = h[i] - h[j];
                dx = i - j;
                ans = max(ans, dx);
                st.pop_back();
            }
            st.push_back(i);
        }
        cout << ans << '\n';
    }

    return 0;
}