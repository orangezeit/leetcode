class Solution {
public:
    vector<string> mostVisitedPattern(vector<string>& username, vector<int>& timestamp, vector<string>& website) {
        int len(username.size());

        unordered_map<string, vector<pair<int, string>>> m;
        map<string, int> m2;
        int k = 0;
        string ans;
        vector<string> res;
        for (int i = 0; i < len; ++i)
            m[username[i]].push_back(make_pair(timestamp[i], website[i]));
        for (auto& p: m) {
            set<string> s;
            sort(p.second.begin(), p.second.end());
            for (int i = 0; i < p.second.size(); ++i) {
                for (int j = i + 1; j < p.second.size(); ++j) {
                    for (int k = j + 1; k < p.second.size(); ++k) {
                        string key = " " + p.second[i].second + " " + p.second[j].second + " " + p.second[k].second;
                        if (!s.count(key)) {
                            s.insert(key);
                            m2[key]++;
                        }
                    }
                }
            }
        }
        for (const auto& p: m2){
            if (p.second > k) {
                k = p.second;
                ans = p.first;
            }
        }
        for (const char& c: ans){
            if (c == ' ') res.push_back("");
            else res.back() += c;
        }
        return res;
    }
};
