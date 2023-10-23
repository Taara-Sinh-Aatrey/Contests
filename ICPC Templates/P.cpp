template <typename T = int64_t>
class fenwick {
public:
    int n;
    vector<T> fetree;

    fenwick(int _n) {
        n = _n;
        fetree = vector<T> (n + 1, 0);
    }

    // O(n) initialization of the Fenwick tree.
    template <typename T_array>
    void build(const T_array & initial) {
        assert(int(initial.size()) == n);

        for (int i = 1; i <= n; i++) {
            fetree[i] = initial[i - 1];

            for (int k = (i & -i) >> 1; k > 0; k >>= 1)
                fetree[i] += fetree[i - k];
        }
    }

    // l, r, idx are 0-indexing
    // idx is in [0, n)
    void update(int idx, T change) {
        // change = original - new
        ++idx;
        // as bit is 1-indexing based and idx is 0-indexing
        while (idx <= n) {
            fetree[idx] += change;
            idx += (idx & (-idx));
            // -idx is 2's comlpement
            // idx & -idx gives the last bit set in a number
        }
    }
    // every index i in the fetree[] array stores the cumulative sum
    // from the index i to i - (1 << r) + 1 (both inclusive), where
    // r represents the last set bit in the index i

    // idx is in [0, n)
    // returns the sum of the range [0, idx]
    T query(int idx) const {
        ++idx;
        // as bit is -indexing based and idx is 0-indexing
        T s = 0;
        while (idx > 0) {
            s += fetree[idx];
            idx -= (idx & (-idx));
        }
        return s;
    }

    // l and r are both in [0, n)
    // returns the sum in the range [l, r]
    T querylr(int l, int r) const {
        return query(r) - query(l - 1);
    }

    // l and r are both in [0, n)
    // add change in entire [l, r]
    void updatelr(int l, int r, T change) {
        update(l, change);
        update(r + 1, -change);
    }

    // Returns the element at index a in O(1) amortized across
    // every index. Equivalent to query(a, a + 1).
    T get(int i) const {
        assert(0 <= i && i < n);
        int above = i + 1;
        T sum = fetree[above];
        above -= above & -above;

        while (i != above) {
            sum -= fetree[i];
            i -= i & -i;
        }

        return sum;
    }

    static int highest_bit(int x) {
        return x == 0 ? -1 : 31 - __builtin_clz(x);
    }

    // Returns the largest p in `[0, n]` such that `query(p) <= sum`. Returns -1 if no such p exists (`sum < 0`).
    // Can be used as an ordered set/multiset on indices in `[0, n)` by using the tree as a 0/1 or frequency array:
    // `set(index, 1)` is equivalent to insert(index). `update(index, +1)` is equivalent to multiset.insert(index).
    // `set(index, 0)` or `update(index, -1)` are equivalent to erase(index).
    // `get(index)` provides whether index is present or not, or the count of index (if multiset).
    // `query(index)` provides the count of elements < index.
    // `find_last_prefix(k)` finds the k-th smallest element (0-indexed). Returns `n` for `sum >= set.size()`.
    int find_last_prefix(T sum) const {
        if (sum < 0)
            return -1;

        int prefix = 0;

        for (int k = highest_bit(n); k >= 0; k--) {
            if (prefix + (1 << k) <= n && fetree[prefix + (1 << k)] <= sum) {
                prefix += 1 << k;
                sum -= fetree[prefix];
            }
        }
        return prefix;

        // for (int k = highest_bit(n); k >= 0; k--) {
        //  if (prefix + (1 << k) <= n && fetree[prefix + (1 << k)] < sum) {
        //      prefix += 1 << k;
        //      sum -= fetree[prefix];
        //  }
        // }
        // return prefix + 1;
        // +1 because 'prefix' will have position of largest value less than 'val'
    }
};
