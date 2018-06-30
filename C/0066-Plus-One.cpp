    vector<int> plusOne(vector<int>& digits) {
        int i = digits.size() - 1;
        
        while (digits[i] == 9) {
            digits[i--] = 0;
            if (i < 0) {
                digits.insert(digits.begin(), 1);
                return digits;
            }
        }
        
        digits[i]++;
        return digits;
    }
