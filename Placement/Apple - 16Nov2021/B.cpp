#include "bits/stdc++.h"
using namespace std;

int main() {
    auto process = [&] (string s) {
        string t = "";
        for (auto &ch : s) {
            if (ch != '#') {
                t += ch;
            }
            else {
                t.pop_back();
            }
        }
        return t;
    };
    string s, t;
    cin >> s >> t;
    cout << (process(s) == process(t) ? 1 : 0);
    return 0;
}