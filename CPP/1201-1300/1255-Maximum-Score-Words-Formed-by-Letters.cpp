class Solution {
public:

    void dfs(vector<int>& m, const vector<vector<int>>& cnts, unordered_set<int>& used, int scores, int& max_scores, const vector<int>& score) {
        bool enter(false);

        for (int i = 0; i < cnts.size(); ++i) {
            //cout << i << endl;
            if (used.count(i)) continue;

            bool success(true);

            for (int j = 0; j < 26; ++j)
                if (cnts[i][j] > m[j]) {
                    success = false;
                    break;
                }

            if (success) {
                enter = true;
                used.insert(i);
                for (int j = 0; j < 26; ++j) {
                    m[j] -= cnts[i][j];
                    scores += cnts[i][j] * score[j];
                    //m[j] += cnts[i][j];
                }
                dfs(m, cnts, used, scores, max_scores, score);
                for (int j = 0; j < 26; ++j) {
                    //m[j] -= cnts[i][j];

                    m[j] += cnts[i][j];
                    scores -= cnts[i][j] * score[j];
                }
                used.erase(i);
            }
        }

        if (!enter) {
            max_scores = max(max_scores, scores);
        }

    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int> m(26);
        for (const char& c: letters)
            m[c - 'a']++;
        vector<vector<int>> cnts(words.size(), vector<int>(26));
        int i(0);

        for (const string& word: words) {
            for (const char& c: word) {
                cnts[i][c - 'a']++;
            }
            i++;
        }
        int max_scores(0);
        unordered_set<int> used;
        dfs(m, cnts, used, 0, max_scores,score);

        return max_scores;
    }
};
