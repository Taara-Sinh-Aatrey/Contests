#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> h(n);
    for(auto& x: h) {
        cin >> x;
    }

    stack<int> st;

    vector<int> Left(n, -1), Right(n, n);

    for(int i = 0; i < n; i++) {
        while(!st.empty() && h[st.top()] >= h[i]) {
            Right[st.top()] = i;
            st.pop();
        }
        if(!st.empty()) {
            Left[i] = st.top();
        }
        st.push(i);
    }

    int ans = 0;
    for(int i = 0; i < n; i++) {
        ans = max(ans, (Right[i] - Left[i] - 1) * h[i]);
    }

    cout << ans;

    return 0;
}