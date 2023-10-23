/**
 *    author:  Taara Sinh Aatrey
 *    created: 03.09.2022 17:30:38
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
    string s;
    cin >> s;
    if (s == "Monday") {
        cout << 5;
    }
    else if (s == "Tuesday") {
        cout << 4;
    }
    else if (s == "Wednesday") {
        cout << 3;
    }
    else if (s == "Thursday") {
        cout << 2;
    }
    else if (s == "Friday") {
        cout << 1;
    }
    else {
        cout << 0;
    }
    return 0;
}