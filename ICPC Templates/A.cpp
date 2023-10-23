Write debug.hpp in /home/contestant

fcompile() { g++ -std=c++17 -O2 -I/home/contestant sol.cpp -o sol.out }
frun() { fcompile sol && time ./sol.out; }
dbcompile() { g++ -std=c++17 -DLOCAL -DGLIBCXX_DEBUG -I/home/contestant sol.cpp -o sol.out }
dbrun() { dbcompile sol && ./sol.out; }
defrun() { dbcompile sol && ./sol.out < in > out; }
    
g++ -std=c++17 -O2 -I/home/contestant sol.cpp -o sol.out
g++ -std=c++17 -O2 -I/home/contestant brute.cpp -o brute.out
g++ -std=c++17 -O2 -I/home/contestant gen.cpp -o gen.out
for (( i = 1; ; i++ )); do
    echo -n "Case# $i"
    ./gen.out > in
    ./sol.out < in > out
    ./brute.out < in > ok
    printf "\r"
    if [[ $(diff -w out ok) ]];
    then
        echo "Case# $i"
        break
    fi
done

int inverse(int a, int m) {
    if(a == 0) return 0;
    int MOD = m;
    int u = 0, v = 1;
    while (a != 0) {
        int t = m / a;
        m -= t * a; swap(a, m);
        u -= t * v; swap(u, v);
    }
    assert(m == 1);
    u %= MOD;
    if(u < 0) u += MOD;
    return u;
}

class CRT {
public:

    // While declaring CRT, vector of primes must be passed to the constructor
    // call get function with vector of remainders to get back the number
    
    int n;
    vector<int> m;

    CRT(vector<int> p) {
        m = p;
        n = (int) m.size();
    }

    // (rem, mod)
    pair<int, int> get(vector<int> r) {
        assert(r.size() == m.size());
        int n = int(r.size());
        // Contracts: 0 <= r0 < m0
        int r0 = 0, m0 = 1;
        for (int i = 0; i < n; i++) {
            assert(m[i] >= 1);
            int r1 = (r[i] % m[i] + m[i]) % m[i], m1 = m[i];
            if (m0 < m1) {
                swap(r0, r1);
                swap(m0, m1);
            }
            if (m0 % m1 == 0) {
                if (r0 % m1 != r1) return {0, 0};
                continue;
            }

            int g = __gcd(m0, m1), im = inverse(m0, m1);
            int u1 = (m1 / g);
            if ((r1 - r0) % g) return {0, 0};
            int x = (r1 - r0) / g % u1 * im % u1;

            r0 += x * m0;
            m0 *= u1;
            if (r0 < 0) r0 += m0;
        }
        return {r0, m0};
        // m0 == 0 means no solution exists
    }
};