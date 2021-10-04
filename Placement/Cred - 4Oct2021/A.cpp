#include "bits/stdc++.h"
using namespace std;

int minimumFlips(string s) {
    char cur = '0';
    int flips = 0;
    for (char ch : s) {
        flips += cur != ch;
        cur = ch;
    }
    return flips;
}

int main() {
    cout << minimumFlips("01001") << endl;
    cout << minimumFlips("0011") << endl;
    return 0;
}