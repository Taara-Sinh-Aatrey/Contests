#include <bits/stdc++.h>
using namespace std;

struct detail {
    string orgName;
    int st, ed;
};

int main() {
    int n;
    cin >> n;
    
    map<string, vector<pair<int, int>>> orgTimes;
    
    const int T = 24;
    
    for (int i = 0; i < n; i++) {
        string name;
        cin >> name;
        int start, end;
        cin >> start >> end;
        orgTimes[name].emplace_back(start, end);
    }
    
    int no_of_orgs = orgTimes.size();

    for (auto it = orgTimes.begin(); it != orgTimes.end(); it++) {
        string name = it->first;
        vector<pair<int, int>> cur = it->second;
        
        vector<int> hours_count(T + 1, 0);
        
        int bill = 0;
        for (int i = 0; i < cur.size(); i++) {
            hours_count[cur[i].first]++;
            hours_count[cur[i].second]--;
        }
        
        for (int i = 0; i <= T; i++) {
            if (i > 0) {
                hours_count[i] += hours_count[i - 1];
            }
            if (hours_count[i] == 1) {
                bill += 100;
            } 
            else if (hours_count[i] == 2) {
                bill += 150;
            } 
            else if (hours_count[i] == 3) {
                bill += 200;
            } 
            else if (hours_count[i] != 0) {
                bill += (200 + (hours_count[i] - 3) * 20);
            }
        }
        
        cout << "Organization " << name << " bill:" << bill << '\n';
    }

    return 0;
}