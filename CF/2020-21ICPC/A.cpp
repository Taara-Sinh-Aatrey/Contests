/**
 *    author:  Taara Sinh Aatrey
 *    created: 10.06.2023 18:49:11
**/

#include "bits/stdc++.h"

using namespace std;

#ifdef AATREY_DEBUG
#include "debug.hpp"
#else
#define dbg(...)
#endif

#define int int64_t

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    for (int x : {49, 50, 51, 52}) {
    	for (int a = 1; a < x; a++) {
    		int b = x - a;
    		if (a * b == 616) {
    			cout << x << endl;
    		}
    	}
    }
    return 0;
}