    void combinationHelper(string digits, vector<string> dict, vector<string>& combinations, string combination) {

        if (digits.empty()) {
            combinations.push_back(combination);
        } else {
            for (int j = 0; j < dict[digits[0]-'2'].size(); ++j) {
                char c = digits[0];
                combination += dict[digits[0]-'2'][j];
                digits.erase(0,1);
                    
                combinationHelper(digits, dict, combinations, combination);
                    
                combination.pop_back();
                digits.insert(0, 1, c);
            }
        }
    }
    
    vector<string> letterCombinations(string digits) {
        vector<string> dict = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> combinations;
        
        if(digits.length() == 0) {
            return combinations;
        }
        
        combinationHelper(digits, dict, combinations, "");
        return combinations;
    }
