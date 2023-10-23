// TODO: set these consts accordinlgy
const char MIN_CHAR = 'a';
const int ALPHABET = 26;

namespace KMP26 {
    template <typename T>
    void compute_link(const T &s, vector<array<int, ALPHABET>> &link, vector<int> &fail) {
        int n = s.size();
        // fail[i + 1] means the index where pref[index] doesn't match
        // link[i][c] means the index where pref[index] doesn't match if we set s[i]=c
        for (int i = 0; i < n; i++) {
            int c = s[i] - MIN_CHAR;
            
            // right now link[i][c] stores the answer for proper prefix
            int previous = link[i][c];
            fail[i] = previous;
            
            // but now we can take whole prefix for the further calculations
            // example: ababac
            // link[3][1] = 2
            // but after processing i=3, we can set link[3][1] = 4
            // so that it updates the correct value to link[5][1]
            link[i][c] = i + 1;
            
            // `i` matches `previous-1`, so `link[i+1]` should be mapped to `link[previous]`
            link[i + 1] = link[previous];
        }
    }

    // Find all indices where `pattern` occurs within `text`
    template<typename T>
    vector<int> find_matches(const T &pattern, const T &text, const vector<array<int, ALPHABET>> &link) {
        if (pattern.size() > text.size())
            return {};
        vector<int> matches;
        int n = pattern.size(), m = text.size();
        int len = 0;
        for (int i = 0; i < m; i++) {
            int c = text[i] - MIN_CHAR;
            len = link[len][c];
            // Check for a match whose last character is at index i
            if (len == n)
                matches.push_back(i - (n - 1));
        }
        return matches;
    }
    
    
    
}