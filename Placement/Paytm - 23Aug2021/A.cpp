#include <bits/stdc++.h>
using namespace std;

#define int int64_t
const int mod = 1e9 + 7; const int INF = 1e18L + 5; const int N = 2e5 + 5;

struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode(int x) {
        data = x;
        left = right = NULL;
    }
};

int ceil(struct TreeNode* tree, int key) {
    if(!tree) {
        return -1;
    }
    
    if(tree->data > key) {
        int ans = ceil(tree->left, key);
        if(ans != -1) {
            return ans;
        }
    }
    
    if(tree->data >= key) {
        return tree->data;
    }
    
    return ceil(tree->right, key);
}

signed main()
{
    struct TreeNode* tree = new TreeNode(5);
    tree->left = new TreeNode(4);
    tree->right = new TreeNode(8);
    tree->left->left = new TreeNode(1);
    tree->left->right = new TreeNode(3);
    tree->right->left = new TreeNode(6);
    tree->right->right = new TreeNode(10);
    cout << ceil(tree, 7);
    
    return 0;
}