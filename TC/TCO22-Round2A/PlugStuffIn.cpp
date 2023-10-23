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

class PlugStuffIn {
  public:
  #undef int
  vector <int> plug(vector<int> a) {
	  #define int int64_t
	  int n = a.size();
	  vector<int32_t> ans(n, -1);
	  vector<int> ord(n);
	  iota(ord.begin(), ord.end(), 0);
	  sort(ord.begin(), ord.end(), [&] (const int &i, const int &j) {
	  	return a[i] > a[j];
	  });
	  vector<int> devices;
	  vector<int> avail;
	  avail.emplace_back(n);
	  for (auto &i : ord) {
	  	if (a[i] == 0) {
	  		devices.emplace_back(i);
	  	}
	  	else if (!avail.empty()) {
	  		ans[i] = avail.back();
	  		avail.pop_back();
	  		for (int x = 0; x < a[i]; x++) {
	  			avail.emplace_back(i);
	  		}
	  	}
	  }
	  if (devices.size() > avail.size()) {
	  	return vector<int32_t>();
	  }
	  for (auto &i : devices) {
	  	ans[i] = avail.back();
	  	avail.pop_back();
	  }
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
			int gadgets[]             = {0};
			int expected__[]          = {1 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = PlugStuffIn().plug(vector <int>(gadgets, gadgets + (sizeof gadgets / sizeof gadgets[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 1: {
			int gadgets[]             = {1, 1, 0, 1, 1, 1};
			int expected__[]          = {-1, -1, 4, -1, 6, -1 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = PlugStuffIn().plug(vector <int>(gadgets, gadgets + (sizeof gadgets / sizeof gadgets[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 2: {
			int gadgets[]             = {1, 1, 0, 1, 1, 1, 0};
			int expected__[]          = { };

			std::clock_t start__      = std::clock();
			vector <int> received__   = PlugStuffIn().plug(vector <int>(gadgets, gadgets + (sizeof gadgets / sizeof gadgets[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 3: {
			int gadgets[]             = {0, 0, 2, 0, 2};
			int expected__[]          = {2, 4, 5, 4, 2 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = PlugStuffIn().plug(vector <int>(gadgets, gadgets + (sizeof gadgets / sizeof gadgets[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 4: {
			int gadgets[]             = {0, 3, 3};
			int expected__[]          = {3, 2, 1 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = PlugStuffIn().plug(vector <int>(gadgets, gadgets + (sizeof gadgets / sizeof gadgets[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 5: {
			int gadgets[]             = {10, 20, 30, 40};
			int expected__[]          = {-1, 1, -1, -1 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = PlugStuffIn().plug(vector <int>(gadgets, gadgets + (sizeof gadgets / sizeof gadgets[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			int gadgets[]             = ;
			int expected__[]          = ;

			std::clock_t start__      = std::clock();
			vector <int> received__   = PlugStuffIn().plug(vector <int>(gadgets, gadgets + (sizeof gadgets / sizeof gadgets[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 7: {
			int gadgets[]             = ;
			int expected__[]          = ;

			std::clock_t start__      = std::clock();
			vector <int> received__   = PlugStuffIn().plug(vector <int>(gadgets, gadgets + (sizeof gadgets / sizeof gadgets[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 8: {
			int gadgets[]             = ;
			int expected__[]          = ;

			std::clock_t start__      = std::clock();
			vector <int> received__   = PlugStuffIn().plug(vector <int>(gadgets, gadgets + (sizeof gadgets / sizeof gadgets[0])));
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
