#include "bits/stdc++.h"
using namespace std;

template <typename T, typename U> istream& operator>>(istream &is, pair<T, U> &p) { return is >> p.first >> p.second; }
template <typename T, typename U> ostream& operator<<(ostream &os, const pair<T, U> &p) { return os << p.first << " " << p.second; }
template <typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> istream &operator>>(istream &is, T_container &v) { for (T &x : v) is >> x; return is; }
template <typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream &operator<<(ostream &os, const T_container &v) { bool f = false; for (const T &x : v) { if (f) os << " "; os << x; f = true; } return os; }
void scan() {} template <typename Head, typename ...Tail> void scan(Head &H, Tail &...T) { cin >> H; scan(T...); }
void print() { cout << "\n"; } template <typename Head> void print(const Head &H) { cout << H << "\n"; } template <typename Head, typename ...Tail> void print(const Head &H, const Tail &...T) { cout << H << " "; print(T...); }
template <typename T, typename T1, typename... Tail> T amin(T& a, T1 b, Tail... c) { if(b < a) a = b; if constexpr (sizeof...(c) != 0) { amin(a, c...); } return a; } template <typename T, typename T1, typename... Tail> T amax(T& a, T1 b, Tail... c) { if(b > a) a = b; if constexpr (sizeof...(c) != 0) { amax(a, c...); } return a; }

#ifdef LOCAL
#include "debug.hpp"
#else
#define dbg(...)
#endif

#define int int64_t
const int inf = 1e18L + 5, mod = 1e9 + 7, N = 2e5 + 5;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
int rand(int a, int b) { return uniform_int_distribution<int>(a, b)(rng); }

map<string, int> id;
vector<string> str;

struct pizza {
    vector<int> likes, dislikes;
    set<int> enemies;
    
    static int read_ingredient() {
        string s;
        cin >> s;
        if (!id.count(s)) {
            id[s] = id.size();
            str.emplace_back(s);
        }
        return id[s];
    }
    
    static void read_ingredients(vector<int> &ings) {
        int n;
        cin >> n;
        while (n--)
            ings.emplace_back(read_ingredient());
    }
    
    friend istream &operator>>(istream &is, pizza &p) {
        read_ingredients(p.likes);
        read_ingredients(p.dislikes);
        return is;
    }
};

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    scan(n);
    vector<pizza> P(n);
    scan(P);
    int m = str.size();
    dbg(n, m);
    vector<vector<int>> likeMe(m), dislikeMe(m);
    for (int i = 0; i < n; i++) {
        for (auto &ing : P[i].likes) {
            likeMe[ing].emplace_back(i);
        }
        for (auto &ing : P[i].dislikes) {
            dislikeMe[ing].emplace_back(i);
        }
    }
    for (int i = 0; i < m; i++) {
        for (auto &x : likeMe[i]) {
            for (auto &y : dislikeMe[i]) {
                P[x].enemies.emplace(y);
                P[y].enemies.emplace(x);
            }
        }
    }
    const int diff = 1;
    auto Get = [&] (int &best_score, set<int> &ans, set<pair<int, int>> order, vector<int> sz) {
        set<int> cur;
        int cur_score = 0;
        // dbg(1, best_score, ans, order, sz);
        while (!order.empty()) {
            vector<set<pair<int, int>>::iterator> choices;
            set<pair<int, int>>::iterator me = order.begin();
            {
                auto it = order. begin();
                while (it != order.end() && it->first <= order.begin()->first + diff) {
                    choices.emplace_back(it);
                    it++;
                }
                int idx = rand(0, int(choices.size()) - 1);
                me = choices[idx];
            }
            auto [_, i] = *me;
            // dbg(_, i);
            order.erase(me);
            for (auto &ing : P[i].likes) {
                cur.emplace(ing);
            }
            cur_score++;
            for (auto &j : P[i].enemies) {
                auto it = order.find({sz[j], j});
                if (it != order.end()) {
                    order.erase(it);
                    for (auto &k : P[j].enemies) {
                        auto it = order.find({sz[k], k});
                        if (it != order.end()) {
                            order.erase(it);
                            sz[k]--;
                            order.emplace(sz[k], k);
                        }
                    }
                }
            }
        }
        if (cur_score > best_score) {
            best_score = cur_score;
            swap(ans, cur);
        }
        // dbg(2, best_score, ans, order, sz);
    };
    vector<int> sz(n);
    set<pair<int, int>> order;
    for (int i = 0; i < n; i++) {
        sz[i] = P[i].enemies.size();
        order.emplace(P[i].enemies.size(), i);
    }
    set<int> ans;
    int best_score = 0;
    const int TRIES = 100;
    for (int i = 0; i < TRIES; i++) {
        // dbg(i);
        Get(best_score, ans, order, sz);
        if ((i + 1) % 10 == 0)
            dbg(best_score);
    }
    dbg(best_score);
    cout << ans.size() << " ";
    vector<string> ings;
    for (auto &ing : ans) {
        ings.emplace_back(str[ing]);
    }
    print(ings);
    return 0;
}