    int longestPalindrome(string s) {
        unordered_map<char, int> record;
        
        for (int i = 0; i < s.length(); ++i) {
            record[s[i]]++;
        }
        
        int l(0);
        bool odd(false);
        
        for (auto it = record.begin(); it != record.end(); ++it) {
            if (it->second % 2) {
                odd = true;
                l--;
            }
            l += it->second;
        }
        
        if (odd) {
            l++;
        }
        
        return l;
    }
