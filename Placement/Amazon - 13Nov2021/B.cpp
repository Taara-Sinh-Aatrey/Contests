#include "bits/stdc++.h"
using namespace std;

struct Connection {
    string firstTown;
    string secondTown;
    int cost = 0;
};

class dsu {
public:
    vector<int> p;
    int n;

    dsu(int _n) : n(_n) {
        p.resize(n);
        iota(p.begin(), p.end(), 0);
    }

    inline int get(int x) {
        return (x == p[x] ? x : (p[x] = get(p[x])));
    }

    inline bool unite(int x, int y) {
        x = get(x);
        y = get(y);
        if (x != y) {
            p[x] = y;
            return true;
        }
        return false;
    }
};

vector<Connection> minimumCostConnection(int num, vector<Connection> connection) {
    vector<Connection> edges;
    map<string, int> id;
    for (auto &c : connection)
        id[c.firstTown] = id[c.secondTown] = 0;
    int cnt = 0;
    for (auto &[x, v] : id)
        v = cnt++;
    int n = id.size();
    sort(connection.begin(), connection.end(), [&] (auto &x, auto &y) {
        return x.cost < y.cost;
    });
    dsu d(n);
    int cc = n;
    for (auto &edge : connection) {
        if (!d.unite(id[edge.firstTown], id[edge.secondTown])) continue;
        cc--;
        edges.emplace_back(edge);
    }
    if (cc != 1) {
        edges.clear();
    }
    return edges;
}

int main() {
    // auto edges = minimumCostConnection(5, {{"A", "B", 1}, {"B", "C", 4}, {"B", "D", 6}, {"D", "E", 5}, {"C", "E", 1}});
    auto edges = minimumCostConnection(4, {{"A", "B", 1}, {"B", "C", 4}, {"B", "D", 6}, {"D", "E", 5}});
    for (auto &edge : edges)
        cout << edge.firstTown << " " << edge.secondTown << " " << edge.cost << endl;
    return 0;
}