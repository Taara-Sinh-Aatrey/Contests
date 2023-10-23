#include "bits/stdc++.h"
using namespace std;

int main() {
    string password;
    cin >> password;
    
    const char min_char = '!';
    
    vector<char> cipherChar = {'_', 't', '-', 'L', '%', ';', 'f', 'c', 'V', '7', 'i', 'z', 'X', 'o', '"', 'h', '\'', 'Y', '1', '&', 'r', '6', '$', 'B', 'C', '?', 'M', 'l', 'j', '|', 'Z', '0', '#', ']', ')', 'O', '9', ',', '[', '{', 'F', '`', 'p', 'v', 'q', 'W', '/', 's', 'D', '+', '~', '!', 'I', 'J', '8', 'u', '<', 'P', 'K', 'T', 'E', 'd', 'y', '3', '2', 'n', '^', 'e', 'b', '5', 'a', 'm', '}', '.', 'H', 'Q', 'N', '4', ':', 'R', '\\', 'w', 'S', '@', '>', 'U', '*', '=', 'A', 'x', 'k', 'g', 'G', '('};
    
    string cipher = "";
    for (char &ch : password) {
        cipher += cipherChar[ch - min_char];
    }
    
    cout << cipher << endl;
    
    return 0;
}