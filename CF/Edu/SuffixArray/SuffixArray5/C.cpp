/**
 *    author:  Taara Sinh Aatrey
 *    created: 29.06.2021 15:02:31
**/

#include <bits/stdc++.h>
using namespace std;

template<typename A, typename B> istream& operator>>(istream &is, pair<A, B> &p) { return is >> p.first >> p.second;} template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> istream& operator>>(istream &is, T_container &v) { for (T& x : v) is >> x; return is;} bool debug;
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return debug ? os << '(' << p.first << ", " << p.second << ')' : os << p.first << " " << p.second;} template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { if(debug) { os << "{"; string sep; for (const T &x : v) os << sep << x, sep = ", "; os << '}'; } else { bool f = false; for (const T &x : v) { if(f) {os << " ";} os << x, f = true; } } return os;}
template <typename T, typename T1, typename... Tail> T amin(T& a, T1 b, Tail... c) { if(b < a) a = b; if constexpr (sizeof...(c) != 0) { amin(a, c...); } return a; } template <typename T, typename T1, typename... Tail> T amax(T& a, T1 b, Tail... c) { if(b > a) a = b; if constexpr (sizeof...(c) != 0) { amax(a, c...); } return a; }
void dbg_out() { cerr << endl; } template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#ifdef ONLINE_JUDGE
#define dbg(...)
#else
#define dbg(...) cerr << "[" << #__VA_ARGS__ << "]:", debug = true, dbg_out(__VA_ARGS__), debug = false
#endif

#define int int64_t
const int mod = 1e9 + 7; const int INF = 1e18L + 5; const int N = 2e5 + 5;

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



void solve() {
    string s;
    cin >> s;
    int n = s.size();
    
    suffix_array SA(s, true);
    
    int q;
    cin >> q;
    vector<pair<int, int>> A(q);
    cin >> A;
    for(auto& [a, b] : A) {
        --a, --b;
    }
    sort(A.begin(), A.end(), [&](const pair<int, int>& a, const pair<int, int>& b) {
        
        int la = a.second - a.first + 1, lb = b.second - b.first + 1;
        
        // finding lcp of [a.first, n-1] && [b.first, n-1]
        int l = SA.get_lcp(a.first, b.first);
        
        amin(l, la, lb);
        
        // first different character
        char c_a = l < la ? s[a.first + l] : ' ';
        char c_b = l < lb ? s[b.first + l] : ' ';
        
        return (c_a == c_b) ? a < b : c_a < c_b; 
    });
    
    for(auto& [a, b] : A) {
        cout << a+1 << " " << b+1 << '\n';
    }
    
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;

    for (int tt = 1; tt <= t; tt++) {
        solve();
    }
    
    return 0;
}