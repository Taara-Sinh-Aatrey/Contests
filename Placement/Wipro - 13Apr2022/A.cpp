#include "bits/stdc++.h"
using namespace std;

int main() {
    int n;
    cin >> n;
    map<string, int> mp;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        mp[s]++;
    }
    int k;
    cin >> k;
    for (int i = 0; i < k; i++) {
        string s;
        cin >> s;
        cout << mp[s] << " ";
    }
    return 0;
}