#include "bits/stdc++.h"
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    // a map to store frequency of each characters
    map<char, int> cnt;
    for (int i = 0; i < n; i++) {
        cnt[s[i]]++;
    }
    
    map<char, bool> cant_replace_with;
    
    char replace = 'a';
    
    for (int i = 0; i < n; i++) {
        char cur = s[i];
        
        // finding the minimum character to replace with
        while (replace <= 'z' && (cnt[replace] == 0 || cant_replace_with[replace])) {
            replace++;
        }
        
        if (replace <= 'z' && replace < s[i]) {
            // replace `s[i]` with `replace`
            // replace `replace` with `s[i]`
            
            for (int j = 0; j < n; j++) {
                if (s[j] == cur) {
                    s[j] = replace;
                }
                else if (s[j] == replace) {
                    s[j] = cur;
                }
            }
            
            replace++;
        }
        
        cant_replace_with[s[i]] = true;
    }
    cout << s << endl;
    return 0;
}