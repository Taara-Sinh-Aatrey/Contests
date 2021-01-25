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

#define CERR cout
// #define CERR cerr

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

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n = 6;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int m;
  cin >> m;
  vector<int> b(m);
  for (int i = 0; i < m; i++) {
    cin >> b[i];
  }
  vector<vector<int>> x(m, vector<int>(n));
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      x[i][j] = b[i] - a[j];
    }
    sort(x[i].begin(), x[i].end());
  }

  vector<pair<int, int>> p;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      p.emplace_back(x[i][j], i);
    }
  }
  sort(p.begin(), p.end());
  multiset<int> s;
  for (int i = 0; i < m; i++) {
    s.insert(x[i][0]);
  }
  vector<int> ptr(m, 0);
  int ans = (int) 2e9;
  {
    int mn = *s.begin();
    int mx = *prev(s.end());
    ans = min(ans, mx - mn);
  }
  for (auto& q : p) {
  	dbg(q);
    int i = q.second;
    s.erase(s.find(x[i][ptr[i]]));
    ++ptr[i];
    if (ptr[i] == n) {
      break;
    }
    s.insert(x[i][ptr[i]]);
    int mn = *s.begin();
    int mx = *prev(s.end());
    dbg(mn, mx);
    cout << '\n';
    ans = min(ans, mx - mn);
  }
  cout << ans << '\n';
  return 0;
}
