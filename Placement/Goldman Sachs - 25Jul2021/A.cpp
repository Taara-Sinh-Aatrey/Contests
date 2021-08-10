#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n;
    cin >> n;
    
    long long sum = 1;
        
    for(long long i = 1; i <= n / 2; i++) {
        long long cur = (2 * i - 1) * (2 * i - 1);
        cur += 2 * i;
        sum += cur; 
        cur += 2 * i;
        sum += cur; 
        cur += 2 * i;
        sum += cur; 
        cur += 2 * i;
        sum += cur; 
    }
    
    cout << sum << '\n';
    
    return 0;
}

