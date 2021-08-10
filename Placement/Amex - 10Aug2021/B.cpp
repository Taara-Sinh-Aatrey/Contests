#include <bits/stdc++.h>
using namespace std;

int maxPairs(int input1, int input2[], int input3, int input4[]) {
    sort(input2, input2 + input1);
    int ans = 0;
    
    for(int i = 0; i < input3; i++) {
        int x = input4[i];
        
        ans += upper_bound(input2, input2 + input1, x) - input2;
    }
    
    return ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int arr1[] = {48};
    int arr2[] = {28, 32, 63};
    cout << maxPairs(1, arr1, 3, arr2) << endl;
    int arr3[] = {44, 45, 56, 39, 2, 6, 17, 75};
    int arr4[] = {54};
    cout << maxPairs(8, arr3, 1, arr4) << endl;
    
    return 0;
}