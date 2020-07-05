class Solution {
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int> cnt_queries(queries.size());
        vector<int> cnt_words(words.size());

        for (int i = 0; i < words.size(); ++i) {
            vector<int> cnts(26);
            for (int j = 0; j < words[i].length(); ++j) {
                cnts[words[i][j] - 'a']++;
            }
            for (int j = 0; j < 26; ++j) {
                if (cnts[j]) {
                    cnt_words[i] = cnts[j];
                    break;
                }
            }
        }
        //cout << "a";
        for (int i = 0; i < queries.size(); ++i) {
            vector<int> cnts(26);
            for (int j = 0; j < queries[i].length(); ++j) {
                cnts[queries[i][j] - 'a']++;
            }
            for (int j = 0; j < 26; ++j) {
                if (cnts[j]) {
                    cnt_queries[i] = cnts[j];
                    break;
                }
            }
        }
        //cout << "a";
        for (int i = 0; i < queries.size(); ++i) {
            int c = 0;
            int compare = cnt_queries[i];
            for (int j = 0; j < words.size(); ++j) {
                if (compare < cnt_words[j]) c++;
            }
            cnt_queries[i] = c;
        }
        return cnt_queries;
    }
};
