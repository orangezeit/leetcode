class WordDistance {
public:
    unordered_map<string, vector<int>> rec;
    WordDistance(vector<string> words) {
        for (int i = 0; i < words.size(); ++i) {
            rec[words[i]].push_back(i);
        }
    }
    
    int shortest(string word1, string word2) {
        int dist(INT_MAX);
        for (const int& i: rec[word1])
            for (const int& j: rec[word2])
                dist = min(dist, abs(i - j));
        return dist;
    }
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance obj = new WordDistance(words);
 * int param_1 = obj.shortest(word1,word2);
 */
