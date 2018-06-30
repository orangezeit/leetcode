    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> record;
        
        for (int i = 0; i < magazine.length(); ++i) {
            record[magazine[i]]++;
        }
        
        for (int i = 0; i < ransomNote.length(); ++i) {
            record[ransomNote[i]]--;
            if (record[ransomNote[i]] < 0) {
                return false;
            }
        }
        
        return true;
    }
