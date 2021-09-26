#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <vector>
using namespace std;

// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0200r0.html
template<class Fun> class y_combinator_result {
    Fun fun_;
public:
    template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
    template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
};
template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }


template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef NEAL_DEBUG
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

using T_tree = int;
const T_tree T_INF = numeric_limits<T_tree>::max() / 2;

struct segment_change {
    T_tree to_add;

    segment_change(T_tree _to_add = 0) : to_add(_to_add) {}
};

struct segment {
    T_tree min_prefix, sum;

    segment(T_tree _min_prefix = T_INF, T_tree _sum = 0) : min_prefix(_min_prefix), sum(_sum) {}

    void apply(const segment_change &change) {
        min_prefix += change.to_add;
        sum += change.to_add;
    }

    void join(const segment &other) {
        min_prefix = min(min_prefix, sum + other.min_prefix);
        sum += other.sum;
    }

    void join(const segment &a, const segment &b) {
        *this = a;
        join(b);
    }
};

int right_half[32];

struct min_prefix_sum_tree {
    static const bool POWER_OF_TWO_MODE = true;

    int tree_n = 0;
    vector<segment> tree;

    min_prefix_sum_tree(int n = -1) {
        if (n >= 0)
            init(n);
    }

    void init(int n) {
        if (POWER_OF_TWO_MODE) {
            tree_n = 1;

            while (tree_n < n)
                tree_n *= 2;
        } else {
            tree_n = n;
        }

        tree.assign(2 * tree_n, segment());
    }

    // Builds our tree from an array in O(n).
    void build(const vector<segment> &initial) {
        int n = int(initial.size());
        init(n);
        assert(n <= tree_n);

        for (int i = 0; i < n; i++)
            tree[tree_n + i] = initial[i];

        for (int position = tree_n - 1; position > 0; position--)
            tree[position].join(tree[2 * position], tree[2 * position + 1]);
    }

    segment query(int a, int b) const {
        assert(0 <= a && a <= b && b <= tree_n);
        segment answer;
        int r_size = 0;

        for (a += tree_n, b += tree_n; a < b; a /= 2, b /= 2) {
            if (a & 1)
                answer.join(tree[a++]);

            if (b & 1)
                right_half[r_size++] = --b;
        }

        for (int i = r_size - 1; i >= 0; i--)
            answer.join(tree[right_half[i]]);

        return answer;
    }

    segment query_full() const {
        assert(POWER_OF_TWO_MODE);
        return tree[1];
    }

    segment query_single(int index) const {
        assert(0 <= index && index < tree_n);
        return tree[tree_n + index];
    }

    void join_up(int position) {
        while (position > 1) {
            position /= 2;
            tree[position].join(tree[2 * position], tree[2 * position + 1]);
        }
    }

    void update(int index, const segment_change &change) {
        assert(0 <= index && index < tree_n);
        int position = tree_n + index;
        tree[position].apply(change);
        join_up(position);
    }

    void update(int index, const segment &seg) {
        assert(0 <= index && index < tree_n);
        int position = tree_n + index;
        tree[position] = seg;
        join_up(position);
    }
};

struct add_min_seg_tree {
    // Build a `min_prefix_sum_tree` on the consecutive differences of the array.
    min_prefix_sum_tree tree;

    add_min_seg_tree(int n = -1) {
        if (n >= 0)
            init(n);
    }

    void init(int n) {
        tree.init(n);
    }

    void build(const vector<T_tree> &initial) {
        vector<segment> segment_initial(initial.size());
        T_tree previous = 0;

        for (int i = 0; i < int(initial.size()); i++) {
            T_tree value = initial[i] - previous;
            previous = initial[i];
            segment_initial[i] = segment(value, value);
        }

        tree.build(segment_initial);
    }

    T_tree query(int a, int b) const {
        return tree.query(0, a).sum + tree.query(a, b).min_prefix;
    }

    T_tree query_full() const {
        return tree.query_full().min_prefix;
    }

    void update(int a, int b, segment_change change) {
        if (a < tree.tree_n)
            tree.update(a, change);

        if (b < tree.tree_n) {
            change.to_add *= -1;
            tree.update(b, change);
        }
    }

    void set_value(int index, T_tree value) {
        T_tree current = tree.query(0, index + 1).sum;
        update(index, index + 1, value - current);
    }

    void minimize(int index, T_tree value) {
        T_tree current = tree.query(0, index + 1).sum;

        if (value < current)
            update(index, index + 1, value - current);
    }
};

template<typename T>
struct fenwick_tree {
    static int highest_bit(unsigned x) {
        return x == 0 ? -1 : 31 - __builtin_clz(x);
    }

    int tree_n = 0;
    T tree_sum = T();
    vector<T> tree;

    fenwick_tree(int n = -1) {
        if (n >= 0)
            init(n);
    }

    void init(int n) {
        tree_n = n;
        tree_sum = T();
        tree.assign(tree_n + 1, T());
    }

    // O(n) initialization of the Fenwick tree.
    template<typename T_array>
    void build(const T_array &initial) {
        assert(int(initial.size()) == tree_n);
        tree_sum = T();

        for (int i = 1; i <= tree_n; i++) {
            tree[i] = initial[i - 1];
            tree_sum += initial[i - 1];

            for (int k = (i & -i) >> 1; k > 0; k >>= 1)
                tree[i] += tree[i - k];
        }
    }

