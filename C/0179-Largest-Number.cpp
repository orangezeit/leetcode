    bool to_compare(string s1, string s2) {
        for (int i = 0; i < min(s1.length(), s2.length()); ++i) {
            if (s1[i] < s2[i]) {
                return true;
            } else if (s1[i] > s2[i]) {
                return false;
            }
        }
        
        if (s1.length() == s2.length()) {
            return false;
        } else {
            return to_compare(s1+s2, s2+s1);
        }
    }
    
    string largestNumber(vector<int>& nums) {
        vector<string> strs(nums.size());
        string str;
        
        for (int i = 0; i < nums.size(); ++i) {
            strs[i] = to_string(nums[i]);
        }
        
        for (int i = 0; i < strs.size()-1; ++i) {
            for (int j = i+1; j < strs.size(); ++j) {
                if(to_compare(strs[i], strs[j])) {
                    swap(strs[i], strs[j]);
                }
            }
        }
        
        for (int i = 0; i < nums.size(); ++i) {
            str += strs[i];
        }
        
        while (str[0] == '0') {
            return "0";
        }
        
        return str;
    }
