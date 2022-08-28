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

#define int int64_t
const int inf = 1e18L + 5, mod = 1e9 + 7, N = 2e5 + 5;

#define ld long double

// CHECK_OVERFLOW64 = true can run up to 2 times slower (particularly on CF).
const bool CHECK_OVERFLOW64 = false;

using dist_t = long double;

struct point {
    int64_t x, y, w;

    point() : x(0), y(0) {}

    point(int64_t _x, int64_t _y) : x(_x), y(_y) {}

    point& operator+=(const point &other) { x += other.x; y += other.y; return *this; }
    point& operator-=(const point &other) { x -= other.x; y -= other.y; return *this; }
    point& operator*=(int64_t mult) { x *= mult; y *= mult; return *this; }
    point& operator/=(int64_t div) { assert(x % div == 0 && y % div == 0); x /= div; y /= div; return *this; }

    point operator+(const point &other) const { return point(*this) += other; }
    point operator-(const point &other) const { return point(*this) -= other; }
    point operator*(int64_t mult) const { return point(*this) *= mult; }
    point operator/(int64_t div) const { return point(*this) /= div; }

    bool operator==(const point &other) const { return x == other.x && y == other.y; }
    bool operator!=(const point &other) const { return !(*this == other); }

    point operator-() const { return point(-x, -y); }
    point rotate90() const { return point(-y, x); }

    int64_t norm() const {
        return (int64_t) x * x + (int64_t) y * y;
    }

    dist_t dist() const {
        return sqrt(dist_t(norm()));
    }

    bool top_half() const {
        return y > 0 || (y == 0 && x > 0);
    }

    friend ostream& operator<<(ostream &os, const point &p) {
        return os << '{' << p.x << ", " << p.y << '}';
    }
    
    friend istream& operator>>(istream &is, point &p) {
        return is >> p.x >> p.y;
    }
    
    bool operator< (const point &other) const {
        return tie(x, y) < tie(other.x, other.y);
    }
};

int64_t cross(const point &a, const point &b) {
    return (int64_t) a.x * b.y - (int64_t) b.x * a.y;
}

int64_t dot(const point &a, const point &b) {
    return (int64_t) a.x * b.x + (int64_t) a.y * b.y;
}

int cross_sign(const point &a, const point &b) {
    if (CHECK_OVERFLOW64) {
        long double double_value = (long double) a.x * b.y - (long double) b.x * a.y;

        if (abs(double_value) > 1e18)
            return double_value > 0 ? +1 : -1;
    }

    uint64_t uint64_value = (uint64_t) a.x * b.y - (uint64_t) b.x * a.y;
    int64_t actual = int64_t(uint64_value);
    return (actual > 0) - (actual < 0);
}

bool left_turn_strict(const point &a, const point &b, const point &c) {
    return cross_sign(b - a, c - a) > 0;
}

bool left_turn_lenient(const point &a, const point &b, const point &c) {
    return cross_sign(b - a, c - a) >= 0;
}

bool collinear(const point &a, const point &b, const point &c) {
    return cross_sign(b - a, c - a) == 0;
}

// Returns twice the signed area formed by three points in a triangle. Positive when a -> b -> c is a left turn.
int64_t area_signed_2x(const point &a, const point &b, const point &c) {
    return cross(b - a, c - a);
}

dist_t distance_to_line(const point &p, const point &a, const point &b) {
    assert(a != b);
    return dist_t(abs(area_signed_2x(p, a, b))) / (a - b).dist();
}

int64_t manhattan_dist(const point &a, const point &b) {
    return (int64_t) abs(a.x - b.x) + abs(a.y - b.y);
}

int64_t infinity_norm_dist(const point &a, const point &b) {
    return max(abs(a.x - b.x), abs(a.y - b.y));
}

// Sort in increasing order of y, with ties broken in increasing order of x.
bool yx_compare(const point &a, const point &b) {
    return make_pair(a.y, a.x) < make_pair(b.y, b.x);
}

// Sort in increasing order of angle to the x-axis.
bool angle_compare(const point &a, const point &b) {
    if (a.top_half() ^ b.top_half())
        return a.top_half();

    return cross_sign(a, b) > 0;
}

bool inside_triangle(const point &x, const point &a, const point &b, const point &c) {
    return (left_turn_strict(x, a, b) && left_turn_strict(x, b, c) && left_turn_strict(x, c, a)) ||
           (left_turn_strict(x, b, a) && left_turn_strict(x, c, b) && left_turn_strict(x, a, c));
}

void normalise (int64_t &a, int64_t &b) {
    assert(a != 0 || b != 0);
    if(a < 0 || (a == 0 && b < 0)) a = -a, b = -b;
    int64_t g = __gcd(a, b);
    a /= g, b /= g;
}

struct slope {
    int dx, dy;
    
    slope() {}
    
    slope (point a, point b = point(0, 0)) {
        dy = a.y - b.y;
        dx = a.x - b.x;
        normalise(dx, dy);
    }
    
    slope (int64_t _dx, int64_t _dy) : dx(_dx), dy(_dy) {
        normalise(dx, dy);
    }
    
    slope perpendicular () {
        return slope(-dy, dx);
    }
    
    bool operator==(const slope &other) const { return dx == other.dx && dy == other.dy; }
    bool operator!=(const slope &other) const { return !(*this == other); }
    
    bool operator< (const slope &other) const {
        return tie(dx, dy) < tie(other.dx, other.dy);
    }
    
    friend istream& operator>>(istream &is, slope &other) {
        return is >> other.dx >> other.dy;
    };
   
    friend ostream& operator<<(ostream &os, const slope &other) {
        return os << "{" << other.dx << " " << other.dy << "}";
    };
};

