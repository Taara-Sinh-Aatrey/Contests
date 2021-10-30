#include"bits/stdc++.h"
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
using namespace std;

static char stdinBuffer[1024];
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

int readInt() {
    readAhead(16);
    int x = 0;
    while (*stdinPos >= '0' && *stdinPos <= '9') {
       x = x * 10 + *stdinPos - '0';
       ++stdinPos;
    }
    stdinPos++;
    return x;
}

int main() {
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
    int n = readInt();
    // fastscan(n);
    int ans = 0;
    int val;
    int a[n];
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        // fastscan(val);
        val = readInt();
        while(cnt > 0 && a[cnt - 1] <= val) {
            ans++;
            --cnt;
        }
        if(cnt) ans++;
        a[cnt++] = val;
    }
    cout << ans;
    return 0;
}

// #include<stdio.h>
// #include<stdlib.h>

// typedef struct node
// {
//     int info;
//     struct node * link;
// }node;

// node* head = NULL;

// int main() {
//     int n = 0;
//     register int c;
//     c = getchar();
//     for (; (c > 47 && c < 58); c=getchar())
//         n = n * 10 + c - 48;
//     int ans = 0;
//     for (int i = 0; i < n; i++) {
//         int val = 0;
//         register int c;
//         c = getchar();
//         for (; (c > 47 && c < 58); c=getchar())
//             val = val * 10 + c - 48;
//         while(head && head->info <= val) {
//             ans++;
//             head = head->link;
//         }
//         ans += (head != NULL);
//         node *newN;
//         newN=(node*)malloc(sizeof(node));
//         newN->info=val;
//         newN->link=head;
//         head=newN;
//     }
//     printf("%d", ans);
//     return 0;
// }