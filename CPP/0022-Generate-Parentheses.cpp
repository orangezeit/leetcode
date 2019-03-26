    void bracketHelper(int x, int y, string str, vector<string>& strs) {
        if (x == 0 && y == 0) {
            strs.push_back(str);
        } else if (x <= y && x >= 0) {
            str += "(";
            bracketHelper(x-1, y, str, strs);
            str.pop_back();
            
            str += ")";
            bracketHelper(x, y-1, str, strs);
            str.pop_back();
        }
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> strs;
        bracketHelper(n, n, "", strs);
        return strs;
    }
