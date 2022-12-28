/**
 *    author:  Taara Sinh Aatrey
 *    created: 20.12.2022 06:05:38
**/

#include "bits/stdc++.h"

using namespace std;

#ifdef AATREY_DEBUG
#include "debug.hpp"
#else
#define dbg(...)
#endif

const int mod = 998244353;
const int inv = (mod + 1) / 2;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    map<int64_t, int, greater<int64_t>> mp;
    int mul = 1, add = 1;
    int64_t tot = 0;
    auto Add = [&] (int &x, int y) {
        x += y;
        if (x >= mod) {
            x -= mod;
        }    
    };
    while (n--) {
        int t;
        cin >> t;
        if (t == 1) {
            int x;
            cin >> x;
            /*
            arr:          10           15          8 
            
            subtract
            from 
            prefix:      2            3          1
            
            final:        10-2-3-1=4   15-3-1=11   8-1=7
            
                           tot = 2+3+1 = 6
            
                        this is how we proceed
            STEP1:
            add
            previous
            subtractions: 10+0=10           15+2=17     8+2+3=13
            
            STEP2:
            subtract
            tot:          10-6=4       17-6=11     13-6=7
            */
            
            // shift x to x + current value of `tot`
            // at the end, subtract final value of `tot` from everything
            Add(mp[x + tot], add);
        }
        else if (t == 2) {
            int x;
            cin >> x;
            tot += x;
        }
        else {
            // can't multiply previous entries with 2 as it would be inefficient
            // so, better to have the upcoming entries divide by 2, and multiple everything by 2 at the end to neutralise the effect
            /*
            how normal progres would look like
            1
            2 1
            4 2 1
            8 4 2 1
            
            how it would look like now
            1 (mul=1)
            1 1/2 (mul=2)
            1 1/2 1/4 (mul=4)
            1 1/2 1/4 1/8 (mul=8)
            
            so, finally the sequence would be: 
            1*8 1/2*8 1/4*8 1/8*8
            8 4 2 1
            */
            if (tot == 0) {
                mul = mul * 1LL * 2 % mod;
                add = add * 1LL * inv % mod;
            }
            else if (tot <= 2e5) {
                // if tot > 0, we can use brute force as we never need to consider more than logx repetitions
                // x clones x+tot
                
                // ATTEMPT 1:
                // Go through the discrete index 
                for (auto &[x, y] : mp) {
                    if (x <= tot) break;
                    Add(mp[x + tot], y);
                }
                
                // ATTEMPT 2:
                // Save the result at a temporary location
                // map<int64_t, int> mp2;
                // for (auto &[x, y] : mp) {
                //     if (x <= tot) break;
                //     Add(mp2[x + tot], y);
                // }
                // for (auto &[x, y] : mp2) {
                //     Add(mp[x], y);
                // }
                
                // ATTEMPT 3:
                // go through all the index continuously instead of going through
                // the discrete points
                // for (int i = tot + 2e5; i > tot; i--) 
                //     Add(mp[i + tot], mp[i]);
                
                tot *= 2;
            }
        }
    }
    int ans = 0;
    for (auto &[x, y] : mp) {
        if (x <= tot) break;
        Add(ans, y);
    }
    ans = ans * 1LL * mul % mod;
    cout << ans;
    return 0;
}