#include<bits/stdc++.h>
using namespace std;

int n;
vector<int> a, b;

void solve(){
	cin >> n;
	a = vector<int>(n, -1);
	b = vector<int>(n);
	for(int i = 0; i < n; i++){
		cin >> b[i];
		b[i]--;
	}
	int cur = 1;
	for(int i = n - 1; i >= 0; i--){
		a[i] = a[b[i]];
		if(a[i] == -1)
			a[i] = ++cur;
	}
	for(int i = 0; i < n; i++){
		cout << a[i] << " ";
	}
	cout << '\n';
}

int main()
{
    ios::sync_with_stdio(0);  cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--) solve();
    return 0;
}