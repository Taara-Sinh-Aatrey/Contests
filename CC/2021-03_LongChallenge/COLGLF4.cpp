#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        int n, e, h, omelette_price, milkshake_price, cake_price;
        cin >> n >> e >> h >> omelette_price >> milkshake_price >> cake_price;

        int ans = 1e18;
        bool successful = false;

        array<int, 3> combination;

        for(int combo = min({e, h, n}); combo >= 0; combo--) {
            array<int, 3> cur;
            cur[2] = combo;
            int eggs_left = e - combo;
            int chocolate_left = h - combo;

            int order = combo;
            int price = combo * cake_price;

            auto get_omellete = [&]() {
                int omelette_taken = min(n - order, eggs_left / 2);
                cur[0] = omelette_taken;
                order += omelette_taken;
                price += omelette_taken * omelette_price;
            };

            auto get_milkshake = [&]() {
                int milkshake_taken = min(n - order, chocolate_left / 3);
                cur[1] = milkshake_taken;
                order += milkshake_taken;
                price += milkshake_taken * milkshake_price; 
            };

            if(omelette_price <= milkshake_price) {
                get_omellete();
                get_milkshake();
            } else {
                get_milkshake();
                get_omellete();
            }

            assert(order <= n);
            if(order == n) {
                if(price < ans) {
                    combination = cur;
                }
                ans = min(ans, price);
                successful = true;
            }
        }
        // cout << combination[0] << " " << combination[1] << " " << combination[2] << '\n';
        cout << (successful ? ans : -1) << '\n';
    }
    return 0;
}