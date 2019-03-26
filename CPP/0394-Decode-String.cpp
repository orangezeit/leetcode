    string decodeString(string s) {
        stack<int> nums;
        stack<string> strs;
        int i(0);
        strs.push("");
        
        while (i < s.length()) {
            if (s[i] >= '0' && s[i] <= '9') {
                int start = i;
                
                while (s[i] != '[') {
                    i++;
                }
                nums.push(stoi(s.substr(start, i-start)));
                strs.push("");
            } else if (s[i] == ']') {
                string str;
                for (int k = 0; k < nums.top(); ++k) {
                    str += strs.top();
                }
                strs.pop();
                strs.top() += str;
                nums.pop();
            } else {
                strs.top() += s[i];
            }
            i++;
        }
        
        return strs.top();
    }
