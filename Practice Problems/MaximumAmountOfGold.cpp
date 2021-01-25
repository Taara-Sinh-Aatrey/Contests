#include<bits/stdc++.h>
using namespace std;

int main() {
	int w, n;
	cin >> w >> n;
	vector<int> a(n + 1);
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	vector<bool> dp(w + 1, false);
	dp[0] = true;
	for(int i = 1; i <= n; i++) {
		for(int j = w; j >= a[i]; j--) {
			if(dp[j - a[i]] == true) {
				dp[j] = true;
			}
		}
	}
	int answer = w;
	while(answer > 0 && dp[answer] == false) {
		answer--;
	}
	cout << answer << '\n';
	return 0;
}