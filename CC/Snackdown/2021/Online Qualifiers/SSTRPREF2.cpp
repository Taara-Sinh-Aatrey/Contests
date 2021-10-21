#include "bits/stdc++.h"
using namespace std;

bool debug;
template <typename T, typename U> istream& operator>>(istream &is, pair<T, U> &p) { return is >> p.first >> p.second;}
template <typename T, typename U> ostream& operator<<(ostream &os, const pair<T, U> &p) { return debug ? os << "(" << p.first << ", " << p.second << ")" : os << p.first << " " << p.second; }
template <typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> istream &operator>>(istream &is, T_container &v) { for (T &x : v) is >> x; return is; }
template <typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream &operator<<(ostream &os, const T_container &v) { bool f = false; if(debug) { os << "{"; for (const T &x : v) { if (f) os << ", "; os << x; f = true; } os << "}"; } else { for (const T &x : v) { if (f) os << " "; os << x; f = true; } } return os; }
void scan() {} template <typename Head, typename ...Tail> void scan(Head &H, Tail &...T) { cin >> H; scan(T...); }
void print() { cout << "\n"; } template <typename Head> void print(const Head &H) { cout << H << "\n"; } template <typename Head, typename ...Tail> void print(const Head &H, const Tail &...T) { cout << H << " "; print(T...); }
template <typename T, typename T1, typename... Tail> T amin(T& a, T1 b, Tail... c) { if(b < a) a = b; if constexpr (sizeof...(c) != 0) { amin(a, c...); } return a; } template <typename T, typename T1, typename... Tail> T amax(T& a, T1 b, Tail... c) { if(b > a) a = b; if constexpr (sizeof...(c) != 0) { amax(a, c...); } return a; }
void dbg_out() { cerr << "\n"; } template <typename Head, typename ...Tail> void dbg_out(const Head &H, const Tail &...T) { cerr << " " << H; dbg_out(T...); }
#ifndef ONLINE_JUDGE
#define dbg(...) cerr << "[" << #__VA_ARGS__ << "]:", debug = true, dbg_out(__VA_ARGS__), debug = false
#else
#define dbg(...)
#endif



#define int int64_t
const int inf = 1e18L + 5, mod = 1e9 + 7, N = 2e5 + 5;

template <typename T>
vector<int> kmp_table(const T &s) {
	int n = s.size(), len = 0;
	vector<int> lps(n, 0);
	for (int i = 1; i < n; i++) {
		while (len > 0 && s[i] != s[len])
			len = lps[len - 1];
		if (s[i] == s[len]) 
			len++;
		lps[i] = len;
	}
	return lps;
}

// find occurences of `pat` in `text`
template <typename T>
int kmp_search(const T& text, const T& pat) {
	auto lps = kmp_table(pat);
	int ret = 0;
	// finding pattern in text using lps
	int n = text.length();
	int m = pat.length();
	
	for (int i = 0, j = 0; i < n; ) {
		if (pat[j] == text[i])
			j++, i++;
		if (j == m) {
			// pattern found
			ret++;
			j = lps[j - 1];
		}
		else if (i < n && pat[j] != text[i]) {
			if (j != 0)
				j = lps[j - 1];
			else
				i++;
		}
	}
	return ret;
}

template <typename T>
vector<int> z_function(const T &s) {
	int l = 0, r = 0, n = s.size();
	vector<int> z(n, n);
	for (int i = 1; i < n; i++) {
		z[i] = (i > r ? 0 : min(r - i + 1, z[i - l]));
		while (i + z[i] < n && s[z[i]] == s[i + z[i]])
			z[i]++;
		if (i + z[i] - 1 > r) {
			l = i;
			r = i + z[i] - 1;
		}
	}
	return z;
}

void solve() {
	string a, b, c;
	scan(a, b, c);
	int na = a.size(), nb = b.size(), nc = c.size();
	auto lps = kmp_table(a + "@" + c);
	auto z = z_function(b + "@" + c + "#");
	vector<int> mx(na + 1, 0);
	for (int i = 0; i <= nc; i++) {
		int pref_len = lps[na + i];
		int suff_len = z[nb + 1 + i];
		amax(mx[pref_len], 1 + suff_len);
	}
	for (int i = na; i > 0; i--) {
		amax(mx[lps[i - 1]], mx[i]);
	}
	print(accumulate(mx.begin(), mx.end(), 0LL));
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
	cin >> t;
	for (int tt = 1; tt <= t; tt++) {
		solve();
	}
	return 0;
}