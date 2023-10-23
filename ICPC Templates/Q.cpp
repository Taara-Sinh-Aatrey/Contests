/*
we know f(1) f(2) f(3)
f(i) = 1 * f(i - 1) + 2 * f(i - 2) + 3 * f(i - 3)
f(i) = a * f(i - 1) + b * f(i - 2) + c * f(i - 3)

               F                  init
|f(i)    | = |a b c| ^ (i - 3)   |f(3)|
|f(i - 1)|   |1 0 0|           * |f(2)|
|f(i - 2)|   |0 1 0|             |f(1)|

*/ 
vector<vector<int>> mul(const vector<vector<int>>& a, const vector<vector<int>>& b) {
    assert(a.size() > 0 && b.size() > 0 && a[0].size() == b.size());
    int n = a.size(), m = b[0].size();
    vector<vector<int>> c(n, vector<int>(m, 0));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++){
            for(int k = 0; k < b.size(); k++) {
                c[i][j] += (a[i][k] * b[k][j]) % mod;
                if(c[i][j] >= mod) {
                    c[i][j] -= mod;
                }
            }
        }
    }
    return c;
}
 
vector<vector<int>> power(vector<vector<int>> a, int b) {
    int n = int(a.size());
    vector<vector<int>> res(n, vector<int>(n));
    for(int i = 0; i < n; i++) {
        res[i][i] = 1;
    }
    while(b > 0) {
        if(b & 1) {
            res = mul(res, a);
        }
        a = mul(a, a);
        b >>= 1;
    }
    return res;
}
 
signed main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        // To calcualate f(n) given f(1), f(2) and f(3)
        // f(i) = f(i-1) + 2 * f(i-2) + 3 * f(i-3)
        if(n <= 3) {
            cout << n << '\n';
            continue;
        }
        vector<vector<int>> F = {{1,2,3},{1,0,0},{0,1,0}};
        vector<vector<int>> init = {{3}, {2}, {1}};
        cout << mul(power(F, n - 3), init)[0][0]  << '\n';
    }
    return 0;
}