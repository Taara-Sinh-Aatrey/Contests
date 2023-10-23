#include "bits/stdc++.h"
#include <algorithm>
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

const int inf = 1e9 + 5, mod = 1e9 + 7, N = 2e5 + 5;

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int* solve(int nums_size, int *nums, int maxes_size, int *maxes, int *result_size) {
    qsort(nums, nums_size, sizeof(int), cmpfunc);
    *result_size = maxes_size;
    int* results = (int *)malloc(sizeof(int) * maxes_size);
    for (int i = 0; i < maxes_size; i++) {
        int lo = 0, hi = nums_size - 1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (nums[mid] > maxes[i]) {
                hi = mid - 1;
            }
            else {
                lo = mid + 1;
            }
        }
        results[i] = hi + 1;
    }
    return results;
}

int main() {    
    int nums_size = 7;
    int nums[] = {23, 4, 2, 12, 18, 20, 16};
    int maxes_size = 4;
    int maxes[] = {13, 22, 29, 1};
    int result_size = 0;
    int *result = solve(nums_size, nums, maxes_size, maxes, &result_size);
    for (int i = 0; i < result_size; i++) {
        cout << result[i] << " "; 
    }
    cout << endl;
    return 0;
}