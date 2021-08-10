#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// functions: set.insert(val), *(set.find_by_order(order-1)), set.order_of_key(val)
// less_equal for multiset

#define int int64_t
const int mod = 1e9 + 7; const int INF = 1e18L + 5; const int N = 2e5 + 5;

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;
    
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    set<int> b;
    for(int i = 0; i < m; i++) {
        int x;
        cin >> x;
        b.insert(x);
    }
    
    int ans = INF;
    
    oset<int> st;
    
    map<int, int> last;
    
    for(int i = 0; i < n; i++) {
        if(!b.count(a[i])) {
            continue;
        }
        
        if(last.count(a[i])) {
            st.erase(last[a[i]]);
        }
        st.insert(i);
        last[a[i]] = i;
        
        if(st.size() < k) {
            continue;
        }
        
        int sz = st.size();
        
        ans = min(ans, i - *st.find_by_order(sz - k) + 1);
        
    }
    
    if(ans >= INF) {
        ans = -1;
    }
    
    cout << ans << '\n';
    
    return 0;
}