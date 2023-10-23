/**
 *    author:  Taara Sinh Aatrey
 *    created: 05.01.2023 00:25:40
**/

#include "bits/stdc++.h"

using namespace std;

#ifdef AATREY_DEBUG
#include "debug.hpp"
#else
#define dbg(...)
#endif

#define int int64_t

template <typename T, class F = function<T(const T&, const T&)>>
class SparseTable {
public:
    int n;
    vector<vector<T>> mat;
    F func;

    SparseTable(const vector<T>& a, const F& f) : func(f) {
        n = static_cast<int>(a.size());
        int max_log = 64 - __builtin_clzll(n);
        mat.resize(max_log);
        mat[0] = a;
        for (int j = 1; j < max_log; j++) {
            mat[j].resize(n - (1 << j) + 1);
            for (int i = 0; i <= n - (1 << j); i++) {
                mat[j][i] = func(mat[j - 1][i], mat[j - 1][i + (1 << (j - 1))]);
            }
        }
    }

    T get(int from, int to) const {
        assert(0 <= from && from <= to && to <= n - 1);
        int lg = 64 - __builtin_clzll(to - from + 1) - 1;
        return func(mat[lg][from], mat[lg][to - (1 << lg) + 1]);
    }
};

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int testcases;
    cin >> testcases;
    for (int caseno = 1; caseno <= testcases; caseno++) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (auto &x : a) {
            cin >> x;
        }
        for (auto &x : b) {
            cin >> x;
        }
        int m;
        cin >> m;
        map<int, int> cnt;
        for (int i = 0; i < m; i++) {
            int x;
            cin >> x;
            cnt[x]++;
        }
        bool ok = true;
        for (int i = 0; i < n; i++) {
            if (a[i] < b[i]) {
                ok = false;
                break;
            }
        }
        if (!ok) {
            cout << "NO" << '\n';
            continue;
        }
        SparseTable<int> st(b, [&] (auto &x, auto &y) {
            return max(x, y);
        });
        int ans = 0;
        map<int, int> last;
        for (int i = 0; i < n; i++) {
            if (a[i] == b[i]) continue;
            if (!last.count(b[i]) || (last[b[i]] != i - 1 && st.get(last[b[i]] + 1, i - 1) > b[i])) {
                cnt[b[i]]--;
            }
            last[b[i]] = i;
        }
        for (auto &[x, y] : cnt) {
            ok &= y >= 0;
        }
        cout << (ok ? "YES" : "NO") << '\n';
    }
    return 0;
}



