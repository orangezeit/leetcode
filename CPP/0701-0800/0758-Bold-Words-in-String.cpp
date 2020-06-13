class Solution {
public:
    void simplify(vector<pair<int, int>>& record) {
        sort(record.begin(), record.end());

        int k = 0;

        while (k < record.size() - 1) {
            if (record[k].second >= record[k+1].first) {
                record[k].second = max(record[k].second, record[k+1].second);
                record.erase(record.begin() + k + 1);
            } else {
                k++;
            }
        }
    }

    string boldWords(vector<string>& words, string S) {
        vector<pair<int, int>> record;

        for (int i = 0; i < words.size(); ++i) {
            int k = 0;
            while (S.find(words[i], k) != string::npos) {
                int n = S.find(words[i], k);
                record.push_back({n, n + words[i].length()});
                k = n + 1;
            }
        }

        if (record.empty())
            return S;

        simplify(record);

        int add = 0;

        for (int i = 0; i < record.size(); ++i) {
            S.insert(record[i].first + add, "<b>");
            add += 3;
            S.insert(record[i].second + add, "</b>");
            add += 4;
        }

        return S;
    }
};
