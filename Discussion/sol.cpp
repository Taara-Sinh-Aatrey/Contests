// program to find 2nd smallest number in a sequence of distinct integers
#include<bits/stdc++.h>
using namespace std;

const int maxN = 1e5 + 5;
int a[maxN]; 

int main() {
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	cout << a[2];
}