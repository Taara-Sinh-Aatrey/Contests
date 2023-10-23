#include "bits/stdc++.h"
using namespace std;

#define int int64_t

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    // The idea is to find the next smaller and previous smaller of each element. 
    // let's say element is at i
    // previous smaller is at l
    // next smaller is at r
    
    // (r - l - 1) will be the biggest window for which
    // a[i] will be the minimum of window
    
    // so, we will update for the window size of
    // r-l+1 nahi hoga
    // r-l-1 that a[i] is a potential answer
    
    // at the end, we need to do 
    // for (int i = n - 1; i >= 1; i--)
    // ans[i] = max(ans[i], ans[i + 1])
    
    // we can understand this through an example
    
    // if a[i] is minimum for window length of 10, then we can say that it is also minimum for window length of 9,8,....1
    
    // because we can always pick subarray of
    // lesser size than 10 having a[i] from the subarray of 10 elements
    
    // bol de ki I am confident

    void printMaxOfMin(int arr[], int n) {
    stack<int> s;

    int left[n + 1];
    int right[n + 1];
 
    for (int i = 0; i < n; i++) {
        left[i] = -1;
        right[i] = n;
    }
 
    for (int i = 0; i < n; i++) {
        while (!s.empty() && arr[s.top()] >= arr[i])
            s.pop();
 
        if (!s.empty())
            left[i] = s.top();
 
        s.push(i);
    }
 
    // Empty the stack as stack is
    // going to be used for right[]
    while (!s.empty())
        s.pop();
 
    // Fill elements of right[] using same logic
    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() && arr[s.top()] >= arr[i])
            s.pop();
 
        if (!s.empty())
            right[i] = s.top();
 
        s.push(i);
    }

    vector<int> ans(n + 1, 0); 
    for (int i = 0; i < n; i++) {
        int len = right[i] - left[i] - 1;
        ans[len] = max(ans[len], arr[i]);
    }

    for (int i = n - 1; i >= 1; i--)
        ans[i] = max(ans[i], ans[i + 1]);
}
    

}