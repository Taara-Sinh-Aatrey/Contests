#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    long long solve(int N, vector<int> A) {
            
        long long cur = 0, ans = 0;
        map<int, int> last;
        for(int i = 0; i < N; i++) {
            cur += i + 1;
            
            if(last.count(A[i])) {
                cur -= last[A[i]] + 1;
            }
            
            last[A[i]] = i;
            
            ans += cur;
        }
        
        return ans;
    }
};

int main() {
    int T;
    cin >> T;
    
    while(T--) {
        int N;
        cin >> N;
        vector<int> A(N);
        
        for(int i = 0; i < N; i++) cin >> A[i];
            
        Solution ob;
        cout << ob.solve(N, A) << '\n';
    }
}