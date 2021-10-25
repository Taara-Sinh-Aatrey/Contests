#include "bits/stdc++.h"
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
using namespace std;

static char stdinBuffer[100005];
static char* stdinDataEnd = stdinBuffer + sizeof (stdinBuffer);
static const char* stdinPos = stdinDataEnd;

void readAhead(size_t amount)
{
    size_t remaining = stdinDataEnd - stdinPos;
    if (remaining < amount) {
       memmove(stdinBuffer, stdinPos, remaining);
       size_t sz = fread(stdinBuffer + remaining, 1, sizeof (stdinBuffer) - remaining, stdin);
       stdinPos = stdinBuffer;
       stdinDataEnd = stdinBuffer + remaining + sz;
       if (stdinDataEnd != stdinBuffer + sizeof (stdinBuffer))
         *stdinDataEnd = 0;
    }
}

void readInt(int& x) {
    readAhead(16);
    x = 0;
    while (*stdinPos >= '0' && *stdinPos <= '9') {
       x = x * 10 + *stdinPos - '0';
       ++stdinPos;
    }
    stdinPos++;
}

void readString(string& x) {
    readAhead(100005);
    x = "";
    while (*stdinPos >= '0' && *stdinPos <= '1') {
       x += *stdinPos;
       ++stdinPos;
    }
    stdinPos++;
}

int main() {
    string s; readString(s);
    // cin >> s;
    int n = s.size();
    int mx[2];
    mx[0] = mx[1] =  -1;
    for (int i = 0, j; i < n; i = j) {
        j = i;
        if (s[j] == '1') {
            j++;
            continue;
        }
        for ( ;j < n && s[j] == '0'; j++) ;
        int cur = j - i;
        if (cur > mx[0]) {
            mx[1] = mx[0];
            mx[0] = cur;
        }
        else if(cur > mx[1]) {
            mx[1] = cur;
        }
    }
    if (mx[0] <= 0 || (mx[0] & 1 ^ 1) || ((mx[0] + 1) >> 1 <= mx[1])) {
        cout << 'B';
    }
    else {
        cout << 'A';
    }
    return 0;
}