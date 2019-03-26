    int scoreOfParentheses(string S) {
        stack<int> nums;
        nums.push(0);
        
        for (int i = 0; i < S.length(); ++i) {
            if (S[i] == '(') {
                nums.push(0);
            } else {
                if (nums.top()) {
                    int temp = 2 * nums.top();
                    nums.pop();
                    nums.top() += temp;
                } else {
                    nums.pop();
                    nums.top()++;
                }
            }
        }
        
        return nums.top();
    }