struct line {
    /*
    line : y = mx + c 
    y = (dy/dx) x + c
    ydx = xdy + cdx
    make sure gcd(dx, dy) = 1 (or, we normalize it in a sense)
    to uniquely identify a line we need: m and c
    m1 = m2 => dy_1/dx_1 = dy_2/dx_2 
    since slopes are normalized, the required condition becomes : dy_1 = dy_2 and dx_1 = dx_2 (Warning : always keep the denominator(dx) positive)
    to find c: we do c = (ydx - xdy) / dx but since dx must be same for the slope condition,
    we can do cdx = (ydx - xdy) and now the only required condition is (ydx - xdy)_1 = (ydx - xdy)_2
    */
    slope m;
    int64_t cdx;
    
    line () {}
    
    line (point a, int64_t dx, int64_t dy) : m(dx, dy) {
        cdx = a.y * m.dx - a.x * m.dy;
    }

    line (point a, slope _m) : m(_m) {
        cdx = a.y * m.dx - a.x * m.dy;
    }

    line (point a, point b) : m(a, b) {
        cdx = a.y * m.dx - a.x * m.dy;
    }
    
    bool operator==(const line &other) const { return m == other.m && cdx == other.cdx; }
    bool operator!=(const line &other) const { return !(*this == other); }
    
    bool operator< (const line &other) const {
        return tie(m, cdx) < tie(other.m, other.cdx);
    }
    
    friend istream& operator>>(istream &is, line &other) {
        return is >> other.m >> other.cdx;
    };
    
    friend ostream& operator<<(ostream &os, const line &other) {
        return os << "{" << other.m << " " << other.cdx << "}";
    };
};

const long double D_INF = 1e100;

const ld eps = 1e-9;

ld mysqrt(ld num) {
    ld lo = 0, hi = 1e9;
    for (int iter = 0; iter <= 200; iter++) {
        ld mid = (lo + hi) * 0.5;
        if (mid * mid > num) {
            hi = mid;
        }
        else {
            lo = mid;
        }
    }
    return lo;
}

void solve2() {
    ld x1, x2, y1, y2;
    scan(x1, y1, x2, y2);
    if (x1 > x2) {
        swap(x1, x2);
        swap(y1, y2);
    }

    ld m1 = (y2-y1) / (x2-x1);
    ld c1 = (y1 - (m1 * x1));
    ld m2 = -1/m1;
    int n;
    cin >> n;
    vector<pair<ld, ld>> ans(n);
    ld tot = 0;
    for (int i = 0; i < n; i++) {
        ld x, y;
        cin >> x >> y;
        ld best = inf;
        if (x1 == x2) {
            if (y1 > y2) {
                swap(x1, x2);
                swap(y1, y2);
            }
            if (y1 - eps <= y && y - eps <= y2) {
                best = abs(x - x1);
                ans[i] = {x1, y};
            }
        }
        else if (y1 == y2) {
            if (x1 > x2) {
                swap(x1, x2);
                swap(y1, y2);
            }
            if (x1 - eps <= x && x - eps <= x2) {
                best = abs(y - y1);
                ans[i] = {x, y1};
            }
        }
        else {
            if (x1 > x2) {
                swap(x1, x2);
                swap(y1, y2);
            }
            ld c2 = y - (x*m2);
            // dbg(m1, m2);
            ld xa = (c1-c2)/(m2-m1);
            ld ya = m2*xa + c2;
            ld ya2 = m1*xa + c1;
            assert(abs(ya-ya2) <= ep);
            if (x1 - eps <= xa && xa - eps <= x2) {
                ans[i] = {xa,ya};
                best = mysqrt((xa-x)*(xa-x) + (ya-y)*(ya-y));
            }
        }
        ld dis = mysqrt((x1-x)*(x1-x) + (y1-y)*(y1-y));
        if (dis < best) {
            best = dis;
            ans[i] = {x1, y1};
        }
        dis = mysqrt((x2-x)*(x2-x) + (y2-y)*(y2-y));
        if (dis < best) {
            best = dis;
            ans[i] = {x2, y2};
        }
        // dbg(best, distance_to_line(point(x, y), point(x1, y1), point(x2, y2)));
        tot += best;
    }
    
    print(tot);
    for (auto &x : ans) {
        print(x);
    }
    
    
    
}

void solve() {
    ld x1, x2, y1, y2;
    scan(x1, y1, x2, y2);
    if (x1 > x2) {
        swap(x1, x2);
        swap(y1, y2);
    }
    ld dx = x2 - x1;
    ld dy = y2 - y1;
    int n;
    cin >> n;
    vector<pair<ld, ld>> ans(n);
    ld tot = 0;
    for (int i = 0; i < n; i++) {
        ld x, y;
        cin >> x >> y;
        ld lx = x1, hx = x2;
        ld best = inf;
        for (int iter = 0; iter <= 400; iter++) {
            ld mx = (lx + hx) * 0.5;
            ld my = y1 + (mx - x1) / dx * dy;
            ld dis = (x - mx) * (x - mx) + (y - my) * (y - my);
            if (dis < best) {
                ans[i] = {mx, my};
                best = dis;
            }
            ld rx = mx + eps;
            ld ry = y1 + (rx - x1) / dx * dy;
            ld dis2 = (x - rx) * (x - rx) + (y - ry) * (y - ry);
            if (dis2 < dis) {
                lx = mx;
            }
            else {
                hx = mx;
            }
        }
        tot += sqrt(best);
    }
    print(tot);
    for (auto &x : ans) {
        print(x);
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cout << fixed << setprecision(10);
    cerr << fixed << setprecision(10);
    for (int tt = 1; tt <= t; tt++) {
        solve2();
    }
    return 0;
}