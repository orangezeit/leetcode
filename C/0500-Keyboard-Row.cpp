    vector<string> findWords(vector<string>& words) {
        unordered_set<char> first = {'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P', 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p'}; 
        unordered_set<char> second = {'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', 'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l'};
        vector<string> res;
        
        for(int i = 0; i < words.size(); ++i) {
            bool flag = true;
            
            for (int j = 1; j < words[i].length(); ++j) {
                bool c1_first = first.find(words[i][j-1]) != first.end();
                bool c2_first = first.find(words[i][j]) != first.end();
                bool c1_second = second.find(words[i][j-1]) != second.end();
                bool c2_second = second.find(words[i][j]) != second.end();
                
                if (c1_first && c2_first) {
                    continue;
                } else if (c1_second && c2_second) {
                    continue;
                } else if (!c1_first && !c2_first && !c1_second && !c2_second) {
                    continue;
                } else {
                    flag = false;
                    break;
                }
            }
            
            if (flag) res.push_back(words[i]);
        }
        
        return res;
    }
