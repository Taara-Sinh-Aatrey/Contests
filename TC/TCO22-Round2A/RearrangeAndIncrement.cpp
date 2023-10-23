#include "bits/stdc++.h"
using namespace std;

template <typename T, typename U> istream& operator>>(istream &is, pair<T, U> &p) { return is >> p.first >> p.second; }
template <typename T, typename U> ostream& operator<<(ostream &os, const pair<T, U> &p) { return os << p.first << " " << p.second; }
template <typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> istream &operator>>(istream &is, T_container &v) { for (T &x : v) is >> x; return is; }
template <typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream &operator<<(ostream &os, const T_container &v) { bool f = false; for (const T &x : v) { if (f) os << " "; os << x; f = true; } return os; }
void scan() {} template <typename Head, typename ...Tail> void scan(Head &H, Tail &...T) { cin >> H; scan(T...); }
void print() { cout << "\n"; } template <typename Head> void print(const Head &H) { cout << H << "\n"; } template <typename Head, typename ...Tail> void print(const Head &H, const Tail &...T) { cout << H << " "; print(T...); }
template <typename T, typename T1> T amin(T& a, T1 b) { if(b < a) a = b; return a; } template <typename T, typename T1, typename... Tail> T amin(T& a, T1 b, Tail... c) { if(b < a) a = b; amin(a, c...); return a; } template <typename T, typename T1> T amax(T& a, T1 b) { if(b > a) a = b; return a; } template <typename T, typename T1, typename... Tail> T amax(T& a, T1 b, Tail... c) { if(b > a) a = b; amax(a, c...); return a; }

#ifdef LOCAL
#include "debug.hpp"
#else
#define dbg(...)
#endif

#define int int64_t
const int inf = 1e18L + 5, mod = 1e9 + 7, N = 2e5 + 5;

class RearrangeAndIncrement {
  public:
  #undef int
  vector <int> change(int _a, int _b) {
  	_a = 1029;
  	_b = 20005;
	  #define int int64_t
	  string a = to_string(_a), b = to_string(_b);
	  vector<int32_t> ans;
	  ans.emplace_back(_a);
	  if (a.size() < b.size()) {
	  	sort(a.rbegin(), a.rend());
	  	_a = stoll(a);
	  	ans.emplace_back(_a);
	  	while (a.size() < b.size()) {
	  		_a += min(13, _b - _a);
	  		a = to_string(_a);
	  		ans.emplace_back(_a);
	  	}
	  }
	  if (a == b) {
	  	return ans;
	  }
	  sort(a.rbegin(), a.rend());
  	_a = stoll(a);
  	ans.emplace_back(_a);
  	a.back() = b[0];
  	ans.emplace_back(stoll(a));
  	a = a.back() + a;
  	a.pop_back();
  	ans.emplace_back(stoll(a));
  	
	  return ans;
  }
};

#undef int

// BEGIN CUT HERE
#include <cstdio>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
namespace moj_harness {
	using std::string;
	using std::vector;
	int run_test_case(int);
	void run_test(int casenum = -1, bool quiet = false) {
		if (casenum != -1) {
			if (run_test_case(casenum) == -1 && !quiet) {
				std::cerr << "Illegal input! Test case " << casenum << " does not exist." << std::endl;
			}
			return;
		}
		
		int correct = 0, total = 0;
		for (int i=0;; ++i) {
			int x = run_test_case(i);
			if (x == -1) {
				if (i >= 100) break;
				continue;
			}
			correct += x;
			++total;
		}
		
		if (total == 0) {
			std::cerr << "No test cases run." << std::endl;
		} else if (correct < total) {
			std::cerr << "Some cases FAILED (passed " << correct << " of " << total << ")." << std::endl;
		} else {
			std::cerr << "All " << total << " tests passed!" << std::endl;
		}
	}
	
	template<typename T> std::ostream& operator<<(std::ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi=v.begin(); vi!=v.end(); ++vi) { if (vi != v.begin()) os << ","; os << " " << *vi; } os << " }"; return os; }

	int verify_case(int casenum, const vector <int> &expected, const vector <int> &received, std::clock_t elapsed) { 
		std::cerr << "Example " << casenum << "... "; 
		
		string verdict;
		vector<string> info;
		char buf[100];
		
		if (elapsed > CLOCKS_PER_SEC / 200) {
			std::sprintf(buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
			info.push_back(buf);
		}
		
		if (expected == received) {
			verdict = "PASSED";
		} else {
			verdict = "FAILED";
		}
		
		std::cerr << verdict;
		if (!info.empty()) {
			std::cerr << " (";
			for (size_t i=0; i<info.size(); ++i) {
				if (i > 0) std::cerr << ", ";
				std::cerr << info[i];
			}
			std::cerr << ")";
		}
		std::cerr << std::endl;
		
		if (verdict == "FAILED") {
			std::cerr << "    Expected: " << expected << std::endl; 
			std::cerr << "    Received: " << received << std::endl; 
		}
		
		return verdict == "PASSED";
	}

	int run_test_case(int casenum__) {
		switch (casenum__) {
		case 0: {
			int X                     = 10234;
			int Y                     = 1247;
			int expected__[]          = {10234, 1234, 1247 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = RearrangeAndIncrement().change(X, Y);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 1: {
			int X                     = 10234;
			int Y                     = 10248;
			int expected__[]          = {10234, 10244, 10248 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = RearrangeAndIncrement().change(X, Y);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 2: {
			int X                     = 999997;
			int Y                     = 1000001;
			int expected__[]          = {999997, 999998, 999999, 1000000, 1000001 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = RearrangeAndIncrement().change(X, Y);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 3: {
			int X                     = 1000000;
			int Y                     = 1000;
			int expected__[]          = {1000000, 1000 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = RearrangeAndIncrement().change(X, Y);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 4: {
			int X                     = 1111111;
			int Y                     = 1111232;
			int expected__[]          = {1111111, 1111122, 1111221, 1111232 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = RearrangeAndIncrement().change(X, Y);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 5: {
			int X                     = 47;
			int Y                     = 47;
			int expected__[]          = {47 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = RearrangeAndIncrement().change(X, Y);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			int X                     = ;
			int Y                     = ;
			int expected__[]          = ;

			std::clock_t start__      = std::clock();
			vector <int> received__   = RearrangeAndIncrement().change(X, Y);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 7: {
			int X                     = ;
			int Y                     = ;
			int expected__[]          = ;

			std::clock_t start__      = std::clock();
			vector <int> received__   = RearrangeAndIncrement().change(X, Y);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 8: {
			int X                     = ;
			int Y                     = ;
			int expected__[]          = ;

			std::clock_t start__      = std::clock();
			vector <int> received__   = RearrangeAndIncrement().change(X, Y);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
		default:
			return -1;
		}
	}
}

#include <cstdlib>
int main(int argc, char *argv[]) {
	if (argc == 1) {
		moj_harness::run_test();
	} else {
		for (int i=1; i<argc; ++i)
			moj_harness::run_test(std::atoi(argv[i]));
	}
}
// END CUT HERE
