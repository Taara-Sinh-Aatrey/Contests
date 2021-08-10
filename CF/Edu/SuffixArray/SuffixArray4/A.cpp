/**
 *    author:  Taara Sinh Aatrey
 *    created: 28.06.2021 01:54:58
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

// suffix[i] cotains the index of (i+1)th smallest suffix array
// rank[i] contains order of the suffix array starting at ith index in the sorted suffix array
void get_suffix_array(string& s, vector<int>& suffix, vector<int>& rank) {
    s += '$';
    int n = s.size();
    
    suffix.resize(n);
    iota(suffix.begin(), suffix.end(), 0);
    sort(suffix.begin(), suffix.end(), [&](const int& i, const int& j) {
        return s[i] < s[j];
    });
    
    rank.resize(n); 
    rank[suffix[0]] = 0;
    for(int i = 1; i < n; i++) {
        rank[suffix[i]] = rank[suffix[i - 1]] + (s[suffix[i]] != s[suffix[i - 1]]);
    }
    
    int k = 0;
    while((1 << k) < n) {
        
        // doing this will sort the suffix by second value
        for(int& i : suffix) {
            i -= 1 << k;
            if(i < 0) {
                i += n;
            }
        }
        
        // sorting by first value using counting sort
        vector<int> cnt(n);
        for(int i = 0; i < n; i++) {
            cnt[rank[i]]++;
        }
        for(int i = 1; i < n; i++) {
            cnt[i] += cnt[i - 1];
        }
        vector<int> new_suffix(n);
        for(int it = n - 1; it >= 0; it--) {
            int i = suffix[it];
            new_suffix[--cnt[rank[i]]] = i;
        }
        suffix = new_suffix;
        
        
        // finding updated rank of all suffix
        vector<int> new_rank(n);
        new_rank[suffix[0]] = 0;
        for(int it = 1; it < n; it++) {
            int i = suffix[it], j = suffix[it - 1];
            int n_i = i + (1 << k), n_j = j + (1 << k);
            n_i = n_i >= n ? n_i - n : n_i;
            n_j = n_j >= n ? n_j - n : n_j;
            new_rank[i] = new_rank[j] + !(rank[i] == rank[j] && rank[n_i] == rank[n_j]);
        }
        rank = new_rank;
        
        k++;
    }
    
    s.pop_back();
}

void get_lcp(string s, vector<int>& suffix, vector<int>& rank, vector<int>& lcp) {
    s += '$';
    int n = s.size();
    lcp.resize(n - 1);
    
    int k = 0;
    for(int i = 0; i < n - 1; i++) {
        int j = suffix[rank[i] - 1];
        while(s[i + k] == s[j + k]) {
            k++;
        }
        lcp[i] = k;
        k = max<int>(0, k - 1);
    }

}
void solve() {
    string s;
    cin >> s;
    
    int n = s.size();
    
    vector<int> suffix, rank;
    get_suffix_array(s, suffix, rank);
    
    vector<int> lcp;
    get_lcp(s, suffix, rank, lcp);
    
    cout << suffix << '\n';
    for(int i = 1; i <= n; i++) {
        cout << lcp[suffix[i]] << " ";
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