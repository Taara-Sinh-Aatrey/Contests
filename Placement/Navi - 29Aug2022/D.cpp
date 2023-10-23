#include "bits/stdc++.h"
using namespace std;

struct treenode {
    int data;
    treenode *left;
    treenode *right;
    treenode (int _data, treenode* _left = nullptr, treenode* _right = nullptr) {
        data = _data;
        left = _left;
        right = _right;
    }
};

// No
// because we are careful everywhere

treenode* build_tree(string &s, int start, int end) {
    if (s[start] == '(') {
        // means string is like (root(left)(right))
        start++;
        end--;
    }
    // now let's extract value of root
    int root_value = 0;
    int idx = 0;
    // EK galti hai
    // -ve numbers handle karna hoga
    bool is_neg = false;
    if (idx <= end && s[idx] == '-') {
        is_neg = true;
        idx++;
    }
    while (idx <= end && isdigit(s[idx])) {
        root_value = root_value * 10 + (s[idx++] - '0');
    }
    if (is_neg) root_value *= -1;
    treenode *left = nullptr, *right = nullptr;
    if (idx <= end) { // check if there is a left subtree or not
        // left tree must be in form of ( left )
        int left_start = idx;
        // cnt will store frequency of '(' - frequency of ')'
        int cnt = 0;
        int left_end = left_start;
        
        // abe dekh na saale ki left kahan end ho raha hai
        // 4 ( 67 ( 34 )  ) 
        //   +1   +2  -1   0
        
        while (left_end <= end) {
            if (!isdigit(s[left_end])) {
                cnt += s[left_end] == '(' ? 1 : -1;
            }
            if (cnt == 0) {
                // we found the left_end
                left = build_tree(s, left_start, left_end);
                break;
            }
            left_end++;
        }
        // check if there is a right subtree
        if (left_end + 1 <= end) {
            int right_start = left_end + 1;
            int right_end = right_start;
            int cnt = 0;
            while (right_end <= end) {
                if (!isdigit(s[right_end])) {
                    cnt += s[right_end] == '(' ? 1 : -1;
                }
                if (cnt == 0) {
                    right = build_tree(s, right_start, right_end);
                    break;
                }
                right_end++;
            }
        }
    }
    return new treenode(root_value, left, right);
}

int main() {
    string s;
    cin >> s;
    int n = s.size();
    treenode* root = build_tree(s, 0, n - 1);
    return 0;
}