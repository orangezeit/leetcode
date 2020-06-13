class Solution {
public:
    vector<string> wordsAbbreviation(vector<string>& dict) {
        unordered_map<string, unordered_set<int>> m;
        vector<string> ans(dict.size());

        for (int i = 0; i < dict.size(); ++i) {
            string label = dict[i].length() <= 3 ? dict[i] : dict[i][0] + to_string(dict[i].length() - 2) + dict[i].back();
            m[label].insert(i);
        }

        for (auto& p: m) {
            if (p.second.size() == 1) {
                ans[*p.second.begin()] = p.first;
            } else {
                int k(1);
                int len = dict[*p.second.begin()].length() - 2;
                while (!p.second.empty()) {
                    k++; len--;
                    unordered_map<string, unordered_set<int>> temp;

                    for (const int& i: p.second) {
                        string lab = len > 1 ? dict[i].substr(0, k) + to_string(len) + dict[i].back() : dict[i];
                        temp[lab].insert(i);
                    }

                    for (auto& q: temp) {
                        if (q.second.size() == 1) {
                            ans[*q.second.begin()] = q.first;
                            p.second.erase(*q.second.begin());
                        }
                    }
                }
            }
        }

        return ans;
    }
};
