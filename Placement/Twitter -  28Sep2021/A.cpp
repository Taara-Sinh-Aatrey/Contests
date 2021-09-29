#include "bits/stdc++.h"
using namespace std;

int restock(vector<int> a, int m) {
    for (int i = 0; i < a.size() && m > 0; i++) {
        m -= a[i];
    }
    return abs(m);
}

int main() {
    cout << restock({6, 1, 2, 1}, 100);
    return 0;
}