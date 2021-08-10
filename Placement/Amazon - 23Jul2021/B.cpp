#include <bits/stdc++.h>
using namespace std;

template<typename A, typename B> istream& operator>>(istream &is, pair<A, B> &p) { return is >> p.first >> p.second;} template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> istream& operator>>(istream &is, T_container &v) { for (T& x : v) is >> x; return is;} bool debug;
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return debug ? os << '(' << p.first << ", " << p.second << ')' : os << p.first << " " << p.second;} template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { if(debug) { os << "{"; string sep; for (const T &x : v) os << sep << x, sep = ", "; os << '}'; } else { bool f = false; for (const T &x : v) { if(f) {os << " ";} os << x, f = true; } } return os;}
template <typename T, typename T1, typename... Tail> T amin(T& a, T1 b, Tail... c) { if(b < a) a = b; if constexpr (sizeof...(c) != 0) { amin(a, c...); } return a; } template <typename T, typename T1, typename... Tail> T amax(T& a, T1 b, Tail... c) { if(b > a) a = b; if constexpr (sizeof...(c) != 0) { amax(a, c...); } return a; }
void dbg_out() { cerr << endl; } template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#ifdef ONLINE_JUDGE
#define dbg(...)
#else
#define dbg(...) cerr << "[" << #__VA_ARGS__ << "]:", debug = true, dbg_out(__VA_ARGS__), debug = false
#endif

#define ll long long

vector<int> getTimes(int numCustomers, vector<int> arrTime, vector<int> direction) {
    
    vector<int> ans(numCustomers);
    
    queue<int> ent, ext;
    
    int p = -1, last = -1;
    int i = 0;
    while(i < numCustomers) {
        
        if(i == 0 || arrTime[i] != last + 1) {
            p = -1;
        }
        
        int j = i;
        while(j < numCustomers && arrTime[j] == arrTime[i]) {
            if(direction[j] == 0) {
                ent.push(j);
            }
            else {
                ext.push(j);
            }
            j++;
        }
        
        int cur = arrTime[i];
        int nxt = (j >= numCustomers ? 2e9 : arrTime[j]);
        
        while((!ent.empty() || !ext.empty()) && cur < nxt) {
            last = cur;
            if(p == -1 || p == 1) {
                if(!ext.empty()) {
                    ans[ext.front()] = cur++;
                    ext.pop();
                    p = 1;
                }
                else {
                    ans[ent.front()] = cur++;
                    ent.pop();
                    p = 0;
                }
            }
            else {
                if(!ent.empty()) {
                    ans[ent.front()] = cur++;
                    ent.pop();
                    p = 0;
                }
                else {
                    ans[ext.front()] = cur++;
                    ext.pop();
                    p = 1;
                }
            }
        }
        
        i = j;
        
    }
    
    return ans;
    
}

int main()
{
    // cout << getTimes(5, {0, 1, 1, 3, 3},  {0, 1, 0, 0, 1}) << endl;
    // cout << getTimes(4, {0, 0, 1, 5},  {0, 1, 1, 0}) << endl;
    // cout << getTimes(4, {1, 3, 5, 5},  {1, 0, 1, 0}) << endl;
    cout << getTimes(5, {1, 1, 3, 3, 4},  {1, 0, 0, 1, 1}) << endl;
    
    return 0;
}