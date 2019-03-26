    int calPoints(vector<string>& ops) {
        stack<int> records;
        int pts(0);
        
        for (int i = 0; i < ops.size(); ++i) {
            if (ops[i] == "C") {
                pts -= records.top();
                records.pop();
            } else if (ops[i] == "D") {
                records.push(2 * records.top());
                pts += records.top();
            } else if (ops[i] == "+") {
                int temp1 = records.top();
                records.pop();
                int temp2 = records.top();
                records.push(temp1);
                records.push(temp1 + temp2);
                pts += records.top();
            } else {
                records.push(stoi(ops[i]));
                pts += records.top();
            }
        }
        
        return pts;
    }
