#include "bits/stdc++.h"
using namespace std;

int main() {
#define int int64_t
    int n;
    cin >> n;
    vector<char> s(n);
    for (auto &ch : s) {
        cin >> ch;
    }
    char I;
    cin >> I;
    vector<int> a;
    for (int i = 0; i < n; i++) {
        if (s[i] == I) {
            a.emplace_back(i);
        }
    }
    n = a.size();
    const int inf = 1e18L + 5;
    int ans = inf;
    auto evaluate = [&] (int mid) {
        int i = n / 2, j = mid;
        int moves = 0;
        while (i < n) {
            moves += abs(a[i] - j);
            i++, j++;
        }
        i = n / 2 - 1, j = mid - 1;
        while (i >= 0) {
            moves += abs(a[i] - j);
            i--, j--;
        }
        ans = min(ans, moves);
        return moves;
    };
    int low = a.front(), high = a.back();
    int sz = a.size();
    while (high - low > 3) {
        int m1 = low + (high - low) / 3;
        int m2 = high - (high - low) / 3;
        int f1 = evaluate(m1);
        int f2 = evaluate(m2);
        if (f1 > f2)
            low = m1;
        else
            high = m2; 
    }
    for (int m = low; m <= high; m++) {
        evaluate(m);
    }
    cout << ans << '\n';
    return 0;
#undef int
}