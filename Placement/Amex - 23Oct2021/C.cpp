#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll R, C;
    cin >> R >> C;
    vector<ll> round(R);
    for (ll i = 0; i < R; i++) {
        cin >> round[i];
    }
    vector<pair<ll, ll>> a(C);
    for (ll i = 0; i < C; i++) {
        cin >> a[i].first >> a[i].second;
    }
    ll p, q, r, s;
    cin >> p >> q >> r >> s;
    ll offset = 0;
    const long long inf = 1e12L + 5;
    vector<vector<ll>> score(2, vector<ll>(C + 1, -inf));
    score[0][0] = 0, score[1][0] = 0;
    for (ll rep = 0; rep < 2; rep++) {
        auto fun = [&] (vector<ll> cand) {
            ll sz = cand.size();
            for (ll cards = offset - sz; cards >= 0; cards--) {
                ll best = 0;
                sort(cand.begin(), cand.end());
                do {
                    ll cur = 0;
                    ll taken = offset;
                    for (ll i = 0; i < cand.size(); i++) {
                        taken++;
                        cur += cand[i];
                        if (taken % p == 0)
                            cur += cand[i] * (q - 1);
                    }
                    best = max(best, cur);
                } while (next_permutation(cand.begin(), cand.end()));
                score[rep][cards + sz] = max(score[rep][cards + sz], score[rep][cards] + best);
            }
        };
        ll ans = 0;
        for (ll r = 0; r < R; r++) {
            ll n = round[r];
            vector<ll> vec[3];
            for (ll i = offset; i < offset + n; i++) {
                vec[a[i].first == 300 ? 0 : (a[i].first == 500 ? 1 : 2)].emplace_back(a[i].second);
            }
            for (ll i = 0; i < 3; i++) {
                if (vec[i].empty()) continue;
                ll want = min<ll>(i == 0 ? 3 : 1, vec[i].size());
                sort(vec[i].rbegin(), vec[i].rend());
                vec[i].resize(want);
                vector<ll> cand;
                for (ll sz = 1; sz <= want; sz++) {
                    cand.emplace_back(vec[i][sz - 1]);
                    fun(cand);
                }
            }
            if (vec[0].size() >= 1 && vec[1].size() >= 1) {
                fun({vec[0][0], vec[1][0]});
            }
            offset += n;
        }
        swap(p, r);
        swap(q, s);
        offset = 0;
    }
    ll mx[2];
    for (ll i = 0; i < 2; i++)
        mx[i] = *max_element(score[i].begin(), score[i].end());
    cout << (mx[0] == mx[1] ? "Draw" : (mx[0] > mx[1] ? "Alice" : "Bob"));
    if (mx[0] != mx[1])
        cout << " " << abs(mx[0] - mx[1]);
    return 0;
}