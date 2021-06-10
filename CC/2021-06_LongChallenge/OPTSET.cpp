/**
 *    author:  Taara Sinh Aatrey
 *    created: 09.06.2021 23:46:37
**/

#include <bits/stdc++.h>
using namespace std;

#define int int64_t

template <typename T1, typename T2>
istream& operator>>(istream& in, pair<T1, T2>& a) {
    in >> a.first >> a.second;
    return in;
}
template <typename T1, typename T2>
ostream& operator<<(ostream& out, pair<T1, T2>& a) {
    out << a.first << " " << a.second;
    return out;
}
template <class A, size_t S>
istream& operator>>(istream& in, array<A, S>& a) {
    for (A& x : a) in >> x;
    return in;
}
template <class A, size_t S>
ostream& operator<<(ostream& out, array<A, S>& a) {
    bool f = false;
    for (A& x : a) {
        if (f) out << " ";
        out << x;
        f = true;
    }
    return out;
}
template <typename T>
istream& operator>>(istream& in, vector<T>& a) {
    for (T& x : a) in >> x;
    return in;
}
template <typename T>
ostream& operator<<(ostream& out, vector<T>& a) {
    bool f = false;
    for (T& x : a) {
        if (f) out << " ";
        out << x;
        f = true;
    }
    return out;
}
void out(bool ok, bool cap = true) {
    if (cap) cout << (ok ? "YES" : "NO") << '\n';
    else cout << (ok ? "Yes" : "No") << '\n';
}
template <typename T, typename T1, typename... Tail>
T amax(T& a, T1 b, Tail... c) {
    if(b > a) a = b;
    if constexpr (sizeof...(c) != 0) {
        amax(a, c...);
    }
    return a;
}
template <typename T, typename T1, typename... Tail>
T amin(T& a, T1 b, Tail... c) {
    if(b < a) a = b;
    if constexpr (sizeof...(c) != 0) {
        amin(a, c...);
    }
    return a;
}

const int mod = 1e9 + 7;
const int INF = 1e18L + 5;
const int N = 2e5 + 5;

void solve() {

    auto fun = [&](int n, int k, int b, vector<int>& ans, int equal, int smaller) {
        while(b >= 0) {
            int nequal = equal, nsmaller = smaller;
            int mn_ones = 0;
            if(n >> b & 1) {
                int one = n - (1 << b) + 1;
                int zero = 1 << b;

                int i = 0;
                while(i < equal) {
                    int j = i;
                    while(j < equal && ans[i] == ans[j]) {
                        j++;
                    }
                    int tot = j - i;
                    int cur = max<int>(0, tot - zero);
                    mn_ones += cur;
                    i = j;
                }

            }
            int one = 1 << b;
            int zero = 1 << b;
            int i = equal;
            while(i < k) {
                int j = i;
                while(j < k && ans[i] == ans[j]) {
                    j++;
                }
                int tot = j - i;
                int cur = max<int>(0, tot - (zero - (ans[i] == 0)));
                mn_ones += cur;
                i = j;
            }

            int f = mn_ones % 2 == 0;

            int cand = -1;

            if(n >> b & 1) {
                int one = n - (1 << b) + 1;
                int zero = 1 << b;

                int i = 0;
                while(i < equal) {
                    int j = i;
                    while(j < equal && ans[i] == ans[j]) {
                        j++;
                    }
                    int x = 0;
                    int tot = j - i;
                    int cur = max<int>(0, tot - zero);
                    int w = f;
                    while(i < j) {
                        if(x < cur) {
                            ans[i] |= 1 << b;
                        }
                        else {
                            if(f == 1 && x < one) {
                                cand = i;
                                f = 0;
                            }
                            nsmaller++;
                            nequal--;
                        }
                        x++;
                        i++;
                    }
                    f = w;
                }

                n -= 1 << b;
            }
            one = 1 << b;
            zero = 1 << b;
            i = equal;
            while(i < k) {
                int j = i;
                while(j < k && ans[i] == ans[j]) {
                    j++;
                }
                int x = 0;
                int tot = j - i;
                int cur = max<int>(0, tot - (zero - (ans[i] == 0)));
                int w = f;
                while(i < j) {
                    if(x < cur) {
                        ans[i] |= 1 << b;
                    }
                    else {
                        if(f == 1 && x < one) {
                            cand = i;
                            f = 0;
                        }
                    }
                    x++;
                    i++;
                }
                f = w;

            }
            if(cand != -1) {
                ans[cand] |= 1 << b;
                nsmaller -= cand < equal;
                nequal += cand < equal;
            }
            equal = nequal;
            smaller = nsmaller;
            b--;
        }

        int x = 0;
        for(int i = 0; i < k; i++) {
            x ^= ans[i];
        }

        return x;
    };

    int n, k;
    cin >> n >> k;

    int b = 63 - __builtin_clzll(n);

    int _equal = n - (1 << b) + 1;
    int _smaller = (1 << b) - 1;

    n -= 1 << b;
    vector<int> ret;
    int xor_sum = -1;
    int mn = max<int>(0, k - _smaller);
    int mx = min<int>(_equal, k);
    for(int equal = mn; equal <= min(mx, mn + 2); equal++) {
        int smaller = k - equal;
        assert(smaller <= _smaller);
        vector<int> ans(k, 0);
        for(int i = 0; i < equal; i++) {
            ans[i] |= 1 << b;
        }
        int x = fun(n, k, b - 1, ans, equal, smaller);
        if(x > xor_sum) {
            xor_sum = x;
            ret = ans;
        }
    }

    cout << ret << '\n';
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        solve();
    }
    
    return 0;
}

/*
15
8 7 3 2 1
*/
