#include <bits/stdc++.h>
using namespace std;

#define int int64_t
const int mod = 1e9 + 7; const int INF = 1e18L + 5; const int N = 2e5 + 5;

string solve(string s) {
    
    int n = s.size();
    
    map<char, int> f;
    int j;
    for(int i = 0; i < n; i = j) {
        string d = "";
        for(j = i + 1; j < n && '0' <= s[j] && s[j] <= '9'; j++) { 
            d += s[j];
        }
        int x = stoll(d);
        f[s[i]] += x;
    }
    
    string ret = "";
    for(auto& [ch, fr] : f) {
        ret += ch;
        ret += to_string(fr);
    }
    
    return ret;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << solve("a12b56c1") << endl;
    cout << solve("a3c9b2c1") << endl;
    
    return 0;
}