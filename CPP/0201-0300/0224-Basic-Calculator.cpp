    int calculate(string s) {
        s += '!';
        stack<int> nums;
        stack<char> ops;
        int k = -1;
        char prev = '+';
        nums.push(0);
        
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(') {
                nums.push(0);
                ops.push(prev);
                
                prev = '+';
                k = i;
            } else if (s[i] == '+' || s[i] == '-' || s[i] == '!') {
                if (i-k != 1 && (s[i] != '!' || s[k] != ')')) {
                    int num = stoi(s.substr(k+1, i-k-1));
                    if (prev == '+') {
                        nums.top() += num;
                    } else {
                        nums.top() -= num;
                    }
                }
                
                prev = s[i];
                k = i;
            } else if (s[i] == ')') {
                if (i-k != 1) {
                    int num = stoi(s.substr(k+1, i-k-1));
                    if (prev == '+') {
                        nums.top() += num;
                    } else {
                        nums.top() -= num;
                    }
                }
                
                int temp;
                if (ops.top() == '+') {
                    temp = nums.top();
                } else {
                    temp = -nums.top();
                }
                
                ops.pop();
                nums.pop();
                nums.top() += temp;
                k = i;
            }
        }
        
        return nums.top();
    }
