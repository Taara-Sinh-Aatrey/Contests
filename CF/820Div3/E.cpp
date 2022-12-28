/**
 *    author:  Taara Sinh Aatrey
 *    created: 13.09.2022 01:11:20
**/

#include "bits/stdc++.h"

using namespace std;

#ifdef AATREY_DEBUG
#include "debug.hpp"
#else
#define dbg(...)
#endif

#define int int64_t

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
int rand(int a, int b) { return uniform_int_distribution<int>(a, b)(rng); }

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int q = 0;
    const int MAX = 1e18;
    auto ask = [&] (int a, int b) {
        if (max(a, b) > MAX)
            return int64_t(-1);
        assert(q < 50);
        cout << "? " << a << " " << b << endl;
        q++;
        int ret;
        cin >> ret;
        return ret;       
    };
    const int N = 5e14;
    if (ask(1, N) == -1) {
        int low = 1, high = N;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (ask(1, mid) == -1) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        cout << "! " << high << endl;
    }
    else {
        while (true) {
            int x = rand(1, N / 2);
            int y = rand(N / 2 + 1, N);
            int n = ask(x, y) + ask(y, x);
            if (n < N)
                continue;
            if (ask(1, n) != -1 && ask(1, n + 1) == -1) {
                cout << "! " << n << endl; 
                break;
            }
        }
    }
    return 0;
}