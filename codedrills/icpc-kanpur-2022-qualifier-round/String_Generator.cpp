/**
 *    author:  Taara Sinh Aatrey
 *    created: 18.03.2023 14:10:39
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
    int testcases;
    cin >> testcases;
    for (int caseno = 1; caseno <= testcases; caseno++) {
        cout << "Case " << caseno << ": ";
        int n;
        cin >> n;
        string a, b;
        cin >> a >> b;
        reverse(a.begin(), a.end());
        map<array<int, 3>, bool> ans;
        function<bool(int, int, int)> recurse = [&] (int i, int j, int k) -> bool {
            auto it = ans.find({i, j, k});
            if (it != ans.end()) {
                return it->second;
            }
            if (i < 0 || i >= n || j < 0 || k >= n || j > k) {
                return true;
            }
            return ans[{i, j, k}] = (a[i] == b[j] && recurse(i + 1, j + 1, k)) || (a[i] == b[k] && recurse(i + 1, j, k - 1));
        };
        recurse(0, 0, n - 1);
        cout << (ans[{0, 0, n - 1}] ? "YES" : "NO")<< '\n';
    }
    return 0;
    
    /*
i
dcba
[j, k]
dbad


    */
}