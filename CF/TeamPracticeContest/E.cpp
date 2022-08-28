/**
 *    author:  Taara Sinh Aatrey
 *    created: 27.08.2022 23:56:23
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
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    vector<vector<int>> left(n, vector<int>(m, m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i][j] == '.') {
                left[i][j] = j;
                if (i == 0)
                    left[i][j] = 0;
                if (i - 1 >= 0)
                    left[i][j] = min(left[i][j], left[i - 1][j]);
                if (j - 1 >= 0)
                    left[i][j] = min(left[i][j], left[i][j - 1]);
            }
            // cout << left[i][j] << " \n"[j == m - 1];
        }
    }
    vector<int> cols(m, -1);
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            if (s[i][j] != 'X') {
                cols[j] = max(cols[j], left[i][j]);
            }
        }
    }
    SparseTable<int> st(cols, [&] (auto &x, auto &y) {
        return max(x, y);
    });
    int q;
    cin >> q;
    while (q--) {
        int start, end;
        cin >> start >> end, --start, --end;
        cout << (st.get(start, end) <= start ? "YES" : "NO") << '\n';
    }
    return 0;
}