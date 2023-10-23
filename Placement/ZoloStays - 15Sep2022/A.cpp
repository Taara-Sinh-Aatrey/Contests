#include "bits/stdc++.h"
using namespace std;

int main() {
#define int int64_t
    int n, k;
    cin >> n >> k;
    multiset<int, greater<int>> st{n};
    while (k--) {
        auto it = st.begin();
        int x = *it;
        st.erase(it);
        st.emplace(x / 2);
        st.emplace(x - x / 2);
    }
    int ans = 0;
    for (auto &x : st) {
        ans += x * x;
    }
    cout << ans << '\n';
#undef int
    return 0;
}