    // index is in [0, tree_n).
    void update(int index, const T &change) {
        assert(0 <= index && index < tree_n);
        tree_sum += change;

        for (int i = index + 1; i <= tree_n; i += i & -i)
            tree[i] += change;
    }

    // Returns the sum of the range [0, count).
    T query(int count) const {
        count = min(count, tree_n);
        T sum = T();

        for (int i = count; i > 0; i -= i & -i)
            sum += tree[i];

        return sum;
    }

    // Returns the sum of the range [start, tree_n).
    T query_suffix(int start) const {
        return tree_sum - query(start);
    }

    // Returns the sum of the range [a, b).
    T query(int a, int b) const {
        return query(b) - query(a);
    }

    // Returns the element at index a in O(1) amortized across every index. Equivalent to query(a, a + 1).
    T get(int a) const {
        assert(0 <= a && a < tree_n);
        int above = a + 1;
        T sum = tree[above];
        above -= above & -above;

        while (a != above) {
            sum -= tree[a];
            a -= a & -a;
        }

        return sum;
    }

    bool set(int index, T value) {
        assert(0 <= index && index < tree_n);
        T current = get(index);

        if (current == value)
            return false;

        update(index, value - current);
        return true;
    }

    // Returns the largest p in `[0, tree_n]` such that `query(p) <= sum`. Returns -1 if no such p exists (`sum < 0`).
    // Can be used as an ordered set/multiset on indices in `[0, tree_n)` by using the tree as a 0/1 or frequency array:
    // `set(index, 1)` is equivalent to insert(index). `update(index, +1)` is equivalent to multiset.insert(index).
    // `set(index, 0)` or `update(index, -1)` are equivalent to erase(index).
    // `get(index)` provides whether index is present or not, or the count of index (if multiset).
    // `query(index)` provides the count of elements < index.
    // `find_last_prefix(k)` finds the k-th smallest element (0-indexed). Returns `tree_n` for `sum >= set.size()`.
    int find_last_prefix(T sum) const {
        if (sum < T())
            return -1;

        int prefix = 0;

        for (int k = highest_bit(tree_n); k >= 0; k--)
            if (prefix + (1 << k) <= tree_n && tree[prefix + (1 << k)] <= sum) {
                prefix += 1 << k;
                sum -= tree[prefix];
            }

        return prefix;
    }
};


const int INF = int(1e9) + 5;

void run_case(int test_case) {
    int R, C, K, S;
    cin >> R >> C >> K >> S;
    K--;
    vector<string> grid(R);

    for (auto &row : grid)
        cin >> row;

    vector<array<int, 2>> toggle(S);

    for (auto &t : toggle) {
        cin >> t[0] >> t[1];
        t[0]--; t[1]--;
    }

    vector<int> answers(S, INF);

    for (int iter = 0; iter < 2; iter++) {
        vector<fenwick_tree<int>> column_tree(C);

        for (int c = 0; c < C; c++) {
            column_tree[c].init(R + 1);
            vector<int> initial(R + 1, 0);

            for (int r = 0; r < R; r++)
                initial[r] = grid[r][c] == 'X';

            column_tree[c].build(initial);
        }

        vector<int> column_cnt(C, 0);
        add_min_seg_tree tree(R + 1);
        vector<int> initial(R + 1, INF);

        for (int r = 0; r <= R; r++) {
            for (int c = 0; c < C; c++)
                column_cnt[c] += r < R && grid[r][c] == 'X';

            if (r >= K) {
                int option = abs(r - K);

                for (int c = 0; c < C; c++)
                    option += (r < R && grid[r][c] == 'X') || column_cnt[c] >= K + 1;

                initial[r] = option;
            }
        }

        tree.build(initial);
        vector<vector<bool>> on(R, vector<bool>(C, false));

        for (int r = 0; r < R; r++)
            for (int c = 0; c < C; c++)
                on[r][c] = grid[r][c] == 'X';

        for (int q = 0; q < S; q++) {
            int r = toggle[q][0];
            int c = toggle[q][1];

            if (on[r][c]) {
                int before = column_tree[c].find_last_prefix(K);
                column_tree[c].set(r, false);
                int after = column_tree[c].find_last_prefix(K);
                assert(before <= after);

                if (before < after)
                    tree.update(before + 1, after, segment_change(-1));

                if (r <= before)
                    tree.update(r, r + 1, segment_change(-1));
            } else {
                int before = column_tree[c].find_last_prefix(K);
                column_tree[c].set(r, true);
                int after = column_tree[c].find_last_prefix(K);
                assert(after <= before);

                if (after < before)
                    tree.update(after + 1, before, segment_change(+1));

                if (r <= after)
                    tree.update(r, r + 1, segment_change(+1));
            }

            on[r][c] = !on[r][c];
            answers[q] = min(answers[q], tree.query_full());
        }

        reverse(grid.begin(), grid.end());
        K = R - 1 - K;

        for (int i = 0; i < S; i++)
            toggle[i][0] = R - 1 - toggle[i][0];
    }
    
    // for (int q = 0; q < S; q++)
    //     cout << answers[q] << " ";
    int64_t ans = accumulate(answers.begin(), answers.end(), 0LL);
    cout << "Case #" << test_case << ": " << ans << '\n';
    // cout << "\nCase #" << test_case << ": " << ans << '\n';
}

int main() {
    int tests;
    cin >> tests;

    for (int tc = 1; tc <= tests; tc++) {
        run_case(tc);
        cout << flush;
    }
}
