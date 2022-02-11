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
using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    const int mod = 1e9 + 7;
    int ans = 1;
    vector<int> v;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            v.emplace_back(i);
        }
    }
    int sz = v.size();
    for (int i = 2; i < sz; i += 2) {
        ans = ans * 1LL * (v[i] - v[i - 1]) % mod;
    }
    if (sz % 2 == 1) {
        ans = -1;
    }
    cout << ans << '\n';
    return 0;
}

