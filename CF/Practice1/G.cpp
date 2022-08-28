/**
 *    author:  Taara Sinh Aatrey
 *    created: 17.08.2022 21:25:28
**/

#include "bits/stdc++.h"

using namespace std;

#ifdef AATREY_DEBUG
#include "debug.hpp"
#else
#define dbg(...)
#endif

int main() {
    int64_t ans = -1, fr = 0;
    while (true) {
        cout << "next\n";
        int64_t x;
        cin >> x;
        if (x == -1) {
            break;
        }
        if (fr == 0) {
            ans = x;
        }
        if (x == ans) {
            fr++;
        }
        else {
            fr--;
        }
    }
    cout << ans << endl;
    return 0;
}