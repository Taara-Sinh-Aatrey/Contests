/**
 *    author:  Taara Sinh Aatrey
 *    created: 04.09.2022 17:45:54
**/

#include "bits/stdc++.h"

using namespace std;

#ifdef AATREY_DEBUG
#include "debug.hpp"
#else
#define dbg(...)
#endif

#define int int64_t

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) 
        cin >> x, --x;
    int cnt = 0;
    vector<int> odd, even;
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 != i % 2) {
            cnt++;
            if (i % 2) {
                odd.emplace_back(i);
            }
            else {
                even.emplace_back(i);
            }
        }
    }
    cnt /= 2;
    assert(odd.size() == even.size());
    vector<pair<char, int>> ans;  
    for (int it = 0; it < odd.size(); it++) {
        int i = odd[it], j = even[it];
        if (i > j) swap(i, j);
        while (j - 2 >= i) {
            ans.emplace_back('B', j - 2);
            swap(a[j - 2], a[j]);
            j -= 2;
        }
        while (j - 1 >= i) {
            ans.emplace_back('A', j - 1);
            swap(a[j - 1], a[j]);
            cnt--;
            j--;
        }
    }
    for (int iter = 0; iter < n; iter++) {
        int i = iter;
        int j = min_element(a.begin() + i, a.end()) - a.begin();
        assert((j - i) % 2 == 0);
        while (j - 2 >= i) {
            ans.emplace_back('B', j - 2);
            swap(a[j - 2], a[j]);
            j -= 2;  
        }
    }
    assert(cnt == 0);
    cout << ans.size() << '\n';
    for (auto &[ch, idx] : ans) {
        cout << ch << " " << idx + 1 << '\n';
    }
    return 0;
}