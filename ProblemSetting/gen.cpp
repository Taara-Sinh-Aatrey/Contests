#include<bits/stdc++.h>
#include<random>
using namespace std;

#define int int64_t

signed main() {
#ifdef LOCAL
    freopen("in2.txt", "w", stdout);
#endif
	// srand(time(0));
	mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
	auto rand = [&](int a, int b) {
		// return a + rand() % (b - a + 1);
		return uniform_int_distribution<int>(a, b)(rng);
	};
	int n = rand(5, 10);
	cout << n << '\n';
	for(int i = 0; i < n; i++) {
		int x = rand(0, 25);
		cout << x << " ";
	}
	cout << '\n';
	int q = rand(5, 20);
	cout << q << '\n';
	while(q--) {
		int l, r, x;
		l = rand(1, n);
		r = rand(1, n);
		// r = rand(1, l + 10);
		// if(r > n) {
		// 	r = rand(l - 10, l);
		// }
		if(l > r) {
			swap(l, r);
		}
		x = rand(0, 20 * n);
		assert(l >= 1);
    	assert(l <= r);
    	assert(r <= n);
    	assert(x >= 0);
		cout << l << " " << r << " " << x << '\n';
	}
	return 0;
}