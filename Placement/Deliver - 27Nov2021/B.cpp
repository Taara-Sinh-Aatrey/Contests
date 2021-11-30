#include<bits/stdc++.h>
using namespace std;


int M, N;
vector<vector<int>> g;

bool bpm(int u,
        bool seen[], int matchR[])
{
    for (auto &v : g[u])
    {
        if (!seen[v]) {
            seen[v] = true;
            if (matchR[v] < 0 || bpm(matchR[v],
                                    seen, matchR)) {
                matchR[v] = u;
                return true;
            }
        }
    }
    return false;
}

int maxBPM() {
    int matchR[N];

    memset(matchR, -1, sizeof(matchR));

    int result = 0;
    for (int u = 0; u < M; u++)
    {
        bool seen[N];
        memset(seen, 0, sizeof(seen));

        if (bpm(u, seen, matchR))
            result++;
    }
    return result;
}

int main()
{
    cin >> M;
    g.resize(M);
    for (int u = 0; u < M; u++) {
        int sz;
        cin >> sz;
        for (int i = 0; i < sz; i++) {
            int v;
            cin >> v, --v;
            if (v < 0) continue;
            g[u].emplace_back(v);
        }
    }
    int R, C;
    cin >> R >> C;
    N = R * C;
    cout << maxBPM() << '\n';
    return 0;
}
