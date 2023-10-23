template<typename T_string = string>
class suffix_array {
    /*
    
    Notes:
    suffix[i] cotains the index of (i+1)th smallest suffix array
    rank[i] contains order of the suffix array starting at ith index in the sorted suffix array
    lcp[i] = lcs of i & (i-1)th smallest suffix array
    
    Warnings:
    You may have missed: if(rank[i] == 0) continue;
    Have you built the sparse table for range_min_query?
    
    */ 
public:
    
    T_string s;
    int n;
    vector<int> suffix, rank, lcp;
    vector<vector<int>> mat;
    function<int(int, int)> func;
    
    
    suffix_array(T_string _s, bool build_rmq = false) : s(_s) {
        n = s.size();
        
        build_suffix();
        build_lcp();
        if(build_rmq)
            build_sparse_table();
    }
    
    void build_suffix() {
        suffix.resize(n);
        for (int i = 0; i < n; i++)
            suffix[i] = i;
        
        bool large_alphabet = false;
        for (int i = 0; i < n; i++)
            if (s[i] < 0 || s[i] >= 128)
                large_alphabet = true;
 
        // Sort each suffix by the first character.
        if (large_alphabet) {
            sort(suffix.begin(), suffix.end(), [&](int a, int b) {
                return s[a] < s[b];
            });
        } else {
            vector<int> freq(128, 0);
            for (int i = 0; i < n; i++)
                freq[s[i]]++;
 
            for (int c = 1; c < 128; c++)
                freq[c] += freq[c - 1];
 
            for (int i = 0; i < n; i++)
                suffix[--freq[s[i]]] = i;
        }
 
        // Compute the rank of each suffix. Tied suffixes share the same rank.
        rank.resize(n);
        rank[suffix[0]] = 0;
 
        for (int i = 1; i < n; i++)
            rank[suffix[i]] = s[suffix[i]] == s[suffix[i - 1]] ? rank[suffix[i - 1]] : i;
 
        vector<int> next_index(n);
        vector<int> values(n);
        bool done = false;
 
        for (int len = 1; len < n && !done; len *= 2) {
            // next_index[i] = the next index to use for a suffix of rank i. We insert them in order of the rank of the
            // suffix that comes len characters after the current suffix.
            for (int i = 0; i < n; i++)
                next_index[i] = i;
 
            // Compute the suffix array for 2 * len. Suffixes of length <= len are prioritized first.
            for (int i = n - len; i < n; i++)
                values[next_index[rank[i]]++] = i;
 
            for (int i = 0; i < n; i++) {
                int prev = suffix[i] - len;
 
                if (prev >= 0)
                    values[next_index[rank[prev]]++] = prev;
            }
 
            swap(suffix, values);
 
            // Compute the rank array for 2 * len.
            values[suffix[0]] = 0;
            done = true;
 
            for (int i = 1; i < n; i++) {
                int cur = suffix[i], prev = suffix[i - 1];
 
                if (cur + len < n && prev + len < n && rank[cur] == rank[prev] && rank[cur + len] == rank[prev + len]) {
                    values[cur] = values[prev];
                    done = false;
                } else {
                    values[cur] = i;
                }
            }
 
            swap(rank, values);
        }
    }

    void build_lcp() {
        lcp.resize(n);
        int k = 0;
        for(int i = 0; i < n; i++) {
            if(rank[i] == 0) continue;
            int j = suffix[rank[i] - 1];
            while(i + k < n && j + k < n && s[i + k] == s[j + k]) {
                k++;
            }
            lcp[rank[i]] = k;
            k = max<int>(0, k - 1);
        }
    }
    
    void build_sparse_table() {
        func = [&](const int& i, const int& j) {
            if(lcp[i] != lcp[j]) {
                return lcp[i] < lcp[j] ? i : j;
            }
            return min(i, j);
        };
        
        int max_log = 64 - __builtin_clzll(n);
        mat.resize(max_log);
        mat[0].resize(n);
        iota(mat[0].begin(), mat[0].end(), 0);
        
        for (int j = 1; j < max_log; j++) {
            mat[j].resize(n - (1 << j) + 1);
            for (int i = 0; i <= n - (1 << j); i++) {
                mat[j][i] = func(mat[j - 1][i], mat[j - 1][i + (1 << (j - 1))]);
            }
        }
    }
    
    int get_lcp(int from, int to) {
        if(from == to) {
            return n - from;
        }
         
        from = rank[from];
        to = rank[to];
        if(from > to) {
            swap(from, to);
        }
        
        assert(0 <= from && from <= to && to <= n - 1);
        
        // lcp(from, to) = min(lcp[from + 1], ......, lcp[to - 1], lcp[to])
        from++;
        int lg = 64 - __builtin_clzll(to - from + 1) - 1;
        // mn = index at which min lcp occurs
        int mn = func(mat[lg][from], mat[lg][to - (1 << lg) + 1]);
        return lcp[mn];
    }
    
};

