#include "bits/stdc++.h"

using namespace std;

#ifdef AATREY_DEBUG
#include "debug.hpp"
#else
#define dbg(...)
#endif

#define int int64_t

struct node {
    int val, count;
    node *left, *right;
    node(int _val) : val(_val), count(0), left(nullptr), right(nullptr) {}
    node() : node(0) {}
};

node* insert(node *cur, int val) {
    if (cur == nullptr) return new node(val);
    
    if (val > cur->val)
        cur->right = insert(cur->right, val);
    else
        cur->left = insert(cur->left, val);
    
    return cur;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    node *root = nullptr;
    for (auto &x : a) {
        cin >> x;
        root = insert(root, x);
    }
    int source, destination, target;
    cin >> source >> destination >> target;
    
    dbg(a, source, destination, target);
    
    auto find = [&] (int val) {
        node *cur = root;
        while (cur) {
            cur->count++;
            
            if (cur->val == val)
                break;
            else if (val > cur->val)
                cur = cur->right;
            else
                cur = cur->left;
        }
    };
    find(source);
    find(destination);
    
    node *lca = root;
    while (lca) {
        if (lca->left && lca->left->count == 2) {
            lca = lca->left;
        }
        else if (lca->right && lca->right->count == 2) {
            lca = lca->right;
        }
        else {
            break;
        }
    }
    
    int ans = 0;
    
    auto traverse = [&] (int val) {
        node *cur = lca;
        while (cur) {
            if (a[cur->val - 1] > target) {
                ans++;
            }
            
            if (cur->val == val)
                break;
            else if (val > cur->val)
                cur = cur->right;
            else
                cur = cur->left;
        }
    };
    
    traverse(source);
    traverse(destination);
    ans -= a[lca->val - 1] > target;
    
    cout << ans << '\n';
    
    return 0;
}