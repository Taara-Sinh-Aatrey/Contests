#include "bits/stdc++.h"
using namespace std;

vector<string> Split(string s) {
    vector<string> ret;
    string players;
    string time;
    int i = 0;
    while (!('0' <= s[i] && s[i] <= '9')) {
        players += s[i];
        i++;
    }
    players.pop_back();
    ret.push_back(players);
    while (s[i] != ' ') {
        time += s[i];
        i++;
    }
    ret.push_back(time);
    i++;
    ret.push_back(string(1, s[i]));
    i += 2;
    if (i < s.size()) {
        ret.push_back(s.substr(i));
    }
    return ret;
}

map<string, int> rnk;

vector<string> split(string s, vector<char> d) {
    vector<string> ret;
    int last = 0;
    for(int i = 0; i <= s.size(); i++) {
        auto it = find(d.begin(), d.end(), s[i]);
        if(i == s.size() || it != d.end()) {
            ret.emplace_back(s.substr(last, i - last));
            last = i + 1;
        }
    }
    return ret;
}

struct S {
    string team, Time, player, event, second;
    int actual;
    S (string  _team, vector<string> s) {
        player = s[0];
        Time = s[1];
        event = s[2];
        if(event == "S") {
            second = s[3];
        }
        team = _team;
        actual = stoi(split(Time, {'+'})[0]);
    }
    bool operator< (const S& other) const {
        if (actual != other.actual) return actual < other.actual;
        if (event != other.event) return rnk[event] < rnk[other.event];
        if (team != other.team) return team < other.team;
        return player < other.player;
    }
};

vector<string> getEventsOrder(string team1, string team2, vector<string> events1, vector<string> events2) {
    rnk["G"] = 0, rnk["Y"] = 1, rnk["R"] = 2, rnk["S"] = 3;
    vector<S> a;
    for (auto& st : events1) {
        vector<string> s = Split(st);
        S x(team1, s);
        a.push_back(x);
    }
    for (auto& st : events2) {
        vector<string> s = Split(st);
        S x(team2, s);
        a.push_back(x);
    }
    sort(a.begin(), a.end());
    vector<string> ans;
    for (int i = 0; i < a.size(); i++) {
        string s = a[i].team + " " + a[i].player + " " + a[i].Time + " " + a[i].event;
        if(a[i].event == "S") s += " " + a[i].second;
        ans.push_back(s);
    }
    return ans;
}

int main() {
    auto vec =  getEventsOrder("ABC", "CBA", {"Mo 45+2 Y", "A 13 G"}, {"D 23 S F", "Z 46 G"});
    for(auto& s : vec) {
        cout << s << '\n';
    }
    return 0;
}