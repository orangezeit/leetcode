    string getHint(string secret, string guess) {
        unordered_map<char, int> r1, r2;
        int bulls(0), cows(0);
        
        for (int i = 0; i < secret.length(); ++i) {
            if (secret[i] == guess[i]) {
                bulls++;
            } else {
                r1[secret[i]]++;
                r2[guess[i]]++;
            }
        }
        
        for (auto it = r1.begin(); it != r1.end(); ++it) {
            if (r2.find(it->first) != r2.end()) {
                cows += min(it->second, r2[it->first]);
            }
        }
        
        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
