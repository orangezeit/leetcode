class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_set<string> vocs;
        pair<int, string> temp;
        vector<pair<int, string>> records;
        vector<string> answers;

        for (int i = 0; i < words.size(); ++i) {
            if (vocs.find(words[i]) == vocs.end()) {
                vocs.insert(words[i]);
                temp = {1, words[i]};
                records.push_back(temp);
            } else {
                for (int j = 0; j < records.size(); ++j) {
                    if (records[j].second == words[i]) {
                        records[j].first++;
                    }
                }
            }
        }

        sort(records.rbegin(), records.rend());
        answers.resize(records.size());

        answers[0] = records[0].second;

        int s = 0;

        for (int i = 1; i < records.size(); ++i) {
            answers[i] = records[i].second;
            if (records[i-1].first != records[i].first) {
                sort(answers.begin()+s, answers.begin()+i);
                s = i;
                if (s >= k) {
                    break;
                }
            }
        }

        sort(answers.begin()+s, answers.end());
        answers.resize(k);

        return answers;
    }
};
