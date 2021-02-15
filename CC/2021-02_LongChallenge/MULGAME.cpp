#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    while(t--) {
        int n, q, m;
        scanf("%d%d%d", &n, &q, &m);
        vector<int> a(n);
        for(int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        array<int, 2> Q[q];
        for(int i = 0; i < q; i++) {
            scanf("%d%d", &Q[i][0], &Q[i][1]);
        }
        sort(Q, Q + q);
        vector<int> ans(m + 2, 0);
        int i = 0;
        while(i < q) {
            int j = i, c = 0;
            while(j < q) {
                if(Q[j] != Q[i]) {
                    break;
                }
                c++;
                j++;
            }
            int l = Q[i][0], r = Q[i][1];
            int x = a[l - 1];
            while(x <= m) {
                int y = a[r - 1] + x - 1;
                if(y > m) {
                    y = m;
                }
                ans[x] += c;
                ans[y + 1] -= c;
                x = y + 1 + a[l - 1];
            }
            i += c;
        }
        int ret = 0;
        for(int i = 1; i <= m; i++) {
            if(ans[i] > ret) {
                ret = ans[i];
            }
            if(i + 1 <= m) {
                ans[i + 1] += ans[i];
            }
        }
        cout << ret << '\n';
    }
}
