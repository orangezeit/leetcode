    int maxProduct(vector<string>& words) {
        if (words.size() <= 1) {
            return 0;
        }
        
        vector<vector<int>> info(words.size(), vector<int>(27, 0));
        
        for (int i = 0; i < words.size(); ++i) {
            info[i][26] = words[i].length();
            for (int j = 0; j < words[i].length(); ++j) {
                info[i][words[i][j] - 'a']++;
            }
        }
        
        int product = 0;
        
        for (int i = 0; i < words.size()-1; ++i) {
            for (int j = i+1; j < words.size(); ++j) {
                for (int k = 0; k < 26; ++k) {
                    if (info[i][k] && info[j][k]) {
                        break;
                    }
                    if (k == 25) {
                        product = max(product, info[i][26] * info[j][26]);
                    }
                }
            }
        }
        
        return product;
    }
