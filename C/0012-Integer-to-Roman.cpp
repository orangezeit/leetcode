    string combineRoman(vector<string> strs, int digit) {
        if (digit == 1) {
            return strs[0];
        } else if (digit == 2) {
            return strs[0] + strs[0];
        } else if (digit == 3) {
            return strs[0] + strs[0] + strs[0];
        } else if (digit == 4) {
            return strs[0] + strs[1];
        } else if (digit == 5) {
            return strs[1];
        } else if (digit == 6) {
            return strs[1] + strs[0];
        } else if (digit == 7) {
            return strs[1] + strs[0] + strs[0];
        } else if (digit == 8) {
            return strs[1] + strs[0] + strs[0] + strs[0];
        } else {
            return strs[0] + strs[2];
        }
    }
    string intToRoman(int num) {
        vector<vector<string>> infos = {{"I", "V", "X"}, {"X", "L", "C"}, {"C", "D", "M"}};
        int tens = 1000;
        int digits = 3;
        string str;
        
        while (num != 0) {
            if (num / tens != 0) {
                if (digits == 3) {
                    str += string(num / tens, 77);
                } else {
                    str += combineRoman(infos[digits], num / tens);
                }
            }
            num -= (num / tens * tens);
            tens /= 10;
            digits--;
        }
        
        return str;
    }
