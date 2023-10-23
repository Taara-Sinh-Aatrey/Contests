#include <iostream>
#include <vector>

using namespace std;

int solution(vector<int>A)
{
    int n = A.size();
    vector<int> order(n);
    for (int i = 0; i < n; i++) {
        order[A[i] - 1] = i;
    }
    int ans = 0;
    for (int i = 1; i < n; i++) {
        ans += abs(order[i] - order[i - 1]);
    }
    return ans;
}