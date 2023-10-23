// Remove the '\' from "\$#" in reform
// This was done to remove the Empty Key error from this snippet

// Manacher's Algorithm
// https://youtu.be/nbTSfrEfo6M

// Check if any rotation of given string is palindromic
// https://www.geeksforgeeks.org/check-given-string-rotation-palindrome/

// https://www.hackerearth.com/practice/algorithms/string-algorithm/manachars-algorithm/tutorial/

function<bool(int, int)> checkPal = [](int x, int len) {
    if (x == len) {
        return true;
    }
    else if (x > len) {
        if ((x % 2 == 0 && len % 2 == 0) || (x % 2 != 0 && len % 2 != 0)) {
            return true;
        }
    }
    return false;
};

function<string(string)> reform = [](string s) {
    string s1 = "$#";
    for (int i = 0; i < s.size(); i++) {
        s1 += s[i];
        s1 += '#';
    }
    s1 += '@';
    return s1;
};

function<void(string, int)> longestPal = [&checkPal](string s, int len) {
    int mirror = 0;
    int R = 0;
    int C = 0;
    int P[s.size()] = { 0 };
    for (int i = 1; i < s.size() - 1; i++) {
        mirror = 2 * C - i;
        if (i < R) {
            P[i] = min((R - i), P[mirror]);
        }
        while (s[i + (1 + P[i])] == s[i - (1 + P[i])]) {
            P[i]++;
        }
        // these lines are to check if any rotation of given string is palindromic
        // bool ans = checkPal(P[i], len);
        // if (ans) {
        //     return true;
        // }
        if (i + P[i] > R) {
            C = i;
            R = i + P[i];
        }
    }
    // return false;
};