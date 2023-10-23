/**
 *    author:  Taara Sinh Aatrey
 *    created: 25.12.2022 16:20:28
**/

#include "bits/stdc++.h"

using namespace std;

#ifdef AATREY_DEBUG
#include "debug.hpp"
#else
#define dbg(...)
#endif

#define int int64_t

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    int n = s.size();
    stack<int> st;
    set<char> ss;
    bool ok = true;
    for (int i = 0; i < n; i++) {
        char ch = s[i];
        if (ch == '(') {
            st.emplace(i);
        }
        else if (ch == ')') {
            while (s[st.top()] != '(') {
                auto it = ss.find(s[st.top()]);
                if (it != ss.end()) {
                    ss.erase(it);
                }
                st.pop();
            }
            st.pop();
        }
        else {
            st.emplace(i);
            if (ss.count(ch)) {
                ok = false;
                break;
            }
            ss.emplace(ch);           
        }
    }
    cout << (ok ? "Yes" : "No") << '\n';
    return 0;
}