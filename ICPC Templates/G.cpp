// ---------------- debug.hpp START ------------------
#include <bits/stdc++.h>
using namespace std;

// basic data types
void dbg_print(const int32_t &x) { cerr << x; } /* int */
void dbg_print(const uint32_t &x) { cerr << x; } /* unsigned */
void dbg_print(const long &x) { cerr << x; }
void dbg_print(const unsigned long &x) { cerr << x; }
void dbg_print(const int64_t &x) { cerr << x; } /* long long */
void dbg_print(const uint64_t &x) { cerr << x; } /* unsigned long long */
void dbg_print(const float &x) { cerr << x; }
void dbg_print(const double &x) { cerr << x; }
void dbg_print(const long double &x) { cerr << x; }
void dbg_print(const char &x) { cerr << x; }
void dbg_print(const string &x) { cerr << x; }

// pair
template <typename T, typename U>
void dbg_print(const pair<T, U> &p) {
    cerr << "(" << p.first << ", " << p.second << ")";
}

// stl containers
template <typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type>
void dbg_print(const T_container &v) {
    bool f = false;
    cerr << "[";
    for (const T &x : v) {
        if (f) cerr << ", ";
        dbg_print(x);
        f = true;
    }
    cerr << "]";
}

// prints #x = x (1 varibale)
template <typename Head> 
void dbg_out(string var, const Head &H) {
    cerr << var << " = ";
    dbg_print(H);
    cerr << endl;
}

// prints #x = x (variadic function)
template <typename Head, typename... Tail>
void dbg_out(string var, const Head &H, const Tail &...T) {
    for (int i = 0, b = 0; i < int(var.size()); i++) {
        if (var[i] == '(' || var[i] == '{') {
            b++;
        } 
        else if (var[i] == ')' || var[i] == '}') {
            b--;
        } 
        else if (var[i] == ',' && b == 0) {
            cerr << var.substr(0, i) << " = ";
            dbg_print(H);
            cerr << " | ";
            dbg_out(var.substr(var.find_first_not_of(' ', i + 1)), T...);
            break;
        }
    }
}

#define dbg(...) dbg_out(#__VA_ARGS__, __VA_ARGS__)

// ---------------- debug.hpp END ------------------