#include <bits/stdc++.h>
using namespace std;


#define ll long long
const ll mod = 1e9 +7;

long long getCount(string str) {
    int n = str.size();
    
    if(n <= 2) {
        return 0LL;
    }
    
    if(str[0] != '?' && str[n - 1] != '?' && str[0] != str[n - 1]) {
        return 0LL;
    }
    
    if(str[0] == '?') {
        str[0] = str[n - 1];
    }
    else {
        str[n - 1] = str[0];
    }
        
    auto fun = [&]() {
        vector<ll> dp(26, 0);
        ll tot = 1;
        for(int i = 0; i < n; i++) {
            
            vector<ll> ndp(26, 0);
            ll ntot = 0;
            
            for(int j = 0; j < 26; j++) {
                if(str[i] == '?' || str[i] == char('a' + j)) {
                    ndp[j] = (tot + mod - dp[j]) % mod;
                    ntot = (ntot + ndp[j]) % mod;
                }
            }
            
            dp = ndp;
            tot = ntot;
        }
        return dp[str[n - 1] - 'a'];
    };
    
    ll tot = 0;
    if(str[0] != '?') {
        tot = fun();
    }
    else {
        for(char ch = 'a'; ch <= 'z'; ch++) {
            str[0] = str[n - 1] = ch;
            tot = (tot + fun()) % mod;
        }
    }
    
    return tot;
    
}

signed main()
{
    cout << getCount("abcd") << endl;
    cout << getCount("abc?") << endl;
    cout << getCount("a?za") << endl;
    cout << getCount("abca") << endl;
    cout << getCount("?a?b?") << endl;
    cout << getCount("?????") << endl;
    cout << getCount("a") << endl;
        
    return 0;
}