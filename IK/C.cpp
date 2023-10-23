#include "bits/stdc++.h"
using namespace std;

int main() {
    // 1 7 5 3 2  6 1 4 5
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> round(n, -1);
    vector<int> mx_right(n, -1);
    stack<int> st;
    for (int i = 0; i < n; i++) {
        
        while (!st.empty() && a[st.top()] <= a[i]) {
            int popped = st.top();
            st.pop();
            if (!st.empty()) {
                int top = st.top();
                mx_right[top] = max(mx_right[top], round[popped]);
                mx_right[top] = max(mx_right[top], mx_right[popped]);
            }
        }
        // if it can be removed by its immediate neighbor
        // it will be removed in round 1
        if (i > 0 && a[i - 1] > a[i]) {
            round[i] = 1;
        }
        // otherwise we know the righmost element in my left
        // which will delete me
        // we can know the max no of rounds any element 
        // in between survived by the value mx_right[st.top()]
        else if (!st.empty()) {
            round[i] = mx_right[st.top()] + 1;
        }
        
        st.push(i);
        
    }
    
    // for (int i = 0; i < n; i++) {
    //     cout << round[i] << " \n"[i == n - 1];
    // }
    
    cout << *max_element(round.begin(), round.end()) << endl;
    
    return 0;
}