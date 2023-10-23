#define int128_t __int128_t
#define uint128_t __uint128_t
istream& operator>>(istream& is, int128_t &number) { bool negative = false; char c; number = 0; c = getchar(); if (c == '-') { negative = true; c = getchar(); } for (; (c >= '0' && c <= '9'); c = getchar()) number = number * 10 + (c - '0'); if (negative) number *= -1; return is; }
istream& operator>>(istream& is, uint128_t &number) { char c; number = 0; c = getchar(); for (; (c >= '0' && c <= '9'); c = getchar()) number = number * 10 + (c - '0'); return is; }
ostream& operator<<(ostream& os, int128_t x) {if (x < 0) { os << "-"; x *= -1; } if (x == 0) { return os << "0"; } string s; while (x) { s += char(x % 10 + '0'); x /= 10; } reverse(s.begin(), s.end()); return os << s; }
ostream& operator<<(ostream& os, uint128_t x) {if (x == 0) { return os << "0"; } string s; while (x) { s += char(x % 10 + '0'); x /= 10; } reverse(s.begin(), s.end()); return os << s;}
void dbg_print(const int128_t &x) { cerr << x; } void dbg_print(const uint128_t &x) { cerr << x; }