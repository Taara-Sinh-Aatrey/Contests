#include <bits/stdc++.h>
using namespace std;

#define int int64_t
const int inf = 1e18L + 5, mod = 1e9 + 7, N = 2e5 + 5;

class ComponentNode {
public:
    int value;
    vector<ComponentNode*> components;
    ComponentNode() {}
    ComponentNode(int numOfLinesChaged) {
        this->value = numOfLinesChaged;
    }
};

map<ComponentNode*, int> sz, sum;

ComponentNode* getFastestComponent(ComponentNode* rootComponent) {
    auto& childs = rootComponent->components;
    sz[rootComponent] = 1;
    sum[rootComponent] = rootComponent->value;
    ComponentNode* ans = new ComponentNode(0);
    sum[ans] = sz[ans] = 0;
    for (auto& child : childs) {
        ComponentNode* ret = getFastestComponent(child);
        sum[rootComponent] += sum[child];
        sz[rootComponent] += sz[child];
        if (sum[ans] == 0 || sum[ans] * 1LL * sz[ret] < sum[ret] * 1LL * sz[ans]) {
            ans = ret;
        }
    }
    if (!childs.empty()) {
        if (sum[ans] == 0 || sum[ans] * 1LL * sz[rootComponent] < sum[rootComponent] * 1LL * sz[ans]) {
            ans = rootComponent;
        }
    }
    return ans;
}

signed main() {
    return 0;
}