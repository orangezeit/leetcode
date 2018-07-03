    string originalDigits(string s) {
        unordered_map<char, int> record;
        
        for (int i = 0; i < s.length(); ++i) {
            record[s[i]]++;
        }
        
        return string(record['z'], '0') + string(record['o'] - record['u'] - record['w'] - record['z'], '1') + string(record['w'], '2') + string(record['h'] - record['g'], '3') + string(record['u'], '4') + string(record['f'] - record['u'], '5') + string(record['x'], '6') + string(record['s'] - record['x'], '7') + string(record['g'], '8') + string(record['i'] + record['u'] - record['f'] - record['g'] - record['x'], '9');
    }
