#include "bits/stdc++.h"
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
// #pragma GCC optimize("Ofast")
// #pragma GCC target("avx,avx2,fma")
using namespace std;

int main() {
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
    const int N = 2e5 + 5;

    static char stdinBuffer[N];
    static char* stdinDataEnd = stdinBuffer + sizeof (stdinBuffer);
    static const char* stdinPos = stdinDataEnd;

    auto readAhead = [&] (size_t amount) {
        size_t remaining = stdinDataEnd - stdinPos;
        if (remaining < amount) {
           memmove(stdinBuffer, stdinPos, remaining);
           size_t sz = fread(stdinBuffer + remaining, 1, sizeof (stdinBuffer) - remaining, stdin);
           stdinPos = stdinBuffer;
           stdinDataEnd = stdinBuffer + remaining + sz;
           if (stdinDataEnd != stdinBuffer + sizeof (stdinBuffer))
             *stdinDataEnd = 0;
        }
    };

    auto readInt = [&] (int& x) {
        // readAhead(1000);
        x = 0;
        while (*stdinPos >= '0' && *stdinPos <= '9') {
           x = x * 10 + *stdinPos - '0';
           ++stdinPos;
        }
        stdinPos++;
    };

    auto readString = [&] (string& x) {
        // readAhead(1000);
        x = "";
        // while ((*stdinPos >= 'a' && *stdinPos <= 'z') || (*stdinPos >= 'A' && *stdinPos <= 'Z') || (*stdinPos >= '0' && *stdinPos <= '9')) {
        //    x += *stdinPos;
        //    ++stdinPos;
        // }
        while (*stdinPos != ' ' && *stdinPos != '\n' && *stdinPos != 0) {
           x += *stdinPos;
           ++stdinPos;
        }
        stdinPos++;
    };
    
    readAhead(N);
    int n, m, a, b;
    readInt(n); readInt(m); readInt(a); readInt(b);
    int lim[3];
    for (int i = 0; i < 3; i++) readInt(lim[i]);
    int p[n];
    int cnt[n][3];
    int* ptr_p = p;
    auto ptr_cnt = cnt;
    // int (*ptr_cnt)[3] = cnt;
    // printf("%u", ptr_cnt);
    // ++ptr_cnt;
    // cout << ptr_cnt << endl;
    cout << "diff " << (ptr_cnt + 1 - ptr_cnt) << endl; 
    // for (int i = 0; i < 3; i++) cnt[i] = new int[n];
    for (int i = 0; i < n; i++) {
        p[i] = i;
        cnt[i][0] = cnt[i][1] = cnt[i][2] = 0;
    }
    function<int(int)> get = [&] (int x) -> int {
        return (x == p[x] ? x : (p[x] = get(p[x])));
    };
    
    auto unite = [&] (int x, int y) {
        x = get(x);
        y = get(y);
        if (x != y) {
            int tot = 0;
            for (int i = 0; i < 3; i++) {
                if (cnt[x][i] + cnt[y][i] > lim[i]) return false;
                tot += cnt[x][i] + cnt[y][i];
            }
            if (tot > b) return false;
            for (int i = 0; i < 3; i++) {
                cnt[y][i] += cnt[x][i];
                cnt[x][i] = 0;
            }
            p[x] = y;
            return true;
        }
        return false;
    };
    string info[n];
    unordered_map<string, int> id;
    // p = new int[n];
    // cnt = new int*[n];
    for (int i = 0; i < n; i++) {
        string s;
        int d;
        // cin >> s >> d, --d;
        readString(s);
        readInt(d);
        --d;
        info[i] = s;
        cnt[i][d] = 1;
        id[s] = i;
    }
    while (m--) {
        string _u, _v;
        // cin >> _u >> _v;
        readString(_u);
        readString(_v);
        int u = id[_u], v = id[_v];
        unite(u, v);
    }
    int sz[n];
    memset(sz, 0, n << 2);
    for (int i = 0; i < n; i++) {
        sz[get(i)]++;
    }
    int mx = 0;
    for (int i = 0; i < n; i++) {
        if (sz[i] > mx) mx = sz[i];
    }
    if (mx < a) {
        puts("no groups");
        return 0;
    }
    set<string> ans;
    int len = 0;
    for (int i = 0; i < n; i++) {
        if(sz[get(i)] == mx) {
            ans.emplace(info[i]);
            len += 1 + info[i].size();
        }
    }
    // for (auto &me : ans) {
    //     cout << me << '\n';
    // }
    
    char str[len];
    int offset = 0;
    for (auto &me : ans) {
        for (auto& ch : me) {
            str[offset++] = ch;
        }
        str[offset++] = '\n';
    }
    fwrite(str, offset, 1, stdout);
    return 0;
}
