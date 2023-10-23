#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <vector>
using namespace std;

#ifdef LOCAL
#include "debug.hpp"
#else
#define dbg(...)
#endif

int count (ListNode *head) {
        int cnt = 0;
        while (head) {
            cnt++;
            head = head->next;
        }
        return cnt;
    }
    
ListNode* move (ListNode *head, int amt) {
    while (amt > 0 && head) {
        amt--;
        head = head->next;
    }
    return head;
}

void display (ListNode *head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
}

class Solution {
public:
    
    void solve () {
        ListNode *head = new ListNode(10);
    }
    
};

int main() {
    
    Solution ob;    
    ob.solve();
    
    return 0;
}