class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());
        vector<vector<string>> res(searchWord.length());
        string prefix;

        for (int i = 0; i <= searchWord.length(); ++i) {
            prefix += searchWord[i];
            auto it = lower_bound(products.begin(), products.end(), prefix);
            while (it != products.end() && it->substr(0, i + 1) == prefix && res[i].size() < 3) {
                res[i].push_back(*it);
                ++it;
            }
        }
        return res;
    }
};
