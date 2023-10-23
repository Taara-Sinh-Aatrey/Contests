#include <bits/stdc++.h>

using namespace std;

""

int solution(string S) {
  map<char, int> right;
  for (char &ch : S) {
    right[ch]++;
  }
  
  int ans = right.size();
  
  set<char> left;
  for (char &ch : S) {
    // exclude ch from the right set and include ch in the left set
    right[ch]--;
    if (right[ch] == 0) {
      right.erase(ch);
    }
    left.insert(ch);
    
    ans = max(ans, (int) (left.size() + right.size()));
  }
  return ans;
}