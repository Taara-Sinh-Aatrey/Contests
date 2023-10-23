class trie {
public:
    vector<vector<int>> child;
    vector<int> val;
    // TODO: set MIN_CHAR
    const char MIN_CHAR = 'a';
    // TODO: set alphabet
    const int alphabet = 26;
    
    int create_node() {
        child.emplace_back(alphabet, -1);
        // TODO: set default value for trie nodes
        val.emplace_back(0);
        return child.size() - 1;
    }
    
    trie() {
        create_node();
    }
    
    void add(string s, int value = 1) {
        int cur = 0;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            int ch = s[i] - MIN_CHAR;
            if (child[cur][ch] == -1) child[cur][ch] = create_node();
            cur = child[cur][ch];
            // TODO: check if intermediate nodes should be updated
            val[cur] += value;
        }
        // TODO: check if leaf node should should be updated
        val[cur] = value;
    }
    
    int search(string s, int start = 0) {
        int cur = start;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            int ch = s[i] - MIN_CHAR;
            if (child[cur][ch] == -1)
                return -1;
            cur = child[cur][ch];
        }
        return cur;
    }
    
    void remove(string s, int value = 1) {
        int cur = 0;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            int ch = s[i] - MIN_CHAR;
            cur = child[cur][ch];
            assert(cur != -1 && val[cur] > 0);
            // TODO: check if intermediate nodes should be updated
            val[cur] -= value;
        }
        // TODO: check if leaf node should should be updated
        val[cur] = value;
    }
};