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

vector<int> solve(int n, string DNA, vector<vector<string>> ar) {
    vector<vector<int>> pref(n, vector<int>(26, 0));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 26; j++) {
            pref[i][j] = (i > 0 ? pref[i - 1][j] : 0) + (DNA[i] == char('a' + j));
        }
    }
    
    int q = ar.size();
    vector<int> ans;
    for(int i = 0; i < q; i++) {
        int l = stoll(ar[i][0]), r = stoll(ar[i][1]), c = ar[i][2][0] - 'a';
        --l, --r;
        
        int sum = 0;
        
        if(l % n != 0) {
            int x = l % n;
            sum += pref[n - 1][c] - pref[x - 1][c];
            l += n - (l % n);
        }
        
        if(r % n != n - 1) {
            sum += pref[r % n][c];
            r -= r % n;
        }
        
        sum += (r - l + 1) / n * (pref[n - 1][c]);
        ans.emplace_back(sum);
    }
    return ans;
}

int main()
{
    
    cout << solve(4, "abcd", {{"13", "16", "b"}, {"1", "17", "a"}, {"5", "13", "c"}}) << endl;
    cout << solve(4, "abaa", {{"13", "17", "a"}, {"1", "17", "a"}, {"5", "13", "c"}}) << endl;
    cout << solve(5, "abcde", {{"1", "1", "a"}, {"4", "40", "d"}}) << endl;
    
    return 0;
}