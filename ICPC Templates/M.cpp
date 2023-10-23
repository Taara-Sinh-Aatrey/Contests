/*
a * s + b * t = gcd(a, b) = g
auto [g, s, t] = extended_gcd(a, b);
*/
tuple<int, int, int> extended_gcd(int a, int b) {
    int x = 1, x1 = 0, y = 0, y1 = 1;
    while (b > 0) {
        int q = a / b;
        tie(x, x1) = make_tuple(x1, x - q * x1);
        tie(y, y1) = make_tuple(y1, y - q * y1);
        tie(a, b) = make_tuple(b, a - q * b);
    }
    return make_tuple(a, x, y);
}