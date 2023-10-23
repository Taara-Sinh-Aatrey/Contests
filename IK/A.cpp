#include "bits/stdc++.h"
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> children(n + 1);
    for (int i = 0; i < n; i++) {
        int node;
        cin >> node;
        int number_of_children;
        cin >> number_of_children;
        for (int i = 0; i < number_of_children; i++) {
            int child;
            cin >> child;
            children[node].push_back(child);
        }
    }
    int r, s, k;
    cin >> r >> s >> k;
    // O(n) space
    vector<int> parent(n + 1, 0);
    function<void(int)> dfs = [&] (int node) {
        for (auto &child : children[node]) {
            parent[child] = node;
            dfs(child);
        }
    };
    // O(n) time
    dfs(r);
    // O(n) space
    set<int> visited;
    int node = s;
    int distance = 0;
    
    // O(n) space
    vector<int> ans;
    
    while (node != 0) {
        // explore the subtree of this node except the vertical path already traversed
        
        function<void(int, int)> go_below = [&] (int node, int d) {
            if (visited.count(node)) {
                return;
            }
            if (d == k) {
                ans.push_back(node);
                return;
            }
            for (auto &child : children[node]) {
                go_below(child, d + 1);
            }
        };
        
        go_below(node, distance);
        
        visited.insert(node);
        node = parent[node];
        distance++;
    }
    
    for (auto &x : ans) {
        cout << x << " ";
    }
    
    return 0;
}