#include "bits/stdc++.h"
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    vector<int> last(26, -1);
    for (int i = 0; i < n; i++) {
        last[s[i] - 'a'] = i;
    }
    int i = 0;
    vector<pair<int, int>> segments;
    vector<int> lengths;
    while (i < n) {
        int start = i, end = i;
        // we are handling every case
        for (int x = start; x <= end; x++) {
            end = max(end, last[s[x] - 'a']);
        }
        lengths.push_back(end - start + 1);
        segments.push_back({start, end});
        i = end + 1;
    }
    return 0;
}