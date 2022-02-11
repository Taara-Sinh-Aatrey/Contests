#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

#define int int64_t
const int inf = 1e18L + 5, mod = 1e9 + 7, N = 2e5 + 5;

// a + b = a ^ b + 2 * (a & b)
// x = y + 2 * sth

// a&b = (a+b - a^b) / 2

// 101010101
// 110110101

// 011100000
// 100010101

void solve() {
    int SUM, XOR;
    cin >> SUM >> XOR;
    if ((SUM - XOR) % 2 != 0) {
        cout << -1 << '\n';
        return;
    }
    int AND = (SUM - XOR) / 2;
    if (XOR & AND) {
        cout << -1 << '\n';
        return;
    }
    int a = 0, b = XOR;
    for (int i = 0; i < 60; i++) {
        if (AND >> i & 1) {
            a |= 1LL << i;
            b |= 1LL << i;
        }
    }
    cout << a << " " << b << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve();
    }
    return 0;
}