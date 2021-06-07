/**
 *    author:  Taara Sinh Aatrey
 *    created: 31.05.2021 20:57:07
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
template <typename T, typename T1>
T amax(T& a, T1 b) {
    if (b > a) a = b;
    return a;
}
template <typename T, typename T1>
T amin(T& a, T1 b) {
    if (b < a) a = b;
    return a;
}


const int mod = 1e9 + 7;
const int INF = 1e18L + 5;
const int N = 2e5 + 5;

int n, m;

void subtask1() {

    if(m == 1) {
        cout << "! 0" << endl;
    }
    else {
        cout << "! -1" << endl;
    }
    int verdict;
    cin >> verdict;
    assert(verdict == 1);
}

void subtask2() {

    vector<int> ans(m);
    for(int i = 0; i < m; i++) {
        int x = 1;
        cout << "?";
        for(int j = 0; j < m; j++) {
            if(i == j) {
                cout << " " << m;
                continue;
            }
            cout << " " << x;
            x++;
        }
        cout << endl;
        int sum = (m - 1) * m / 2;
        for(int j = 0; j < n - 1; j++) {
            int x;
            cin >> x;
            sum -= x;
        }
        ans[i] = sum;
    }

    cout << "! " << ans << endl; 
    int verdict;
    cin >> verdict;
    assert(verdict == 1);

}

void subtask3() {

    vector<int> ans(m);
    set<int> not_found;
    for(int i = 0; i < m; i++) {
        not_found.insert(i);
    }
    set<int> prev;
    for(int i = 0; i < m; i++) {
        set<int> done;
        int low = 1, high = m;
        cout << "?";
        for(int j = 0; j < m; j++) {
            cout << " " << ((j - i + m) % m + 1);
        }
        cout << endl;
        for(int j = 0; j < n - 1; j++) {
            int x;
            cin >> x;
            done.insert(x);
        }
        if(i > 0) {
            for(int j = 0; j < m; j++) {
                if(done.count(j) && prev.count(j)) {
                    prev.erase(j);
                }
            }
            if(int(prev.size()) != 1) {
                cout << "! -1" << endl;
                int verdict;
                cin >> verdict;
                assert(verdict == 1);
                return;
            }
            ans[i - 1] = *prev.begin();
            not_found.erase(ans[i - 1]);
        }
        prev = done;
    }

    if(int(not_found.size()) != 1) {
        cout << "! -1" << endl;
        int verdict;
        cin >> verdict;
        assert(verdict == 1);
        return;
    }
    ans.back() = *not_found.begin();

    cout << "! " << ans << endl;
    int verdict;
    cin >> verdict;
    assert(verdict == 1);

}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int type, t;
    cin >> type >> t;

    for (int tt = 1; tt <= t; tt++) {
        cin >> n >> m;
        if(m == n - 1) {
            subtask1();
        }
        else if(m == n) {
            subtask2();
        }
        else {
            subtask3();
        }
    }
    
    return 0;
}