template <typename T>
vector<int> kmp_table(const T &s) {
    int n = s.size(), len = 0;
    vector<int> lps(n, 0);
    for (int i = 1; i < n; i++) {
        while (len > 0 && s[i] != s[len])
            len = lps[len - 1];
        if (s[i] == s[len]) 
            len++;
        lps[i] = len;
    }
    return lps;
}

// find occurences of `pat` in `text`
template <typename T>
int kmp_search(const T& text, const T& pat) {
    auto lps = kmp_table(pat);
    int ret = 0;
    // finding pattern in text using lps
    int n = text.size();
    int m = pat.size();
    
    for (int i = 0, j = 0; i < n; ) {
        if (pat[j] == text[i])
            j++, i++;
        if (j == m) {
            // pattern found
            ret++;
            j = lps[j - 1];
        }
        else if (i < n && pat[j] != text[i]) {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }
    return ret;
}
