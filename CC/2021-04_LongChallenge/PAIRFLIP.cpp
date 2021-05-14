#include<bits/stdc++.h>
using namespace std;

#define int long long

        
template <typename A, typename B>
string to_string(pair<A, B> p);

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);

string to_string(const string& s) {
    return '"' + s + '"';
}

string to_string(const char* s) {
    return to_string((string) s);
}

string to_string(bool b) {
    return (b ? "true" : "false");
}

string to_string(vector<bool> v) {
    bool first = true;
    string res = "{";
    for (int i = 0; i < static_cast<int>(v.size()); i++) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(v[i]);
    }
    res += "}";
    return res;
}

template <size_t N>
string to_string(bitset<N> v) {
    string res = "";
    for (size_t i = 0; i < N; i++) {
        res += static_cast<char>('0' + v[i]);
    }
    return res;
}

template <typename A>
string to_string(A v) {
    bool first = true;
    string res = "{";
    for (const auto &x : v) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(x);
    }
    res += "}";
    return res;
}

template <typename A, typename B>
string to_string(pair<A, B> p) {
    return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
    return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";
}

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
    return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}

#define CERR cout
// #define CERR cerr

void debug_out() { CERR << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    CERR << " " << to_string(H);
    debug_out(T...);
}

#ifndef ONLINE_JUDGE
#define dbg(...) CERR << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define dbg(...) 42
#endif

void solve(int tt) {
    int n, m, e;
    cin >> n >> m >> e;

    bool question_mark = false;

    int op = 0;

    vector<vector<int>> a(n, vector<int>(m));
    vector<bool> parity(n);
    int x = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            char ch;
            cin >> ch;
            a[i][j] = (ch == '1');
        }
    }
    for(int i = 0; i < n; i++) {
        int cnt = 0;
        for(int j = 0; j < m; j++) {
            char ch;
            cin >> ch;
            if(ch == '?') {
                a[i][j] = 2;
                question_mark = true;
            } else {                
                a[i][j] ^= (ch == '1');
                if(a[i][j] == 1) {
                    cnt++;
                }
            }

            // cout << a[i][j] << " \n"[j + 1 == m];
        }
        parity[i] = cnt & 1;
        x += cnt & 1;
    }


    vector<pair<int, int>> ans_c[m];
    vector<pair<int, int>> ans_r[n];

    vector<array<int, 3>> pairs;

    for(int j = 0; j < m; j++) {
        int pvi = -1;
        for(int i = 0; i < n; i++) {
            if(a[i][j] == 1 && parity[i] == 1) {
                if(pvi == -1) {
                    pvi = i;
                } else {
                    pairs.push_back({pvi, i, j});
                    pvi = -1;
                }
            }
        }
    }

    sort(pairs.begin(), pairs.end());

    for(auto& [pvi, i, j] : pairs) {
        if(parity[pvi] == 0 || parity[i] == 0) continue;
        ans_c[j].emplace_back(pvi, i);
        op++;
        a[pvi][j] = 0;
        a[i][j] = 0;
        parity[pvi] = 0;
        parity[i] = 0;
    }

    vector<int> odd_row_num_col(m, -1);

    // A column will have atmost one 1 of an odd row

    for(int i = 0; i < n; i++) {
        if(parity[i]) {
            for(int j = 0; j < m; j++) {
                if(a[i][j] == 1) {
                    // assert(odd_row_num_col[j] == -1);
                    odd_row_num_col[j] = i;
                }
            }
        }
    }

    queue<int> q;
    for(int i = 0; i < n; i++) {
        if(parity[i]) continue;
        q.push(i);
    }

    while(!q.empty()) {
        int r = q.front();
        q.pop();

        map<int, int> mp;
        for(int c = 0; c < m; c++) {
            if(a[r][c] != 1) continue;
            mp[odd_row_num_col[c]] = c;
        }
        // dbg(mp);

        pair<int, int> pv{-1, -1};
        for(auto [_r, c] : mp) {
            if(pv.first == -1) {
                pv = {_r, c};
            } else {
                ans_c[pv.second].push_back({r, pv.first});
                ans_c[c].push_back({r, _r});
                op += 2;

                for(int j = 0; j < m; j++) {
                    if(a[pv.first][j] == 1) {
                        odd_row_num_col[j] = -1;
                    }
                    if(a[_r][j] == 1) {
                        odd_row_num_col[j] = -1;
                    }
                }

                a[r][pv.second] = 0;
                a[pv.first][pv.second] = 0;
                a[r][c] = 0;
                a[_r][c] = 0;

                parity[pv.first] = 0;
                parity[_r] = 0;
                q.push(pv.first);
                q.push(_r);

                pv = {-1, -1};

            }
        }

        int pvc = -1;

        for(int c = 0; c < m; c++) {
            if(a[r][c] != 1) continue;
            if(pvc == -1) {
                pvc = c;
            } else {
                ans_r[r].emplace_back(pvc, c);
                op++;
                a[r][pvc] = 0;
                a[r][c] = 0;
                pvc = -1;
            }
        }

        
    }

    pair<int, int> w = {-1, -1};

    for(int r = 0; r < n; r++) {
        if(parity[r] == 0) {
            for(int c = 0; c < m; c++) {
                // assert(a[r][c] != 1);
            }
        } else {
            int pvc = -1;
            for(int c = 0; c < m; c++) {
                if(a[r][c] != 1) continue;
                if(pvc == -1) {
                    pvc = c;
                } else {
                    ans_r[r].emplace_back(pvc, c);
                    op++;
                    a[r][pvc] = 0;
                    a[r][c] = 0;
                    pvc = -1;
                }
            }

            // assert(pvc != -1);
            if(w.first == -1) {
                w = {r, pvc};
            } else {
                ans_r[w.first].emplace_back(w.second, pvc);
                ans_c[pvc].emplace_back(w.first, r);
                op += 2;
                a[w.first][w.second] = 0;
                a[r][pvc] = 0;
                w = {-1, -1};
            }
        }
    }

    for(int r = 0; r < n; r++) {
        for(int c = 0; c < m; c++) {
            if(a[r][c] == 1) {
                cout << -1 << '\n';
                return;
            }
        }
    }

    // if(question_mark && x & 1) {

    // } else {
        
    // }
    cout << op << '\n';
    if(e == 0) {
        return;
    }
    for(int r = 0; r < n; r++) {
        for(auto [c1, c2] : ans_r[r]) {
            cout << 'R' << " " << r + 1 << " " << c1 + 1 << " " << c2 + 1 << '\n';
        }
    }
    for(int c = 0; c < m; c++) {
        for(auto [r1, r2] : ans_c[c]) {
            cout << 'C' << " " << c + 1 << " " << r1 + 1 << " " << r2 + 1 << '\n';
        }
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("err", "w", stderr);

    int t;
    cin >> t;

    for(int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
    

    return 0;
}