#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <vector>
using namespace std;

#define int int64_t
const int N = 1e5 + 5;

signed main() {
    int n;
    cin >> n;
    vector<vector<int>> rectangles(n, vector<int>(4));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> rectangles[i][j];
        }
    }
    set<int> ys;
    for (auto const & r: rectangles)
    {
        ys.insert(r[1]);
        ys.insert(r[3]);
    }
    
    // sort rectangle with x_start
    sort(rectangles.begin(), rectangles.end(), [](
                        auto const & r1, auto const & r2
                        ){return r1[0] < r2[0];});
    
    // sweep from bottom to top
    int prev_y= *ys.begin();
    long long res = 0;
    for (auto y: ys)
    {
        if(y == prev_y) continue;
        long long height = y-prev_y;
        long long x_start = rectangles[0][0];
        long long x_end = x_start;
        for (auto const & r: rectangles)
        {
            // check if r fully occupy in between y and prev_y
            if (r[1] <= prev_y && r[3] >=y)
            {
                if (r[0] > x_end)
                {
                    res+= height * (x_end-x_start);
                    x_start = r[0];
                }
                if (r[2] > x_end)
                {
                    x_end = r[2];
                }
            }
        }
        res+= height * (x_end-x_start);
        prev_y = y;
    }
    cout << res << '\n';
    return 0;
} 