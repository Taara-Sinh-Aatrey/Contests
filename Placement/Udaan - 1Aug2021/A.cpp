#include <bits/stdc++.h>
using namespace std;

template<typename A, typename B> istream& operator>>(istream &is, pair<A, B> &p) { return is >> p.first >> p.second;} template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> istream& operator>>(istream &is, T_container &v) { for (T& x : v) is >> x; return is;} bool debug;
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return debug ? os << '(' << p.first << ", " << p.second << ')' : os << p.first << " " << p.second;} template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { if(debug) { os << "{"; string sep; for (const T &x : v) os << sep << x, sep = ", "; os << '}'; } else { bool f = false; for (const T &x : v) { if(f) {os << " ";} os << x, f = true; } } return os;}
template <typename T, typename T1, typename... Tail> T amin(T& a, T1 b, Tail... c) { if(b < a) a = b; if constexpr (sizeof...(c) != 0) { amin(a, c...); } return a; } template <typename T, typename T1, typename... Tail> T amax(T& a, T1 b, Tail... c) { if(b > a) a = b; if constexpr (sizeof...(c) != 0) { amax(a, c...); } return a; }
void dbg_out() { cerr << endl; } template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#ifdef ONLINE_JUDGE
#define dbg(...)
#else
#define dbg(...) cerr << "[" << #__VA_ARGS__ << "]:", debug = true, dbg_out(__VA_ARGS__), debug = false
#endif

#define int int64_t
const int mod = 1e9 + 7; const int INF = 1e18L + 5; const int N = 2e5 + 5;

vector<vector<string>> strings;

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

int Hash(string day) {
    auto temp = split(day, {'-'});
    int _day = stoll(temp[0]) * 10000 + stoll(temp[1]) * 100 + stoll(temp[2]);
    return _day;
}

set<string> all_users;

map<pair<array<int, 3>, string>, int> user_list;

map<pair<string, int>, pair<vector<array<int, 2>>, array<bool, 1440>>> busy;

bool register_user() {
    string name;
    cin >> name;
    
    if(all_users.count(name)) {
        cout << "failure" << '\n';
        return false;
    }
    else { 
        all_users.insert(name);
        cout << "success" << '\n';
        return true;
    }
}

void create_event() {
    string day;
    int start, duration, n;
    cin >> day >> start >> duration >> n;
    vector<string> users(n);
    cin >> users;
    
    if(start + duration > 1440) {
        cout << "failure" << '\n';
        return;
    }
    
    int _day = Hash(day);
    
    array<int, 3> key = {_day, start, duration};
    
    for(auto& name : users) {
        pair<string, int> a = {name, _day};
        array<bool, 1440>& x = busy[a].second;
        
        for(int i = start; i < start + duration; i++) {
            if(x[i]) {
                cout << "failure" << '\n';
                return;
            }
        }
    }
    
    int sz = strings.size();
    strings.emplace_back(users);
    
    for(auto& name : users) {
        user_list[make_pair(key, name)] = sz;
    }
    
    for(auto& name : users) {
        pair<string, int> x = {name, _day};
        auto& [vec1, vec2] = busy[x];
        for(int i = start; i < start + duration; i++) {
            vec2[i] = true;
        }
        vec1.push_back({start, duration});
    }
    
    cout << "success" << '\n';
}

void show_events() {
    string day;
    cin >> day;
    string name;
    cin >> name;

    pair<string, int> req = {name, Hash(day)};
    // auto data = busy.find(req);
    // if (data == busy.end()) {

    // }
    auto &data = busy[req].first;
    for (auto &[a, b]: data) {
        cout << a << '-' << a + b << ' ';
        array<int, 3> ww = {Hash(day), a, b};
        pair<array<int, 3>, string> event_users = make_pair(ww, name);
        for (auto &user : strings[user_list[event_users]]) {
            cout << user << ' ';
        }
        cout << '\n';
    }
}

void suggest_slot() {
    string day;
    cin >> day;
    
    int start, end, duration, n;
    cin >> start >> end >> duration >> n;
    
    vector<string> users(n);
    cin >> users;
    
    set<int> st;
    for(int i = start; i + duration <= end - 1; i++) {
        st.insert(i);
    }
    
    for(auto& user: users) {
        pair<string, int> x = {user, Hash(day)};
        auto& bool_array = busy[x].second;
        
        vector<int> temp(1440, 0);
        
        int ans = -1;
        for(int i = end - 1; i >= start; i--) {
            temp[i] = (i + 1 >= 1440 ? 0 : temp[i + 1]) + 1;
            if(bool_array[i]) {
                temp[i] = 0;
            }
            if(temp[i] < duration && st.count(i)) {
                st.erase(i);
            }
        }
    }
    
    if(st.empty()) {
        cout << "none" << '\n';
    }
    else  {
        cout << *st.begin() << '\n';
    }
}

signed main()
{
    int q;
    cin >> q;
    
    while(q--) {
        string s;
        cin >> s;
        
        if(s == "add-user") {
            register_user();
        }
        else if(s == "create-event") {
            create_event();
        }
        else if(s == "show-events") {
            show_events();
        }
        else {
            suggest_slot();
        }
    }
    
    return 0;
}

/*

success
success
success
success
success
success
failure
success
600-660 user1 user2
660-690 user1 user3
600-660 user1 user2
660-690 user2 user4
690
none

*/