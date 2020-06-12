class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        vector<int> id1, id2;
        int ans(words.size());
        for (int i = 0; i < words.size(); ++i) {
            if (word1 == words[i]) id1.push_back(i);
            else if (word2 == words[i]) id2.push_back(i);
        }
        for (const int& i: id1) for (const int& j: id2) ans = min(ans, abs(i - j));
        return ans;
    }
};
