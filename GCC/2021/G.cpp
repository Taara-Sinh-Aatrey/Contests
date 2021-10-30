// // #include "bits/stdc++.h"
// // #pragma GCC optimize ("O3")
// // #pragma GCC target ("sse4")
// // using namespace std;

// // template<typename A, typename B> istream& operator>>(istream &is, pair<A, B> &p) { return is >> p.first >> p.second;} template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> istream& operator>>(istream &is, T_container &v) { for (T& x : v) is >> x; return is;} bool debug;
// // template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return debug ? os << '(' << p.first << ", " << p.second << ')' : os << p.first << " " << p.second;} template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { if(debug) { os << "{"; string sep; for (const T &x : v) os << sep << x, sep = ", "; os << '}'; } else { bool f = false; for (const T &x : v) { if(f) {os << " ";} os << x, f = true; } } return os;}
// // template <typename T, typename T1, typename... Tail> T amin(T& a, T1 b, Tail... c) { if(b < a) a = b; if constexpr (sizeof...(c) != 0) { amin(a, c...); } return a; } template <typename T, typename T1, typename... Tail> T amax(T& a, T1 b, Tail... c) { if(b > a) a = b; if constexpr (sizeof...(c) != 0) { amax(a, c...); } return a; }
// // void dbg_out() { cerr << endl; } template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

// // #ifdef ONLINE_JUDGE
// // #define dbg(...)
// // #else
// // #define dbg(...) cerr << "[" << #__VA_ARGS__ << "]:", debug = true, dbg_out(__VA_ARGS__), debug = false
// // #endif

// // const int mod = 1e9 + 7;
// // const int N = 1e6 + 1;

// // int main()
// // {
// //     ios::sync_with_stdio(0);
// //     cin.tie(0);
// //     int n;
// //     cin >> n;
// //     int cc = n;
// //     vector<int> a(n);
// //     int N = 0;
// //     for (int i = 0; i < n; i++) {
// //         cin >> a[i];
// //         if (N <= a[i]) N = a[i] + 1;
// //     }
// //     // int spf[N];
// //     // memset(spf, 0, N << 2);
// //     vector<int> spf(N);
// //     // int nxt[N];
// //     vector<int> primes;
// //     primes.reserve(min(N, 78498));
// //     for(int i = 2; i < N; i++) {
// //         if(spf[i] == 0) {
// //             spf[i] = i;
// //             primes.emplace_back(i);
// //         }
// //         int prod;
// //         for(int j = 0; j < (int) primes.size() && primes[j] <= spf[i] && (prod = primes[j] * i) < N; j++) {
// //             spf[prod] = primes[j];
// //             // nxt[prod] = i;
// //         }
// //     }
// //     if (primes.size()) N = primes.back() + 1;
// //     else N = 2;
// //     primes = {};
    
    
// //     int p[n];
// //     for (int i = 0; i < n; i++) p[i] = i;
// //     vector<int> idx(N, -1);
    
// //     function<int(int)> get = [&] (int x) -> int {
// //         return (x == p[x] ? x : (p[x] = get(p[x])));
// //     };
    
// //     auto unite = [&] (int x, int y) {
// //         x = get(x);
// //         y = get(y);
// //         if (x != y) {
// //             // if(sz[x] > sz[y]) {
// //             //     swap(x, y);
// //             // }
// //             p[x] = y;
// //             cc--;
// //             // sz[y] = 0;
// //         }
// //     };
    
// //     vector<vector<int>> g(n);
// //     // cc = 0;
// //     vector<bool> vis(n);
// //     int i = 0;
// //     for(auto& ai: a) {
// //         // dbg(i, n, ai);
// //         // cin >> ai;
// //         // if (ai == 1) {
// //         //     cc++;
// //         //     vis[i] = true;
// //         //     continue;
// //         // }
// //         while(ai > 1) {
// //             // dbg(a[i], ai);
// //             int factor = spf[ai];
// //             // while (spf[ai] == factor) {
// //             //     ai = nxt[ai];
// //             // }
// //             while (ai % factor == 0) {
// //                 ai /= factor;
// //             }
// //             if (idx[factor] != -1) {
// //                 unite(i, idx[factor]);
// //                 // g[i].emplace_back(idx[factor]);
// //                 // g[idx[factor]].emplace_back(i);
// //             }
// //             else idx[factor] = i;
// //         }
// //         i++;
// //     }
    
// //     // function<void(int)> dfs = [&](int u) {
// //     //     vis[u] = true;
        
// //     //     for(auto& v : g[u]) {
// //     //         if(vis[v]) continue;
// //     //         dfs(v);
// //     //     }    
// //     // };
// //     // for (int i = 0; i < n; i++) {
// //     //     if (!g[i].empty()) {
// //     //         sort(g[i].begin(), g[i].end());
// //     //         g[i].resize(unique(g[i].begin(), g[i].end()) - g[i].begin());
// //     //     }
// //     // }
// //     // for (int i = 0; i < n; i++) {
// //     //     if (!vis[i]) {
// //     //         dfs(i);
// //     //         cc++;
// //     //     }
// //     // }
    
// //     cout << (cc == 1 ? "NO" : "YES") << '\n';
// //     int mul = 1;
// //     for (int i = 0; i < cc; i++) {
// //         mul <<= 1;
// //         if (mul >= mod) mul -= mod;
// //     }
// //     mul -= 2;
// //     if (mul < 0) mul += mod;
// //     cout << mul;
// //     return 0;
// // }

// #include "bits/stdc++.h"
// #pragma GCC optimize ("O3")
// #pragma GCC target ("sse4")
// using namespace std;

// const int mod = 1e9 + 7;
// const int N = 1e6 + 1;
// int cc;

