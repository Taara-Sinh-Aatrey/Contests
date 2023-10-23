#include "bits/stdc++.h"
#include <algorithm>
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

class EllysTwinLetters {
	public:
	int getMin(string s) {
	    int n = s.size();
	    vector<vector<int>> dp(2, vector<int>(26, inf));
	    for (int mv = 0; mv < 26; mv++) {
	    	for (auto &ch : {s[0] + mv, s[0] - mv}) {
	    		if ('A' <= ch && ch <= 'Z') {
	    			amin(dp[0][ch - 'A'], mv);
	    		}
	    	}
	    }
	    for (int i = 1; i < n; i++) {
	    	vector<vector<int>> ndp(2, vector<int>(26, inf));
	    	char ch = s[i];
	    	int best = *min_element(dp[1].begin(), dp[1].end());
	    	for (int mv = 0; mv < 26; mv++) {
		    	for (auto &new_ch : {ch + mv, ch - mv}) {
		    		if ('A' <= new_ch && new_ch <= 'Z') {
		    			amin(ndp[0][new_ch - 'A'], best + mv);
		    			amin(ndp[1][new_ch - 'A'], dp[1][new_ch - 'A'] + mv, dp[0][new_ch - 'A'] + mv);
		    		}
		    	}
		    }
		    swap(dp, ndp);
	    }
    	return *min_element(dp[1].begin(), dp[1].end());
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
	
	int verify_case(int casenum, const int &expected, const int &received, std::clock_t elapsed) { 
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
			string S                  = "TOPCODER";
			int expected__            = 30;

			std::clock_t start__      = std::clock();
			int received__            = EllysTwinLetters().getMin(S);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string S                  = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
			int expected__            = 13;

			std::clock_t start__      = std::clock();
			int received__            = EllysTwinLetters().getMin(S);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string S                  = "ESPRIT";
			int expected__            = 25;

			std::clock_t start__      = std::clock();
			int received__            = EllysTwinLetters().getMin(S);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string S                  = "WITHOUTITIMJUSTESPR";
			int expected__            = 54;

			std::clock_t start__      = std::clock();
			int received__            = EllysTwinLetters().getMin(S);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string S                  = "NOZAPHODJUSTVERYVERYIMPROBABLE";
			int expected__            = 93;

			std::clock_t start__      = std::clock();
			int received__            = EllysTwinLetters().getMin(S);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			string S                  = "FROMALLTHETHINGSIVELOSTMYMINDIMISSTHEMOST";
			int expected__            = 111;

			std::clock_t start__      = std::clock();
			int received__            = EllysTwinLetters().getMin(S);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			string S                  = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = EllysTwinLetters().getMin(S);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string S                  = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = EllysTwinLetters().getMin(S);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			string S                  = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = EllysTwinLetters().getMin(S);
			return verify_case(casenum__, expected__, received__, clock()-start__);
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
