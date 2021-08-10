#include <bits/stdc++.h>
using namespace std;

int SheenaFlowers(int input1, int input2, int input3[]) {
    set<int> s;
    for(int i = 0; i < min(input1, input2); i++) {
        s.insert(input3[i]);
    }
    
    return (int) s.size();
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int arr1[] = {1, 1, 2, 1, 5};
    cout << SheenaFlowers(5, 3, arr1) << endl;
    int arr2[] = {2, 1, 2, 1, 3, 1, 5, 6, 1};
    cout << SheenaFlowers(10, 7, arr2) << endl;
    
    return 0;
}