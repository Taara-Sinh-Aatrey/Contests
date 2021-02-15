#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
vector<int> atleast(N, 0);
vector<bool> prime(N, 1);

void sieve() {
    prime[0] = prime[1] = 0;
    for(int i = 2; i < N; i++) {
    	atleast[i] = atleast[i - 1];
    	if(prime[i]) {
    		atleast[i]++;
    		for(int j = 2 * i; j < N; j += i) {
    			prime[j] = 0;
    		}
    	}
    }
}

int main() {
	ios::sync_with_stdio(0);
    cin.tie(0);
	sieve();
	int t;
	cin >> t;
	while(t--) {
		int x, y;
		cin >> x >> y;
		cout << (atleast[x] > y ? "Divyam" : "Chef") << '\n';
	}
	return 0;
}
