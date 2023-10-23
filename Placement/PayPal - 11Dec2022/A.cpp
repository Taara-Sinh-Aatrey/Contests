#include "bits/stdc++.h"

using namespace std;

#ifdef AATREY_DEBUG
#include "debug.hpp"
#else
#define dbg(...)
#endif


int largestCountValue(vector<int> a) {
    int n = a.size();
    vector<pair<int, int>> arr(n);
    for (int i = 0; i < n; i++) {
        arr[i] = {a[i], 0};
    }
    function<void(int, int)> mergeSort = [&] (int left, int right) -> void {
        if (left >= right) {
            return;
        }
        int mid = (left + right) / 2;
        mergeSort(left, mid);
        mergeSort(mid + 1, right);
        vector<pair<int, int>> temp(right - left + 1);
        int i = left, j = mid + 1, k = 0;
        while (i <= mid && j <= right) {
            if (arr[i].first < arr[j].first) {
                temp[k++] = arr[i++];
            }
            else {
                if (arr[j].first < arr[mid].first) {
                    arr[j].second++;
                }
                temp[k++] = arr[j++];
            }
        }
        while (i <= mid) {
            temp[k++] = arr[i++];
        }
        while (j <= right) {
            temp[k++] = arr[j++];
        }
        i = left, k = 0;
        while (i <= right) {
            arr[i++] = temp[k++];
        }
    };
    mergeSort(0, n - 1);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, arr[i].second);
    }
    return ans;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << largestCountValue({2, 3, 1}) << '\n';
    cout << largestCountValue({2, 1, 3}) << '\n';
    cout << largestCountValue({0, 3, 5, 2, 1}) << '\n';
    return 0;
}