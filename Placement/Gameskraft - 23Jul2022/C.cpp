#include "bits/stdc++.h"
using namespace std;

template <typename T, typename U> istream& operator>>(istream &is, pair<T, U> &p) { return is >> p.first >> p.second; }
template <typename T, typename U> ostream& operator<<(ostream &os, const pair<T, U> &p) { return os << p.first << " " << p.second; }
template <typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> istream &operator>>(istream &is, T_container &v) { for (T &x : v) is >> x; return is; }
template <typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream &operator<<(ostream &os, const T_container &v) { bool f = false; for (const T &x : v) { if (f) os << " "; os << x; f = true; } return os; }
void scan() {} template <typename Head, typename ...Tail> void scan(Head &H, Tail &...T) { cin >> H; scan(T...); }
void print() { cout << "\n"; } template <typename Head> void print(const Head &H) { cout << H << "\n"; } template <typename Head, typename ...Tail> void print(const Head &H, const Tail &...T) { cout << H << " "; print(T...); }
template <typename T, typename T1, typename... Tail> T amin(T& a, T1 b, Tail... c) { if(b < a) a = b; if constexpr (sizeof...(c) != 0) { amin(a, c...); } return a; } template <typename T, typename T1, typename... Tail> T amax(T& a, T1 b, Tail... c) { if(b > a) a = b; if constexpr (sizeof...(c) != 0) { amax(a, c...); } return a; }

#ifdef LOCAL
#include "debug.hpp"
#else
#define dbg(...)
#endif

#define int long
const int inf = 1e18L + 5, mod = 1e9 + 7, N = 2e5 + 5;

int merge(vector<int32_t> &arr, vector<int> &temp, int left, int mid, int right) {
    int inv_count = 0;
 
    int i = left;
    int j = mid;
    int k = left;
    while ((i <= mid - 1) && (j <= right)) {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else {
            temp[k++] = arr[j++];
            inv_count = inv_count + (mid - i);
        }
    }

    while (i <= mid - 1)
        temp[k++] = arr[i++];
 
    while (j <= right)
        temp[k++] = arr[j++];
 
    for (i=left; i <= right; i++)
        arr[i] = temp[i];
 
    return inv_count;
}
 
int swapSort(vector<int32_t> &arr, vector<int> &temp, int left, int right) {
    int mid, inv_count = 0;
    if (right > left) {
        mid = (right + left) / 2;
        inv_count  = swapSort(arr, temp, left, mid);
        inv_count += swapSort(arr, temp, mid+1, right);
        inv_count += merge(arr, temp, left, mid + 1, right);
    }
    return inv_count;
}

#undef int

long getMinSwaps(vector<int> arr) {
    #define int long
    int n = arr.size();
    vector<int> temp(n);
    int swaps = 0;
    for (int i = 0, j; i < n; i = j) {
        j = i;
        while (j < n && __builtin_popcount(arr[j]) == __builtin_popcount(arr[i])) {
            j++;
        }
        swaps += swapSort(arr, temp, i, j - 1);
    }
    #undef int
    if (is_sorted(arr.begin(), arr.end())) {
        return swaps;
    }
    return -1;
}

signed main() {
    cout << getMinSwaps({3, 2, 1}) << endl;
    cout << getMinSwaps({1, 4, 2, 6, 12, 10}) << endl;
    return 0;
}