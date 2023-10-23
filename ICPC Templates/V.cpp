// Bit manipulation:
// x | (x + 1) sets lowest unset bit of x
// x & (x - 1) unsets lowest set bit of x
// x - 1 unsets the lowest set bit and sets all bits on its right
const int LOG = 64;

#define lsb(x) __builtin_ctzll(x)
#define msb(x) (63 - __builtin_clzll(x))
#define setbits(x) __builtin_popcountll(x)

template <size_t bits = LOG>
string to_binary(int num) {
    string binary = bitset<bits>(num).to_string();
    reverse(binary.begin(), binary.end());
    return binary;
}