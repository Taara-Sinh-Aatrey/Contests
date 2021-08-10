#include <bits/stdc++.h>
using namespace std;
template<typename A, typename B> istream& operator>>(istream &is, const pair<A, B> &p) { return is >> p.first >> p.second;} template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> istream& operator>>(istream &is, T_container &v) { for (T& x : v) is >> x; return is;} bool debug;
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return debug ? os << '(' << p.first << ", " << p.second << ')' : os << p.first << " " << p.second;} template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { if(debug) { os << "{"; string sep; for (const T &x : v) os << sep << x, sep = ", "; os << '}'; } else { bool f = false; for (const T &x : v) { if(f) {os << " ";} os << x, f = true; } } return os;}
void dbg_out() { cerr << endl; } template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#ifdef ONLINE_JUDGE
#define dbg(...)
#else
#define dbg(...) cerr << "[" << #__VA_ARGS__ << "]:", debug = true, dbg_out(__VA_ARGS__), debug = false
#endif

#define endl '\n'
#define all(a) a.begin(),a.end()
const string YES = "Yes";
const string NO = "No";
void solve() {
    long long int n , m ;
    cin >> n >> m;
    long long int same=m;
    map<long long int,vector<long long int>>store1;
    while(m--){
        long long int a,b;
        cin >> a >> b;
        store1[a].push_back(b);
    }
    
    long long int cycles = 0;

    auto get = [&](int a, int b) {
        return (b - a) + (b < a ? n : 0);
    };

    for(auto& p : store1) {
        sort(all(p.second), [&](const int& i, const int& j) {
            int di = get(p.first, i);
            int dj = get(p.first, j);
            return di > dj;
        });
        cycles = max(cycles, (long long) p.second.size());
    }
    
    
    for(int st = 1; st <= n; st++) {
        long long int max_d_in_last_cycle = 0;
        for(auto& p : store1) {
            if(int(p.second.size()) == cycles) {
                max_d_in_last_cycle = max(max_d_in_last_cycle, get(st, p.first) + get(p.first, p.second.back()));
            }
            if(cycles >= 2 && int(p.second.size()) >= cycles - 1) {
                if(get(st, p.second[cycles - 2]) < get(p.first, p.second[cycles - 2]))
                    max_d_in_last_cycle = max(max_d_in_last_cycle, get(st, p.second[cycles - 2]));
            }
        }
        
        int ans = (cycles - 1) * n + max_d_in_last_cycle;
        cout << ans << " \n"[st == n];
    }
    
    
}
int main()
{
    int t=1;
    //scanf("%d", &t);
    while(t--) solve();
    return 0;
}