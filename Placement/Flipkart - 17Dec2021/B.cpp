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
// #include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> cnt(2);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cnt[x]++;
    }
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        if (cnt[a[i]] == 0) {
            break;
        }
        cnt[a[i]]--;
    }
    cout << (cnt[0] + cnt[1]) << '\n';
    return 0;
}