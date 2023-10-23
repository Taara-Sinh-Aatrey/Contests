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