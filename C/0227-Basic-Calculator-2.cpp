    int calculate(string s) {
        s += '+';
        stack<int> nums;
        
        int k = -1;
        char prev = '+';
        for (int i = 0; i < s.length(); ++i) {
            if ((s[i] < '0' || s[i] > '9') && s[i] != ' ') {
                int num = stoi(s.substr(k+1, i-k-1));
                if (prev == '+') {
                    nums.push(num);
                } else if (prev == '-') {
                    nums.push(-num);
                } else if (prev == '*') {
                    nums.top() *= num;
                } else {
                    nums.top() /= num;
                }
                prev = s[i];
                k = i;
            }
        }
        
        int res = 0;
        
        while (!nums.empty()) {
            res += nums.top();
            nums.pop();
        }
        
        return res;
    }
