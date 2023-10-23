/**
 *    author:  Taara Sinh Aatrey
 *    created: 22.08.2022 21:32:57
**/

#include "bits/stdc++.h"

using namespace std;

#ifdef AATREY_DEBUG
#include "debug.hpp"
#else
#define dbg(...)
#endif

#define int int64_t

/*
n = 3, k = 0

0 2 3 1
1 2 3 4 prefix
4 0 0 0 suffix

let's assume that A >= B
|A-B| = k
A - B = k
B = n+1 // 0 [1...n] => sum of suffix mex = n+1
A = n+1 + k
A = n+1+k
target sum of prefix mex = n+k+1
given that array should start from 0
A (ignoring 0) => n+k
=> [0] [1 ..... n]
0 1 3 2 5 6 7 4
  2 3 4 5 6 7 8
  2 3 4 5 6 6 8 => <1
  2 3 4 5 5 5 8 => <1+2
  2 2 4 4 4 4 8 => <1+2+3+1
  
  2 2 4 4 4 4 8
0 1 3 2 5 6 7 4
  
         <2 <1 <0 <2 <1 <0
  
                => <8 => <1+2+3
  
1 2 3 4 4 4 4 8
1...........n+1
max value = (n+1+2)*n/2


*/
int get_diff(vector<int> &a) {
    int n = a.size() - 1;
    int pref_mex = 0;
    int suff_mex = 0;
    {
        set<int> st;
        for (int i = 0; i <= n + 1; i++) {
            st.insert(i);
        }
        for (int i = 0; i <= n; i++) {
            st.erase(a[i]);
            pref_mex += *st.begin();
        }
    }
    {
        set<int> st;
        for (int i = 0; i <= n + 1; i++) {
            st.insert(i);
        }
        for (int i = n; i >= 0; i--) {
            st.erase(a[i]);
            suff_mex += *st.begin();
        }
    }
    return abs(pref_mex - suff_mex);
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        int n, k;
        cin >> n >> k;
        vector<int> vec(n + 1);
        iota(vec.begin(), vec.end(), 0);
        do {
            if (get_diff(vec) == k) {
                {
                    set<int> st;
                    for (int i = 0; i <= n + 1; i++) {
                        st.insert(i);
                    }
                    for (int i = 0; i <= n; i++) {
                        st.erase(vec[i]);
                        cout << *st.begin() << " ";
                    }
                    cout << endl;
                }
            }
        } while (next_permutation(vec.begin(), vec.end()));
        vector<int> a(n + 1);
        a[0] = 0;
        int B = n + 1;
        int req_A = B + k;
        vector<int> pref_mex(n + 1);
        int A = 0;
        for (int i = 0; i <= n; i++) {
            pref_mex[i] = i + 1;
            A += pref_mex[i];
        }
        if (A < req_A) {
            // cout << -1 << '\n';
            cout << "NO" << '\n';
            continue;
        }
        map<int, int> Len;
        {
            int sum = 0, len = 0;
            while (len <= n) {
                sum += len + 2;
                len++;
                Len[sum] = len;
                dbg(sum);
            }
        }
        
        for (int i = n; i > 0;) {
            int req_decrement = A - req_A;
            int sum = 0, len = 0;
            while (sum + len + 1 <= req_decrement && (!Len.count(req_decrement - sum) || Len[req_decrement - sum] + 1 + len + 1 > i + 1)) {
                sum += len + 1;
                len++;
            }
            int next_i = i - len - 1;
            int left = i - len, right = i - 1;
            dbg(left, right, sum, req_decrement);
            for (int x = right; x >= left; x--) {
                pref_mex[x] -= len--;
            }
            i = next_i;
            A -= sum;
        }   
        if (A != req_A && Len.count(A - req_A)) {
            int len = Len[A - req_A];
            int left = 0;
            int right = 0 + len - 1;
            for (int x = left; x <= right; x++) {
                pref_mex[x] = 0;
            }
            A = req_A;
        }
        // if (A != req_A) {
            
        // }
        set<int> st;
        for (int i = 0; i <= n + 1; i++) {
            st.emplace(i);
        }
        for (int i = 0; i <= n; i++) {
            if (pref_mex[i] == *st.begin()) {
                a[i] = *next(st.begin());
            }
            else {
                a[i] = *st.begin();
            }
            st.erase(a[i]);
        }
        if (get_diff(a) != k) {
            cout << "NO" << '\n';
            continue;
        }
        cout << "YES" << '\n';
        // for (auto &x : a) {
        //     cout << x << " ";
        // }
    }
    return 0;
}
// 1 2 0 3 4 5 6
// 1 2 3 4 5 6 7
// 0 0 3 4 5 6 7
// 7 0 0 0 0 0 0
// 7 1 1 0 0 0 0

// n*1+(n+1)-(n+1) = n
// 0   0  0 0  0  6 7
// 7  1  1  1  1  1   1  0
// 0 1 2 3 4 5 6
// 0 0 0 0 0 1 7
// 7 0 0 0 0 0 0