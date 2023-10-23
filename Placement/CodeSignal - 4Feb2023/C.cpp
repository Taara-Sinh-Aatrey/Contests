#include "bits/stdc++.h"

using namespace std;

#ifdef AATREY_DEBUG
#include "debug.hpp"
#else
#define dbg(...)
#endif

vector<vector<char>> solution(vector<vector<char>> board) {
    int n = board.size(), m = board[0].size();
    board.resize(n + 1);
    n++;
    for (int i = 0; i < n; i++) {
        board[i].resize(m + 1, '*');
    }
    m++;
    for (int i = 0; i < n; i++) {
        vector<char> row(m, '.');
        int cnt = 0;
        for (int j = 0; j < m; j++) {
            char ch = board[i][j];
            if (ch == '*') {
                row[j] = '*';
                int k = j - 1;
                while (cnt > 0) {
                    dbg(i, k);
                    row[k--] = '#';
                    cnt--;
                }
                assert(cnt == 0);
            }
            else if (ch == '#') {
                cnt++;
            }
        }
        board[i] = row;
    }
    for (int j = 0; j < m; j++) {
        vector<char> col(n, '.');
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            char ch = board[i][j];
            if (ch == '*') {
                col[i] = '*';
                int k = i - 1;
                while (cnt > 0) {
                    col[k--] = '#';
                    cnt--;
                }
                assert(cnt == 0);
            }
            else if (ch == '#') {
                cnt++;
            }
        }
        for (int i = 0; i < n; i++) {
            board[i][j] = col[i];
        }
    }
    board.resize(n - 1);
    n--;
    for (int i = 0; i < n; i++) {
        board[i].resize(m - 1);
    }
    m--;
    return board;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<char>> board(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }
    dbg(solution(board));
    // dbg(solution({"ls", "cp", "mv", "mv", "mv", "!1", "!3", "!6"}));
    return 0;
}