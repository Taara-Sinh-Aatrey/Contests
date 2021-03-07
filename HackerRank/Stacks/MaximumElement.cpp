#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    stack<int> st;

    while(n--) {
        int type;
        cin >> type;

        if(type == 1) {
            int x;
            cin >> x;
            if(st.empty()) {
                st.push(x);
            }
            else {
                int top = st.top();
                st.push(max(top, x));
            }
        }
        else if(type == 2) {
            assert(!st.empty());
            st.pop();
        }
        else {
            assert(type == 3);
            cout << st.top() << '\n';
        }
    }

    return 0;
}