/**
 *    author:  Taara Sinh Aatrey
 *    created: 21.08.2022 23:44:41
**/

#include "bits/stdc++.h"

using namespace std;

#ifdef AATREY_DEBUG
#include "debug.hpp"
#else
#define dbg(...)
#endif

#define int int64_t

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    auto get_month_number = [&] (string s) {
        if (s == "Jul") return 7;
        if (s == "Aug") return 8;
        if (s == "Sep") return 9;
        if (s == "Oct") return 10;
        if (s == "Nov") return 11;
        if (s == "Dec") return 12;
        return 6;
    };
    long double mx = 0;
    string ans;
    for (int i = 0; i < n; i++) {
        string s;
        getline(cin, s);
        getline(cin, s);
        string mnth, _day, _year;
        cin >> mnth >> _day >> _year;
        _day.pop_back();
        int day = stoll(_day);
        int year = stoll(_year);
        long double per;
        cin >> per;
        if (year > 1928 || (year == 1928 && get_month_number(mnth) > 7) || (get_month_number(mnth) == 7 && day > 7)) {
            if (per > mx) {
                mx = per;
                ans = s;
            }
        }
    }
    cout << ans;
    return 0;
}