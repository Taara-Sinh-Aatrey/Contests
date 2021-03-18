#include<bits/stdc++.h>
using namespace std;

#define int long long

template <typename T>
T inverse(T a, T m) {
    T u = 0, v = 1;
    T temp = m;
    while (a != 0) {
        T t = m / a;
        m -= t * a; swap(a, m);
        u -= t * v; swap(u, v);
    }
    assert(m == 1);
    if(u < 0) u += temp;
    return u;
}

const int mod = 998244353;
const int h_mod = 1e9 + 7;
const int p = 31, inv_p = inverse(p, h_mod);

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    vector<int> p_pow(2001, 1), inv_pow(2001, 1);

    for(int i = 1; i <= 2000; i++) {
        p_pow[i] = (p_pow[i - 1] * p) % h_mod;
        inv_pow[i] = (inv_pow[i - 1] * inv_p) % h_mod;
    }

    while(T--) {

        auto precal = [&](int n, string s, int m, string t, vector<vector<pair<int, int>>>& pos) {

            vector<int> hash(m, 0);

            for(int i = 0; i < m; i++) {
                hash[i] = (i > 0 ? hash[i - 1] : 0) + (t[i] - 'a' + 1) * p_pow[i] % h_mod;
            }

            int cur = 0;

            for(int i = 0; i < n; i++) {
                cur += (s[i] - 'a' + 1) * p_pow[i];
                cur %= h_mod;
                
                for(int j = 0; j + i < m; j++) {
                    int val = (hash[j + i] - (j > 0 ? hash[j - 1] : 0) + h_mod) % h_mod;
                    val = val * inv_pow[j] % h_mod;
                    if(val == cur) {
                        if(pos[i].empty() || pos[i].back().second != j + i - 1) {
                            pos[i].emplace_back(j + i, j + i);
                        } else {
                            pos[i].back().second = j + i;
                        }
                    }
                }

            }
        };

        string s, t;
        cin >> s >> t;

        int n = (int) s.size(), m = (int) t.size();
        vector<vector<pair<int, int>>> start_position(n), end_position(n);

        precal(n, s, m, t, end_position);

        reverse(s.begin(), s.end());
        reverse(t.begin(), t.end());
        precal(n, s, m, t, start_position);
        reverse(start_position.begin(), start_position.end());
        for(auto &vec : start_position) {
            for(auto& [a, b] : vec) {
                a = m - 2 - a;
                b = m - 2 - b;
                swap(a, b);
            }
            reverse(vec.begin(), vec.end());
        }

        int ans = 0;
        for(int pref = 0; pref < n; pref++) {
            for(int suff = 0; suff < n; suff++) {
                int n = end_position[pref].size();
                int m = start_position[suff].size();
                int i = 0, j = 0;
                while(i < n && j < m) {
                    auto& [a, b] = end_position[pref][i];
                    auto& [c, d] = start_position[suff][j];
                    if(b < c) {
                        i++;
                    } else if(d < a) {
                        j++;
                    } else {
                        ans++;
                        break;
                    }
                }
            }
        }

        if(ans >= mod) ans -= mod;

        int tot = inverse(n * n % mod, mod);

        ans = ans * tot % mod;

        cout << ans << '\n';
    }
    

    return 0;
}