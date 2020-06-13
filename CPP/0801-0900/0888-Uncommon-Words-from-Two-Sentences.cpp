    vector<string> uncommonFromSentences(string A, string B) {
        istringstream iss(A + " " + B);
        unordered_set<string> uncommon, repeated;
        
        while (iss >> A) {
            if (uncommon.find(A) == uncommon.end()) {
                if (repeated.find(A) == repeated.end())
                    uncommon.insert(A);
            } else {
                uncommon.erase(A);
                repeated.insert(A);
            }
        }
        
        return vector<string>(uncommon.begin(), uncommon.end());
    }
