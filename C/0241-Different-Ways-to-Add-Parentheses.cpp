private:
    unordered_map<string, vector<int>> fs;
public:
    vector<int> cartesian(vector<int> ls, vector<int> rs, char op) {
        vector<int> newResults(ls.size() * rs.size());
        int k(0);
        
        for (int i = 0; i < ls.size(); ++i) {
            for (int j = 0; j < rs.size(); ++j) {
                if (op == '+') {
                    newResults[k++] = ls[i] + rs[j];
                } else if (op == '-') {
                    newResults[k++] = ls[i] - rs[j];
                } else {
                    newResults[k++] = ls[i] * rs[j];
                }
            }
        }
        
        return newResults;
    }
    
    vector<int> diffWaysToCompute(string input) {
        string left, right;
        vector<int> ls, rs, res;
        bool equation = false;
        
        for (int i = 0; i < input.length(); ++i) {
            if (input[i] == '+' || input[i] == '-' || input[i] == '*') {
                equation = true;
                left = input.substr(0, i);
                right = input.substr(i+1, input.length()-i-1);
                
                if (fs.find(left) == fs.end()) {
                    ls = diffWaysToCompute(left);
                    fs.insert({left, ls});
                } else {
                    ls = fs[left];
                }
                
                if (fs.find(right) == fs.end()) {
                    rs = diffWaysToCompute(right);
                    fs.insert({right, rs});
                } else {
                    rs = fs[right];
                }
                
                vector<int> newres = cartesian(ls, rs, input[i]);
                res.insert(res.end(), newres.begin(), newres.end());
            }
        }
        
        if (!equation) {
            return vector<int>(1, stoi(input));
        }
        
        return res;
    }
