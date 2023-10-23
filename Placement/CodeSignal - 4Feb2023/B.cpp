#include "bits/stdc++.h"

using namespace std;

#ifdef AATREY_DEBUG
#include "debug.hpp"
#else
#define dbg(...)
#endif

vector<int> solution(vector<string> commands) {
    vector<int> ans(3);
    for (auto &command : commands) {
        if (command[0] == '!') {
            command = commands[stoi(command.substr(1)) - 1];
        }
        if (command == "cp") {
            ans[0]++;
        }
        else if (command == "ls") {
            ans[1]++;
        }
        else {
            ans[2]++;
        }
    }
    return ans;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    dbg(solution({"ls", "cp", "mv", "mv", "mv", "!1", "!3", "!6"}));
    return 0;
}