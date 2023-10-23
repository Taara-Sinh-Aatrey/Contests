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

#define ld long double

class SingleOrDouble {
	public:
	double probAlice(int32_t N, int32_t D, int32_t A, int32_t B) {
	    const int MAX = N * D;
	    vector<ld> dp(MAX + 1);
	    dp[0] = 1;
	    for (int i = 0; i < N; i++) {
	    	vector<ld> ndp(MAX + 1);
	    	for (int sm = 0; sm <= MAX; sm++) {
		    	for (int j = 1; j <= D; j++) {
		    		if (sm + j <= MAX) {
		    			ndp[sm + j] += dp[sm];
		    		}
		    	}	    		
	    	}
	    	swap(dp, ndp);
	    }
	    ld tot = 1;
	    for (int i = 0; i < N; i++) {
	    	tot *= D;
	    }
	    for (int i = 0; i <= MAX; i++) {
	    	dp[i] /= tot;
	    }
	    cout << fixed << setprecision(10);
	    return dp[A] * (1 + dp[B]) / (dp[A] * (1 + dp[B]) + dp[B] * dp[B]);
	}
};
#undef int

// BEGIN CUT HERE
#include <algorithm>
#include <cmath>
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
	
	static const double MAX_DOUBLE_ERROR = 1e-9;
	static bool topcoder_fequ(double expected, double result) {
		if (std::isnan(expected)) {
			return std::isnan(result);
		} else if (std::isinf(expected)) {
			if (expected > 0) {
				return result > 0 && std::isinf(result);
			} else {
				return result < 0 && std::isinf(result);
			}
		} else if (std::isnan(result) || std::isinf(result)) {
			return false;
		} else if (std::fabs(result - expected) < MAX_DOUBLE_ERROR) {
			return true;
		} else {
			double mmin = std::min(expected * (1.0 - MAX_DOUBLE_ERROR), expected * (1.0 + MAX_DOUBLE_ERROR));
			double mmax = std::max(expected * (1.0 - MAX_DOUBLE_ERROR), expected * (1.0 + MAX_DOUBLE_ERROR));
			return result > mmin && result < mmax;
		}
	}
	double moj_relative_error(double expected, double result) {
		if (std::isnan(expected) || std::isinf(expected) || std::isnan(result) || std::isinf(result) || expected == 0) {
			return 0;
		}
		return std::fabs(result-expected) / std::fabs(expected);
	}
	
	int verify_case(int casenum, const double &expected, const double &received, std::clock_t elapsed) { 
		std::cerr << "Example " << casenum << "... "; 
		
		string verdict;
		vector<string> info;
		char buf[100];
		
		if (elapsed > CLOCKS_PER_SEC / 200) {
			std::sprintf(buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
			info.push_back(buf);
		}
		
		if (topcoder_fequ(expected, received)) {
			verdict = "PASSED";
			double rerr = moj_relative_error(expected, received); 
			if (rerr > 0) {
				std::sprintf(buf, "relative error %.3e", rerr);
				info.push_back(buf);
			}
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
			int N                     = 1;
			int D                     = 2;
			int A                     = 1;
			int B                     = 2;
			double expected__         = 0.75;

			std::clock_t start__      = std::clock();
			double received__         = SingleOrDouble().probAlice(N, D, A, B);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int N                     = 1;
			int D                     = 6;
			int A                     = 1;
			int B                     = 2;
			double expected__         = 0.8749999999999999;

			std::clock_t start__      = std::clock();
			double received__         = SingleOrDouble().probAlice(N, D, A, B);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int N                     = 2;
			int D                     = 6;
			int A                     = 2;
			int B                     = 7;
			double expected__         = 0.538461538461538;

			std::clock_t start__      = std::clock();
			double received__         = SingleOrDouble().probAlice(N, D, A, B);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int N                     = 3;
			int D                     = 10;
			int A                     = 29;
			int B                     = 16;
			double expected__         = 0.3644067796610159;

			std::clock_t start__      = std::clock();
			double received__         = SingleOrDouble().probAlice(N, D, A, B);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			int N                     = ;
			int D                     = ;
			int A                     = ;
			int B                     = ;
			double expected__         = ;

			std::clock_t start__      = std::clock();
			double received__         = SingleOrDouble().probAlice(N, D, A, B);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			int N                     = ;
			int D                     = ;
			int A                     = ;
			int B                     = ;
			double expected__         = ;

			std::clock_t start__      = std::clock();
			double received__         = SingleOrDouble().probAlice(N, D, A, B);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int N                     = ;
			int D                     = ;
			int A                     = ;
			int B                     = ;
			double expected__         = ;

			std::clock_t start__      = std::clock();
			double received__         = SingleOrDouble().probAlice(N, D, A, B);
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
