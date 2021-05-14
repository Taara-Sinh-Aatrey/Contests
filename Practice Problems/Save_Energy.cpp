#include <bits/stdc++.h>
using namespace std;

/*
	i   j   k
	x = (j - i) * A[i] + (j^2 - i^2) * A[i]^2 + (k - j) * A[j] + (k^2 - j^2) * A[j]^2

	i   k
	y = (k - i) * A[i] + (k^2 - i^2) * A[i]^2

	diff = y - x = (k - j) * A[i] + (k^2 - j^2) * A[i]^2 - (k - j) * A[j] - (k^2 - j^2) * A[j]^2
	             = (k - j) * (A[i] - A[j])           +                  (k^2 - j^2) * (A[i]^2 - A[j]^2)

	if abs(A[j]) < abs(A[i]):
		y - x > 0
		x < y
		so x is better (go to j)
	else if abs(A[j]) == abs(A[i])
		y - x = (k - j) * (A[i] - A[j]) > 0
		when A[i] > A[j] which is when A[i] > 0
		so y - x > 0 
        x < y
		when A[i] > 0 (go to j)

    conclusion: go to first element j such that abs(A[j]) < abs(A[i]) || abs(A[i]) == abs(A[j]) && A[i] > 0
*/


signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> A(n);
    for(auto& x: A) {
        cin >> x;
    }
    int ans = 0;
    int i = 0, j;
    for(j = 1; j < n - 1; j++){
        if(abs(A[j]) < abs(A[i]) || (abs(A[i]) == abs(A[j]) && A[i] > 0)) {
            ans  += (j - i) * A[i] + (j * j - i * i) * A[i] * A[i];
            i = j;
        }
    }
    ans  += (j - i) * A[i] + (j * j - i * i) * A[i] * A[i];

    return 0;
}
