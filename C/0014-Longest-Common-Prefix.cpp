    string longestCommonPrefix(vector<string>& strs) {
        string common;
        int k = INT_MAX;
        
        for (int i = 0; i < strs.size(); ++i) {
            if (strs[i].length() < k) {
                k = strs[i].length();
            }
        }
        
        if (k != INT_MAX) {
            int t = 0;
            
            while (t < k) {
                for (int i = 0; i < strs.size() - 1; ++i) {
                    if (strs[i][t] != strs[i+1][t]) {
                        return common;
                    }
                }
                common += strs[0][t++];
            }
        }
        
        return common;
    }
