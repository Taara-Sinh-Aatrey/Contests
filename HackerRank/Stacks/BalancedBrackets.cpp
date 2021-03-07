#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        string s;
        cin >> s;

        map<char, char> matching_bracket;
        matching_bracket['}'] = '{';
        matching_bracket[']'] = '[';
        matching_bracket[')'] = '(';

        bool possible = true;

        stack<char> st;

        for(int i = 0; s[i]; i++) {

            if(s[i] == '{' || s[i] == '[' || s[i] == '(') {
                st.push(s[i]);
            }
            else {
                if(st.empty() || st.top() != matching_bracket[s[i]]) {
                    possible = false;
                    break;
                } else {
                    st.pop();
                }
            }

        }

        cout << (st.empty() && possible ? "YES" : "NO") << '\n';
    }

    return 0;
}

