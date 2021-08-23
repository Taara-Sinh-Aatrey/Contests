#include<bits/stdc++.h>
using namespace std;

const long long N = 1e6, mod = 1e9 + 7;
bool ok = false;

vector<long long> p(N + 5, 1);
void sieve() {
    p[0] = p[1] = 0;
    for(long long i = 2; i <= N; i++) {
        if(p[i] == 0)
            continue;
        for(long long j = i * i; j <= N; j += i) {
            p[j] = 0;
        }
    }
}

long long solve(string &s){
    long long n = s.size();
    vector<long long> dp(n + 1);
    dp[0] = 1;

    for(long long i = 1; i <= n; i++){
        for (long long j = 1; j <= 6; j++) {
            if(i-j >= 0 && s[i-j] != '0' && p[stoi(s.substr(i-j,j))]) {
                dp[i] = (dp[i] + dp[i-j]) % mod;
            }
        }
    }
    return dp[n];
}

int countprimeStrings(string s) {
    if (!ok) {
        sieve();
        ok = true;
    }
    return solve(s);
}

int main(){
    
    return 0;
}