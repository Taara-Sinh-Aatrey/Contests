// brute force solution to find 2nd smallest number in a sequence of distinct integers
#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	int a[n + 1];
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++) {
		int num = a[i];
		int cnt = 0;
		for(int j = 1; j <= n; j++) {
			if(i == j) continue;
			if(a[j] < a[i]) {
				cnt++;
			}
		}
		if(cnt == 1) {
			cout << num;
			return 0;
		}
	}
}