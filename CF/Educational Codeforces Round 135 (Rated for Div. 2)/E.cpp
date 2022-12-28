/**
 *    author:  Taara Sinh Aatrey
 *    created: 18.09.2022 00:02:09
**/

#include "bits/stdc++.h"

using namespace std;

#ifdef AATREY_DEBUG
#include "debug.hpp"
#else
#define dbg(...)
#endif

class manacher {
public:
    string &s;
    vector<int> p;
    
    manacher(string &_s) : s(_s) {
        string t;
        for (char &c : s) {
            t += string("#") + c;
        }
        t += "#";
        int n = t.size();
        t = "$" + t + "^";
        p.resize(n + 2);
        int l = 1, r = 1;
        for(int i = 1; i <= n; i++) {
            p[i] = max(0, min(r - i, p[l + (r - i)]));
            while(t[i - p[i]] == t[i + p[i]]) {
                p[i]++;
            }
            if (i + p[i] > r) {
                l = i - p[i], r = i + p[i];
            }
        }
        p = vector<int>(p.begin() + 1, p.end() - 1);
    }
    
    bool is_palindrome(int l, int r) {
        l = 2 * l + 1, r = 2 * r + 1;
        int m = (l + r) / 2;
        return p[m] >= m - l + 1;
    }
};

class trie {
public:
    vector<vector<int>> child;
    vector<int> val;
    const char MIN_CHAR = 'a';
    const int alphabet = 26;
    
    int create_node() {
        child.emplace_back(alphabet, -1);
        val.emplace_back(-1);
        return child.size() - 1;
    }
    
    trie() {
        create_node();
    }
    
    trie(vector<string> &a) {
        create_node();
        for (int i = 0; i < a.size(); i++)
            add(a[i], i);
    }
   
    void add(string s, int value) {
        int cur = 0;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            int ch = s[i] - MIN_CHAR;
            if (child[cur][ch] == -1) child[cur][ch] = create_node();
            cur = child[cur][ch];
        }
        val[cur] = value;
    }
    
    int search(string s, int start = 0) {
        int cur = start;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            int ch = s[i] - MIN_CHAR;
            if (child[cur][ch] == -1)
                return -1;
            cur = child[cur][ch];
        }
        return cur;
    }
    
    void remove(string s) {
        int cur = 0;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            int ch = s[i] - MIN_CHAR;
            cur = child[cur][ch];
            assert(cur != -1 && val[cur] > 0);
        }
        val[cur] = -1;
    }
};


class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        int n = words.size();
        set<vector<int>> ans;
        auto Insert = [&] (int i, int j) {
            if (i != j)
                ans.insert({i, j});    
        };
        trie fwd, rev;
        for (int i = 0; i < n; i++) {
            string s = words[i];
            
            fwd.add(s, i);
            reverse(s.begin(), s.end());
            rev.add(s, i);
        }
        for (int it = 0; it < n; it++) {
            string &s = words[it];
            int sz = s.size();
            manacher man(s);
            {
                auto &child = rev.child;
                auto &val = rev.val;
                // words[it] + words[...]
                int cur = 0;
                for (int i = -1; i < sz; i++) {
                    if (i != -1)
                        cur = child[cur][s[i] - 'a'];
                    if (cur == -1)
                        break;
                    if (val[cur] != -1 && (i + 1 > sz - 1 || man.is_palindrome(i + 1, sz - 1))) {
                        Insert(it, val[cur]);
                    }
                }
            }
            
            // words[...] + words[it]
            {
                auto &child = fwd.child;
                auto &val = fwd.val;
                int cur = 0;
                for (int i = sz; i >= 0; i--) {
                    if (i != sz)
                        cur = child[cur][s[i] - 'a'];
                    if (cur == -1)
                        break;
                    if (val[cur] != -1 && (0 > i - 1 || man.is_palindrome(0, i - 1))) {
                        Insert(val[cur], it);
                    }
                }
            }
        }
        return vector<vector<int>>(ans.begin(), ans.end());
    }
};

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s = "abdjafdfaabbaafdfaa";
    manacher man(s);
    int n = s.size();
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            string a = s.substr(i, j - i + 1);
            string b = a;
            reverse(b.begin(), b.end());
            assert((a == b) == man.is_palindrome(i, j));
        }
    }
    return 0;
}