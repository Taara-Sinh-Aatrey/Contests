/*You know a shop where you can buy chocolates for your friend. The shop has limited availablility of chocolates. On day i, there are only Ai 
chocolates available in the shop. Your friend is angry with you and she asks you to buy her X chocolate otherwise she won't talk to you. Also due 
to COVID 19 pandemic, the government has imposed lockdown from Lth day to Rth day which means the shop will be closed from L to R (both inclusive). 
Now you want to find out the no of days she won't talk to you. If you fail to buy her X chocolate on or before nth day, she will never talk to you 
and print -1 in this case. 

Note: She will start talking to you the day after you fulfill her demand.

Input
The first line contains an integer n, total no of days.
Second line contains n space separated integers where ith integer is the chocolate available on ith day.
Third line contains an integer q, no of queries.
Next q lines contain three space separated integers L, R and X.

Output
For every query, print no of days she won't talk to you. If she will never talk to you, print -1 instead.*/


#include <bits/stdc++.h>
using namespace std;

		
template <typename A, typename B>
string to_string(pair<A, B> p);

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);

string to_string(const string& s) {
	return '"' + s + '"';
}

string to_string(const char* s) {
	return to_string((string) s);
}

string to_string(bool b) {
	return (b ? "true" : "false");
}

string to_string(vector<bool> v) {
	bool first = true;
	string res = "{";
	for (int i = 0; i < static_cast<int>(v.size()); i++) {
		if (!first) {
			res += ", ";
		}
		first = false;
		res += to_string(v[i]);
	}
	res += "}";
	return res;
}

template <size_t N>
string to_string(bitset<N> v) {
	string res = "";
	for (size_t i = 0; i < N; i++) {
		res += static_cast<char>('0' + v[i]);
	}
	return res;
}

template <typename A>
string to_string(A v) {
	bool first = true;
	string res = "{";
	for (const auto &x : v) {
		if (!first) {
			res += ", ";
		}
		first = false;
		res += to_string(x);
	}
	res += "}";
	return res;
}

template <typename A, typename B>
string to_string(pair<A, B> p) {
	return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
	return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";
}

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
	return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}

// #define CERR cout
#define CERR cerr

void debug_out() { CERR << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
	CERR << " " << to_string(H);
	debug_out(T...);
}

#ifndef ONLINE_JUDGE
#define dbg(...) CERR << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define dbg(...) 42
#endif

#define int int64_t

signed main()
{
#ifdef LOCAL
    freopen("in0.txt", "r", stdin);
    freopen("out0.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto& x: a) {
    	cin >> x;
    }
    vector<int> pref(n + 1, 0);
    for(int i = 1; i <= n; i++) {
    	pref[i] = pref[i - 1] + a[i - 1];
    }
    int q;
    cin >> q;
    int neg = 0, low = 0, high = 0;
    while(q--) {
    	int l, r, x;
    	cin >> l >> r >> x;
    	assert(l >= 1);
    	assert(l <= r);
    	assert(r <= n);
    	assert(x >= 0);
    	int idx = lower_bound(pref.begin(), pref.begin() + l, x) - pref.begin();
    	if(idx < l) {
    		cout << idx << '\n';
    		low++;
    		continue;
    	}
    	int offset = pref[r] - pref[l - 1];
    	idx = lower_bound(pref.begin() + r + 1, pref.end(), x + offset) - pref.begin();
    	if(idx <= n) {
    		cout << idx << '\n';
    		high++;
    		continue;
    	}
    	neg++;
    	cout << -1 << '\n';
    }
    dbg(neg, low, high);
    return 0;
}