// // vector<int> p;
// int *p;
// vector<int> idx(N, -1);
// int get(int x) {
//     return (x == p[x] ? x : (p[x] = get(p[x])));
// }

// void unite(int x, int y) {
//     x = get(x);
//     y = get(y);
//     if (x != y) {
//         // if(sz[x] > sz[y]) {
//         //     swap(x, y);
//         // }
//         p[x] = y;
//         cc--;
//     }
// }

// void fastscan(int &number)
// {
//     register int c;
//     number = 0;  
//     c = getchar();
//     for (; (c>47 && c<58); c=getchar())
//         number = number *10 + c - 48;
// }

// // vector<int> nxt(N);
// vector<int> spf(N);

// // vector<int> primes;
// // void sieve() {
// //     for(int i = 2; i < N; i++) {
// //         if(!spf[i]) {
// //             spf[i] = i;
// //             primes.push_back(i);
// //         }
// //         int prod;
// //         // for(int j = 0; j < (int) primes.size() && primes[j] <= spf[i] && (prod = primes[j] * i) < N; j++) {
// //         //     spf[prod] = primes[j];
// //         // }
// //         for(auto& pr : primes) {
// //             prod = pr * i;
// //             if (pr > spf[i] || prod >= N) break;
// //             spf[prod] = pr;
// //             if (i % pr != 0) {
// //                 nxt[prod] = i;
// //             }
// //             else {
// //                 nxt[prod] = nxt[i];
// //             }
// //         }
// //     }
// // }

// // taken from gfg
// void sieve()
// {
//     spf[1] = 1;
//     for (int i = 2; i < N; i += 2) spf[i] = 2;
//     for (int i = 3; i < N; i += 2) spf[i] = i;
//     int J = 9;
//     for (int i = 3; J < N; i += 2) {
//         if (spf[i] == i)
//             for (int j = J; j < N; j += i)
//                 if (spf[j] == j) spf[j] = i;
//         J += ((i << 1) + 2) << 1;        
//     }
// }

// int main()
// {
//     // ios::sync_with_stdio(0);
//     // cin.tie(0);
//     sieve();
//     int n;
//     // cin >> n;
//     fastscan(n);
//     cc = n;

//     // sz = new int[n];
//     // memset(sz, 0, n << 2);
//     // sz.resize(n, 1);

//     p = new int[n];
//     for (int i = 0; i < n; i++) p[i] = i;
//     // p.resize(n);
//     // iota(p.begin(), p.end(), 0);
    
//     for(int i = 0; i < n; i++) {
//         int ai;
//         fastscan(ai);
//         // cin >> ai;
//         while(ai > 1) {
//             int factor = spf[ai];
//             while (ai % factor == 0) {
//                 ai /= factor;
//             }
//             // ai = nxt[ai];
//             auto &id = idx[factor];
//             if (~id) {
//                 unite(i, id);
//             }
//             else id = i;
//         }
//     }
//     cout << (cc == 1 ? "NO" : "YES") << '\n';
//     int mul = 1;
//     for (int i = 0; i < cc; i++) {
//         mul <<= 1;
//         if (mul >= mod) mul -= mod;
//     }
//     mul -= 2;
//     if (mul < 0) mul += mod;
//     cout << mul;
//     return 0;
// }

#include "bits/stdc++.h"
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
    readAhead(1000);
    x = "";
    while ((*stdinPos >= 'a' && *stdinPos <= 'z') || (*stdinPos >= 'A' && *stdinPos <= 'Z') || (*stdinPos >= '0' && *stdinPos <= '9')) {
       x += *stdinPos;
       ++stdinPos;
    }
    stdinPos++;
}

const int mod = 1e9 + 7;
const int N = 1e6 + 1;
int cc;

int *p;
vector<int> idx(N, -1);
int get(int x) {
    return (x == p[x] ? x : (p[x] = get(p[x])));
}

void unite(int x, int y) {
    x = get(x);
    y = get(y);
    if (x != y) {
        p[x] = y;
        cc--;
    }
}

void fastscan(int &number)
{
    register int c;
    number = 0;  
    c = getchar();
    for (; (c > 47 && c < 58); c=getchar())
        number = number * 10 + c - 48;
}

int* spf;
void sieve(int _N = N)
{
    spf = new int[_N];
    spf[1] = 1;
    for (int i = 2; i < _N; i += 2) spf[i] = 2;
    for (int i = 3; i < _N; i += 2) spf[i] = i;
    int J = 9;
    for (int i = 3; J < _N; i += 2) {
        if (spf[i] == i)
            for (int j = J; j < _N; j += i)
                if (spf[j] == j) spf[j] = i;
        J += ((i << 1) + 2) << 1;        
    }
}

int main()
{
    int n; readInt(n);
    // fastscan(n);
    cc = n;

    p = new int[n];
    for (int i = 0; i < n; i++) p[i] = i;
        
    int mx = 0;
    int a[n];
    for (int i = 0; i < n; i++) {
        // fastscan(a[i]);
        readInt(a[i]);
        if (mx < a[i]) mx = a[i];
    }
    sieve(mx + 1);
    
    for(int i = 0; i < n; i++) {
        int& ai = a[i];
        // fastscan(ai);
        while(ai > 1) {
            int factor = spf[ai];
            while (ai % factor == 0) {
                ai /= factor;
            }
            auto &id = idx[factor];
            if (~id) {
                unite(i, id);
            }
            else id = i;
        }
    }
    cout << (cc == 1 ? "NO" : "YES") << '\n';
    int mul = 1;
    for (int i = 0; i < cc; i++) {
        mul <<= 1;
        if (mul >= mod) mul -= mod;
    }
    mul -= 2;
    if (mul < 0) mul += mod;
    cout << mul;
    return 0;
}