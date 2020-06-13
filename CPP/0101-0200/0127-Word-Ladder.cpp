    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        vector<bool> visited(wordList.size(), false);
        
        while (!q.empty()) {
            string str = q.front().first;
            int k = q.front().second;
            q.pop();
            
            for (int i = 0; i < wordList.size(); ++i) {
                if (!visited[i]) {
                    int c = 0;
                
                    for (int j = 0; j < str.length(); ++j) {
                        if (str[j] != wordList[i][j]) {
                            c++;
                            if (c == 2) {
                                break;
                            }
                        }
                    }
                    
                    if (c == 1) {
                        if (wordList[i] == endWord) {
                            return k+1;
                        } else {
                            q.push({wordList[i], k + 1});
                            visited[i] = true;
                        }
                    }
                }
            }
        }
        
        return 0;
    }
