#include "bits/stdc++.h"
using namespace std;

template <typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream &operator<<(ostream &os, const T_container &v) { bool f = false; for (const T &x : v) { if (f) os << " "; os << x; f = true; } return os; }

vector<string> split(string s, vector<char> d) {
    vector<string> ret;
    int last = 0;
    for (int i = 0; i <= s.size(); i++) {
        auto it = find(d.begin(), d.end(), s[i]);
        if (i == s.size() || it != d.end()) {
            ret.emplace_back(s.substr(last, i - last));
            last = i + 1;
        }
    }
    return ret;
}

vector<string> implementAPI(vector<string> logs) {
    map<string, bool> active_users;
    map<string, string> users_password;
    vector<string> ans;
    for (int i = 0; i < logs.size(); i++) {
        string &log = logs[i];
        vector<string> words = split(log, {' '});
        string operation = words[0];
        string username = words[1];
        if (operation == "logout") {
            if (!active_users.count(username)) {
                ans.emplace_back("Logout Unsuccessful");
            }
            else {
                active_users.erase(username);
                ans.emplace_back("Logged Out Successfully");
            }
            continue;
        }
        string password = words[2];
        if (operation == "register") {
            if (!users_password.count(username)) {
                users_password[username] = password;
                ans.emplace_back("Registered Successfully");
            }
            else {
                ans.emplace_back("Username already exists");
            }
        }
        else {
            if (!users_password.count(username) || users_password[username] != password || active_users.count(username)) {
                ans.emplace_back("Login Unsuccessful");
            }
            else {
                active_users[username] = true;
                ans.emplace_back("Logged In Successfully");
            }
        }
    }
    return ans;
}

int main() {
    cout << implementAPI({"register david david123", "register adam 1Adam1", "login david david123", "login adam 1adam1", "logout david"});
    return 0;
}