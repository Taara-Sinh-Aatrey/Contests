#include "bits/stdc++.h"
using namespace std;

vector<vector<int>> shortest_path(int source, int destination, vector<vector<int>> adj) {
int n = adj.size();
    const int inf = 1e9 + 5;
    vector<int> bfs_distance(n, inf);
    queue<int> qu;
    qu.emplace(source);
    bfs_distance[source] = 0;
    
    vector<vector<int>> paths[n];
    paths[source] = {{source}};
    

    while (!qu.empty()) {
        int node = qu.front();
        qu.pop();
        
        for (auto &neighbor : adj[node]) {
            if (bfs_distance[neighbor] > bfs_distance[node] + 1) {
                qu.emplace(neighbor);
                bfs_distance[neighbor] = bfs_distance[node] + 1;
            }
            if (bfs_distance[neighbor] == bfs_distance[node] + 1) {
                for (auto &path : paths[node]) {
                    path.push_back(neighbor);
                    paths[neighbor].push_back(path);
                    path.pop_back();
                }
            }
        }
    }

    return paths[destination];
}

int main() {
    vector<vector<int>> paths = shortest_path(3, 6, {
    {1, 3},
    {0, 2},
    {1},
    {0, 7, 4},
    {3, 7, 6},
    {4, 6},
    {4, 5, 7},
    {3, 4, 6}
});
    for (auto &path : paths) {
        for (auto &node : path) {
            cout << node << " ";
        }
        cout << '\n';
    }
    return 0;
}