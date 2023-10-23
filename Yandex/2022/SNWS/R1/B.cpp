#include "bits/stdc++.h"
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, vector<int>> mp;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mp[a[i] + i].emplace_back(i);
    }
    for (auto &[x, vec] : mp) {
        reverse(vec.begin(), vec.end());
    }
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    oset<int> st;
    int ops = 0;
    for (int i = 0; i < n; i++) {
        int x = b[i] + i;
        if (mp[x].empty()) {
            cout << -1 << '\n';
            return 0;
        }
        int j = mp[x].back();
        mp[x].pop_back();
        int pos = j + st.size() - st.order_of_key(j);
        ops += pos - i;
        st.insert(j);
    }
    cout << ops << '\n';
    return 0;
}