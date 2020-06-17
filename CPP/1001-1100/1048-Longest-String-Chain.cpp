class Solution {
public:
    int longestStrChain(vector<string>& words) {
        unordered_map<string, int> record;
        int ans(1);
        sort(words.begin(), words.end(), [](const string& w1, const string& w2)
            {return w1.length() < w2.length() || w1.length() == w2.length() && w1 < w2;});

        for (const string& w: words) {
            record[w] = 1;
            if (w.length() == 1) continue;
            for (int j = 0; j < w.length(); ++j) {
                string temp = w;
                temp.erase(j, 1);
                if (record.count(temp))
                    ans = max(ans, record[w] = max(record[w], record[temp] + 1));
            }
        }


        return ans;
    }
};
