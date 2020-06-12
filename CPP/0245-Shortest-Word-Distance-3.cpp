class Solution {
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        vector<int> loc1, loc2;
        
        for (int i = 0; i < words.size(); ++i) {
            if (word1 == words[i]) loc1.push_back(i);
            else if (word2 == words[i]) loc2.push_back(i);
        }
        int dist(INT_MAX);
        if (word1 == word2) {
            for (int i = 1; i < loc1.size(); ++i) {
                dist = min(dist, loc1[i] - loc1[i - 1]);
            }
            return dist;
        }
        int k(0);
        
        
        for (int i = 0; i < loc1.size(); ++i) {
            dist = min(dist, abs(loc1[i] - loc2[k]));
            while (loc1[i] > loc2[k]) {
                if (++k == loc2.size()) return dist;
                dist = min(dist, abs(loc1[i] - loc2[k]));
            }
        }
        
        return dist;
    }
};
