/**
 *    author:  Taara Sinh Aatrey
 *    created: 28.12.2022 11:16:47
**/

#include "bits/stdc++.h"

using namespace std;

#ifdef AATREY_DEBUG
#include "debug.hpp"
#else
#define dbg(...)
#endif

#define int int64_t

class A {
public:
    int x;
};

r = q * p / 100
q = r * 100 / p

class B : public A {
public:
    int x;
};

int myHash(string s) {
    int hsh = 0;
    for (int i = 0; i < s.size(); i++) {
        hsh += (i % 2) * (i + 1) * (s[i] - 'a' + 1);
    }
    return hsh;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << (myHash("veoylywz") == myHash("qtmzmzwu")) << endl;
    cout << (myHash("vogxnwpy") == myHash("ofjrdyiy")) << endl;
    cout << (myHash("avzzcwqq") == myHash("sitrntdy")) << endl;
    cout << (myHash("wrsxmvdx") == myHash("quwydsry")) << endl;
    return 0;
}