#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll secretInfo(string text, string pat) {
    ll ret = 0;
    
    ll m = pat.length();
    vector<ll> lps(m, 0);
    
    for (ll i = 1, len = 0; i < m; ) {
        if (pat[i] == pat[len]) {
            lps[i] = ++len;
            i++;
        }
        else {
            if (len != 0) {
                len = lps[len - 1];
            }
            else {
                lps[i] = len;
                i++;
            }
        }
    }
    
    ll n = text.length();
    
    for (ll i = 0, j = 0, next_i = 0; i < n; ) {
        if (pat[j] == text[i]) {
            j++, i++;
        }
        if (j == m) {
            ret++;      
            j = lps[j - 1];
        }
        else if (i < n && pat[j] != text[i]) {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }
    return ret;
}
 
int main()
{
    cout << secretInfo("aaacaaaa", "abacabad");
    cout << secretInfo("aaacaaaa", "aaa");
     
    return 0;
}