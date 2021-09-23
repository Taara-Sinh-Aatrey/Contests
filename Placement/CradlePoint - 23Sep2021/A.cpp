#include "bits/stdc++.h"
using namespace std;

bool debug;
template <typename T, typename U> istream& operator>>(istream &is, pair<T, U> &p) { return is >> p.first >> p.second;}
template <typename T, typename U> ostream& operator<<(ostream &os, const pair<T, U> &p) { return debug ? os << "(" << p.first << ", " << p.second << ")" : os << p.first << " " << p.second; }
template <typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> istream &operator>>(istream &is, T_container &v) { for (T &x : v) is >> x; return is; }
template <typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream &operator<<(ostream &os, const T_container &v) { bool f = false; if(debug) { os << "{"; for (const T &x : v) { if (f) os << ", "; os << x; f = true; } os << "}"; } else { for (const T &x : v) { if (f) os << " "; os << x; f = true; } } return os; }
void scan() {} template <typename Head, typename ...Tail> void scan(Head &H, Tail &...T) { cin >> H; scan(T...); }
void print() { cout << "\n"; } template <typename Head> void print(const Head &H) { cout << H << "\n"; } template <typename Head, typename ...Tail> void print(const Head &H, const Tail &...T) { cout << H << " "; print(T...); }
void dbg_out() { cerr << "\n"; } template <typename Head, typename ...Tail> void dbg_out(const Head &H, const Tail &...T) { cerr << " " << H; dbg_out(T...); }
#ifndef ONLINE_JUDGE
#define dbg(...) cerr << "[" << #__VA_ARGS__ << "]:", debug = true, dbg_out(__VA_ARGS__), debug = false
#else
#define dbg(...)
#endif

template<typename T>
struct Tree {
    T value;
    Tree* left;
    Tree* right;
    Tree(const T& v) : value(v), left(nullptr), right(nullptr) {}
};

void TreePaths(Tree<int>* t, vector<string>& ret, string s) {
    if(!t) return;
    
    if(!s.empty()) s += "->";
    s += to_string(t->value);
    
    if(!t->left && !t->right) {
        ret.emplace_back(s);
        return;
    }
    
    if(t->left) {
        TreePaths(t->left, ret, s);
    }
    if(t->right) {
        TreePaths(t->right, ret, s);
    }
}

vector<string> treePaths(Tree<int>* t, string s = "") {
    vector<string> ret;
    TreePaths(t, ret, "");
    return ret;
}

signed main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    Tree<int> *root = new Tree<int>(5);
    root->left = new Tree<int>(2);
    root->right = new Tree<int>(-3);
    root->left->left = new Tree<int>(10);
    root->left->right = new Tree<int>(4);
    return 0;
}