/**
 *    author:  Taara Sinh Aatrey
 *    created: 17.08.2022 20:37:25
**/

#include "bits/stdc++.h"

using namespace std;

#ifdef AATREY_DEBUG
#include "debug.hpp"
#else
#define dbg(...)
#endif

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) {
        cin >> x;
    }
    int m;
    cin >> m;
    vector<int> b(m);
    for (auto &x : b) {
        cin >> x;
    }
    if (accumulate(a.begin(), a.end(), 0LL) != accumulate(b.begin(), b.end(), 0LL)) {
        cout << 0;
        return 0;
    } 
    int g = 0;
    int k = 0;
    for (int i = 0, j; i < n; i = j) {
        j = i;
        int64_t sum = 0;
        while (j < n && sum < b[k]) {
            sum += a[j++];
        }
        if (sum != b[k]) {
            cout << 0;
            return 0;
        }
        k++;
        int len = j - i;
        if (len != 1) {
            g = gcd(g, len - 1);
        }
    }
    if (g == 0) {
        cout << n << '\n';
        for (int i = 1; i <= n; i++) {
            cout << i << " ";
        }
        return 0;
    }
    vector<int> vec;
    for (int i = 1; i * i <= g; i++) {
        if (g % i) continue;
        vec.emplace_back(i + 1);
        if (g / i != i) {
            vec.emplace_back(g / i + 1);
        }
    }
    sort(vec.begin(), vec.end());
    cout << vec.size() << '\n';
    for (auto &x : vec) {
        cout << x << " ";
    }
    return 0;
}